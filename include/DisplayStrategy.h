#ifndef DISPLAYSTRATEGY_H
#define DISPLAYSTRATEGY_H

#include "PayStationImpl.h"
#include "AlphaTownFactory.h"
#include "BetaTownFactory.h"
#include "GammaTownFactory.h"

/// Display Strategy Class
class DisplayStrategy
{
	public:
		/// Constructor
		/**
		 * Main constructor. Initializes the paystation to alphatownfactory
		 * by default
		**/
		DisplayStrategy();
		
		/// Destructor
		/**
		 * Destructor to delete paystation
		**/
		~DisplayStrategy();
		
		/// Cancel Function
		/**
		 * Cancel incoming payment
		**/
		void cancel();
		
		/// Payment adding function
		/**
		 * Add payment. Throws an error if invalid payment
		**/
		void addPayment(int);
		
		/// Iterate to next city function
		/**
		 * Iterate to the next city. By default, the order of iteration
		 * goes from AlphaTown->BetaTown->GammaTown and back around
		**/
		void nextCity();
		
		/// Buy transcation function
		/**
		 * Buy the amount entered. This will reset the value and print
		 * out a receipt
		**/
		void buy();
		
		/// Get current amount of time purchased
		/**
		 * Get the current time that you've entered in
		**/
		int getCurrentPaymentTime();
		
		/// Get currentCity that the simulation is rnning through
		/**
		 * Get the current city. City names are dissected into numerical
		 * value. AlphaTown = 0, BetaTown = 1, and GammaTown = 2
		**/
		int getCurrentCity();
		
	private:
		/// Main data members
		PayStation ps;
		int currentCity;
		
};
#endif
