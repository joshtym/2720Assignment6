/* Source code for textbook:
 * Flexible Reliable Software, by Henrik B. Christensen
 * CRC Press 2010
 * ****************************************
 * Project developed in java by Henrik B. Christensen
 * C++ port by Robert Benkoczi
 * *****************************************
*/

/**
 * Implementation for RateStrategy interface that uses a linear function
 * 
 * Responsibilities:
 * 
 * 1) Provide an actual implementation for calculateTime function
**/

#ifndef LINEARRATESTRATEGY_H
#define LINEARRATESTRATEGY_H

#include "RateStrategy.h"

class LinearRateStrategy : public RateStrategyInterface
{
	public:
		/// Implementation for calculateTime function that implements
		/// Alphatown's linear strategy
		int calculateTime(int amount);
};
#endif
