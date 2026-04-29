# Beispiel zur Zinsrechnung

[Zurück](../Readme.md)

---

## Realisierung in C++

```cpp
01: void example_zinsrechnung()
02: {
03:     auto capitalStock { 1000.0 };
04:     auto startCapitalStock{ capitalStock };
05:     auto interestRate{ 5.0 };
06:     auto numberYears{ 10 };
07: 
08:     std::println("Zinstabelle fuer Grundkapital {:.2f}", capitalStock);
09:     std::println("Verzinsung:                   {:.2f}%", interestRate);
10:     std::println("=====================================");
11:     std::println();
12:     std::println("Kapitalstand zum Jahresende:");
13: 
14:     auto year{ 0 };
15: 
16:     while (year < numberYears)
17:     {
18:         double interest{ (capitalStock / 100.0) * interestRate };
19:         capitalStock += interest;
20:         std::println("Jahr: {:2}    Kapital: {:.2f}", (year + 1), capitalStock);
21:         ++year;
22:     }
23: 
24:     std::println();
25:     std::println("Aus {:.2f} Grundkapital wurden in {} Jahren {:.2f} Euro.\n",
26:         startCapitalStock, year, capitalStock);
27: }
```


## Realisierung in Python

```python
01: def main_zinsberechnung():
02:     capital_stock = 1000.0
03:     start_capital_stock = capital_stock
04:     interest_rate = 5.0
05:     number_years = 10
06: 
07:     print(f"Zinstabelle fuer Grundkapital {capital_stock:.2f}")
08:     print(f"Verzinsung:                   {interest_rate:.2f}%")
09:     print("=====================================")
10:     print()
11:     print("Kapitalstand zum Jahresende:")
12: 
13:     year = 0
14: 
15:     while year < number_years:
16:         interest = (capital_stock / 100.0) * interest_rate
17:         capital_stock += interest
18:         print(f"Jahr: {year + 1:2}    Kapital: {capital_stock:.2f}")
19:         year += 1
20: 
21:     print()
22:     print(f"Aus {start_capital_stock:.2f} Grundkapital wurden in {year} Jahren {capital_stock:.2f} Euro.\n")
```

*Hinweise*:

  * In der Portierung des C++ Beispiels nach Python wurden &bdquo;f-Zeichenketten&rdquo; verwendet,
  um die Formatierung der C++&ndash;`std::println`-Befehle (wie Nachkommastellen und Spaltenbreiten) beizubehalten.

  * In Python schreibt man Variablennamen üblicherweise in `snake_case` (kleingeschrieben mit Unterstrichen),
  während C++ oft `camelCase` nutzt.

---

[Zurück](../Readme.md)

---
