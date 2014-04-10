/* Source code for textbook:
 * Flexible Reliable Software, by Henrik B. Christensen
 * CRC Press 2010
 * ****************************************
 * Project developed in java by Henrik B. Christensen
 * C++ port by Robert Benkoczi
 * *****************************************
*/

/**
 * The pay station factory interface
 * 
 * Responsibilities:
 * 
 * 1) Create RateStrategy object
 * 2) Create Receipt object
**/

#ifndef PAYSTATIONFACTORY_H
#define PAYSTATIONFACTORY_H

#include "RateStrategy.h"
#include "Receipt.h"

/// PayStationFactory interface class
class PayStationFactoryInterface
{
	public:
		/// Creates the appropiate RateSTrategy object
		/// \return a RateStrategy implementation object allocated
		/// on the heap. Must be freed by the Paystation object
		virtual RateStrategy createRateStrategy() = 0;
		
		/// Creates an appropiate receipt implementation object
		/// \return a receipt object allocated on the heap to be
		/// freed by the client of the PayStation::buy method.
		virtual Receipt createReceipt(int parkingTime) = 0;
};

typedef PayStationFactoryInterface* PayStationFactory;
#endif
