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
#include "Budget.h"
#pragma once

using namespace std;

Product* Budget::createCreditCard() 
{
    return new CreditCard;
};
 Product* Budget:: createDebitCard() 
{
    return new DebitCard;
}
 Product* Budget::createWallet()
 {
     return nullptr;
 }
 ;
 Product* createWallet() 
{
    return new Wallet;
};
void Budget::CreateNewCreditCard()
{
    auto card = createCreditCard();

    card->setName();
    card->setHowManyMoney();

    _creditCards.push_back(card);

};
void Budget::CreateNewDibitCard()
{
    auto card = createDebitCard();

    card->setName();
    card->setHowManyMoney();

    _debitCards.push_back(card);
};
void Budget::CreateNewWallet()
{
    auto wallet = createWallet();

    wallet->setName();
    wallet->setHowManyMoney();

    _wallets.push_back(wallet);
};
void Budget::PrintCreditCards()
{
    for (auto it : _creditCards)
        it->ShowInfo();
};
void Budget::PrintDebitCards()
{
    for (auto it : _debitCards)
        it->ShowInfo();
};
void Budget::PrintWallets()
{
    for (auto it : _wallets)
        it->ShowInfo();
};
void Budget::AddMoneyOnCreditCard()
{
    string tmp;
    cout << "Enter name card" << endl;
    cin.ignore();
    getline(cin, tmp);

    for (auto it : _creditCards)
    {
        if (it->getName().compare(tmp) == 0)
        {
            it->Refill();
            return;
        }
    }
    cout << "Not found" << endl;
};
void Budget::AddMoneyOnDebitCard()
{
    string tmp;
    cout << "Enter name card" << endl;
    cin.ignore();
    getline(cin, tmp);

    for (auto it : _debitCards)
    {
        if (it->getName().compare(tmp) == 0)
        {
            it->Refill();
            return;
        }
    }
    cout << "Not found" << endl;
};
void Budget::AddMoneyOnWallet()
{
    string tmp;
    cout << "Enter name wallet" << endl;
    cin.ignore();
    getline(cin, tmp);

    for (auto it : _wallets)
    {
        if (it->getName().compare(tmp) == 0)
        {
            it->Refill();
            return;
        }
    }
    cout << "Not found" << endl;
};
void Budget::MinusMoneyOnCreditCard(double value)
{
    string name;

    cout << "Enter name card" << endl;
    cin.ignore();
    getline(cin, name);

    for (auto it : _creditCards)
        if (it->getName().compare(name) == 0)
            it->Withdrawals(value);
};
void Budget::MinusMoneyOnDebitCard(double value)
{
    string name;

    cout << "Enter name card" << endl;
    cin.ignore();
    getline(cin, name);

    for (auto it : _debitCards)
        if (it->getName().compare(name) == 0)
            it->Withdrawals(value);
};
void Budget::MinusMoneyOnWallet(double value)
{
    
    string name;

    cout << "Enter name wallet" << endl;
    cin.ignore();
    getline(cin, name);

    for (auto it : _wallets)
        if (it->getName().compare(name) == 0)
            it->Withdrawals(value);
};
void Budget::Menu()
{
    string nameCat;
    int choice;
    int tmp;
    do {
        system("cls");

        cout << "1.Create  card or wallet" << endl;
        cout << "2.Show cards and wallet" << endl;
        cout << "3.Plus money on cards or wallet" << endl;
        cout << "4.Spend money" << endl;
        cout << "5.Show categories" << endl;
        cout << "6.Rating categories" << endl;
        cout << "0.Exit" << endl;

        cin >> choice;
        switch (choice)
        {
        case 1:
            system("cls");
            cout << "1.Create credit card" << endl;
            cout << "2.Create debit card" << endl;
            cout << "3.Ceate wallet" << endl;

            cin >> tmp;
            switch (tmp)
            {
            case 1:
                CreateNewCreditCard();
                break;
            case 2:
                CreateNewDibitCard();
                break;
            case 3:
                CreateNewWallet();
                break;
            }
            break;
        case 2:
            system("cls");
            cout << "1.Show credit cards" << endl;
            cout << "2.Show debit cards" << endl;
            cout << "3.Show wallets" << endl;

            cin >> tmp;

            switch (tmp)
            {
            case 1:
                PrintCreditCards();
                system("pause");
                break;
            case 2:
                PrintDebitCards();
                system("pause");
                break;
            case 3:
                PrintWallets();
                system("pause");
                break;
            }
            break;
        case 3:
            system("cls");
            cout << "1.Plus money on credits card" << endl;
            cout << "2.Plus money on debit card" << endl;
            cout << "3.Plus money on wallet" << endl;

            cin >> tmp;
            switch (tmp)
            {
            case 1:
                AddMoneyOnCreditCard();
                break;
            case 2:
                AddMoneyOnDebitCard();
                break;
            case 3:
                AddMoneyOnWallet();
                break;
            }
            break;
        case 4:
            system("cls");



            cout << "1.From credit card" << endl;
            cout << "2.From debit card" << endl;
            cout << "3.From wallet" << endl;

            cin >> tmp;

            switch (tmp)
            {
            case 1:
                system("cls");
                double spend;


                cout << "How many you spend?" << endl;
                cin >> spend;

                cout << "Enter category" << endl;
                cin.ignore();
                getline(cin, nameCat);

                date.AddExpenditure(nameCat, spend);
                MinusMoneyOnCreditCard(spend);

                break;
            case 2:
                system("cls");


                cout << "How many you spend?" << endl;

                cin >> spend;

                cout << "Enter category" << endl;
                cin.ignore();
                getline(cin, nameCat);

                date.AddExpenditure(nameCat, spend);
                MinusMoneyOnDebitCard(spend);

                break;
            case 3:
                system("cls");



                cout << "How many you spend?" << endl;
                cin >> spend;

                cout << "Enter category" << endl;
                cin.ignore();
                getline(cin, nameCat);

                date.AddExpenditure(nameCat, spend);
                MinusMoneyOnWallet(spend);

                break;
            }
            break;
        case 5:
            system("cls");
            cout << "1. day " << endl;
            cout << "2. week" << endl;
            cout << "3.month" << endl;

            cin >> tmp;
            switch (tmp)
            {
            case 1:
                date.PrintDay();
                system("pause");
                break;
            case 2:
                date.PrintWeek();
                system("pause");
                break;
            case 3:
                date.PrintMonth();
                system("pause");
                break;
            }
            break;
        case 6:
            system("cls");
            cout << "1.Rating for week" << endl;
            cout << "2.Rating for month" << endl;

            cin >> tmp;

            switch (tmp)
            {
            case 1:
                date.RatingOfWeek();

                break;
            case 2:
                date.RatingOfMonth();

                break;
            }
            break;
       
        }
    } while (choice != 0);
};
