//
// Created by cirno on 05/09/23.
//

#ifndef OPPTEST_DATE_H
#define OPPTEST_DATE_H


class Date {
    int m_day{};
    int m_month{};
    int m_year{};
public:
    void setDate(int day, int month, int year);

    void print();

    void copyFrom(const Date &d);
};


#endif //OPPTEST_DATE_H
