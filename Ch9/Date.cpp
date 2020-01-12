// From: https://www.learncpp.com/cpp-tutorial/89-class-code-and-header-files/

#include "Date.h"
 
// Date constructor
Date::Date(int year, int month, int day) : m_year(year), m_month(month), m_day(day) {
    
}
 
// Date member function
void Date::SetDate(int year, int month, int day)
{
    m_month = month;
    m_day = day;
    m_year = year;
}