// ===========================================================================
// Strings.cpp // std::string
// ===========================================================================

#include <string>
#include <print>

void strings_demo()
{
    std::string s = "12345";
    std::println("String: {}", s);

    // len
    size_t length = s.length(); // oder s.size()
    bool empty = s.empty();
    std::println("Length: {} - Empty: {}", length, empty);

    // find
    size_t pos = s.find("3");
    if (pos != std::string::npos) {
        std::println("Pos: {}", pos);
    }

    // replace
    size_t replacePos = s.find("3");
    if (replacePos != std::string::npos) {
        s.replace(replacePos, 1, "ABABA"); // pos, len, new string     
    }
    std::println("String: {}", s);

    // count
    std::size_t count = std::count(s.begin(), s.end(), 'A');
    std::println("Count: {}", count);

    // startswith (use rfind with index 0)
    bool n = (s.rfind("12", 0) == 0);
    std::println("startswith: {}", n);

    // endswith
    bool ends = false;
    if (s.length() >= 1) {
        ends = (s.compare(s.length() - 1, 1, "X") == 0);
    }
    std::println("endswith: {}", n);

    // insert
    if (s.length() >= 5) {
        s.insert(5, "XYZ");
    }
    std::println("String: {}", s);

    // append
    s += "!!!";
    std::println("String: {}", s);

    // equals
    std::string s1 = "12345";
    std::string s2 = "12345";
    std::string s3 = "123456";

    n = (s1 == s2);
    std::println("equals s1==s2: {}", n);
    n = (s1 == s3);
    std::println("equals s1==s3: {}", n);

    // string to int
    std::string number = "123";
    int value = std::stoi(number);
    std::println("Number: {}", value);
}

void example_strings()
{
    strings_demo();
}

// ===========================================================================
// End-of-File
// ===========================================================================
