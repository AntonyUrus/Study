#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  FILE *input;
  char s[80];
  printf("Enter the full path to the file and press Enter:\n");
  do
  {
    scanf("%s", s);
    if ((input = fopen(s, "r")) == NULL)
      printf("Incorrect path, try another file:\n");
    else break;
  }
  while (1);
  int delay, id;
  while (!feof(input))
  {
    fscanf(input, "%d %s\n", &delay, s);
    if ((id  = fork())!= 0)
    {
      sleep(delay);
      execv(s, NULL);
    }
  }
  if (fclose (input))
  {
    printf("An error occcured while closing the file.\n");
    return 1;
  }
  return 0;
}
