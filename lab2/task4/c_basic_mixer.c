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
	//3==4 = 0
	printf("3==3 = %d\n", 3==3);
	//3==3 = 1
	printf("!0 = %d\n", !0);
	//!0 = 1
	printf("!(-1) = %d\n", !(-1));
	//!(-1) = 1
	printf("!\"abc\" =%d\n", !"abc");
	//!"abc" =0
	printf("2.0f == 2.0 is %d\n", (2.0f == 2.0));
	//2.0f == 2.0 is 1
	printf("1.1f == 1.1 is %d\n", (1.1f == 1.1));
	//1.1f == 1.1 is 0

        printf("%d\n", ch < 'z' && ch > 'a');
	//1
	printf("%d\n", !(ch-'z')?1:0);
	//0
	printf("%d\n", 2 * 3 == 6 || (i = i + 1));
	//1
        printf("%d\n", i);
	//6
	printf("%d\n", 2 * 3 == 6 && (i = i + 1));
	//1
        printf("%d\n", i);
	//7
}

void typemixer() {
	int   i=1, j=10, k=20 ;					
	char  a='a', B='B', dollarSign='$';
	float x=2.2, y=4.2/5.1, z=1.116e-5;
		
	// ---------------------------------------------------------------------
	// The variables were already assigned values.  Let's check them out.
	// ---------------------------------------------------------------------
	printf ("i = %d \tj=%d \t\t k=%d\n", i, j, k);	
	//i = 1     j=10         k=20	
	printf ("a = %c \tB=%c \t\t dollarSign=%c\n", a, B, dollarSign);
	//a = a     B=B          dollarSign=$		
        printf ("x = %f \ty=%f \t\t z=%e\n", x, y, z);		
	//x= 2.200000     y=0.823529          z=-1.966397
	// ---------------------------------------------------------------------		
	// And now the fun stuff ....
	// ---------------------------------------------------------------------
		
	// ---------------------------------------------------------------------
	// an integer plus a character

	printf("a+j=%d\n", a+j);
	//a+j=107
	// ---------------------------------------------------------------------
	// a character plus an integer
		
        printf("k+B=%d\n", k+B);
	//k+B=86
	// ---------------------------------------------------------------------
	// mixing floats and characters
		
	printf("x/dollarSign = %f\n", x/dollarSign);
	//x/dollarSign = 0.061111
	// ---------------------------------------------------------------------
	// we can declare new objects at any time!
		
	char newChar;
	newChar = a+j; //newChar = k;
			
	// ---------------------------------------------------------------------
	// huh? What's going on here?
		
	printf("a+j=%c\n", newChar);
	//a+j=k
	printf("B-6=%d\n", B-6);
	//B-6=60

}
int main( void )
{
	typemixer();
        conditionmixer();
	return 0;
}
