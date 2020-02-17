
// ----------------------------------------------------------------------------
//
// ----------------------------------------------------------------------------
//
//
// scope_mixer was created for examination of several aspects
// of scopes:
//   - variables declared inside blocks
//   - access to variables outside blocks
//   - global variables
//   - address parameters
//
// JL Popyack, February 1999
// Modified
//   JL Popyack, February 2002 - created composite from earlier programs
//                               and reformatted
//Jun Yuan,  April 2006 -- modified and reformatted for CS102, HUST
//Jun Yuan,  October 2016 -- modified and reformatted for BCS120, Farmingdale State College
//Jun Yuan,  March 2019 -- modified and reformatted for CS232, Pace University
// ----------------------------------------------------------------------------

#include <stdio.h>
// ----------------------------------------------------------------------------
// ---"read comments carefully~ (•̀o•́)ง" -Jun-----------------------------------
//
// -------------------------------- Prototypes --------------------------------
//
// ----------------------------------------------------------------------------

void U(int n);
void A(void);
void val(int x);
void addr(int *x);
// ----------------------------------------------------------------------------
//
// ------------------------------ Global Variables ----------------------------
//
// ----------------------------------------------------------------------------

int m = 1;  // This is a global variable

// ----------------------------------------------------------------------------
//
// ------------------------------- Main Program -------------------------------
//
// ----------------------------------------------------------------------------
int main(void)
{

	// ---------------------------------------------------------------------
	// Blocks:
	// ---------------------------------------------------------------------
	// Any code may be surrounded by braces { ... }
	// Such code represents a block, which may have its own local variables.

	int n = 7;
	printf("main : m=%d, n=%d\n", m, n);
	U(n);
	printf("main : m=%d, n=%d\n", m, n);
	A();
	printf("main : m=%d, n=%d\n\n\n", m, n);

	// -------------------------------------------------
	// Below is a block, which may declare its own local
	// variables:
	// -------------------------------------------------
	{
		// -------------------------------------------------
		// A local variable n is declared here.
		// References to m refer to the global m.
		// -------------------------------------------------
		int n = 100;

		printf("block : m=%d, n=%d\n", m, n);
		U(n);
		printf("block : m=%d, n=%d\n", m, n);
		// -------------------------------------------------
		// A local variable m is now declared.
		// References to m from here to the end of the
		// block refer to this m.
		// -------------------------------------------------
		int m = -40;

		printf("block : m=%d, n=%d\n", m, n);
		val(m);
		printf("block : m=%d\n", m);
		addr(&m);
		printf("block : m=%d\n", m);

	}

	printf("main : m=%d, n=%d\n\n\n", m, n);
	//
	// ---------------------------------------------------------------------
	return 0;
}


// ----------------------------------------------------------------------------
//
// -------------------------- Subprogram Definitions --------------------------
//
// ----------------------------------------------------------------------------

void U(int n)
{
	m = n;
	printf("   U: m=%d, n=%d\n", m, n);
}

// ----------------------------------------------------------------------------
//
void A(void)
{
	int m = 3;
       {
		extern int m;
		m = 5; 
		printf("  global m=%d\n",  m);
	}
	printf("   A: m=%d\n", m);
}
// ----------------------------------------------------------------------------

void val(int x)
{
	printf("val  : x=%d\n", x);
	x = 5;
}
// ----------------------------------------------------------------------------
// -------------can't help testing your pass-by-pointers -Jun -----------------
void addr(int *x)
{
	printf("ref  : *x=%d\n", *x);
	*x = 5;
}
