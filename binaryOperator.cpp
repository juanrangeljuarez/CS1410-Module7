// File: binaryOperator
// Created by Juan Rangel Juarez on 10/10/17 for CS1410.
// Copyright (c) 2017 WSU
//
#include <iostream>

using namespace std;
// Constants
class Distance
{
private:
    int feet;
    float inches;
public:
    Distance(): feet(0), inches(0.0){} // constructor no arguments
    Distance(int f, float i) // constructor with two arguments
    {
        feet = f;
        inches = i;
    }
    void getdist()
    {
        cout <<"\nEnter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }
    void showdis() // display distance
    {
        cout << feet << "\'-" << inches << "\"";
    }
    Distance operator +(Distance) const; // add 2 distances
    void operator += (Distance) ; // add 1 distance to an existing

};
// return the sum if birh
 Distance Distance::operator+(Distance d2) const
{
    int f = feet + d2.feet;
    float i = inches + d2.inches;
    if(i >= 12.0)
    {
        i-=12.0;
        f++;
    }
    return Distance(f,i);
}
void Distance::operator += (Distance d)
{
    feet += d.feet;
    inches += d.inches;
    if(inches >= 12.0)
    {
        inches -=12.0;
        feet++;
    }
}
// Prototypes

// Main Program Program
int main() {
    Distance d1;
    Distance d2(11, 6.25), d3, d4;
    d1.getdist();
    cout << "Distance d1 = "; d1.showdis(); cout << endl;
    cout << "Distance d2 = "; d2.showdis(); cout << endl;
    // add binary operator support
    d3 = d1 + d2;
    cout << "Distance d3= "; d3.showdis(); cout << endl;

    d2+=d3;
    cout << "Distance d2= "; d2.showdis(); cout << endl;
    return 0;
}
// Function Definitions