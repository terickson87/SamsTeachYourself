// Initial Code From:
// https://www.learncpp.com/cpp-tutorial/89-class-code-and-header-files/

#include "Date.h"
#include <cassert>
 
 // Initialize static member of class Date
std::map<int,int> Date::m_DaysInMonth = {   {1,31},
                                            {2,28},
                                            {3,31},
                                            {4,30},
                                            {5,31},
                                            {6,30},
                                            {7,31},
                                            {8,31},
                                            {9,30},
                                            {10,31},
                                            {11,30},
                                            {12,31}};

// Date constructor
Date::Date(const int year, const int month, const int day) : m_year(year), m_month(month), m_day(day) {
    assert(Date::m_DaysInMonth.at(m_month) >= m_day);
}
 
// Date member function
void Date::SetDate(int year, int month, int day) {
    m_month = month;
    m_day = day;
    m_year = year;
}

// << operator overload
std::ostream& operator<< (std::ostream &out, const Date &date) {
    // Since operator<< is a friend of the Point class, we can access Point's members directly.
    out << date.getDay() << "/" << date.getMonth() << "/" << date.getYear(); // actual output done here
 
    return out; // return std::ostream so we can chain calls to operator<<
}
