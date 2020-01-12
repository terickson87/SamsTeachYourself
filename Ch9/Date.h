#ifndef DATE_H
#define DATE_H

#include <map>
#include <iostream>

// Initial Code From:
// https://www.learncpp.com/cpp-tutorial/89-class-code-and-header-files/
 
class Date {
private:
    int m_year;
    int m_month;
    int m_day;
 
public:
    const static int MONTHS_IN_YEAR = 12;
    static std::map<int,int> m_DaysInMonth;

    Date(int year, int month, int day);
 
    void SetDate(int year, int month, int day);
 
    int getYear() const { return m_year; }
    int getMonth() const { return m_month; }
    int getDay() const { return m_day; }

    bool isDayGood();
    static bool isDayGood(int day, int month);
    bool isMonthGood();
    static bool isMonthGood(int month);
};

std::ostream& operator<< (std::ostream &out, const Date &date);
Date operator+ (const Date& date1, const Date& date2);

#endif