// =====================================================================================
// Dictionaries.cpp
// =====================================================================================

#include <iostream>
#include <print>
#include <string>
#include <unordered_map>


// https://www.python-kurs.eu/python3_dictionaries.php

static void example_dictionaries_01()
{
    std::unordered_map<std::string, int> cities_inhabitants = {
        { "Berlin", 3669491 },
        { "Hamburg", 1847253 },
        { "Muenchen", 1484226 },
        { "Koeln", 1087863 },
        { "Frankfurt am Main", 763380 },
        { "Stuttgart", 635911 },
        { "Duesseldorf", 621877 },
        { "Leipzig", 593145 },
        { "Dortmund", 588250 },
        { "Essen", 582760 },
        { "Bremen", 567559 },
        { "Dresden", 556780 },
        { "Hanover", 536925 },
        { "Nuernberg", 518370 }
    };

    for (const auto& [city, population] : cities_inhabitants) {
        std::println("{:20}: {}", city, population);
    }

    cities_inhabitants["Nuernberg"] = 546'397;
}

void example_dictionaries()
{
    example_dictionaries_01();
}

// =====================================================================================
// End-of-File
// =====================================================================================
