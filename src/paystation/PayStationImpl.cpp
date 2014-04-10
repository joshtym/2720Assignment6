/* Source code for textbook:
 * Flexible Reliable Softare, by Henrik B. Christensen
 * CRC Press 2010
 * *********************************
 * Project developed in Java by Henrik B. Chrinstensen
 * C++ port by Robert Benkoczi
 * *********************************
*/

#include "PayStationImpl.h"

void PayStationImpl::addPayment( int coinValue )
	throw (IllegalCoinException)
{
	switch (coinValue)
	{
		case 5: break;
		case 10: break;
		case 25: break;
		default:
			throw IllegalCoinException("Invalid coin: " + coinValue);
	}
	
	insertedSoFar += coinValue;
	timeBoughtSoFar = rateStrategy->calculateTime(insertedSoFar);
}
  
int PayStationImpl::readDisplay()
{
	return timeBoughtSoFar;
}
  
Receipt PayStationImpl::buy()
{
	Receipt r =  psFactory->createReceipt(timeBoughtSoFar);
	reset();
	return r;
}

void PayStationImpl::cancel()
{
	reset();
}

PayStationImpl::~PayStationImpl()
{
	delete rateStrategy;
}


void PayStationImpl::reset()
{
	insertedSoFar = timeBoughtSoFar = 0;
}


PayStationImpl::PayStationImpl(PayStationFactory pf)
{
	reset();
	rateStrategy = pf->createRateStrategy();
	psFactory = pf;
}
