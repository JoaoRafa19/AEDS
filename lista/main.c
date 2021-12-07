#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <string.h>
#include <time.h>

char *randstring(int length)
{
  static int mySeed = 25011984;
  char *string = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!";
  size_t stringLen = strlen(string);
  char *randomString = NULL;

  srand(time(NULL) * length + ++mySeed);

  if (length < 1)
  {
    length = 1;
  }

  randomString = malloc(sizeof(char) * (length + 1));

  if (randomString != NULL)
  {
    short key = 0;

    for (int n = 0; n < length; n++)
    {
      key = rand() % stringLen;
      randomString[n] = string[key];
    }

    randomString[length] = '\0';

    return randomString;
  }
  else
  {
    printf("No memory");
    exit(1);
  }
}

int main(int argc, char *argv[])
{
  int arg1 = atoi(argv[1]);
  printf("%s", randstring(arg1));
  return 0;
}