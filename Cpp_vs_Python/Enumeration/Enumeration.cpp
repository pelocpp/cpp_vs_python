// =====================================================================================
// Enumeration.cpp
// =====================================================================================

#include <print>
#include <ranges>
#include <string>
#include <utility>
#include <vector>

// standard vector as equivalent of a Python list
static std::vector<std::string> cities = {
    "Berlin", "Hamburg", "Muenchen", "Koeln" 
};

// helper function for pretty-printing pairs
static void print_pair(const std::pair<std::size_t, std::string>& p) {
    std::print("({}, {})", p.first, p.second);
}

static void example_enumeration_01()
{
    // direct printing of the list
    std::print("[");
    for (std::size_t i{}; i < cities.size(); ++i) {
        std::println("'{}'{}", cities[i], (i < cities.size() - 1) ? ", " : "");
    }
    std::print("]");
    std::println();
}

static void example_enumeration_02()
{
    // =====================================================================================
    // 1. Enumerating a list (starting with 0)
    //    std::views::enumerate creates a lazy view (iterator), just like Python's enumerate():
    auto enumerated_cities = std::views::enumerate(cities);

    // conversion into a concrete "list object" (std::vector of std::pair)
    std::vector<std::pair<std::size_t, std::string>> list_enumerated_cities(
        enumerated_cities.begin(), 
        enumerated_cities.end()
    );

    std::print("[");
    for (std::size_t i{}; i < list_enumerated_cities.size(); ++i) {
        print_pair(list_enumerated_cities[i]);
        if (i < list_enumerated_cities.size() - 1) {
            std::print(", ");
        }
    }
    std::print("]");
    std::println();
}


static void example_enumeration_03()
{
   // 2. Enumerating a list with a start index of 1
   //    In C++20, we use transform() to subsequently increment the view's index by 1:

    //auto enumerated_cities =
    //    std::views::enumerate(cities) |
    //    std::views::transform([](/*auto*/ const std::pair<std::size_t, std::string>& p) {
    //        return std::make_pair(p.first + 1, p.second);
    //    });

    auto enumerated_cities =
        std::views::enumerate(cities) |
        std::views::transform([](const auto& proxy) {

            // Note: implementation detail:
            // std::views::enumerate doesn't hand to the lambda a std::pair;
            // it hands a proxy/tuple-like element that supports structured binding and get<>,
            // but does not expose .first/.second.
            // With MSVC: it's a std::tuple
            // When you write the parameter as an explicit std::pair
            // it forces a conversion to a pair (so .first works).
            // 
            // If you use auto the parameter is deduced to the proxy type
            // and p.first is not a member — compile error

            const auto& [first, second] = proxy;

            return std::make_pair(first + 1, second);
        }
    );

    std::vector<std::pair<std::size_t, std::string>> list_enumerated_cities(
        enumerated_cities.begin(),
        enumerated_cities.end()
    );

    std::print("[");
    for (std::size_t i{}; i < list_enumerated_cities.size(); ++i) {
        print_pair(list_enumerated_cities[i]);
        if (i < list_enumerated_cities.size() - 1) {
            std::print(", ");
        }
    }
    std::print("]");
    std::println();
}

static void example_enumeration_04()
{
    // =====================================================================================
    // 3. Enumerating a list without creating a new list object (manually advancing via an iterator)
    //    This corresponds exactly to Python's `next()` principle for iterators:
    
    auto enum_view = std::views::enumerate(cities);
    auto it = enum_view.begin();

    print_pair(*it); std::println(); ++it; // next(1)
    print_pair(*it); std::println(); ++it; // next(2)
    print_pair(*it); std::println(); ++it; // next(3)
    print_pair(*it); std::println();       // next(4)
    std::println();
}

static void example_enumeration_05()
{
    // =====================================================================================
    // 4. Iterating through a list with a for-loop
    //    In C++, structured binding (auto [index, value]) is used for this:

    for (auto [index, city] : std::views::enumerate(cities)) {
        std::println("({}, {})", index, city);
    }
    std::println();

    // pure value loop without index
    for (const auto& city : cities) {
        std::println("{}", city);
    }
    std::println();
}

void example_enumeration()
{
    example_enumeration_01();
    example_enumeration_02();
    example_enumeration_03();
    example_enumeration_04();
    example_enumeration_05();
}

// =====================================================================================
// End-of-File
// =====================================================================================
