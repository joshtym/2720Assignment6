/* Source code for textbook:
 * Flexible Reliable Softare, by Henrik B. Christensen
 * CRC Press 2010
 * ***********************************
 * Project devleoped in Java by Henrik B. Christensen
 * C++ port by Robert Benkoczi
 * ***********************************
*/
 
/**Implementation for clock based weekend decision interface:
 * 
 * Responsibilities:
 * 
 * 1) Decide whether current time is weekend or not
**/

#ifndef FIXEDDECISIONSTRATEGY_H
#define FIXEDDECISIONSTRATEGY_H

#include "WeekendDecisionStrategy.h"

class FixedDecisionStrategy : public WeekendDecisionStrategyInterface
{
	private:
		bool weekend; // true if should return weekend
	public:
		/// \return true if current day is on a weekend
		bool isWeekend()
		{
			return weekend;
		}

		/// Constructor
		/// \param [in] theWeekend true if the object should always return
		/// weekend state, false if it should return weekday state 
		FixedDecisionStrategy(bool theWeekend)
		{
			weekend = theWeekend;
		}
};

#endif
