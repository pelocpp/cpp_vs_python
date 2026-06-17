# Enumerationen

[Zurück](../../Readme.md)

---

Die Funktion `enumerate()` ist eine in Python integrierte Funktion, die ein iterierbares Objekt
(eine Sammlung von Elementen oder ein beliebiges anderes Python-Objekt, das Iteration unterstützt,
wie etwa Tupel, Listen, Mengen oder Zeichenketten) entgegennimmt,
dessen Elemente intern durchläuft und ein `enumerate`-Objekt zurückgibt.

Mit anderen Worten: Diese Funktion weist jedem Element des iterierbaren Objekts einen Zähler zu,
der bei jedem Schritt um 1 erhöht wird, und ermöglicht es uns so, den Fortschritt der Iteration
beim Durchlaufen des Objekts zu verfolgen.

Nach der Erstellung des `enumerate`-Objekts lässt sich dieses in eine Liste,
ein Tupel oder ein Dictionary umwandeln (mithilfe der Funktionen `list()`, `tuple()` bzw. `dict()`)
oder direkt durchlaufen, um sowohl auf die Elemente als auch auf die zugehörigen Indizes zuzugreifen.

Die Verwendung der Funktion `enumerate()` ist im Hinblick auf Speicher- und Recheneffizienz vorteilhafter
gegenüber herkömmlichen `for`-Schleifen, da sie den Index und das zugehörige Element in einem einzigen Schritt liefert.

---

## Eine einfache Gegenüberstellung

#### Realisierung in Python

```python
01: cities = [
02:     "Berlin",
03:     "Hamburg",
04:     "Muenchen",
05:     "Koeln"
06: ]
07: 
08: print(cities)  # printing the list directly
09: print()
10: 
11: # =====================================================================================
12: # enumerating a list
13: 
14: enumerated_cities = enumerate(cities)
15: list_enumerated_cities = list(enumerated_cities)
16: print(list_enumerated_cities)
17: print()
18: 
19: enumerated_cities = enumerate(cities, start = 1)
20: list_enumerated_cities = list(enumerated_cities)
21: print(list_enumerated_cities)
22: print()
23: 
24: # =====================================================================================
25: # enumerating a list without creating another list object
26: 
27: enumerated_cities = enumerate(cities)
28: print(next(enumerated_cities))
29: print(next(enumerated_cities))
30: print(next(enumerated_cities))
31: print(next(enumerated_cities))
32: print()
33: 
34: # =====================================================================================
35: # enumerating through a list with a for-Loop
36: 
37: for item in enumerate(cities):
38:   print(item)
39: print()
40: 
41: for item in cities:
42:   print(item)
43: print()
44: 
45: print(cities)
```

#### Realisierung in C++

