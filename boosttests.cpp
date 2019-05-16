#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>

#include "integer.h"
#include <string>
#include <iostream>

using namespace ExactArithmetic;


using std::cout;
using std::cin;
using std::endl;

Integer add( Integer x, Integer y )
{
    return x + y;
}

BOOST_AUTO_TEST_SUITE( exact_arithmetic_tests )

BOOST_AUTO_TEST_CASE( addition_small )
{
    Integer x(3);
    Integer y(5);
    Integer z(8);

    BOOST_CHECK_EQUAL( add( x,y ), z );
    if ( add( x,y ) != z )
    {
        BOOST_ERROR( "addition test failed" );
    }
}

BOOST_AUTO_TEST_CASE( addition_large )
{
    Integer x(339487983274329);
    Integer y(29347983748419);
    Integer z(368835967022748);
    
    BOOST_CHECK_EQUAL( add( x,y ), z );
    if ( add( x,y ) != z )
    {
        BOOST_ERROR( "addition test failed" );
    }
}

BOOST_AUTO_TEST_SUITE_END()
