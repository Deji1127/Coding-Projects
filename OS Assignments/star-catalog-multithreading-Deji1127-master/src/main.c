#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <getopt.h>
#include <stdint.h>
#include <pthread.h>
#include "utility.h"
#include "star.h"
#include "float.h"

pthread_mutex_t mutex;

#define NUM_STARS 30000
#define MAX_LINE 1024
#define DELIMITER " \t\n"

struct Star star_array[NUM_STARS];
uint8_t (*distance_calculated)[NUM_STARS];
int num_of_threads;

double min = FLT_MAX;
double max = FLT_MIN;
double mean = 0.0;
uint64_t count = 0;
void showHelp()
{
  printf("Use: findAngular [options]\n");
  printf("Where options are:\n");
  printf("-t          Number of threads to use\n");
  printf("-h          Show this help\n");
}

//
// Embarassingly inefficient, intentionally bad method
// to calculate all entries one another to determine the
// average angular separation between any two stars
void *determineAverageAngularDistance(void *arg)
{
  uint32_t i, j;
  //uint64_t count = 0;
  int thread_id = (int)arg;

  int start = (NUM_STARS/max)*thread_id;
  int end = 30000;//(NUM_STARS/max) + start;//(NUM_STARS/max)*(thread_id+1);
  // determine the start and end points of the outer loop based
  // on thread_id and max number of threads
  for (i = start; i < end; i++)
  {
    for (j = 0; j < NUM_STARS; j++)
    {
      if (i != j && distance_calculated[i][j] == 0)
      {
        double distance = calculateAngularDistance(star_array[i].RightAscension, star_array[i].Declination,
                                                   star_array[j].RightAscension, star_array[j].Declination);
        distance_calculated[i][j] = 1;
        distance_calculated[j][i] = 1;

        pthread_mutex_lock( &mutex );// start of the critical region. lock here
        count++;
        if (min > distance)
        {
          min = distance;
        }

        if (max < distance)
        {
          max = distance;
        }
        mean = mean + (distance - mean) / count;
        pthread_mutex_unlock( &mutex );// end of the critical region. unlock here
      }
    }
  }
}

int main(int argc, char *argv[])
{

  FILE *fp;
  uint32_t star_count = 0;

  uint32_t n;

  distance_calculated = malloc(sizeof(uint8_t[NUM_STARS][NUM_STARS]));

  if (distance_calculated == NULL)
  {
    uint64_t num_stars = NUM_STARS;
    uint64_t size = num_stars * num_stars * sizeof(uint8_t);
    printf("Could not allocate %ld bytes\n", size);
    exit(EXIT_FAILURE);
  }

  int i, j;
  // default every thing to 0 so we calculated the distance.
  // This is really inefficient and should be replace by a memset
  for (i = 0; i < NUM_STARS; i++)
  {
    for (j = 0; j < NUM_STARS; j++)
    {
      distance_calculated[i][j] = 0;
    }
  }

  for (n = 1; n < argc; n++)
  {
    if (strcmp(argv[n], "-help") == 0)
    {
      showHelp();
      exit(0);
    }
    if (strcmp(argv[n], "-t") == 0)
    {
      num_of_threads = atoi(argv[2]);
    }
  }

  fp = fopen("data/tycho-trimmed.csv", "r");

  if (fp == NULL)
  {
    printf("ERROR: Unable to open the file data/tycho-trimmed.csv\n");
    exit(1);
  }

  char line[MAX_LINE];
  while (fgets(line, 1024, fp))
  {
    uint32_t column = 0;

    char *tok;
    for (tok = strtok(line, " ");
         tok && *tok;
         tok = strtok(NULL, " "))
    {
      switch (column)
      {
      case 0:
        star_array[star_count].ID = atoi(tok);
        break;

      case 1:
        star_array[star_count].RightAscension = atof(tok);
        break;

      case 2:
        star_array[star_count].Declination = atof(tok);
        break;

      default:
        printf("ERROR: line %d had more than 3 columns\n", star_count);
        exit(1);
        break;
      }
      column++;
    }
    star_count++;
  }
  printf("%d records read\n", star_count);

  pthread_t id[num_of_threads];
  clock_t t;
  t = clock();// start timing here
  for (i = 0; i < num_of_threads; i++) // create as many threads as the user specifies using pthread_create
  {
    pthread_create(&id[i], NULL, determineAverageAngularDistance, (void *)i);
  }

  for (j = 0; j < num_of_threads; j++) // calls pthread_join
  {
    pthread_join(id[j], NULL);
  }
  t = clock()-t;//end timing here

  // Find the average angular distance in the most inefficient way possible
  // double distance = determineAverageAngularDistance(star_array);
  printf("Average distance found is %lf\n", mean);
  printf("Minimum distance found is %lf\n", min);
  printf("Maximum distance found is %lf\nTime: %f\n", max, ((double)t)/CLOCKS_PER_SEC);
  return 0;
}