```cpp
001: // standard vector as equivalent of a Python list
002: static std::vector<std::string> cities = {
003:     "Berlin", "Hamburg", "Muenchen", "Koeln" 
004: };
005: 
006: // helper function for pretty-printing pairs
007: static void print_pair(const std::pair<std::size_t, std::string>& p) {
008:     std::print("({}, {})", p.first, p.second);
009: }
010: 
011: static void example_enumeration_01()
012: {
013:     // direct printing of the list
014:     std::print("[");
015:     for (std::size_t i{}; i < cities.size(); ++i) {
016:         std::println("'{}'{}", cities[i], (i < cities.size() - 1) ? ", " : "");
017:     }
018:     std::print("]");
019:     std::println();
020: }
021: 
022: static void example_enumeration_02()
023: {
024:     // =====================================================================================
025:     // 1. Enumerating a list (starting with 0)
026:     //    std::views::enumerate creates a lazy view (iterator), just like Python's enumerate():
027:     auto enumerated_cities = std::views::enumerate(cities);
028: 
029:     // conversion into a concrete "list object" (std::vector of std::pair)
030:     std::vector<std::pair<std::size_t, std::string>> list_enumerated_cities(
031:         enumerated_cities.begin(), 
032:         enumerated_cities.end()
033:     );
034: 
035:     std::print("[");
036:     for (std::size_t i{}; i < list_enumerated_cities.size(); ++i) {
037:         print_pair(list_enumerated_cities[i]);
038:         if (i < list_enumerated_cities.size() - 1) {
039:             std::print(", ");
040:         }
041:     }
042:     std::print("]");
043:     std::println();
044: }
045: 
046: 
047: static void example_enumeration_03()
048: {
049:    // 2. Enumerating a list with a start index of 1
050:    //    In C++20, we use transform() to subsequently increment the view's index by 1:
051: 
052:     //auto enumerated_cities =
053:     //    std::views::enumerate(cities) |
054:     //    std::views::transform([](/*auto*/ const std::pair<std::size_t, std::string>& p) {
055:     //        return std::make_pair(p.first + 1, p.second);
056:     //    });
057: 
058:     auto enumerated_cities =
059:         std::views::enumerate(cities) |
060:         std::views::transform([](const auto& proxy) {
061: 
062:             // Note: implementation detail:
063:             // std::views::enumerate doesn't hand to the lambda a std::pair;
064:             // it hands a proxy/tuple-like element that supports structured binding and get<>,
065:             // but does not expose .first/.second.
066:             // With MSVC: it's a std::tuple
067:             // When you write the parameter as an explicit std::pair
068:             // it forces a conversion to a pair (so .first works).
069:             // 
070:             // If you use auto the parameter is deduced to the proxy type
071:             // and p.first is not a member — compile error
072: 
073:             const auto& [first, second] = proxy;
074: 
075:             return std::make_pair(first + 1, second);
076:         }
077:     );
078: 
079:     std::vector<std::pair<std::size_t, std::string>> list_enumerated_cities(
080:         enumerated_cities.begin(),
081:         enumerated_cities.end()
082:     );
083: 
084:     std::print("[");
085:     for (std::size_t i{}; i < list_enumerated_cities.size(); ++i) {
086:         print_pair(list_enumerated_cities[i]);
087:         if (i < list_enumerated_cities.size() - 1) {
088:             std::print(", ");
089:         }
090:     }
091:     std::print("]");
092:     std::println();
093: }
094: 
095: static void example_enumeration_04()
096: {
097:     // =====================================================================================
098:     // 3. Enumerating a list without creating a new list object (manually advancing via an iterator)
099:     //    This corresponds exactly to Python's `next()` principle for iterators:
100:     
101:     auto enum_view = std::views::enumerate(cities);
102:     auto it = enum_view.begin();
103: 
104:     print_pair(*it); std::println(); ++it; // next(1)
105:     print_pair(*it); std::println(); ++it; // next(2)
106:     print_pair(*it); std::println(); ++it; // next(3)
107:     print_pair(*it); std::println();       // next(4)
108:     std::println();
109: }
110: 
111: static void example_enumeration_05()
112: {
113:     // =====================================================================================
114:     // 4. Iterating through a list with a for-loop
115:     //    In C++, structured binding (auto [index, value]) is used for this:
116: 
117:     for (auto [index, city] : std::views::enumerate(cities)) {
118:         std::println("({}, {})", index, city);
119:     }
120:     std::println();
121: 
122:     // pure value loop without index
123:     for (const auto& city : cities) {
124:         std::println("{}", city);
125:     }
126:     std::println();
127: }
```

*Ausgabe*:

```
['Berlin', 'Hamburg', 'Muenchen', 'Koeln']

[(0, 'Berlin'), (1, 'Hamburg'), (2, 'Muenchen'), (3, 'Koeln')]

[(1, 'Berlin'), (2, 'Hamburg'), (3, 'Muenchen'), (4, 'Koeln')]

(0, 'Berlin')
(1, 'Hamburg')
(2, 'Muenchen')
(3, 'Koeln')

(0, 'Berlin')
(1, 'Hamburg')
(2, 'Muenchen')
(3, 'Koeln')

Berlin
Hamburg
Muenchen
Koeln

['Berlin', 'Hamburg', 'Muenchen', 'Koeln']
```

---

[Zurück](../../Readme.md)

---
