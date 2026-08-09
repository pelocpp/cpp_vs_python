# Tuples

[Zurück](../../Readme.md)

---

Der *built-in* Datentyp *Tuple* ist in C++ prinzipiell mit der Klasse `std::tuple` direkt nachahmbar.
Allerdings gibt es einen wesentlichen Unterschied:
Die Werte eines C++ Tupels sind änderbar (*mutable*).
Python Tupel unterstützen keine Mutationen oder Änderungen an den darin enthaltenen Elementen (*immutable*).

---

## Eine einfache Gegenüberstellung

### Realisierung in Python

```python
01: susan = ("Susan Meier", 25, 1.75, "Germany")
```

### Realisierung in C++

```cpp
01: auto susan = std::make_tuple<std::string, std::size_t, double, std::string>(
02:     "Susan Meier", 25, 1.75, "Germany"
03: );
```

---

## Zugriff auf Elemente in einem Tupel

### Realisierung in Python

```python
01: susan = ("Susan Meier", 25, 1.75, "Germany")
02: 
03: name = susan[0]
04: age = susan[1]
05: size = susan[2]
06: country = susan[3]
```

### Realisierung in C++

```cpp
01: auto susan = std::make_tuple<std::string, std::size_t, double, std::string>(
02:     "Susan Meier", 25, 1.75, "Germany"
03: );
04: 
05: const auto& name = std::get<0>(susan);
06: auto age = std::get<1>(susan);
07: auto size = std::get<2>(susan);
08: const auto& country = std::get<3>(susan);
```

Ein etwas komplexeres Beispiel:

### Realisierung in Python

```python
01: # tuple containing a list
02: employee = (
03:     "John",
04:     35,
05:     "Python Developer",
06:     ["Django", "Flask", "FastAPI", "CSS", "HTML"]
07: )
08: 
09: # accessing the first skill
10: firstSkill = employee[3][0]
11: firstSkill = employee[-1][0]
```

### Realisierung in C++

```cpp
01: auto employee = std::make_tuple<std::string, std::size_t, std::string, std::vector<std::string>>(
02:     "John",
03:     35,
04:     "Python Developer",
05:     { "Django", "Flask", "FastAPI", "CSS", "HTML" }
06: );
07: 
08: const auto& firstSkill = std::get<3>(employee)[0];
```

---

[Zurück](../../Readme.md)

---
