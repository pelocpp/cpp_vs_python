// ===========================================================================
// BankAccount.cpp
// ===========================================================================

#include "BankAccount.h"

#include <iomanip>

// c'tor
BankAccount::BankAccount(double balance) 
    : m_number{ s_nextAccountNumber }, m_balance{ balance }
{
    // move to next available account number
    s_nextAccountNumber++;
}

BankAccount::BankAccount() : BankAccount{ 0.0 } {}

// getter / setter
std::size_t BankAccount::getAccountNumber() const
{
    return m_number;
}

double BankAccount::getBalance() const
{
    return m_balance;
}

// public interface
void BankAccount::deposit(double amount)
{
    m_balance += amount;
}

void BankAccount::withdraw(double amount)
{
    if (m_balance < amount)
        return;

    m_balance -= amount;
}

bool BankAccount::equals(const BankAccount& other) const
{
    if (m_balance == other.m_balance) {
        return true;
    }
    else {
        return false;
    }
}

// operators
bool BankAccount::operator== (const BankAccount& other) {

    if (m_balance == other.m_balance) {
        return true;
    }
    else {
        return false;
    }
}

bool BankAccount::operator!= (const BankAccount& other) {

    return !(*this == other);
}

bool BankAccount::operator<  (const BankAccount& other) {

    if (m_balance < other.m_balance) {
        return true;
    }
    else {
        return false;
    }
}

bool BankAccount::operator<= (const BankAccount& other) {

    return (*this < other || *this == other);
}

bool BankAccount::operator>  (const BankAccount& other) {

    return !(*this <= other);
}

bool BankAccount::operator>= (const BankAccount& other) {

    return !(*this < other);
}

// output operator
std::ostream& operator<< (std::ostream& os, const BankAccount& other)
{
    os << "BankAccount Nr.: " << other.getAccountNumber() << ":";
    os << std::fixed << std::setprecision(2);
    os << " Balance = " << std::setw(2) << std::setfill('0') << other.getBalance();
    return os;
}

// ===========================================================================
// End-of-File
// ===========================================================================
