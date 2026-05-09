# Dictionaries

[Zurück](../../Readme.md)

---

Ein Dictionary in Python ist eine geordnete, veränderbare Ansammlung von Schlüssel-Wert-Paaren (*Key*-*Value* Paaren),
die in geschweiften Klammern `{}` definiert wird. Es ermöglicht einen schnellen Zugriff auf Daten,
indem man statt eines numerischen Index (wie bei Listen) einen eindeutigen Schlüssel (*Key*) verwendet,
um den dazugehörigen Wert (*Value*) abzurufen.

---

## Eine einfache Gegenüberstellung

### Realisierung in Python

```python
01: cities_inhabitants = {
02:     "Berlin": 3669491,
03:     "Hamburg": 1847253,
04:     "Muenchen": 1484226,
05:     "Koeln": 1087863,
06:     "Frankfurt am Main": 763380,
07:     "Stuttgart": 635911,
08:     "Duesseldorf": 621877,
09:     "Leipzig": 593145,
10:     "Dortmund": 588250,
11:     "Essen": 582760,
12:     "Bremen": 567559,
13:     "Dresden": 556780,
14:     "Hanover": 536925,
15:     "Nuernberg": 518370
16: }
17: 
18: print(cities_inhabitants)
```

#### Realisierung in C++

```cpp
01: void example_dict()
02: {
03:     std::unordered_map<std::string, int> cities_inhabitants = {
04:         { "Berlin", 3669491 },
05:         { "Hamburg", 1847253 },
06:         { "Muenchen", 1484226 },
07:         { "Koeln", 1087863 },
08:         { "Frankfurt am Main", 763380 },
09:         { "Stuttgart", 635911 },
10:         { "Duesseldorf", 621877 },
11:         { "Leipzig", 593145 },
12:         { "Dortmund", 588250 },
13:         { "Essen", 582760 },
14:         { "Bremen", 567559 },
15:         { "Dresden", 556780 },
16:         { "Hanover", 536925 },
17:         { "Nuernberg", 518370 }
18:     };
19: 
20:     for (const auto& [city, population] : cities_inhabitants) {
21:         std::println("{:20}: {}", city, population);
22:     }
23: 
24:     cities_inhabitants["Nuernberg"] = 546'397;
25: }
```

*Ausgabe*:

```
Berlin              : 3669491
Leipzig             : 593145
Duesseldorf         : 621877
Stuttgart           : 635911
Hamburg             : 1847253
Muenchen            : 1484226
Koeln               : 1087863
Frankfurt am Main   : 763380
Dortmund            : 588250
Essen               : 582760
Bremen              : 567559
Dresden             : 556780
Hanover             : 536925
Nuernberg           : 518370
```

---

[Zurück](../../Readme.md)

---
