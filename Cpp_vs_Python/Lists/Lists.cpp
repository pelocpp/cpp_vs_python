// =====================================================================================
// Lists.cpp
// =====================================================================================

#include <print>
#include <variant>
#include <vector>

static void example_lists_01_homogenous()
{
    std::vector list = { 1, 2, 3, 4, 5 };

    std::print("[");
    for (auto i{ 0 }; auto n : list) {
        if (i != list.size() - 1) {
            std::print("{}, ", n);
            ++i;
        }
    }
    if (list.size() != 0) {
        std::print("{}", list.back());
    }
    std::print("]");
}


static void example_lists_02_heterogeneous()
{
    std::vector<std::variant<std::string, int>> list = {
        "Hans", 123, "Sepp", 124 
    };

    std::print("[");
    for (auto i{ 0 }; const auto& elem : list) {
        if (i != list.size() - 1) {
            std::visit(
                [](const auto& value) {
                    std::print("{}, ", value);
                },
                elem
            );
            ++i;
        }
    }
    if (list.size() != 0) {
        std::visit(
            [](const auto& value) {
                std::print("{}", value);
            },
            list.back()
        );
    }
    std::print("]");
}


void example_lists()
{
   // example_lists_01_homogenous();
    example_lists_02_heterogeneous();
}

// =====================================================================================
// End-of-File
// =====================================================================================
