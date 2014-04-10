/* Source code for textbook:
 * Flexible Reliable Softare, by Henrik B. Christensen
 * CRC Press 2010
 * *********************************
 * Project developed in Java by Henrik B. Chrinstensen
 * C++ port by Robert Benkoczi
 * *********************************
*/

/** The pay station factory interface implementation for Alphatown
 * 
 * Responsibilities:
 * 
 * 1) Create RateStrategy object
 * 2) Create Receipt object
**/

#ifndef BETATOWNFACTORY_H
#define BETATOWNFACTORY_H

#include "PayStationFactory.h"
#include "ProgressiveRateStrategy.h"
#include "StandardReceipt.h"


/// Class implementing the PayStationFactory interface; configures the
/// PayStationImpl with One2OneRateStrategy and StandardReceipt
class BetaTownFactory : public PayStationFactoryInterface
{
	public:
		RateStrategy createRateStrategy()
		{
			return new ProgressiveRateStrategy;
		}

		Receipt createReceipt(int parkingTime)
		{
			return new StandardReceipt(parkingTime, true);
		}
};


#endif
