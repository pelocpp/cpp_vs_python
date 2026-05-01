# Listen

[Zurück](../../Readme.md)

---

Der *built-in* Datentyp *List* ist in C++ nicht unmittelbar nachahmbar.
Zwar gibt es in C++ eine Reihe sehr ähnlicher Datentypen (`std::array`, `std::vector`),
aber Python Listen sind heterogen.
Sie können verschiedene Datentypen speichern und dynamisch ihre Größe anpassen,
während C++ Container statisch typisiert ist.

---

## Eine einfache Gegenüberstellung

### Homogenität: Identische Datentypen in einer Liste

#### Realisierung in Python

```python
01: list = [1, 2, 3, 4, 5]
02: print(list) 
```

#### Realisierung in C++

```cpp
01: void example_lists()
02: {
03:     std::vector list = { 1, 2, 3, 4, 5 };
04: 
05:     auto print_list = [](const auto& list) {
06:         std::print("[");
07:         for (size_t i{}; i != list.size(); ++i) {
08:             std::print("{}{}", list[i], (i == list.size() - 1) ? "" : ", ");
09:         }
10:         std::println("]");
11:     };
12: 
13:     print_list(list);
14: }
```

*Ausgabe*:

```
[1, 2, 3, 4, 5]
```

Wir müssen beim Vergleich der beiden Realisierungen etwas *Fair Play* walten lassen:
Python unterstützt in der *built-in* Funktion `print` eine Ausgabe von Listen,
das ist bei C++ so nicht der Fall.
Deshalb müssen wir in diesem Fall für die Ausgabe eine
entsprechende Funktion selbst schreiben.

Da wir so nebensächliche Dinge wie die Ausgabe eines Komma zwischen zwei Elementen,
aber nicht nach dem letzten Element, sauber durchführen wollen,
zieht sich eine händische C++&ndash;Realisierung etwas in die Länge.

Dies trifft ebenso zu, wenn wir nun heterogene Listen (Python) / Container (C++) anschauen.

---

### Heterogenität: Verschiedene Datentypen in einer Liste

#### Realisierung in Python

```python
list = ["Hans", 123, "Sepp", 123]
print(list) 
```

*Ausgabe*:

```
['Hans', 123, 'Sepp', 123]
```

#### Realisierung in C++

```cpp
01: void example_lists()
02: {
03:     std::vector<std::variant<std::string, int>> list = { "Hans", 123, "Sepp", 124 };
04: 
05:     auto print_list = [](const auto& list) {
06:         std::print("[");
07:         for (size_t i{}; i != list.size(); ++i) {
08:             std::visit(
09:                 [i,&list](const auto& value) {
10:                     std::print("{}{}", value, (i == list.size() - 1) ? "" : ", ");
11:                 },
12:                 list[i]
13:             );
14:         }
15:         std::println("]");
16:     };
17: 
18:     print_list(list);
19: }
```

*Ausgabe*:

```
[Hans, 123, Sepp, 123]
```

---

## List Comprehension

In Python kann man Listen mit der so genannten *List Comprehension*
in einem Zug filtern und transformieren.

Dieses auch als &bdquo;pythonisches&rdquo; Verfahren bezeichnete Schreibweise
ist die bevorzugte Methode, da sie prägnant ist
und das Filtern und Transformieren in einer einzigen Zeile ermöglicht:


#### Realisierung in Python

```python
01: numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
02: result = [x*x for x in numbers if x % 2 == 0]
03: print(result)
```

#### Realisierung in C++

```cpp
01: static void example_lists_03_list_comprehension()
02: {
03:     std::vector numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
04: 
05:     auto view = numbers
06:         | std::views::filter([](int x) { return x % 2 == 0; })
07:         | std::views::transform([](int x) { return x * x; });
08: 
09:     std::vector<int> result{ view.begin(), view.end() };
10: 
11:     for (int x : result) {
12:         std::print("{} ", x);
13:     }
14: }
```

*Ausgabe*:

```
4 16 36 64 100
```

Bemerkung:<br />
Die Ausgabe des C++&ndash;Fragments unterscheidet sich geringfügig von der des
Python&ndash;Fragments. Die öffnende und schließenden Klammer und die Kommas
lasse ich von nun ab der Einfachheit halber weg.

---

## Listen traversieren

#### Realisierung in Python

  * *Loop Through List Items with For Loop*

```python
01: numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
02: for x in numbers:
03:     print(x, end = " ")
```

  * *Loop Through List Items with Index*

```python
01: numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
02: indices = range(len(numbers))
03: for i in indices:
04:    print ("numbers[{}]: ".format(i), numbers[i])
```

  * *Iterate using List Comprehension*

```python
01: numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
02: [print(x, end = " - ") for x in numbers]
```

  * *Iterate using the enumerate() Function*

```python
01: numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
02: for index, x in enumerate(numbers):
03:    print(index, x, end = " - ")
```

#### Realisierung in C++

```cpp
01: void example_lists()
02: {
03:     std::vector numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
04: 
05:     for (int x : numbers) {
06:         std::print("{} ", x);
07:     }
08: }
```

*Ausgabe*:

```
1 2 3 4 5 6 7 8 9 10
```

---

##  Slicing Lists

Slicing bietet eine leistungsstarke Methode, um eine Teilmenge von Elementen aus einer Liste zu extrahieren.
Die Syntax für Slicing lautet `[start:stop:step]`,
wobei `start` inklusive und `stop` exklusiv ist.
Der optionale `step` definiert das Intervall zwischen den Elementen.

### Realisierung in Python

```python
01: fruits = ['apple', 'banana', 'cherry', 'strawberry', 'pear', 'pineapple']
02: print(fruits)
03: 
04: first_two = fruits[0:2]                # Gets the first two items
05: print(first_two)
06: 
07: remaining_fruits = fruits[2:]          # Gets every remaining items
08: print(remaining_fruits)
```

*Ausgabe*:

```
['apple', 'banana', 'cherry', 'strawberry', 'pear', 'pineapple']
['apple', 'banana']
['cherry', 'strawberry', 'pear', 'pineapple']
```

### Realisierung in C++

```cpp
01: void example_lists()
02: {
03:     // 1. create original list
04:     std::vector<std::string> fruits = { "apple", "banana", "cherry", "strawberry", "pear", "pineapple" };
05: 
06:     // 2. simulate sclicing "fruits[0:2]" / first two elements
07:     std::vector<std::string> first_two(fruits.begin(), fruits.begin() + 2);
08: 
09:     // 3. simulate sclicing "fruits[2:]" / last elements
10:     std::vector<std::string> remaining_fruits(fruits.begin() + 2, fruits.end());
11: 
12:     // output-function
13:     auto print_list = [](const std::vector<std::string>& vec) {
14:         std::print("[");
15:         for (size_t i{}; i != vec.size(); ++i) {
16:             std::print("\"{}\"{}", vec[i], (i == vec.size() - 1) ? "" : ", ");
17:         }
18:         std::println("]");
19:     };
20: 
21:     print_list(fruits);
22:     print_list(first_two);
23:     print_list(remaining_fruits);
24: }
```

---

[Zurück](../../Readme.md)

---
