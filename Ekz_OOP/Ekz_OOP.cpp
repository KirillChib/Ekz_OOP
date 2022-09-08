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
    vector <Category> _categories;

public:
    Category category;

    int getDate()
    {
        return date;
    }
    void AddNewCategory()
    {
        category.setName();

        _categories.push_back(category.create());
    }
    void PlusSummaOfCategory(double val)
    {
        if (!_categories.empty())
        {
            cout << "No categories" << endl;
            return;
        }
        string tmp;
        int current{0};
        
            cout << "Enter category" << endl;
            cin.ignore();
            getline(cin, tmp);

            for (auto it : _categories)
            {
                if (it.getName().compare(tmp) == 0)
                {
                    it.PlusSumma(val);
                    current ++;
                    break;
                }
            }
       
    }
    void PrintCategories()
    {
        for (auto it : _categories)
        {
            cout <<"Category : "<< it.getName() << endl;
            cout << it.getSumma() << " rub" << endl;
        }
    }
};

struct Week : public Day
{
public:
    Day arWeek[7];
};

struct Month : public Week
{
public:
    Day arMonth[31];
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
        int date;

        cout << "Enter date (1-31)" << endl;
        cin >> date;

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

        month.arMonth[date - 1].PlusSummaOfCategory(value);
        month.arWeek[date - 1].PlusSummaOfCategory(value);
    }
    void PaymentDebitCard()
    {
        double value;
        string tmp;
        int date;

        cout << "Enter date (1-31)" << endl;
        cin >> date;

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

        month.arMonth[date - 1].PlusSummaOfCategory(value);
        month.arWeek[date - 1].PlusSummaOfCategory(value);
    }
    void PaymentWallet()
    {
        double value;
        string tmp;
        int date;

        cout << "Enter date (1-31)" << endl;
        cin >> date;

        cout << "how much did you spend?" << endl;
        cin >> value;


        cout << "Which wallet to use?" << endl;
        cin.ignore();
        getline(cin, tmp);

        for (auto it : _wallets)
        {
            if (it->getName().compare(tmp) == 0)
                it->Withdrawals(value);
        }

        month.arMonth[date - 1].PlusSummaOfCategory(value);
        month.arWeek[date - 1].PlusSummaOfCategory(value);
    }
    void PrintInfoCategories()
    {
        int choice;
        int day;

        cout << "1.Show day" << endl << "2.Show week" << endl << "3.Show month" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter day (1-31)" << endl;
            cin >> day;

            system("cls");

            month.arMonth[day - 1].PrintCategories();
            break;
        case 2:
            for (auto i = 0; i < 7; i++)
            {
               
                if (month.arWeek[i].getDate() == 0)
                {
                    while (month.arWeek[i].getDate() != 0)
                        i++;
                }

                cout << "Day " << i + 1;
                month.arWeek[i].PrintCategories();
            }
            break;
        case 3:
            for (auto i = 0; i < 31; i++)
            {
                cout << "Day " << i + 1;
                if (month.arMonth[i].getDate() == 0)
                {
                    while (month.arMonth[i].getDate() != 0)
                        i++;
                }
                month.arMonth[i].PrintCategories();
            }
            break;
            }
        }
    void RatingCategories()
    {
        Category cat, cat1, cat2;
        vector <Category> list;

        for (auto i = 0; i < 31; i++)
        {
            if (month.arMonth[i].getDate() == 0)
                i++;

            if (month.arMonth[i].category.getSumma() > month.arMonth[i + 1].category.getSumma())
                cat = month.arMonth[i].category;
            else
            {
                cat = month.arMonth[i + 1].category;
            }
        }
        list.push_back(cat);

        for (auto i = 0; i < 31; i++)
        {
            if (month.arMonth[i].category.getName().compare(cat.getName()) == 0)
                i++;

            if (month.arMonth[i].category.getSumma() > month.arMonth[i + 1].category.getSumma())
                cat1 = month.arMonth[i].category;

            else
            {
                cat1 = month.arMonth[i + 1].category;
            }
        }
        list.push_back(cat1);

        for (auto i = 0; i < 31; i++)
        {
            if (month.arMonth[i].category.getName().compare(cat.getName()) == 0 || month.arMonth[i].category.getName().compare(cat1.getName()) == 0)
                i++;

            if (month.arMonth[i].category.getSumma() > month.arMonth[i + 1].category.getSumma())
                cat2 = month.arMonth[i].category;

            else
            {
                cat2 = month.arMonth[i + 1].category;
            }
        }
        list.push_back(cat2);

        for (auto it : list)
        {
            cout <<endl<< "Category : " << it.getName() << endl;
            cout << "Summa : " << it.getSumma() << " rub" << endl;
        }

    }
    void Rating()
    {

    }
    void Menu()
    {
        int choice;
        int tmp;
        do {
            cout << "1.Create  card or wallet" << endl;
            cout << "2.Show cards and wallet" << endl;
            cout << "3.Plus money on cards or wallet" << endl;
            cout << "4.Create category of expenses" << endl;
            cout << "5.Spend money" << endl;
            cout << "6.Show categories" << endl;
            cout << "7.Rating categories" << endl;
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
                    break;
                case 2:
                    PrintDebitCards();
                    break;
                case 3:
                    PrintWallets();
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
                month.AddNewCategory();
                break;
            case 5:
                system("cls");
                cout << "1.From credit card" << endl;
                cout << "2.From debit card" << endl;
                cout << "3.From wallet" << endl;

                cin >> tmp;
                    switch (tmp)
                    {
                    case 1:
                        PaymentCreditCard();
                        break;
                    case 2:
                        PaymentDebitCard();
                        break;
                    case 3:
                        PaymentWallet();
                        break;
                    }
                    break;
            case 6:
                system("cls");
                PrintInfoCategories();
                break;
            case 7:
                system("cls");
                RatingCategories();
                break;
            }
        } while (choice != 0);
    }
};

int main()
{
    Budget b;
    b.Menu();
   
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
