/* Source code for textbook:
 * Flexible Reliable Softare, by Henrik B. Christensen
 * CRC Press 2010
 * *********************************
 * Project developed in Java by Henrik B. Chrinstensen
 * C++ port by Robert Benkoczi
 * *********************************
*/
/** Implementation for RateStrategy interface that uses a piecewise
 * linear function
 * 
 * Responsibilities:
 * 
 * 1) Provide an actual implementation for calculateTime function.
**/

#ifndef PROGRESSIVERATESTRATEGY_H
#define PROGRESSIVERATESTRATEGY_H

#include "RateStrategy.h"

class ProgressiveRateStrategy : public RateStrategyInterface
{
	public:
		/// implementation for calculateTime function that implements
		/// Alphatown's linear strategy
		int calculateTime(int amount);
};
#endif
