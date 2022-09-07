// Ekz_OOP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<vector>
#include<string>

using namespace std;


struct Product
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

struct CrediCard : public Product
{
    virtual void setName() override
    {
        cout << "Enter name for card" << endl;
        cin.ignore();
        getline(cin, _name);
    }
    virtual void setHowManyMoney() override
    {
        cout << "How many money?" << endl;
        cin >> _howManyMoney;
    }
    virtual string getName() override
    {
        return _name;
    }
    virtual double getHowManyMoney() override
    {
        return _howManyMoney;
    }
    virtual void Refill() override
    {
        double value;

        cout << "How much to deposit?" << endl;
        cin >> value;

        _howManyMoney += value;
    }
    virtual void Withdrawals(double value) override
    {
        if (value > _howManyMoney)
            cout << "not enough funds" << endl;
        _howManyMoney -= value;
    }
    virtual void ShowInfo()
    {
        cout << endl << "Card : " << _name << endl;
        cout << "Balance : " << _howManyMoney << endl;
    }
};

struct DebitCard : public Product
{
    virtual void setName() override
    {
        cout << "Enter name for card" << endl;
        cin.ignore();
        getline(cin, _name);
    }
    virtual void setHowManyMoney() override
    {
        cout <<"How many money?" << endl;
        cin >> _howManyMoney;
    }
    virtual string getName() override
    {
        return _name;
    }
    virtual double getHowManyMoney() override
    {
        return _howManyMoney;
    }
    virtual void Refill() override
    {
        double value;

        cout << "How much to deposit?" << endl;
        cin >> value;

        _howManyMoney += value;
    }
    virtual void Withdrawals(double value) override
    {
        if (value > _howManyMoney)
            cout << "not enough funds" << endl;
        _howManyMoney -= value;
    }
    virtual void ShowInfo()
    {
        cout << endl << "Card : " << _name << endl;
        cout << "Balance : " << _howManyMoney << endl;
    }
};

struct Wallet : public Product
{
    virtual void setName() override
    {
        cout << "Enter name for wallet" << endl;
        cin.ignore();
        getline(cin, _name);
    }
    virtual void setHowManyMoney() override
    {
        cout << "How many money?" << endl;
        cin >> _howManyMoney;
    }
    virtual string getName() override
    {
        return _name;
    }
    virtual double getHowManyMoney() override
    {
        return _howManyMoney;
    }
    virtual void Refill() override
    {
        double value;

        cout << "How much to deposit?" << endl;
        cin >> value;

        _howManyMoney += value;
    }
    virtual void Withdrawals(double value) override
    {
        if (value > _howManyMoney)
            cout << "not enough funds" << endl;
        _howManyMoney -= value;
    }
    virtual void ShowInfo()
    {
        cout << endl << "Wallet : "<<_name << endl;
        cout << "Balance : "<<_howManyMoney << endl;
    }
};

struct Fabrica
{
public:
    virtual Product* createCreditCard() = 0;
    virtual Product* createDebitCard() = 0;
    virtual Product* createWallet() = 0;
};

struct Category
{
private:
    string _name;
    double _summa{0};

public:
    void setName()
    {
        cout << "Enter name for category" << endl;
        cin.ignore();
        getline(cin, _name);
    }
    void PlusSumma(double value)
    {
        _summa += value;
    }
    string getName()
    {
        return _name;
    }
    double getSumma()
    {
        return _summa;
    }
    Category create()
    {
        return *this;
    }
};

struct Day
{
private:
    int date{ 0 };
    Category category;
    vector <Category> _categories;

public:
    void AddNewCategory()
    {
        category.setName();

        _categories.push_back(category.create());
    }
    void PlusSummaOfCategory(double val)
    {
        if (_categories.empty())
        {
            cout << "No categories" << endl;
            return;
        }
        string tmp;
        int current{0};
        do {
            cout << "Enter category" << endl;
            cin.ignore();
            getline(cin, tmp);

            for (auto it : _categories)
            {
                if (it.getName().compare(tmp) == 0)
                {
                    it.PlusSumma(val);
                    current = 1;
                    break;
                }
            }
        } while (current != 1);
    }
};

struct Week : public Day
{
private:
    Day arWeek[7];

public:

};

struct Month : public Week
{
private:
    Day arMonth[31];
public:

};

class Budget : public Fabrica
{
private:
    double _expenses;
    Month month;
    vector <Product*> _creditCards;
    vector <Product*> _debitCards;
    vector<Product*> _wallets;
   

public:
    void setExpenses()
    {
        cout << "how much is spent?" << endl;
        cin >> _expenses;
    }
    virtual Product* createCreditCard() override
    {
        return new CrediCard;
    }
    virtual Product* createDebitCard() override
    {
        return new DebitCard;
    }
    virtual Product* createWallet() override
    {
        return new Wallet;
    }
    void CreateNewCreditCard()
    {
        auto card = createCreditCard();

        card->setName();
        card->setHowManyMoney();

        _creditCards.push_back(card);

    }
    void CreateNewDibitCard()
    {
        auto card = createDebitCard();

        card->setName();
        card->setHowManyMoney();

        _debitCards.push_back(card);
    }
    void CreateNewWallet()
    {
        auto wallet = createWallet();

        wallet->setName();
        wallet->setHowManyMoney();

        _wallets.push_back(wallet);
    }
    void PrintCreditCards()
    {
        for (auto it : _creditCards)
            it->ShowInfo();
    }
    void PrintDebitCards()
    {
        for (auto it : _debitCards)
            it->ShowInfo();
    }
    void PrintWallets()
    {
        for (auto it : _wallets)
            it->ShowInfo();
    }
    void AddMoneyOnCreditCard()
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
    }
    void AddMoneyOnDebitCard()
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
    }
    void AddMoneyOnWallet()
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
    }
    void PaymentCreditCard()
    {
        double value;
        string tmp;

        cout << "how much did you spend?" << endl;
        cin >> value;


        cout << "Which card to use?" << endl;
        cin.ignore();
        getline(cin, tmp);

        for (auto it : _creditCards)
        {
            if (it->getName().compare(tmp) == 0)
                it->Withdrawals(value);
        }

        month.PlusSummaOfCategory(value);
    }
    void PaymentDebitCard()
    {
        double value;
        string tmp;

        cout << "how much did you spend?" << endl;
        cin >> value;


        cout << "Which card to use?" << endl;
        cin.ignore();
        getline(cin, tmp);

        for (auto it : _debitCards)
        {
            if (it->getName().compare(tmp) == 0)
                it->Withdrawals(value);
        }

        month.PlusSummaOfCategory(value);
    }
    void PaymentWallet()
    {
        double value;
        string tmp;

        cout << "how much did you spend?" << endl;
        cin >> value;


        cout << "Which card to use?" << endl;
        cin.ignore();
        getline(cin, tmp);

        for (auto it : _wallets)
        {
            if (it->getName().compare(tmp) == 0)
                it->Withdrawals(value);
        }

        month.PlusSummaOfCategory(value);
    }
    
};

int main()
{
    std::cout << "Hello World!\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
