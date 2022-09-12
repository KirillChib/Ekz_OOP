#include <iostream>
#include<vector>
#include<string>
#include <map>
#include"ListOfCategories.h"
#include"Category.h"
#pragma once

using namespace std;


class Date : public Category
{
private:
    int _day{ 0 };

    Category* _month[31];

public:
    ~Date();
    int GetDay();
    void Init();
    void AddExpenditure(string nameCategory, double spend);
    void PrintDay();
    void PrintWeek();
    void PrintMonth();
    void RatingOfWeek();
    void RatingOfMonth();
};

