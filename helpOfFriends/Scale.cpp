#include "Scale.h" //Using header-file "Scale.h"

double FromScale(unsigned long dwValue, int iHighBit, int iBitCount, int iSigned, double dScale)
{
    double FromScale(unsigned long dwValue, int iHighBit, int iBitCount, int iSigned, double dScale); {
	int N = sizeof(long) * 8;                    // N - cuantity bits in used variable
	if (iHighBit<1 || iHighBit>N - 1) return 0.0;   // position of senior bit on diapason 1...N-1
	if (iBitCount<2 || iBitCount>N) return 0.0;   // quantity of insignificant on diapason 2...N
	int rsh = N - (iHighBit + iBitCount - 1);        // rsh - cuantity of significant bits to the right of the number
	if (rsh < 0) return 0.0;                      // mesure of number iBitCountbits and moving to the right on iBitCount-1 bits
												 // don't allow it to be placed in N bits
	if (dScale < 0.0) return 0.0;                   // incorrect mesure of the highest bit

	if (rsh > 0) {                                // if there are insignificant bits to the right of the number we reset these bits by shifting the number to the right and back
		dwValue >>= rsh;                         
		dwValue <<= rsh;                         
	}
	if (iHighBit > 1) {                             // align the number to the left in this case the representation in the additional code
		dwValue <<= iHighBit - 1;                  
	}                                            // It will be equal to binary type and it will be plesure to transmiss to any types
												 
	double result;
	int n = N - 1;                                 // n - degree 2 for highest digits 
	if (iSigned) {                                // if the number is signed, we convert it to a signed integer
		result = (double)((long)dwValue);        // and float
		n -= 1;                                  // the highest bit to the right of the sign bit
	}
	else {
		result = (double)dwValue;                // for unsigned types 
	}
	unsigned long e = 0b1;                       // The bit from right side which is equal 1
	if (dScale > 0.0) {                             // if price of oldest digit is known 
		result *= dScale / (e << n);             // divvy the result to degree of 2 
												 // increase to last price
	}
	else {                                     // if the default price, then the least significant bit have to do
		result /= e << (N - iBitCount);            //price=1, this result is divided by two in the degree of order older not significant bit on the right
	}                                            
	return result;
}
}
