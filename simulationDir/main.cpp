// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #6
 * Main Program
 * Professor: Robert  Benkoczi
 * Program Name: main.cpp
 * Software Used: Geany
*/

#include "AlphaTownFactory.h"
#include "BetaTownFactory.h"
#include "GammaTownFactory.h"
#include "PayStationImpl.h"
#include <string>
#include <iostream>

int main()
{
	// Variable declartion of the object
	PayStation ps = new PayStationImpl(new AlphaTownFactory);
	char ch;
	int givenInt;
	int currentCity = 0;
	
	std::cout << "Simulation started."<< std::endl << std::endl;
	std::cout << "The following operations are available:" << std::endl;
	std::cout << "- Hit 'c' to cancel the current payment" << std::endl;
	std::cout << "- Hit '+' to add a value" << std::endl;
	std::cout << "- Hit 'b' to buy the amount entered. This will print" << std::endl;
	std::cout << "  out a receipt" << std::endl;
	std::cout << "- Hit 'n' to iterate through cities" << std::endl;
	std::cout << "- Hit 'm' to see this menu again" << std::endl;
	std::cout << "- Hit 'q' to quit the simulation" << std::endl;
	std::cout << std::endl;
	
	// Get next char
	std::cout << "Current Value implemented at city is:" << std::endl;
	std::cout << ps->readDisplay() << std::endl;
	std::cin >> ch;
	
	while ( ch != 'Q' && ch != 'q')
	{
		
		// If this key, then cancel whatever has been put into the
		// paystation and just reset to 0. 
		if (ch == 'c' || ch == 'C')
		{
			ps->cancel();
			std::cout << "Current session reset" << std::endl;
		}
		// If this key, then find out which value they would like to put
		// into the display
		else if (ch == '+')
		{
			std::cout << "Please enter the amount. Current valid amounts are " << std::endl;
			std::cout << "5, 10, and 25 cents" <<std:: endl;
			
			std::cin >> givenInt;
			ps->addPayment(givenInt);
		}
		
		// If this key, iterate through the cities
		else if (ch == 'n')
		{
			currentCity = (currentCity + 1) % 3;
			if (currentCity == 0)
			{
				delete ps;
				ps = new PayStationImpl(new AlphaTownFactory);
				std::cout << "Now in AlphaTown PayStation" << std::endl;
			}
			else if (currentCity == 1)
			{
				delete ps;
				ps = new PayStationImpl(new BetaTownFactory);
				std::cout << "Now in BetaTown PayStation" << std::endl;
			}
			else
			{
				delete ps;
				ps = new PayStationImpl(new GammaTownFactory);
				std::cout << "Now in GammaTown PayStation" << std::endl;
			}
		}
		
		else if(ch == 'b' || ch == 'B')
		{
			//Receipt receipt = ps->buy();
		}
		
		else if (ch == 'm' || ch == 'M')
		{
			std::cout << "The following operations are available:" << std::endl;
			std::cout << "- Hit 'c' to cancel the current payment" << std::endl;
			std::cout << "- Hit '+' to add a value" << std::endl;
			std::cout << "- Hit 'b' to buy the amount entered. This will print" << std::endl;
			std::cout << "  out a receipt" << std::endl;
			std::cout << "- Hit 'n' to iterate through cities" << std::endl;
			std::cout << "- Hit 'm' to see this menu again" << std::endl;
			std::cout << "- Hit 'q' to quit the simulation" << std::endl;
			std::cout << std::endl;
		}
		
		std::cout << "Current Value implemented at city is:" << std::endl;
		std::cout << ps->readDisplay() << std::endl;		
		std::cin >> ch;
	}
	
	std::cout << "Simulation ended." << std::endl;
	
	return 0;
}
