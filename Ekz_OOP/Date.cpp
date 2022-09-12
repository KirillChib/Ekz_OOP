
#include<string>
#include <map>
#include"ListOfCategories.h"
#include"Category.h"
#include "Date.h"

#pragma once

using namespace std;

Date::~Date()
{
    for (int i = 0; i < 31; i++)
    {
        delete _month[i];
    }
}
int Date::GetDay()
{
    return _day;
}
void Date::Init()
{
    for (int i = 0; i < 31; i++)
    {
        _month[i] = new Category();
    }
}
void Date::AddExpenditure(string nameCategory, double spend)//Добавляем траты в день
{

    auto cat = create(nameCategory);

    cout << "Enter day (1-31) " << endl;
    cin >> _day;

    for (auto it : _month[_day - 1]->_catigories)
    {
        if (it->getName().compare(nameCategory) == 0)
        {
            _month[_day - 1]->PlusSumma(spend);
            return;
        }

    }
    _month[_day - 1]->_catigories.push_back(cat);
    for (auto it : _month[_day - 1]->_catigories)
    {
        if (it->getName().compare(nameCategory) == 0)
            it->PlusSumma(spend);
    }
}
void Date::PrintDay()
{
    int day;

    cout << "Enter day (1-31)" << endl;
    cin >> day;

    if (_month[day - 1]->_catigories.empty() != 0)
    {
        cout << "No data" << endl;
        return;
    }

    for (auto it : _month[day - 1]->_catigories)
    {
        cout << it->getName() << " - " << it->getSumma() << " rub" << endl;
    }

}
void Date::PrintWeek()
{
    int first, last;

    cout << "Enter first day of week (1-31)" << endl;
    cin >> first;

    cout << "Enter last day of week (1-31)" << endl;
    cin >> last;

    for (auto it : _namesCategories)
    {
        double sum = 0;

        for (int i = first - 1; i < last - 1; i++)
        {
            for (auto j : _month[i]->_catigories)
            {
                if (it.compare(j->getName()) == 0)
                    sum += j->getSumma();
            }

        }
        cout << it << " - " << sum << " rub" << endl;
    }



}
void Date::PrintMonth()
{
    for (auto it : _namesCategories)
    {
        double sum = 0;

        for (auto i : _month)
        {
            for (auto j : i->_catigories)
            {
                if (it.compare(i->getName()) == 0)
                {
                    sum += i->getSumma();
                }
            }
        }

        cout << it << " - " << sum << " rub" << endl;
    }
}
void Date::RatingOfWeek()
{
    int first, last;
    int count = 0;
    map<int,string> list;
    

    cout << "Enter first day of week (1-31)" << endl;
    cin >> first;

    cout << "Enter last day of week (1-31)" << endl;
    cin >> last;

    for (auto it : _namesCategories)
    {
        double sum = 0;

        for (int i = first - 1; i < last - 1; i++)
        {
            for (auto j : _month[i]->_catigories)
            {
                if (it.compare(j->getName()) == 0)
                    sum += j->getSumma();
            }

        }
        list.emplace(make_pair(sum,it));
    }

    map <int, string> ::reverse_iterator list_riter;

    for (list_riter = list.rbegin(); list_riter != list.rend(); list_riter++)
    {
        if (count == 3)
            break;

        count++;

        cout << list_riter->second << " - " << list_riter->first << " rub";
    }

}
void Date::RatingOfMonth()
{
    int count = 0;
    map<int, string> list;

    for (auto it : _namesCategories)
    {
        double sum = 0;

        for (int i = 0; i < 31; i++)
        {
            for (auto j : _month[i]->_catigories)
            {
                if (it.compare(j->getName()) == 0)
                    sum += j->getSumma();
            }

        }
        list.emplace(make_pair(sum, it));
    }

    map <int, string> ::reverse_iterator list_riter;

    for (list_riter = list.rbegin(); list_riter != list.rend(); list_riter++)
    {
        if (count == 3)
            break;

        count++;

        cout << list_riter->second << " - " << list_riter->first << " rub";
    }
}