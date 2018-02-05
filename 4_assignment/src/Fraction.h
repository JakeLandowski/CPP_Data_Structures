#ifndef H_Fraction_H
#define H_Fraction_H

#include <iostream>

class Fraction
{
    public:
        //~~~Constructors~~~//
        Fraction(int num = 0, int den = 1);
        Fraction(const Fraction& other);

        //~~~Getters/Setters~~~//
        void setNumer(int num); // checks negs/zeroes/reduce
        void setDenom(int den); // checks negs/zeroes/reduce
        int  getNumer() const;
        int  getDenom() const;

        //~~~General~~~//
        double toDouble() const;
         
        //~~~Operators~~~//
        Fraction operator+ (const Fraction &other);
        Fraction operator- (const Fraction &other);
        Fraction operator* (const Fraction &other);
            bool operator==(const Fraction &other);
        friend std::ostream& operator<<(std::ostream &o, const Fraction &right);

    private:
        int numerator, denominator;
        
        void reduce();
        int  gcd(int x, int y);
        void checkNegatives();
        void checkZeroes();
        Fraction addFractions(int a, int b, int c, int d);
};

#endif