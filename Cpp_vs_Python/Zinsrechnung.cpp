// =====================================================================================
// Zinsrechnung.cpp
// =====================================================================================

#include <print>

void example_zinsrechnung()
{
    auto capitalStock { 1000.0 };
    auto startCapitalStock{ capitalStock };
    auto interestRate{ 5.0 };
    auto numberYears{ 10 };

    std::println("Zinstabelle fuer Grundkapital {:.2f}", capitalStock);
    std::println("Verzinsung:                   {:.2f}%", interestRate);
    std::println("=====================================");
    std::println();
    std::println("Kapitalstand zum Jahresende:");

    auto year{ 0 };

    while (year < numberYears)
    {
        double interest{ (capitalStock / 100.0) * interestRate };
        capitalStock += interest;
        std::println("Jahr: {:2}    Kapital: {:.2f}", (year + 1), capitalStock);
        ++year;
    }

    std::println();
    std::println("Aus {:.2f} Grundkapital wurden in {} Jahren {:.2f} Euro.\n",
        startCapitalStock, year, capitalStock);
}

// =====================================================================================
// End-of-File
// =====================================================================================
