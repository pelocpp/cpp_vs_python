// ===========================================================================
// Program.cpp // Cpp versus Python
// https://github.com/pelocpp
// ===========================================================================

// ===========================================================================
// defines / includes

#include <print>
#define MessageText "Collection of C++/Python Comparison Code Examples - Copyright (C) 2026 Peter Loos."
#pragma message(MessageText)

// ===========================================================================
// external function prototypes
extern void example_teuflische_folge();
extern void example_zinsrechnung();
extern void example_bank_account();
extern void example_phonebook();
extern void example_lists();
extern void example_tuples();
extern void example_dictionaries();
extern void example_parameter_passing();
extern void example_strings();
extern void example_enumeration();

int main()
{
    std::println(MessageText);

    //example_teuflische_folge();
    //example_zinsrechnung();
    //example_bank_account();
    //example_phonebook();
    //example_lists();
    //example_tuples();
    //example_dictionaries();
    //example_parameter_passing();
    //example_strings();
    example_enumeration();

    std::println("Done.");
    return 0;
}

// ===========================================================================
// End-of-File
// ===========================================================================
