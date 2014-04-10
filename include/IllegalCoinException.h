/* Source code for textbook:
 * Flexible Reliable Softare, by Henrik B. Christensen
 * CRC Press 2010
 * *********************************
 * Project developed in Java by Henrik B. Chrinstensen
 * C++ port by Robert Benkoczi
 * *********************************
*/

#ifndef ILLEGALCOINEXCEPTION_H
#define ILLEGALCOINEXCEPTION_H

#include <exception>
#include <string>

/** 
 * Exception representing illegal coin entry.
**/
class IllegalCoinException : public std::exception
{
	public:
		/**
		* @param e is a description of the exception
		**/
		IllegalCoinException( std::string e ) {};
};

#endif
