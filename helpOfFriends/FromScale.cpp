#include <iostream> //calling input output library
#include <bitset>  // calling library of binary functions
#include "Scale.h"  //calling our header
using namespace std;

// The print function
void print_FromScale(ostream& cout, unsigned long dwValue, int iHighBit, int iBitCount, int iSigned, double dScale) {
	cout << "\nFromScale(\n";
	cout << "\t0b" << bitset<sizeof(long) * 8>(dwValue) << " ,\t // dwValue\n";
	cout << "\t" << iHighBit << " ,\t // iHighBit\n";
	cout << "\t" << iBitCount << " ,\t // iBitCount\n";
	cout << "\t" << iSigned << " ,\t // iSigned\n";
	cout << "\t" << dScale << "  \t // dScale \n";
	cout << ") = " << FromScale(dwValue, iHighBit, iBitCount, iSigned, dScale) << "\t\t // RESULT\n";
}

int main() {

	int N = sizeof(long) * 8;
	cout << "\n" << N << " бит в типах long и unsigned long\n"; 

	unsigned long e = 0b1;

	unsigned long dwValue;
	int iHighBit, iBitCount, iSigned;
	double dScale;

	dwValue = 35;
	iHighBit = 1;
	iBitCount = N;
	iSigned = 0;
	dScale = 0.0;
	// let's check unsigned, with the price of the highest digit by default
	print_FromScale(cout, dwValue, iHighBit, iBitCount, iSigned, dScale);

	iSigned = 1; // positive (with sign plus)
	print_FromScale(cout, dwValue, iHighBit, iBitCount, iSigned, dScale);

	// let's set the price of the highest digit as a degree of two
	dScale = (double)(e << (N - 2)); // -2 because the bit numbering is set with 1 and minus 1 sign bit
	print_FromScale(cout, dwValue, iHighBit, iBitCount, iSigned, dScale);

	dScale = (double)(e << (N - 3)); // we will reduce the previous price of the highest digit by half, so we will move the fixed point to the left by a digit
	print_FromScale(cout, dwValue, iHighBit, iBitCount, iSigned, dScale);

	dScale = (double)(e << (N - 5)); // and a couple more digits to the left
	print_FromScale(cout, dwValue, iHighBit, iBitCount, iSigned, dScale);

	dwValue = -35; // The same for dubziro 
	print_FromScale(cout, dwValue, iHighBit, iBitCount, iSigned, dScale);

	iHighBit = 2;    // now let the sign bit is not in the first place,
	   			   //i.e.the number takes place from the second bit
	iBitCount = N - 1; // now the number takes up less bits than before
	print_FromScale(cout, dwValue, iHighBit, iBitCount, iSigned, dScale);

	iBitCount = N - 2; /*let the number take up another 1 bit less, i.e.
		one insignificant bit appears on the right*/
	print_FromScale(cout, dwValue, iHighBit, iBitCount, iSigned, dScale);

	return 0;
}


