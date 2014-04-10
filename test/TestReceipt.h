/* Source code for textbook:
 * Flexible Reliable Softare, by Henrik B. Christensen
 * CRC Press 2010
 * ***********************************
 * Project devleoped in Java by Henrik B. Christensen
 * C++ port by Robert Benkoczi
 * ***********************************
*/


/// Testcases for the Receipt interface implementation

#ifndef TESTRECEIPT_H
#define TESTRECEIPT_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "StandardReceipt.h"

class TestReceipt : public CppUnit::TestFixture
{
	private:
		CPPUNIT_TEST_SUITE(TestReceipt);
		CPPUNIT_TEST(testReceiptValue);
		CPPUNIT_TEST(testPrint);
		CPPUNIT_TEST(testPrintBar);
		CPPUNIT_TEST_SUITE_END();

	private:
		Receipt receipt,receiptBar;
	
	public:
		void setUp()
		{
			receipt = new StandardReceipt(30);
			receiptBar = new StandardReceipt(13, true);
		}

		void tearDown()
		{
			delete receipt;
		}

		// test that receipt can hold the value 30 
		void testReceiptValue()
		{
			CPPUNIT_ASSERT(receipt->value() == 30);
		}

		// test the print function
		void testPrint()
		{
			std::ostringstream sstr;
			receipt->print(sstr);
			std::string s = sstr.str();  // get the output as string
			std::size_t line1 = s.find('\n');
			std::size_t line2 = s.find('\n',line1+1);
			std::size_t lineCollon = s.find(':', line2+1);
			CPPUNIT_ASSERT(s.substr(0, line1) == "PARKING RECEIPT");
			CPPUNIT_ASSERT(s.substr(line1+1, line2-line1-1) == "Value: 30 min.");
			CPPUNIT_ASSERT(s.substr(line2+1, lineCollon-line2-1) == "Car parked at");
			CPPUNIT_ASSERT(s[lineCollon+4] == ':');
		}


		// test the print function for bar receipts
		void testPrintBar()
		{
			std::ostringstream sstr;
			receiptBar->print(sstr);
			std::string s = sstr.str();  // get the output as string
			std::size_t line1 = s.find('\n');
			std::size_t line2 = s.find('\n',line1+1);
			std::size_t lineCollon = s.find(':', line2+1);
			std::size_t line3 = s.find('\n', line2+1);
			
			CPPUNIT_ASSERT(s.substr(0, line1) == "PARKING RECEIPT");
			CPPUNIT_ASSERT(s.substr(line1+1, line2-line1-1) == "Value: 13 min.");
			CPPUNIT_ASSERT(s.substr(line2+1, lineCollon-line2-1) == "Car parked at");
			CPPUNIT_ASSERT(s[lineCollon+4] == ':');
			CPPUNIT_ASSERT(s.substr(line3+1, 5) == "|||||");
			// perhaps also test that there is nothing following the bar
		}

};

#endif
