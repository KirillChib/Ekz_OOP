#include <iostream>
#include<vector>
#include<string>
#include <map>

using namespace std;

#pragma once
class Product
{
protected:
    string _name{ "none" };
    double _howManyMoney{ 0 };

public:
    virtual void setName() = 0;
    virtual void setHowManyMoney() = 0;
    virtual string getName() = 0;
    virtual double getHowManyMoney() = 0;
    virtual void Refill() = 0;
    virtual void Withdrawals(double value) = 0;
    virtual void ShowInfo() = 0;
};

