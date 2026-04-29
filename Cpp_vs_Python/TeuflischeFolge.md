# Teuflische Folge

[Zurück](../Readme.md)

---

## Realisierung in C++

Zum Testen des Beispiels sind `7` und `27` geeignete Startwerte:

```cpp
01: static void berechne_teuflische_folge(int start);
02: 
03: void example_teuflische_folge()
04: {
05:     std::println("Teuflische Zahlenfolge");
06:     std::println("======================");
07:     std::println();
08:     
09:     std::print("Startwert: ");
10:     std::string input;
11:     std::cin >> input;
12:     int number = std::stoi(input);
13: 
14:     berechne_teuflische_folge(number);
15: }
16: 
17: void berechne_teuflische_folge(int start)
18: {
19:     auto number{ start };   // start number
20:     auto n{ 1 };            // counter for length of sequence
21: 
22:     while (number != 1)
23:     {
24:         if (number % 2 == 0)
25:         {
26:             number = number / 2;
27:         }
28:         else
29:         {
30:             number = 3 * number + 1;
31:         }
32: 
33:         std::println("Schritt {:3}: Zahl = {}", n, number);
34:         n++;
35:     }
36: }
```


## Realisierung in Python

```python
01: def example_teuflische_folge(start_number=7):
02:     print("Teuflische Zahlenfolge\n")
03:     print("======================\n")
04: 
05:     number = start_number   # Startzahl
06:     n = 1                   # Zaehler fuer die Laenge der Folge
07: 
08:     print(f"Startzahl: {number}")
09:     print()
10: 
11:     while number != 1:
12:         if number % 2 == 0:
13:             number //= 2                # Ganzzahl-Division
14:         else:
15:             number = 3 * number + 1
16: 
17:         print(f"Schritt {n:3}: Zahl = {number}")
18:         n += 1
19: 
20: if __name__ == "__main__":
21:     example_teuflische_folge(7)
22: 
23: if __name__ == "__main__":
24:     # Benutzereingabe in eine int-Variable umwandeln
25:     value = int(input("Startzahl: "))
26:     example_teuflische_folge(value)
```

*Hinweise*:

  * In Python wandelt ein einfacher Schrägstrich `/` das Ergebnis
  in eine Fließkommazahl (`float`) um (aus `8` würde `4.0`).

  * Mit `//` bleibt die Zahl ein Integer, genau wie im C++ Beispiel.
  Der Operator `//` steht also für eine Ganzzahl-Division.

  * Die interne Funktion `input()` liest die Eingabe als Text (String).

  * Die interne Funktion `int()` wandelt diesen Text in eine ganze Zahl um.

---

[Zurück](../Readme.md)

---
