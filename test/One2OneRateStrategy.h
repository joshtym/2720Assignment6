/* Source code for textbook:
 * Flexible Reliable Softare, by Henrik B. Christensen
 * CRC Press 2010
 * ***********************************
 * Project devleoped in Java by Henrik B. Christensen
 * C++ port by Robert Benkoczi
 * ***********************************
*/

/** Implementation for RateStrategy interface that uses a 1to1 function
 * It is used as test stub for testing PayStationImpl
 * 
 * 1) Provides an implementation for calculateTime function
**/
   
#ifndef ONE2ONERATESTRATEGY_H
#define ONE2ONERATESTRATEGY_H

#include "RateStrategy.h"

class One2OneRateStrategy : public RateStrategyInterface
{
	public:
		/// RateStrategy stub to unit test PayStationImpl
		int calculateTime(int amount) { return amount; };
};

#endif
