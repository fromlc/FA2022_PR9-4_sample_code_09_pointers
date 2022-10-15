//------------------------------------------------------------------------------
// Pr9-4LRC.cpp
// 
// This program demonstrates 
//		1) a pointer variable referencing int and char variables, and
//		2) how to use a pointer to get the value of int and char variables.
// 
// Author: Gaddis 9E pp.510-511, modified by Prof. Linda C
//------------------------------------------------------------------------------
#include <iostream>

//------------------------------------------------------------------------------
// using symbols
//------------------------------------------------------------------------------
using std::cin;
using std::cout;

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

	//------------------------------------------------------------------------------
	// allocate memory for an int variable and initialize it
	int x = 25;
	//------------------------------------------------------------------------------
	// allocate memory for int pointer variable pInt
	//		pInt will know the address of an int value
	// 
	// best practice: always initialize pointer variables to nullptr!
	//------------------------------------------------------------------------------
	int* pInt = nullptr;

	// Display the contents of memory location x
	cout << "The value at memory location x is: " << x << "\n";

	// Use the pointer pInt to manipulate int x

	pInt = &x;      // Store the address of x in ptr.
	*pInt += 100;   // Add 100 to the value in x.

	// Display the contents of memory location x again
	cout << "After pInt changes the value of memory location x, the value at x is: "
		<< x << "\n";

	//------------------------------------------------------------------------------
	// How to use int* pInt to traverse an array
	//------------------------------------------------------------------------------

	// first, the traditional way (see Checkpoint 9.5 on p.519 in Gaddis 9E)

	int intArray[5] = { 5, 10, 15, 20, 25 };
	cout << "intArray elements, using square bracket syntax:\n";

	for (int i = 0; i < 5; i++) {
		cout << intArray[i] << ' ';
	}
	cout << "\n";

	// now we use pInt

	pInt = intArray;				// pInt has intArray's starting address
	pInt = &intArray[0];			// another way to say the same thing

	cout << "intArray elements, using *pInt pointer syntax:\n";

	for (int i = 0; i < 5; i++) {
		cout << *pInt << ' ';		// display the value at address pInt
		pInt++;						// set pInt's value to the next int element
	}
	cout << '\n';

	//------------------------------------------------------------------------------
	// Notice that pInt increases by 4 each time through the for loop above.
	// 
	// The ++ operator knows pInt points to an int so pInt++ adds 4 to pInt.
	//------------------------------------------------------------------------------

	// let's try this with a char array

	char charArray[5] = { 'L', 'i', 'n', 'd', 'a' };
	char* pChar = charArray;		// pChar has charArray's starting address
	pChar = &charArray[0];			// another way to say the same thing
	cout << "charArray's elements, using *pChar :\n";

	for (int i = 0; i < 5; i++) {
		cout << *pChar << ' ';		// display the value at address pChar
		pChar++;					// move pChar to the next char element
	}
	cout << '\n';

	//------------------------------------------------------------------------------
	// Notice that pChar increases by 1 each time through the for loop above.
	// 
	// The ++ operator knows pChar points to a char so pChar++ adds 1 to pChar.
	//------------------------------------------------------------------------------
	
	//------------------------------------------------------------------------------
	// Also notice that charArray is not a C++ string or even a C string! Why?
	//------------------------------------------------------------------------------

	// console app window will stay until user types any key
	cin.get();

	return 0;
}