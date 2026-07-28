# Unterprogramme (Prozeduren / Funktionen)

[Zurück](../../Readme.md)

---

## Realisierung in C++

```cpp
01: void sayHello(std::size_t count, const std::string& message)
02: {
03:     for (std::size_t i{}; i != count; ++i) {
04:         std::println("{}", message);
05:     }
06:     std::println();
07: }
08: 
09: void example_01()
10: {
11:     sayHello(2, "I'm saying Hello :)");
12:     sayHello(3, "... and Goodbye!");
13: }
14: 
15: std::size_t powerOf(std::size_t base, std::size_t exponent)
16: {
17:     std::size_t result{ 1 };
18: 
19:     for (std::size_t i{}; i != exponent; ++i) {
20:         result *= base;
21:     }
22: 
23:     return result;
24: }
25: 
26: void example_02()
27: {
28:     std::size_t base{ 2 };
29:     std::size_t exponent{ 5 };
30:     std::size_t result{};
31: 
32:     result = powerOf(base, exponent);
33:     std::println("{} to the power of {}: {}", base, exponent, result);
34: }
```

---

## Realisierung in Python

In Python kann man zwei Realisierungen unterscheiden:

  * Eine minimale Realisierung, die ohne Verwendung von Typ-Hinweisen auskommt.
  * Eine Realisierung mit Typ-Hinweisen.

Mit Typ-Hinweisen:

```python
01: def say_hello(count: int, message: str) -> None:
02:     for _ in range(count):
03:         print(message)
04:     print()
05: 
06: def example_01() -> None:
07:     say_hello(2, "I'm saying Hello :)")
08:     say_hello(3, "... and Goodbye!")
09: 
10: def power_of(base: int, exponent: int) -> int:
11:     result = 1
12:     for _ in range(exponent):
13:         result *= base
14:     return result
15: 
16: def example_02() -> None:
17:     base = 2
18:     exponent = 5
19:     
20:     result = power_of(base, exponent)
21:     print(f"{base} to the power of {exponent}: {result}")
22: 
23: example_01()
24: example_02()
```

Ohne Typ-Hinweise:

```python
01: def say_hello(count, message):
02:     for _ in range(count):
03:         print(message)
04:     print()
05: 
06: def example_01():
07:     say_hello(2, "I'm saying Hello :)")
08:     say_hello(3, "... and Goodbye!")
09: 
10: def power_of(base, exponent):
11:     result = 1
12:     for _ in range(exponent):
13:         result *= base
14:     return result
15: 
16: def example_02():
17:     base = 2
18:     exponent = 5
19:     
20:     result = power_of(base, exponent)
21:     print(f"{base} to the power of {exponent}: {result}")
22: 
23: example_01()
24: example_01()
```

*Ausgabe*:

```
I'm saying Hello :)
I'm saying Hello :)

... and Goodbye!
... and Goodbye!
... and Goodbye!
```

---

[Zurück](../../Readme.md)

---
