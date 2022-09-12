#include <iostream>
#include<vector>
#include<string>
#include <map>
#include"ListOfCategories.h"
#pragma once


using namespace std;

class Category : public ListOfCategories
{
private:
    string _name;
    double _summa{ 0 };

public:

    vector<Category*> _catigories;

    void setName(string name);
    void PlusSumma(double value);
    string getName();
    double getSumma();
    bool ÑheckVector(string name);
    void AddCategory(Category* cat);
    Category* create(string name);
};

