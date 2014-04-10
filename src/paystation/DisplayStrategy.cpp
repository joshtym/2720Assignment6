#include "DisplayStrategy.h"
#include <iostream>

DisplayStrategy::DisplayStrategy()
{
	ps = new PayStationImpl(new AlphaTownFactory);
	currentCity = 0;
	
}

DisplayStrategy::~DisplayStrategy()
{
	delete ps;
}

void DisplayStrategy::buy()
{
	Receipt r = ps->buy();
	r->print(std::cout);
}

void DisplayStrategy::cancel()
{
	ps->cancel();
}

void DisplayStrategy::nextCity()
{
	currentCity++;
	currentCity = currentCity % 3;
	delete ps;
	
	if (currentCity == 0)
		ps = new PayStationImpl(new AlphaTownFactory);
	else if (currentCity == 1)
		ps = new PayStationImpl(new BetaTownFactory);
	else if (currentCity == 2)
		ps = new PayStationImpl(new GammaTownFactory);
}

void DisplayStrategy::addPayment(int coinValue)
{
	ps->addPayment(coinValue);
}

int DisplayStrategy::getCurrentCity()
{
	return currentCity;
}

int DisplayStrategy::getCurrentPaymentTime()
{
	return ps->readDisplay();
}
