# Shallow versus Deep Copy

[Zurück](../../Readme.md)

---

Die beiden Optionen des Kopierens (Shallow Copy, Deep Copy) werden an Hand von Beispielen aufgezeigt.

In C++ sind für die tiefe Kopie ein Kopier-Konstruktor notwendig, wenn keine STL Standardklassen verwendet werden.

In Python ist die tiefe Kopie zunächst einmal nicht direkt vorhanden, es werden Referenzen kopiert.

Um eine tiefe Kopie zu erstellen, stellt Python eine integrierte Bibliothek namens &bdquo;copy&rdquo; bereit.

---

## Realisierung in C++

```cpp
001: class Data
002: {
003: public:
004:     int number1 = 123;
005:     int number2 = 456;
006: 
007:     void print() const {
008:         std::println("number1: {}", number1);
009:         std::println("number2: {}", number2);
010:     }
011: };
012: 
013: // --- Python: data2 = data1 ---
014: // Creates a new reference pointing to the exact same heap memory.
015: static void example_data_01()
016: {
017:     auto data1 = std::make_shared<Data>();
018: 
019:     auto data2 = data1; // pointer aliasing (shares ownership)
020: 
021:     data1->print();
022:     data2->print();
023: 
024:     data1->number1 = 999; // modifying via data1 affects data2
025: 
026:     data1->print();
027:     data2->print();
028: 
029:     std::println();
030: }
031: 
032: // --- Python: data2 = copy.copy(data1) ---
033: // Creates a new heap object and performs a member-wise shallow copy.
034: static void example_data_02()
035: {
036:     auto data1 = std::make_shared<Data>();
037: 
038:     // Explicit shallow clone: copies values/pointers as they are
039:     auto data2 = std::make_shared<Data>(*data1);
040: 
041:     data1->print();
042:     data2->print();
043: 
044:     data1->number1 = 999; // independent objects; data2 is unaffected
045: 
046:     data1->print();
047:     data2->print();
048: 
049:     std::println();
050: }
051: 
052: // --- Python: data2 = copy.deepcopy(data1) ---
053: // Recursively duplicates the object graph. 
054: // For this flat class, it behaves exactly like the shallow copy.
055: static void example_data_03()
056: {
057:     auto data1 = std::make_shared<Data>();
058: 
059:     // in a complex class, this would invoke a deep clone mechanism
060:     auto data2 = std::make_shared<Data>(*data1);
061: 
062:     data1->print();
063:     data2->print();
064: 
065:     data1->number1 = 999; // independent objects; data2 is unaffected
066: 
067:     data1->print();
068:     data2->print();
069: 
070:     std::println();
071: }
072: 
073: class MoreData {
074: public:
075:     int number = 123;
076:     // Managed as a shared resource to emulate Python's reference behavior
077:     std::shared_ptr<std::vector<int>> numbers;
078: 
079:     MoreData() {
080:         numbers = std::make_shared<std::vector<int>>(std::vector<int>{123, 456, 789});
081:     }
082: 
083:     void print() const {
084: 
085:         std::println("number:  {}", number);
086:         std::print("numbers: [");
087:         for (size_t i = 0; i < numbers->size(); ++i) {
088:             // std::cout << (*numbers)[i] << (i < numbers->size() - 1 ? ", " : "");
089:             std::print("{}{}", (*numbers)[i], (i < numbers->size() - 1) ? ", " : "");
090:         }
091:         std::println("]");
092:     }
093: };
094: 
095: // --- 1. Reference Assignment ---
096: // data1 and data2 point to the exact same MoreData instance.
097: static void example_moredata_01()
098: {
099:     auto data1 = std::make_shared<MoreData>();
100:     auto data2 = data1; // Alias pointer
101: 
102:     data1->print();
103:     data2->print();
104: 
105:     data1->number = 888;
106:     (*data1->numbers)[1] = 999; // Mutates the shared list
107: 
108:     data1->print();
109:     data2->print(); // BOTH changes are visible here
110:     std::println();
111: }
112: 
113: // --- 2. Shallow Copy ---
114: // Allocates a new MoreData object, but copies the member references (pointers) as-is.
115: static void example_moredata_02()
116: {
117:     auto data1 = std::make_shared<MoreData>();
118: 
119:     // Default compiler copy constructor: copies 'number' by value, 
120:     // and copies the 'numbers' shared_ptr by reference count!
121:     auto data2 = std::make_shared<MoreData>(*data1);
122: 
123:     data1->print();
124:     data2->print();
125: 
126:     data1->number = 888;        // Only data1 changes (primitive int value)
127:     (*data1->numbers)[1] = 999; // Modifies the shared heap vector!
128: 
129:     data1->print();
130:     data2->print(); // data2 sees the vector change, but NOT the 'number' change
131:     std::println();
132: }
133: 
134: // --- 3. Deep Copy ---
135: // Allocates a new MoreData object AND fully duplicates nested heap structures.
136: static void example_moredata_03()
137: {
138:     auto data1 = std::make_shared<MoreData>();
139:     auto data2 = std::make_shared<MoreData>();
140: 
141:     // Manual deep clone execution
142:     data2->number = data1->number;
143:     // Deep copy the vector data into a completely new heap allocation
144:     data2->numbers = std::make_shared<std::vector<int>>(*data1->numbers);
145: 
146:     data1->print();
147:     data2->print();
148: 
149:     data1->number = 888;
150:     (*data1->numbers)[1] = 999; // Modifies data1's private vector
151: 
152:     data1->print();
153:     data2->print(); // data2 remains completely unaffected ([123, 456, 789])
154:     std::println();
155: }
```


