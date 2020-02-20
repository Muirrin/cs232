#include <stdio.h>
#include <string.h>
#define MAX_BUF 1024

int
main ()
{

  /* Zero out the array */
  int letter_frequency[26] = { 0 };
  int len, i;
  char buf[MAX_BUF];
  printf("Enter a line of text: \n");
  fgets (buf, MAX_BUF, stdin);
  len = strlen(buf);
  do
 {

  for (i = 0; i < len; i++)
	{
	  if (buf[i] >= 'A' && buf[i] <= 'Z')
	    {
            letter_frequency[buf[i]-65] = letter_frequency[buf[i]-65]+1;
	    }
    else if (buf[i] >= 'a' && buf[i] <= 'z')
    {
         letter_frequency[buf[i]-97] = letter_frequency[buf[i]-97]+1;
    }
	}
	printf("Enter a line of text or press enter to escape: \n");
	fgets (buf, MAX_BUF, stdin);
	len = strlen(buf);

    }
  while (len > 1);

  printf ("Distribution of letters in corpus:\n");
  for (i = 0; i < 26; i++)
    {
      // 'A' is ASCII code 65
      printf ("%c: %d\n", 65 + i, letter_frequency[i]);
    }
}
