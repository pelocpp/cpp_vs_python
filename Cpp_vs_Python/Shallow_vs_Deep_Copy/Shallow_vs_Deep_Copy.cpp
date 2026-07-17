// =====================================================================================
// Shallow_vs_Deep_Copy.cpp
// =====================================================================================

#include <memory>
#include <print>
#include <vector>

class Data
{
public:
    int number1 = 123;
    int number2 = 456;

    void print() const {
        std::println("number1: {}", number1);
        std::println("number2: {}", number2);
    }
};

// --- Python: data2 = data1 ---
// Creates a new reference pointing to the exact same heap memory.
static void example_data_01()
{
    auto data1 = std::make_shared<Data>();

    auto data2 = data1; // pointer aliasing (shares ownership)

    data1->print();
    data2->print();

    data1->number1 = 999; // modifying via data1 affects data2

    data1->print();
    data2->print();

    std::println();
}

// --- Python: data2 = copy.copy(data1) ---
// Creates a new heap object and performs a member-wise shallow copy.
static void example_data_02()
{
    auto data1 = std::make_shared<Data>();

    // Explicit shallow clone: copies values/pointers as they are
    auto data2 = std::make_shared<Data>(*data1);

    data1->print();
    data2->print();

    data1->number1 = 999; // independent objects; data2 is unaffected

    data1->print();
    data2->print();

    std::println();
}

// --- Python: data2 = copy.deepcopy(data1) ---
// Recursively duplicates the object graph. 
// For this flat class, it behaves exactly like the shallow copy.
static void example_data_03()
{
    auto data1 = std::make_shared<Data>();

    // in a complex class, this would invoke a deep clone mechanism
    auto data2 = std::make_shared<Data>(*data1);

    data1->print();
    data2->print();

    data1->number1 = 999; // independent objects; data2 is unaffected

    data1->print();
    data2->print();

    std::println();
}

static void example_shallow_vs_deep_copy_01()
{
    example_data_01();
    example_data_02();
    example_data_03();
}

// =====================================================================================

class MoreData {
public:
    int number = 123;
    // Managed as a shared resource to emulate Python's reference behavior
    std::shared_ptr<std::vector<int>> numbers;

    MoreData() {
        numbers = std::make_shared<std::vector<int>>(std::vector<int>{123, 456, 789});
    }

    void print() const {

        std::println("number:  {}", number);
        std::print("numbers: [");
        for (size_t i = 0; i < numbers->size(); ++i) {
            // std::cout << (*numbers)[i] << (i < numbers->size() - 1 ? ", " : "");
            std::print("{}{}", (*numbers)[i], (i < numbers->size() - 1) ? ", " : "");
        }
        std::println("]");
    }
};

// --- 1. Reference Assignment ---
// data1 and data2 point to the exact same MoreData instance.
static void example_moredata_01()
{
    auto data1 = std::make_shared<MoreData>();
    auto data2 = data1; // Alias pointer

    data1->print();
    data2->print();

    data1->number = 888;
    (*data1->numbers)[1] = 999; // Mutates the shared list

    data1->print();
    data2->print(); // BOTH changes are visible here
    std::println();
}

// --- 2. Shallow Copy ---
// Allocates a new MoreData object, but copies the member references (pointers) as-is.
static void example_moredata_02()
{
    auto data1 = std::make_shared<MoreData>();

    // Default compiler copy constructor: copies 'number' by value, 
    // and copies the 'numbers' shared_ptr by reference count!
    auto data2 = std::make_shared<MoreData>(*data1);

    data1->print();
    data2->print();

    data1->number = 888;        // Only data1 changes (primitive int value)
    (*data1->numbers)[1] = 999; // Modifies the shared heap vector!

    data1->print();
    data2->print(); // data2 sees the vector change, but NOT the 'number' change
    std::println();
}

// --- 3. Deep Copy ---
// Allocates a new MoreData object AND fully duplicates nested heap structures.
static void example_moredata_03()
{
    auto data1 = std::make_shared<MoreData>();
    auto data2 = std::make_shared<MoreData>();

    // Manual deep clone execution
    data2->number = data1->number;
    // Deep copy the vector data into a completely new heap allocation
    data2->numbers = std::make_shared<std::vector<int>>(*data1->numbers);

    data1->print();
    data2->print();

    data1->number = 888;
    (*data1->numbers)[1] = 999; // Modifies data1's private vector

    data1->print();
    data2->print(); // data2 remains completely unaffected ([123, 456, 789])
    std::println();
}

// =====================================================================================

static void example_shallow_vs_deep_copy_02()
{
    example_moredata_01();
    example_moredata_02();
    example_moredata_03();
}

void example_shallow_vs_deep_copy()
{
    example_shallow_vs_deep_copy_01();
    example_shallow_vs_deep_copy_02();
}

// =====================================================================================
// End-of-File
// =====================================================================================