---

## Realisierung in Python

```python
01: import copy
02: 
03: class Data :
04:     def __init__(self):
05:         self.number1 = 123
06:         self.number2 = 456
07:     def print(self):
08:         print(f"number1: {self.number1}")
09:         print(f"number2: {self.number2}")
10: 
11: def example_data_01():
12:     data1 = Data()
13:     data2 = data1
14:     data1.print()
15:     data2.print()
16:     data1.number1 = 999
17:     data1.print()
18:     data2.print()
19:     print()
20: 
21: def example_data_02():
22:     data1 = Data()
23:     data2 = copy.copy(data1) 
24:     data1.print()
25:     data2.print()
26:     data1.number1 = 999
27:     data1.print()
28:     data2.print()
29:     print()
30: 
31: def example_data_03():
32:     data1 = Data()
33:     data2 = copy.deepcopy(data1) 
34:     data1.print()
35:     data2.print()
36:     data1.number1 = 999
37:     data1.print()
38:     data2.print()
39:     print()
40: 
41: example_data_01()
42: example_data_02()
43: example_data_03()
44: 
45: class MoreData :
46:     def __init__(self):
47:         self.number = 123
48:         self.numbers = [123, 456, 789]
49:     def print(self):
50:         print(f"number:  {self.number}")
51:         print(f"numbers: {self.numbers}")
52: 
53: def example_more_data_01():
54:     data1 = MoreData()
55:     data2 = data1
56:     data1.print()
57:     data2.print()
58:     data1.number = 888
59:     data1.numbers[1] = 999
60:     data1.print()
61:     data2.print()
62:     print()
63: 
64: def example_more_data_02():
65:     data1 = MoreData()
66:     data2 = copy.copy(data1) 
67:     data1.print()
68:     data2.print()
69:     data1.number = 888
70:     data1.numbers[1] = 999
71:     data1.print()
72:     data2.print()
73:     print()
74: 
75: def example_more_data_03():
76:     data1 = MoreData()
77:     data2 = copy.deepcopy(data1) 
78:     data1.print()
79:     data2.print()
80:     data1.number = 888
81:     data1.numbers[1] = 999
82:     data1.print()
83:     data2.print()
84:     print()
85: 
86: example_more_data_01()
87: example_more_data_02()
88: example_more_data_03()
```

---

[Zurück](../../Readme.md)

---
