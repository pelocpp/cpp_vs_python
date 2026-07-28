// =====================================================================================
// Procedures_Functions.cpp
// =====================================================================================

#include <cstddef>
#include <print>
#include <string>

// procedure
static void sayHello(std::size_t count, const std::string& message)
{
    for (std::size_t i{}; i != count; ++i) {
        std::println("{}", message);
    }
    std::println();
}

static void example_procedures_functions_01()
{
    sayHello(2, "I'm saying Hello :)");
    sayHello(3, "... and Goodbye!");
}

static std::size_t powerOf(std::size_t base, std::size_t exponent)
{
    std::size_t result{ 1 };

    for (std::size_t i{}; i != exponent; ++i) {
        result *= base;
    }

    return result;
}

static void example_procedures_functions_02()
{
    std::size_t base{ 2 };
    std::size_t exponent{ 5 };
    std::size_t result{};

    result = powerOf(base, exponent);
    std::println("{} to the power of {}: {}", base, exponent, result);
}

void example_procedures_functions()
{
    example_procedures_functions_01();
    example_procedures_functions_02();
}

// =====================================================================================
// End-of-File
// =====================================================================================
