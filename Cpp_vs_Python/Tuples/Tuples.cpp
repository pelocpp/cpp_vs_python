// =====================================================================================
// Tuples.cpp
// =====================================================================================

#include <cstddef>
#include <print>
#include <tuple>
#include <vector>

static void example_tuples_01()
{
    auto susan = std::make_tuple<std::string, std::size_t, double, std::string>(
        "Susan Meier", 25, 1.75, "Germany"
    );

    const auto& name = std::get<0>(susan);
    auto age = std::get<1>(susan);
    auto size = std::get<2>(susan);
    const auto& country = std::get<3>(susan);

    auto employee = std::make_tuple<std::string, std::size_t, std::string, std::vector<std::string>>(
        "John",
        35,
        "Python Developer",
        { "Django", "Flask", "FastAPI", "CSS", "HTML" }
    );

    const auto& firstSkill = std::get<3>(employee)[0];
}

void example_tuples()
{
    example_tuples_01();
}

// =====================================================================================
// End-of-File
// =====================================================================================
