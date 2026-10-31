# Zeichenketten

[Zurück](../../Readme.md)

---

## Realisierung in C++

```cpp
01: void example_strings()
02: {
03:     std::string s = "12345";
04:     std::println("String: {}", s);
05: 
06:     // len
07:     size_t length = s.length(); // oder s.size()
08:     bool empty = s.empty();
09:     std::println("Length: {} - Empty: {}", length, empty);
10: 
11:     // find
12:     size_t pos = s.find("3");
13:     if (pos != std::string::npos) {
14:         std::println("Pos: {}", pos);
15:     }
16: 
17:     // replace
18:     size_t replacePos = s.find("3");
19:     if (replacePos != std::string::npos) {
20:         s.replace(replacePos, 1, "ABABA"); // pos, len, new string     
21:     }
22:     std::println("String: {}", s);
23: 
24:     // count
25:     std::size_t count = std::count(s.begin(), s.end(), 'A');
26:     std::println("Count: {}", count);
27: 
28:     // startswith (use rfind with index 0)
29:     bool n = (s.rfind("12", 0) == 0);
30:     std::println("startswith: {}", n);
31: 
32:     // endswith
33:     bool ends = false;
34:     if (s.length() >= 1) {
35:         ends = (s.compare(s.length() - 1, 1, "X") == 0);
36:     }
37:     std::println("endswith: {}", n);
38: 
39:     // insert
40:     if (s.length() >= 5) {
41:         s.insert(5, "XYZ");
42:     }
43:     std::println("String: {}", s);
44: 
45:     // append
46:     s += "!!!";
47:     std::println("String: {}", s);
48: 
49:     // equals
50:     std::string s1 = "12345";
51:     std::string s2 = "12345";
52:     std::string s3 = "123456";
53: 
54:     n = (s1 == s2);
55:     std::println("equals s1==s2: {}", n);
56:     n = (s1 == s3);
57:     std::println("equals s1==s3: {}", n);
58: 
59:     // string to int
60:     std::string number = "123";
61:     int value = std::stoi(number);
62:     std::println("Number: {}", value);
63: }
```

*Ausgabe*:<br />

```
String: 12345
Length: 5 - Empty: false
Pos: 2
String: 12ABABA45
Count: 3
startswith: true
endswith: true
String: 12ABAXYZBA45
String: 12ABAXYZBA45!!!
equals s1==s2: true
equals s1==s3: false
Number: 123
```

---

## Realisierung in Python

```python
def strings_demo():
    s = "12345"
    print(f"String: {s}")

    # len
    length = len(s)
    empty = len(s) == 0
    print(f"Length: {length} - Empty: {empty}")

    # find
    pos = s.find("3")
    print(f"Pos: {pos}")

    # replace
    s = s.replace("3", "ABABA")
    print(f"String: {s}")
    
    # count
    count = s.count("A");
    print(f"Count: {count}")
  
    # startswith
    n = s.startswith("12")
    print(f"startswith: {n}")

    # endswith
    n = s.endswith("X")
    print(f"endswith: {n}")

    # insert
    s = s[:5] + "XYZ" + s[5:]
    print(f"String: {s}")
    
    # append
    s += "!!!"
    print(f"String: {s}")
    
    # equals
    s1 = "12345"
    s2 = "12345"
    s3 = "123456"

    n = (s1 == s2)
    print(f"equals s1==s2: {n}")
    n = (s1 == s3)
    print(f"equals s1==s2: {n}")

    number = "123"
    value = int(number)
    print(f"Number: {number}")
```


*Ausgabe*:<br />

```
String: 12345
Length: 5 - Empty: False
Pos: 2
String: 12ABABA45
Count: 3
startswith: True
endswith: False
String: 12ABAXYZBA45
String: 12ABAXYZBA45!!!
equals s1==s2: True
equals s1==s2: False
Number: 123
```

---

[Zurück](../../Readme.md)

---
