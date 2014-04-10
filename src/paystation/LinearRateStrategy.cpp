/* Source code for textbook:
 * Flexible Reliable Softare, by Henrik B. Christensen
 * CRC Press 2010
 * *********************************
 * Project developed in Java by Henrik B. Chrinstensen
 * C++ port by Robert Benkoczi
 * *********************************
*/

#include "LinearRateStrategy.h"

int LinearRateStrategy::calculateTime(int amount)
{
	return amount / 5 * 2;  // 5 cents are 2 min
}
