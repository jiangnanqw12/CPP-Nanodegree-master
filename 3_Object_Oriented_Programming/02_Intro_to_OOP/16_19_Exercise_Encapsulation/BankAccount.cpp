#include <iostream>

class BankAccount
{
private:
    long int number;
    std::string name;
    float funds;

public:
    void set_number(long int number);
    void set_name(std::string name);
    void set_funds(float funds);
    long int get_number() const;
    std::string get_name() const;
    float get_funds() const;
};

void BankAccount::set_number(long int number)
{
    BankAccount::number = number;
}
void BankAccount::set_name(std::string name)
{
    BankAccount::name = name;
}
void BankAccount::set_funds(float funds)
{
    BankAccount::funds = funds;
}
long int BankAccount::get_number() const
{
    return BankAccount::number;
}
std::string BankAccount::get_name() const
{
    return BankAccount::name;
}
float BankAccount::get_funds() const
{
    return BankAccount::funds;
}
int main()
{
    BankAccount ba;
    ba.set_number(100);

    std::cout << ba.get_number() << std::endl;
}