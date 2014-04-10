/* Source code for textbook:
 * Flexible Reliable Softare, by Henrik B. Christensen
 * CRC Press 2010
 * ***********************************
 * Project devleoped in Java by Henrik B. Christensen
 * C++ port by Robert Benkoczi
 * ***********************************
*/


/** The pay station factory interface implementation
 * 
 * Responsibilities:
 * 
 * 1) Create RateSTrategy object
 * 2) Create Receipt object
**/

#ifndef TESTTOWNFACTORY_H
#define TESTTOWNFACTORY_H

#include "PayStationFactory.h"
#include "One2OneRateStrategy.h"
#include "StandardReceipt.h"
#include <cstddef>


/// Class implementing the PayStationFactory interface; configures the
/// PayStationImpl with One2OneRateStrategy and StandardReceipt
class TestTownFactory : public PayStationFactoryInterface
{
	public:
		RateStrategy createRateStrategy()
		{
			return new One2OneRateStrategy;
		}

		Receipt createReceipt(int parkingTime)
		{
			return new StandardReceipt(parkingTime);
		}
};


#endif
