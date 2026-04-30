// =====================================================================================
// TeuflischeFolge.cpp
// =====================================================================================

#include <iostream>
#include <print>
#include <string>

static void berechne_teuflische_folge(int start);

void example_teuflische_folge()
{
    std::println("Teuflische Zahlenfolge");
    std::println("======================");
    std::println();
    
    std::print("Startwert: ");
    std::string input;
    std::cin >> input;
    int number = std::stoi(input);

    berechne_teuflische_folge(number);
}

void berechne_teuflische_folge(int start)
{
    auto number{ start };   // start number
    auto n{ 1 };            // counter for length of sequence

    while (number != 1)
    {
        if (number % 2 == 0)
        {
            number = number / 2;
        }
        else
        {
            number = 3 * number + 1;
        }

        std::println("Schritt {:3}: Zahl = {}", n, number);
        n++;
    }
}

// =====================================================================================
// End-of-File
// =====================================================================================
