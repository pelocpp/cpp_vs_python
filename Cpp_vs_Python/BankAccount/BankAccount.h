// ===========================================================================
// BankAccount.h
// ===========================================================================

#pragma once

#include <cstddef>
#include <iostream>

class BankAccount
{
private:
    std::size_t m_number;
    double      m_balance;

public:
    // c'tor
    BankAccount();
    BankAccount(double start);

    // getter / setter
    std::size_t getAccountNumber() const;
    double      getBalance() const;

    // public interface
    void deposit(double amount);
    void withdraw(double amount);
    bool equals(const BankAccount& other) const;

    // operators
    bool operator== (const BankAccount& other);
    bool operator!= (const BankAccount& other);
    bool operator<  (const BankAccount& other);
    bool operator<= (const BankAccount& other);
    bool operator>  (const BankAccount& other);
    bool operator>= (const BankAccount& other);

private:
    inline static std::size_t s_nextAccountNumber = 10'000;;
};

// output operator
std::ostream& operator<< (std::ostream& os, const BankAccount& other);

// ===========================================================================
// End-of-File
// ===========================================================================
