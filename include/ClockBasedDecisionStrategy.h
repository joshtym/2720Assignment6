/* Source code for textbook:
 * Flexible Reliable Softare, by Henrik B. Christensen
 * CRC Press 2010
 * *********************************
 * Project developed in Java by Henrik B. Chrinstensen
 * C++ port by Robert Benkoczi
 * *********************************
*/

/**Implementation for clock based weekend decision interface:
 * 
 * Responsibilities:
 * 
 * 1) Decide whether current time is weekend or not
*/

#ifndef CLOCKDECISIONSTRATEGY_H
#define CLOCKDECISIONSTRATEGY_H

#include "WeekendDecisionStrategy.h"

class ClockBasedDecisionStrategy : public WeekendDecisionStrategyInterface
{
	public:
		/// \return true if current day is on a weekend
		bool isWeekend();
};

#endif
