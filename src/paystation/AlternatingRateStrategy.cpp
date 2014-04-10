/* Source code for textbook:
 * Flexible Reliable Softare, by Henrik B. Christensen
 * CRC Press 2010
 * *********************************
 * Project developed in Java by Henrik B. Chrinstensen
 * C++ port by Robert Benkoczi
 * *********************************
*/

#include "AlternatingRateStrategy.h"
#include <cstddef>

AlternatingRateStrategy::AlternatingRateStrategy
(RateStrategy weekend, RateStrategy weekday,
	WeekendDecisionStrategy weStrategy)
{
	weekendStrategy = weekend;
	weekdayStrategy = weekday;
	currentState = NULL;
	weekendDecision = weStrategy;
}

AlternatingRateStrategy::~AlternatingRateStrategy()
{
	delete weekendStrategy;
	delete weekdayStrategy;
	delete weekendDecision;
}

int AlternatingRateStrategy::calculateTime(int amount)
{
	if (weekendDecision->isWeekend())
		currentState = weekendStrategy;
	else
		currentState = weekdayStrategy;
		
	return currentState->calculateTime(amount);
}
