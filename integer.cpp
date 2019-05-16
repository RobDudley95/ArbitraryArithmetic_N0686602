#include <cstdlib> // for abs(long long int)
#include <sstream>
#include <iterator>
#include <algorithm>
#include <string>

#include "integer.h"
#include "dividebyzeroerror.h"
#include "gcd.h"

namespace ExactArithmetic
{

////////////  Default constructor, creates an Integer with value 0. ////////////

Integer::Integer()
{
    Digit x = 0;
    digits.push_back(x);
}


//////////////////////////// Converting constructor ////////////////////////////

Integer::Integer(unsigned long long int x)
{
    // Iterate through x, inserting each individual Digit into the digits list
    while (x > 0)
    {
        Digit y = x%10;
        digits.push_back(y);
        x /= 10;
    }

    // The digits have been inserted into the list backwards; reverse this order
    std::reverse(digits.begin(), digits.end());
}

////////////////////////////////////////////////////////////////////////////////

// Accepts a sequence of digits.
// For any other input, throws a std::invalid_argument exception.
// (For full integers, it should also allow an optional initial  '+' or '-' character.)
Integer::Integer(const std::string & str)
{
    std::istringstream iss(str);
    iss >> *this;
    if (! iss.eof()) throw std::invalid_argument(str + " cannot be parsed as an Integer.");
}

///////////////////////////// Arithmetic Operators /////////////////////////////

// Add
Integer Integer::operator+(const Integer & i) const
{
    int check = 0;
    int carry = 0;
    std::list<Digit> first { };
    std::list<Digit> second { };

    if (digits.size() > i.digits.size())
    {
        first = digits;
        second = i.digits;
    }
    else if (i.digits.size() > digits.size())
    {
        first = i.digits;
        second = digits;
    }
    else
    {
        first = digits;
        second = i.digits;
    }
    std::string answer = "";

    while (first.size() != 0 && second.size() != 0)
    {
        check = first.back() + second.back() + carry;
        if (check > 9)
        {
            answer += std::to_string(check%10);
            check /= 10;
            carry = check;
        }
        else
        {
            answer += std::to_string(check);
            carry = 0;
        }
        first.pop_back();
        second.pop_back();
    }

    while (first.size() != 0)
    {
        answer += std::to_string(first.back());
        first.pop_back();
    }

    std::reverse(answer.begin(), answer.end());

    std::istringstream iss(answer);
    unsigned long int ansInt;
    iss >> ansInt;

    return Integer(ansInt);
}

// Subtract
//Integer operator-(const Integer &) const
//{

//}

// Multiply
//Integer operator*(const Integer &) const
//{

//}

// Divide
//Integer operator/(const Integer &) const
//{

//}

// Modulo
//Integer operator%(const Integer &) const
//{

//}

///////////////////////////// Comparison Operators /////////////////////////////

// Less than
bool Integer::operator<(const Integer & i) const
{
    return (digits < i.digits);
}

// More than
bool Integer::operator>(const Integer & i) const
{
    return (digits > i.digits);
}

// Less than or equal to
bool Integer::operator<=(const Integer & i) const
{
    return (digits <= i.digits);
}

// More than or equal to
bool Integer::operator>=(const Integer & i) const
{
    return (digits >= i.digits);
}

// Equal to
bool Integer::operator==(const Integer & i) const
{
    return (digits == i.digits);
}

// Not equal to
bool Integer::operator!=(const Integer & i) const
{
    return (digits != i.digits);
}

//////////////////////// Compound Assignment Operators /////////////////////////

//Integer & operator+=(const Integer &)
//{

//}

//Integer & operator-=(const Integer &)
//{

//}

//Integer & operator*=(const Integer &)
//{

//}

//Integer & operator/=(const Integer &)
//{

//}

//Integer & operator%=(const Integer &)
//{

//}

///////////////////// Increment and Decrement Operators ////////////////////////

//Integer & operator++() // pre-increment
//{

//}

//Integer operator++(int) // post-increment
//{

//}

//Integer & operator--() // pre-decrement
//{

//}

//Integer operator--(int) // post-decrement
//{

//}

std::string Integer::toString() const
{
    // do nothing
}

///////////////////////////// Friend Declarations //////////////////////////////

std::ostream & operator<<(std::ostream & output , const Integer & i)
{
    output << i;
    return output;
}

std::istream & operator>>(std::istream & input , Integer & i)
{
    input >> i;
    return input;
}

} // End of namespace ExactArithmetic
