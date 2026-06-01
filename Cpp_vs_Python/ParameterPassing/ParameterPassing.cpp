// =====================================================================================
// ParameterPassing.cpp
// =====================================================================================

#include <print>

static void malZwei(int n)
{
    n = 2 * n;
}

static void malZweiByAdress(int* n)
{
    *n = 2 * *n;
}

static void malZweiByReference(int& n)
{
    n = 2 * n;
}

static void test_malZwei()
{
    int x = 10;

    std::println("x: {}", x);

    malZweiByAdress(&x);
    std::println("x: {}", x);

    malZweiByReference(x);
    std::println("x: {}", x);
}

void example_parameter_passing()
{
    test_malZwei();
}

// =====================================================================================
// End-of-File
// =====================================================================================
