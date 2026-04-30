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
das ist bei C++ so nicht der Fall. Deshalb können wir hier die Daten
in einem `std::vector`-Objekt ablegen und müssen für die Ausgabe eine
entsprechende Funktion selbst schreiben.

Da wir so nebensächliche Dinge wie die Ausgabe eines Komma zwischen zwei Elementen,
aber nicht nach dem letzten Element, sauber durchführen wollen,
gerät eine händische C++&ndash;Rea

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
```

*Ausgabe*:

```
['Hans', 123, 'Sepp', 123]
```



---

[Zurück](../../Readme.md)

---
