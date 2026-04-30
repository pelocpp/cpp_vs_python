// ===========================================================================
// BankAccount_Example.cpp
// ===========================================================================

#include "BankAccount.h"

#include <cstddef>
#include <iostream>

void example_bank_account()
{
    BankAccount myAccount{ 50 };
    myAccount.deposit(50);
    myAccount.withdraw(25);
    std::cout << myAccount << std::endl;

    BankAccount firstAccount{};
    std::cout << firstAccount << std::endl;

    BankAccount secondAccount{};
    secondAccount.deposit(50);
    secondAccount.withdraw(25);
    std::cout << secondAccount << std::endl;

    if (firstAccount.equals(secondAccount)) {
        std::cout << "Same Balance" << std::endl;
    }
    else {
        std::cout << "Different Balances" << std::endl;
    }
}

// ===========================================================================
// End-of-File
// ===========================================================================