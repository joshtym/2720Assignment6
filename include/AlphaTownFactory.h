/* Source code for textbook:
 * Flexible Reliable Software, by Henrik B. Christensen
 * CRC Press 2010
 * ****************************************
 * Project developed in java by Henrik B. Christensen
 * C++ port by Robert Benkoczi
 * *****************************************
*/

/**
 * The pay station factory interface implementation for Alphatown
 * 
 * Responsibilities:
 * 
 * 1) Create RateStrategy object
 * 2) Create Receipt Object
**/

#ifndef ALPHATOWNFACTORY_H
#define ALPHATOWNFACTORY_H

#include "PayStationFactory.h"
#include "LinearRateStrategy.h"
#include "StandardReceipt.h"
#include <cstddef>

/// Class implementing the Pay Station Factory interface; Configures the
/// PayStationImpl with One2OneRateStrategy and StandardReceipt
class AlphaTownFactory : public PayStationFactoryInterface
{
	public:
		RateStrategy createRateStrategy()
		{
			return new LinearRateStrategy;
		}
		
		Receipt createReceipt(int parkingTime)
		{
			return new StandardReceipt(parkingTime);
		}
};
#endif
