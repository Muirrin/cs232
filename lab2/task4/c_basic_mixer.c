// ----------------------------------------------------------------------------
//
// -------------------------------- C Basic Mixer --------------------------------
//
// ----------------------------------------------------------------------------
//
//  Purpose : To study the effects of performing operations on 
//            mixed data types.
//
//  Author  : Paul Zoski
//  Date    : 4/3/99
//  Modified: reformatted, JL Popyack Jan. 2002, Jan. 2003.
//  Modified: rewritten by Jun Yuan-Murray, 2016, August.
// 
// ----------------------------------------------------------------------------

#include <stdio.h>

// ----------------------------------------------------------------------------
//
// ------------------------------- Main Program -------------------------------
//
// ----------------------------------------------------------------------------

void conditionmixer() {
	int i = 6;
	char ch = 'm';
	
	printf("3==4 = %d\n", 3==4);
	printf("3==3 = %d\n", 3==3);
	printf("!0 = %d\n", !0);
	printf("!(-1) = %d\n", !(-1));
	printf("!\"abc\" =%d\n", !"abc");
	printf("2.0f == 2.0 is %d\n", (2.0f == 2.0));
	printf("1.1f == 1.1 is %d\n", (1.1f == 1.1));

        printf("%d\n", ch < 'z' && ch > 'a');
	printf("%d\n", !(ch-'z')?1:0);
	printf("%d\n", 2 * 3 == 6 || (i = i + 1));
        printf("%d\n", i);
	printf("%d\n", 2 * 3 == 6 && (i = i + 1));
        printf("%d\n", i);
}

void typemixer() {
	int   i=1, j=10, k=20 ;					
	char  a='a', B='B', dollarSign='$';
	float x=2.2, y=4.2/5.1, z=1.116e-5;
		
	// ---------------------------------------------------------------------
	// The variables were already assigned values.  Let's check them out.
	// ---------------------------------------------------------------------
	printf ("i = %d \tj=%d \t\t k=%d\n", i, j, k);		
	printf ("a = %c \tB=%c \t\t dollarSign=%c\n", a, B, dollarSign);		
        printf ("x = %f \ty=%f \t\t z=%e\n", x, y, z);		
	// ---------------------------------------------------------------------		
	// And now the fun stuff ....
	// ---------------------------------------------------------------------
		
	// ---------------------------------------------------------------------
	// an integer plus a character

	printf("a+j=%d\n", a+j);
	// ---------------------------------------------------------------------
	// a character plus an integer
		
        printf("k+B=%d\n", k+B);
	// ---------------------------------------------------------------------
	// mixing floats and characters
		
	printf("x/dollarSign = %f\n", x/dollarSign);
	// ---------------------------------------------------------------------
	// we can declare new objects at any time!
		
	char newChar;
	newChar = a+j;
			
	// ---------------------------------------------------------------------
	// huh? What's going on here?
		
	printf("a+j=%c\n", newChar);
	printf("B-6=%d\n", B-6);

}
int main( void )
{
	typemixer();
        conditionmixer();
	return 0;
}
