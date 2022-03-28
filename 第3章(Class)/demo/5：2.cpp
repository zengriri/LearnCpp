#include <cassert>
#include <iostream>

class Fraction
{
private:
    int m_numerator { 0 };
    int m_denominator { 1 };

public:
    // Default constructor
    Fraction(int numerator = 0, int denominator = 1)
        : m_numerator{ numerator }
        , m_denominator{ denominator }
    {
        assert(denominator != 0);
    }

    // Possible implementation of implicit copy constructor
    Fraction(const Fraction& f)
        : m_numerator( f.m_numerator )
        , m_denominator( f.m_denominator )
    {
    }

    // Possible implementation of implicit assignment operator
    Fraction& operator= (const Fraction& fraction)
    {
        // self-assignment guard
        if (this == &fraction)
            return *this;

        // do the copy
        m_numerator = fraction.m_numerator;
        m_denominator = fraction.m_denominator;

        // return the existing object so we can chain this operator
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f1)
    {
	out << f1.m_numerator << '/' << f1.m_denominator;
	return out;
    }
};

