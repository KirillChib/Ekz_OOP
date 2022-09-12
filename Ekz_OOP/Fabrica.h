#include <iostream>
#include<vector>
#include<string>
#include <map>
#include "Product.h"
#pragma once

using namespace std; 

class Fabrica
{
public:
    virtual Product* createCreditCard() = 0;
    virtual Product* createDebitCard() = 0;
    virtual Product* createWallet() = 0;

};

