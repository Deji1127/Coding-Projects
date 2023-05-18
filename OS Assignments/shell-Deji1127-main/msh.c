// The MIT License (MIT)
//
// Copyright (c) 2016 Trevor Bakker
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

#define WHITESPACE " \t\n" // We want to split our command line up into tokens
                           // so we need to define what delimits our tokens.
                           // In this case  white space
                           // will separate the tokens on our command line

#define MAX_COMMAND_SIZE 255 // The maximum command-line size

#define MAX_NUM_ARGUMENTS 10 // Mav shell only supports four arguments

int main(int argc, char *argv[])
{
  char *command_string = (char *)malloc(MAX_COMMAND_SIZE);
  //Allocate memory for the command string and initialize the history array to zero
  while (1)
  {
    printf("msh> "); // Print out the msh prompt

    // Read the command from the commandline.  Th
    // maximum command that will be read is MAX_COMMAND_SIZE
    // This while command will wait here until the user
    // inputs something since fgets returns NULL when there
    // is no input
    while (!fgets(command_string, MAX_COMMAND_SIZE, stdin));

    /* Parse input */
    char *token[MAX_NUM_ARGUMENTS];
    
    for (int i = 0; i < MAX_NUM_ARGUMENTS; i++)
    {
      token[i] = NULL;
    }

    int token_count = 0;

    // Pointer to point to the token
    // parsed by strsep
    char *argument_ptr = NULL;

    char *working_string = strdup(command_string);

    // we are going to move the working_string pointer so
    // keep track of its original value so we can deallocate
    // the correct amount at the end
    char *head_ptr = working_string;

    // Tokenize the input strings with whitespace used as the delimiter
    while (((argument_ptr = strsep(&working_string, WHITESPACE)) != NULL) &&
           (token_count < MAX_NUM_ARGUMENTS))
    {
      //Copy the token into the array and set it to NULL if it is an empty string
      token[token_count] = strndup(argument_ptr, MAX_COMMAND_SIZE);
      if (strlen(token[token_count]) == 0)
      {
        token[token_count] = NULL;
      }
      token_count++;
    }

    // Now print the tokenized input as a debug check

    // Check if the first token is empty or NULL and continue to the next iteration of the loop
    if (token[0] == NULL || strlen(token[0]) == 0)
    {
      continue;
    }
    //Check if the user entered the "quit" or "exit" command and exit the shell
    else if (strcmp(token[0], "quit") == 0)
    {
      exit(0);
    }
    else if (strcmp(token[0], "exit") == 0)
    {
      exit(0);
    }
    //Check if the user entered the "cd" command and change the working directory
    else if (strcmp(token[0], "cd") == 0)
    {
      chdir(token[1]);
    }
    
    // This code is executed if none of the previous conditions are met,
    // which means it is a command that needs to be executed.
    else
    {
      pid_t pid = fork();// Create a new process to run the command.
      if (pid == 0)// If we're in the child process, execute the command.
      {
        int ret = execvp(token[0], token); // Use the execvp() function to execute the command.

        if (ret == -1)// If execvp() returns -1, the command was not found
        {
          printf("%s: Command not found.\n", token[0]);
          break;
        }
      }
      else// If we're in the parent process, wait for the child to finish.
      {
        int status;
        wait(&status);
      }
    }

    // Free the memory allocated for the tokens.
    for (int i = 0; i < MAX_NUM_ARGUMENTS; i++)
    {
      if (token[i] != NULL)
      {
        free(token[i]);
      }
    }

    free(head_ptr);// Free the memory allocated for the working string.
  }

  free(command_string); // Free the memory allocated for the command string.
  return 0;
}
