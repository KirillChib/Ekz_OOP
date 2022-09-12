#include <iostream>
#include<vector>
#include<string>
#include <map>
#include "Product.h"
#include "DebitCard.h"

#pragma once

using namespace std;

 void DebitCard::setName() 
{
    cout << "Enter name for card" << endl;
    cin.ignore();
    getline(cin, _name);
}
 void DebitCard::setHowManyMoney() 
{
    cout << "How many money?" << endl;
    cin >> _howManyMoney;
}
 string DebitCard::getName() 
{
    return _name;
}
 double DebitCard::getHowManyMoney() 
{
    return _howManyMoney;
}
 void DebitCard::Refill() 
{
    double value;

    cout << "How much to deposit?" << endl;
    cin >> value;

    _howManyMoney += value;
}
 void DebitCard::Withdrawals(double value) 
{
    if (value > _howManyMoney)
        cout << "not enough funds" << endl;
    _howManyMoney -= value;
}
void DebitCard::ShowInfo()
{
    cout << endl << "Card : " << _name << endl;
    cout << "Balance : " << _howManyMoney << endl;
}