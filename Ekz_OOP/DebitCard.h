#include <iostream>
#include<vector>
#include<string>
#include <map>
#include "Product.h"
#pragma once

using namespace std;

class DebitCard:public Product
{
    virtual void setName() override;
    virtual void setHowManyMoney() override;
    virtual string getName() override;
    virtual double getHowManyMoney() override;
    virtual void Refill() override;
    virtual void Withdrawals(double value) override;
    virtual void ShowInfo();
};

