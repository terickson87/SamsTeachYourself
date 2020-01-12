#ifndef DATE_H
#define DATE_H

// From: https://www.learncpp.com/cpp-tutorial/89-class-code-and-header-files/
 
class Date
{
private:
    int m_year;
    int m_month;
    int m_day;
 
public:
    Date(int year, int month, int day);
 
    void SetDate(int year, int month, int day);
 
    int getYear() { return m_year; }
    int getMonth() { return m_month; }
    int getDay()  { return m_day; }
};
 
#endif