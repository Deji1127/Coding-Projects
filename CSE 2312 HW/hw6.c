// C99

#include <stdio.h>  // printf
#include <stdint.h> // C99 uintX_t and intX_t types

extern float sumF32(const float x[], const uint32_t count);
extern double prodF64(const double x[], const uint32_t count);
extern double dotpF64(const double x[], const double y[], uint32_t count);
float maxF32(const float x[], uint32_t count);

#define COUNT 10
#define COUNT2 10

int main(void)
{

  float x[COUNT] = {
    200.2,
    47.55,
    77.54,
    240.41,
    90.28,
    2.25,
    5.925,
    423.1,
    970.0,
    580.65
  };

  float sum = 0.0;
  sum = sumF32(x, COUNT);
  printf("sumF32 student answer: %f\n", sum);

  float sum2 = 0.0;
  for (int i = 0; i < COUNT; i++){
    sum2 += x[i];
  }
  printf("sumF32 correct answer: %f\n\n", sum2);

  double y[COUNT] = {
    4083.17,
    4168.4,
    366.23,
    3990.19,
    11.09,
    4637.8,
    168.63,
    3127.73,
    1710.28,
    4152.27
  };

  double prod = prodF64(y, COUNT);
  printf("prodF64 student answer: %lf\n", prod);
  double prod2 = 1.0;
  for (int i = 0; i < COUNT; i++){
    prod2 *= y[i];
  }
  printf("prodF64 correct answer: %lf\n\n", prod2);

  double z[COUNT] = {
    83.17,
    168.4,
    66.23,
    990.19,
    1.09,
    637.8,
    68.63,
    127.73,
    710.28,
    152.27
  };
  double dotp = dotpF64(y, z, COUNT);
  printf("dotpF64 student answer: %lf\n", dotp);
  double dotp2 = 0.0;
  for (int i = 0; i < COUNT; i++) {
    dotp2 += y[i]*z[i];
  }
  printf("dotpF64 correct answer: %lf\n\n", dotp2);

  float max = maxF32(x, COUNT);
  printf("maxF32 student answer: %.2f\n", max);
  float max2 = x[0];
  for ( int i = 1; i < COUNT; i++ ) {
    if (x[i] > max2)
      max2 = x[i];
  }
  printf("maxF32 correct answer: %.2f\n", max2);

    return 0;
}