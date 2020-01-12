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
    assert(Date::MONTHS_IN_YEAR >= m_month);
}

bool Date::isDayGood() {
    return Date::isDayGood(this->getDay(), this->getMonth());
}

bool Date::isDayGood(int day, int month) {
    if (day <= Date::m_DaysInMonth.at(month)) {
        return true;
    } else {
        return false;
    }
}

bool Date::isMonthGood() {
    return Date::isMonthGood(this->m_month);
}

bool Date::isMonthGood(int month) {
    if (month <= Date::MONTHS_IN_YEAR) {
        return true;
    } else {
        return false;
    }
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

// + operator overload
Date operator+ (const Date& date1, const Date& date2) {
    int day = date1.getDay() + date2.getDay();
    int month = date1.getMonth() + date2.getMonth();
    int year = date1.getYear() + date2.getYear();

    bool dayIsGoodFlag = Date::isDayGood(day, month);
    bool monthIsGoodFlag = Date::isMonthGood(month);
    while (!dayIsGoodFlag || !monthIsGoodFlag) {
        while (!monthIsGoodFlag) {
            int excessMonths = month - Date::MONTHS_IN_YEAR;
            ++year;
            month = excessMonths;
        }
        while (!dayIsGoodFlag) {
            int excessDays = day - Date::m_DaysInMonth.at(month);
            ++month;
            day = excessDays;
        }
        dayIsGoodFlag = Date::isDayGood(day, month);
        monthIsGoodFlag = Date::isMonthGood(month);
    }
    Date newDay{year, month, day};
    return newDay;
}