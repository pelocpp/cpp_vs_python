// ===========================================================================
// Strings.cpp // std::string
// ===========================================================================

#include <string>
#include <print>

static void strings_demo()
{
    // standard class 'std::string'

    // constructor
    std::string s("12345");

    // operator <<
    //std::cout << s << std::endl;
    std::println("{}", s);

    // getter: size
    size_t len = s.size();
    //std::cout << "Length: " << len << std::endl;
    std::println("Length: {}", len);

    // getter: empty
    bool b = s.empty();
   // std::cout << "Empty: " << std::boolalpha << b << std::endl;
    std::println("Empty: {}", b);

    // method: insert
    // insert "ABC" at position 2
    s.insert(2, "ABC");
 //   std::cout << "s.insert(2, \"ABC\") ==> " << s << std::endl;

    // method: append
    // append "!!!"
    s.append("!!!");
   // std::cout << "s.append(\"!!!\")    ==> " << s << std::endl;
    std::println("append: {}", s);

    // comparison operators
    std::string s1("12345");
    std::string s2("12345");
    std::string s3("123456");

    bool b1 = (s1 == s2);
    bool b2 = (s1 == s3);

    //std::cout << "s1 == s2           ==> " << std::boolalpha << b1 << std::endl;
    //std::cout << "s1 == s3           ==> " << std::boolalpha << b2 << std::endl;
    std::println("s1 == s2: {}", b1);
    std::println("s1 == s3: {}", b2);


    // method: substr - retrieve a substring
    // first param = position of the first character to include
    // second param = length of the substring
    std::string sub = s1.substr(1, 3);
  //  std::cout << "s1.substr(1, 3)    ==> " << sub << std::endl;
    std::println("s1.substr(1, 3): {}", sub);
        
    // index operator []
    s[2] = '?';
   // std::cout << "s[2] = '?'         ==> " << s << std::endl;

    // method: append
    // append another std::string object
    s1.append(s2);
    //  std::cout << "s1.append(s2)      ==> " << s1 << std::endl;

    // operator +
    // concatenating two strings (same as using method append)
    std::string result = s1 + s3;
    //  std::cout << "s1 + s3            ==> " << result << std::endl;

    // converting a string to an integer
    std::string number("123");
    int value = std::stoi(number);
    // std::cout << "std::stoi(\"123\")   ==> " << value << std::endl;
}

static void strings_demo_02()
{
    std::string s{ "12345" };
    std::println("{}", s);

    auto len = s.size();
    auto empty = s.empty();

    s.insert(2, "ABC");
    s.append("!!!");

    std::string s1("12345");
    std::string s2("12345");
    std::string s3("123456");

    bool b;
    b = (s1 == s2);
    b = (s1 == s3);

    std::string sub{ s1.substr(1, 3) };

    s[2] = '?';
    char ch = s[0];

    std::string result{ s1 + s3 };

    std::string number{ "123" };
    int value = std::stoi(number);
}

void example_strings()
{
    strings_demo();
}

// ===========================================================================
// End-of-File
// ===========================================================================
