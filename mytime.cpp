// File: mytime
// Created by Juan Rangel Juarez on 10/12/17 for CS1410.
// Copyright (c) 2017 WSU
//
#include <iostream>

using namespace std;
// Constants
class time12
{
private:
    bool pm;    // truw =pm, false =am
    int hrs;
    int mins;
public:
    time12(): pm(true), hrs(0), mins(0){}
    time12(bool ap, int h, int m)
    {
        pm = ap;
        hrs = h;
        mins = m;
    }
    void display() const // format: 12:24 p.m.
    {
        cout << hrs << ":";
        if(mins < 10)
            cout << "0";
        cout << mins << " ";
        string am_pm = pm ? "p.m." : "a.m.";
        cout << am_pm;
    }

};

class time24
{
private:
    int hours;
    int minutes;
    int seconds;
public:
    time24(): hours(0), minutes(0), seconds(0)
    {}
    time24(int h, int m, int s)     // const 3 arguments
    {
        hours = h;
        minutes = m;
        seconds = s;
    }
    void display() const    // format:23:12:01
    {
        if(hours < 10)
            cout << "0";
        cout << hours << ":";
        if(minutes < 10)
            cout << "0";
        cout << minutes << ":";
        if(seconds < 10)
            cout << "0";
        cout << seconds;
    }
    operator time12() const;
};
// Prototypes
time24::operator time12() const
{
    int hrs24 = hours;
    bool pm = (hours < 12) ? false : true;
    int roundMins = seconds < 30 ? minutes:minutes+1;
    if(roundMins == 0)
    {
        roundMins = 0;
        ++hrs24;
        if(hrs24 == 12 || hrs24 == 24)
            pm = (pm == true)? false: true;
    }
    int hrs12 = (hrs24 < 13)? hrs24: hrs24 -12;
    if(hrs12 == 0)
    {
        hrs12 = 12;
        pm = false;
    }
    return time12(pm, hrs12, roundMins);

}
// Main Program Program
int main() {
    time24 t1;
    time24 t2(18,2,40);
    t1.display();
    cout << endl;
    t2.display();
    cout << endl;
    time12 t3;
    time12 t4(false,2,40);
    t3.display();
    cout << endl;
    t4.display();
    cout << endl;
    // convert time24
    time12 t12 = t2;
    t12.display();
    return 0;
}
// Function Definitions