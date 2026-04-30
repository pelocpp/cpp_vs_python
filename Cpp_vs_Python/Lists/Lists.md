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
05:     std::print("[");
06:     for (auto i{ 0 }; auto n : list) {
07:         if (i != list.size() - 1) {
08:             std::print("{}, ", n);
09:             ++i;
10:         }
11:     }
12:     if (list.size() != 0) {
13:         std::print("{}", list.back());
14:     }
15:     std::print("]");
16: }
```

*Ausgabe*:

```
[1, 2, 3, 4, 5]
```

Wir müssen beim Vergleich der beiden Realisierungen etwas *Fair Play* walten lassen:
Python unterstützt in der *built-in* Funktion `print` eine Ausgabe von Listen,
das ist bei C++ so nicht der Fall.

Deshalb können wir hier die Daten
in einem `std::vector`-Objekt ablegen und müssen für die Ausgabe eine
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

#### Realisierung in C++

```cpp
01: void example_lists()
02: {
03:     std::vector<std::variant<std::string, int>> list = {
04:         "Hans", 123, "Sepp", 124 
05:     };
06: 
07:     std::print("[");
08:     for (auto i{ 0 }; const auto& elem : list) {
09:         if (i != list.size() - 1) {
10:             std::visit(
11:                 [](const auto& value) {
12:                     std::print("{}, ", value);
13:                 },
14:                 elem
15:             );
16:             ++i;
17:         }
18:     }
19:     if (list.size() != 0) {
20:         std::visit(
21:             [](const auto& value) {
22:                 std::print("{}", value);
23:             },
24:             list.back()
25:         );
26:     }
27:     std::print("]");
28: }
```

*Ausgabe*:

```
['Hans', 123, 'Sepp', 123]
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

[Zurück](../../Readme.md)

---
