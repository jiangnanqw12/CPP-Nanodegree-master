#include<iostream>

class BankAccount{
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
    BankAccount::number=number;
}