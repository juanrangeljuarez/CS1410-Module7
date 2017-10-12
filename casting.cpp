// File: casting
// Created by Juan Rangel Juarez on 10/12/17 for CS1410.
// Copyright (c) 2017 WSU
#include <iostream>

using namespace std;
// Constants
class Distance
{
private:
    float MTF; // meters to feet
    int feet;
    float inches;
public:
    Distance(): feet(0), inches(0.0), MTF(3.280833){} // 1. constructor no arguments
    Distance(int meters): MTF(3.280833) // 2. constructor with two arguments
    {
        float fltfeet = MTF * meters;   // convert to float feet
        // feet = static_cast<int> (fltfeet);
        feet = int(fltfeet);    // feet is the integer part
        inches = 12*(fltfeet - feet);// inches is what is left
    }
    Distance(int f, float i): MTF(3.280833) // 3. constructor with two arguments
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
    operator float() const // convert to inches
    {
        float ffeet = inches/12;
        ffeet += static_cast<float>(feet);
        return ffeet/MTF;
    }

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
    Distance d1; // 1 constructor
    Distance d2(11, 6.25); // 2 constructor
    Distance d3(5); // 3 constructor
    //d1.getdist();
    float mtrs;
    cout << "Distance d1 = "; d1.showdis(); cout << endl;
    cout << "Distance d2 = "; d2.showdis(); cout << endl;
    cout << "Distance d3= "; d3.showdis(); cout << endl;
    mtrs = static_cast<float>(d2);
    cout << "Distance d2= " << mtrs << " meters" << endl;
    return 0;
}
