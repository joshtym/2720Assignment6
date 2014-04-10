/* Source code for textbook:
 * Flexible Reliable Softare, by Henrik B. Christensen
 * CRC Press 2010
 * *********************************
 * Project developed in Java by Henrik B. Chrinstensen
 * C++ port by Robert Benkoczi
 * *********************************
*/

/**Weekend decision interface:
 * 
 * Responsibilities:
 * 
 * 1) Decide whether current time is weekend or not
**/

#ifndef WEEKENDDECISIONSTRATEGY_H
#define WEEKENDDECISIONSTRATEGY_H


class WeekendDecisionStrategyInterface
{
	public:
		/// function that determines if current day falls on a weekend
		/// \return true if current day is on a weekend
		virtual bool isWeekend() = 0;

		/// virtual destructor
		virtual ~WeekendDecisionStrategyInterface() {};
};

typedef WeekendDecisionStrategyInterface* WeekendDecisionStrategy;

#endif
