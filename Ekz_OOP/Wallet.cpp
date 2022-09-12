#include <iostream>
#include<vector>
#include<string>
#include <map>
#include "Product.h"
#include "Wallet.h"
#pragma once

using namespace std;

void Wallet::setName() 
{
    cout << "Enter name for wallet" << endl;
    cin.ignore();
    getline(cin, _name);
}
 void Wallet::setHowManyMoney() 
{
    cout << "How many money?" << endl;
    cin >> _howManyMoney;
}
 string Wallet::getName() 
{
    return _name;
}
 double Wallet::getHowManyMoney() 
{
    return _howManyMoney;
}
 void Wallet::Refill() 
{
    double value;

    cout << "How much to deposit?" << endl;
    cin >> value;

    _howManyMoney += value;
}
 void Wallet::Withdrawals(double value) 
{
    if (value > _howManyMoney)
        cout << "not enough funds" << endl;
    _howManyMoney -= value;
}
 void Wallet:: ShowInfo()
{
    cout << endl << "Wallet : " << _name << endl;
    cout << "Balance : " << _howManyMoney << endl;
}