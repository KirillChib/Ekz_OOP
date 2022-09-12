#include <iostream>
#include<vector>
#include<string>
#include <map>
#include "Product.h"
#include "CreditCard.h"

#pragma once

using namespace std;

 void CreditCard::setName() 
{
    cout << "Enter name for card" << endl;
    cin.ignore();
    getline(cin, _name);
}
void CreditCard::setHowManyMoney() 
{
    cout << "How many money?" << endl;
    cin >> _howManyMoney;
}
 string CreditCard::getName()
{
    return _name;
}
 double CreditCard::getHowManyMoney()
{
    return _howManyMoney;
}
 void CreditCard::Refill() 
{
    double value;

    cout << "How much to deposit?" << endl;
    cin >> value;

    _howManyMoney += value;
}
void CreditCard::Withdrawals(double value) 
{
    if (value > _howManyMoney)
        cout << "not enough funds" << endl;
    _howManyMoney -= value;
}
void CreditCard::ShowInfo()
{
    cout << endl << "Card : " << _name << endl;
    cout << "Balance : " << _howManyMoney << endl;
}