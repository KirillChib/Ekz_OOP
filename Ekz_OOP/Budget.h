#include <iostream>
#include<vector>
#include<string>
#include <map>
#include"ListOfCategories.h"
#include"Category.h"
#include"Fabrica.h"
#include"Date.h"
#include"Product.h"
#include"CreditCard.h"
#include"DebitCard.h"
#include"Wallet.h"

#pragma once

using namespace std;
class Budget : public Fabrica
{
private:

    vector <Product*> _creditCards;
    vector <Product*> _debitCards;
    vector<Product*> _wallets;

public:
    Date date;
    virtual Product* createCreditCard() override;
    virtual Product* createDebitCard() override;
    virtual Product* createWallet() override;
    void CreateNewCreditCard();
    void CreateNewDibitCard();
    void CreateNewWallet();
    void PrintCreditCards();
    void PrintDebitCards();
    void PrintWallets();
    void AddMoneyOnCreditCard();
    void AddMoneyOnDebitCard();
    void AddMoneyOnWallet();
    void MinusMoneyOnCreditCard(double value);
    void MinusMoneyOnDebitCard(double value);
    void MinusMoneyOnWallet(double value);
    void Menu();
};

