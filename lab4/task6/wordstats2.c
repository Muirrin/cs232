#include <stdio.h>
#include <string.h>
#define MAX_BUF 1024

int
main ()
{

  /* Zero out the array */
  int frequency[7] = {0};
  int len, i;
  char buf[MAX_BUF];
  printf("Enter a line of text: \n");
  fgets (buf, MAX_BUF, stdin);
  len = strlen(buf);
  do
 {
  for (i = 0; i < len; i++)
	{
    frequency[0]++;
	  if (buf[i] >= 'A' && buf[i] <= 'Z') //uppercase
	    {
            frequency[4]++;
	    }
    else if (buf[i] >= 'a' && buf[i] <= 'z') //lowercase
    {
         frequency[5]++;
    }
    else if (buf[i] >= 48 && buf[i] <= 57) //digits
    {
         frequency[6]++;
    }

    else if (buf[i] == ' ' || buf[i] == '\t') //white spaces
    {
         frequency[3]++;
         frequency[1]++;
    }


	}
	printf("Enter a line of text or press enter to escape: \n");
	fgets (buf, MAX_BUF, stdin);
	len = strlen(buf);
  frequency[2]++;
  frequency[1]++;
    }while (len > 1);

  printf ("Distribution of letters in corpus:\n");
  for (i = 0; i < 7; i++)
    {
      // 'A' is ASCII code 65
      printf ("%d ",frequency[i]);
    }
}
