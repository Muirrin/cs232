/*  Example: C program to find area of a circle */

#include <stdio.h>
#define PI 3.14159

int main()
{
  float r, a, c;
//prompt user to enter radius

  printf("Enter radius (in mm):\n");
  scanf("%f", &r);

while(r!=0){
//while r is not = 0, execute the following
r = r/25.4;
a = (PI * r *r);
c = (PI * 2 * r);

printf("Circle's area is %3.2f (sq in).\n", a);
printf("Its circumference is %3.2f (in).\n", c);
printf("Enter radius (in mm):\n");
  scanf("%f", &r);
}
printf("Exit");
}
