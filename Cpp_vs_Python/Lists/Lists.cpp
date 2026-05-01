// =====================================================================================
// Lists.cpp
// =====================================================================================

#include <print>
#include <ranges>
#include <variant>
#include <vector>

static void example_lists_01_homogenous()
{
    std::vector list = { 1, 2, 3, 4, 5 };

    // output-function
    auto print_list = [](const auto& list) {
        std::print("[");
        for (size_t i{}; i != list.size(); ++i) {
            std::print("{}{}", list[i], (i == list.size() - 1) ? "" : ", ");
        }
        std::println("]");
    };

    print_list(list);
}

static void example_lists_02_heterogeneous()
{
    std::vector<std::variant<std::string, int>> list = { "Hans", 123, "Sepp", 124 };

    auto print_list = [](const auto& list) {
        std::print("[");
        for (size_t i{}; i != list.size(); ++i) {
            std::visit(
                [i,&list](const auto& value) {
                    std::print("{}{}", value, (i == list.size() - 1) ? "" : ", ");
                },
                list[i]
            );
        }
        std::println("]");
    };

    print_list(list);
}

static void example_lists_03_list_comprehension()
{
    std::vector numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    auto view = numbers
        | std::views::filter([](int x) { return x % 2 == 0; })
        | std::views::transform([](int x) { return x * x; });

    std::vector<int> result{ view.begin(), view.end() };

    for (int x : result) {
        std::print("{} ", x);
    }
}

static void example_lists_04_list_traversal()
{
    std::vector numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    for (int x : numbers) {
        std::print("{} ", x);
    }
}

static void example_lists_05_list_slicing()
{
    // 1. create original list
    std::vector<std::string> fruits = { "apple", "banana", "cherry", "strawberry", "pear", "pineapple" };

    // 2. simulate sclicing "fruits[0:2]" / first two elements
    std::vector<std::string> first_two(fruits.begin(), fruits.begin() + 2);

    // 3. simulate sclicing "fruits[2:]" / last elements
    std::vector<std::string> remaining_fruits(fruits.begin() + 2, fruits.end());

    // output-function
    auto print_list = [](const std::vector<std::string>& vec) {
        std::print("[");
        for (size_t i{}; i != vec.size(); ++i) {
            std::print("\"{}\"{}", vec[i], (i == vec.size() - 1) ? "" : ", ");
        }
        std::println("]");
    };

    print_list(fruits);
    print_list(first_two);
    print_list(remaining_fruits);
}

void example_lists()
{
    example_lists_01_homogenous();
    example_lists_02_heterogeneous();
    example_lists_03_list_comprehension();
    example_lists_04_list_traversal();
    example_lists_05_list_slicing();
}

// =====================================================================================
// End-of-File
// =====================================================================================
