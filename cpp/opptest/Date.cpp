//
// Created by cirno on 05/09/23.
//

#include "Date.h"
#include "iostream"

void Date::copyFrom(const Date &d) {
    m_day = d.m_day;
    m_month = d.m_month;
    m_year = d.m_year;
}
void Date::print() {
    std::cout << m_day << "/" << m_month << "/" << m_year << "\n";
}

void Date::setDate(int day, int month, int year) {
    m_day = day;
    m_month = month;
    m_year = year;
}