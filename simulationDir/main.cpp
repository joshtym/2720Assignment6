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

#include "DisplayStrategy.h"
#include <string>
#include <iostream>

/// Helper function to print the available options
void printMenu();

/// Helper function to print the primary information
void printInformation(int, int);

int main()
{
	// Variable declartion of the object
	DisplayStrategy display;
	Receipt r;
	char ch;
	int givenInt;
	int currentCity = 0;
	
	std::cout << "Simulation started." << std::endl;
	printMenu();
	printInformation(currentCity, display.getCurrentPaymentTime());
	
	// Get next char
	std::cin >> ch;
	
	while ( ch != 'Q' && ch != 'q')
	{
		
		// If this key, then cancel whatever has been put into the
		// paystation and just reset to 0. 
		if (ch == 'c' || ch == 'C')
		{
			display.cancel();
			std::cout << "Current session reset" << std::endl;
			std::cout << std::endl;
		}
		// If this key, then find out which value they would like to put
		// into the display
		else if (ch == '+')
		{
			std::cout << "Please enter the amount. Current valid amounts are " << std::endl;
			std::cout << "5, 10, and 25 cents" <<std:: endl;
			
			std::cin >> givenInt;
			std::cout << std::endl;
			display.addPayment(givenInt);
		}
		
		// If this key, iterate through the cities
		else if (ch == 'n')
		{
			display.nextCity();
			
			if (display.getCurrentCity() == 0)
			{
				std::cout << "Now in AlphaTown's parking meter.";
				std::cout << std::endl << std::endl;
			}
			else if (display.getCurrentCity() == 1)
			{
				std::cout << "Now in BetaTown's parking meter.";
				std::cout << std::endl << std::endl;
			}
			else if (display.getCurrentCity() == 2)
			{
				std::cout << "Now in GammaTown's parking meter.";
				std::cout << std::endl << std::endl;
			}
		}
		
		else if(ch == 'b' || ch == 'B')
		{
			display.buy();
			std::cout << std::endl << std::endl;
		}
		
		else if (ch == 'm' || ch == 'M')
		{
			printMenu();
		}
		
		printInformation(display.getCurrentCity(), display.getCurrentPaymentTime());
				
		std::cin >> ch;
	}
	
	std::cout << "Simulation ended." << std::endl;
	
	return 0;
}

void printMenu()
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

void printInformation(int currentCity, int currentTime)
{
	std::cout << "Current amount of time implemented at city ";
	
	if (currentCity == 0)
		std::cout << "AlphaTown";
	else if (currentCity == 1)
		std::cout << "BetaTown";
	else
		std::cout << "GammaTown";
	
	std::cout << " is:  " << currentTime << std::endl;
	std::cout << std::endl;
}  
