#include <iostream>
#include<vector>
#include<string>
#include <map>
#include"ListOfCategories.h"
#include "Category.h"
#pragma once


using namespace std; 

void Category::setName(string name)
{
    _name = name;

}
void Category::PlusSumma(double value)
{
    _summa += value;
}
string Category::getName()
{
    return _name;
}
double Category::getSumma()
{
    return _summa;
}
bool Category::ÑheckVector(string name)
{
    for (auto it : _catigories)
    {
        if (it->getName().compare(name))
            return true;
    }
    return false;
}
void Category::AddCategory(Category* cat)
{


    _namesCategories.push_back(cat->getName());


    for (auto it : _namesCategories)
        if (it.compare(cat->getName()) == 0)
            return;

    _catigories.push_back(cat);


}
Category* Category::create(string name)
{

    setName(name);
    return this;
}