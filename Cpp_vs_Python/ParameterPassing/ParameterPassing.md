# Parameter Passing

[Zurück](../../Readme.md)

---

## Realisierung in C++


```cpp
01: static void malZwei(int n)
02: {
03:     n = 2 * n;
04: }
05: 
06: static void malZweiByAdress(int* n)
07: {
08:     *n = 2 * *n;
09: }
10: 
11: static void malZweiByReference(int& n)
12: {
13:     n = 2 * n;
14: }
```

Ein kleines Beispiel für eine Anwendung der drei Funktionen `malZwei`, `malZweiByAdress` und `malZweiByReference`:

```cpp
01: static void test_malZwei()
02: {
03:     int x = 10;
04: 
05:     std::println("x: {}", x);
06: 
07:     malZweiByAdress(&x);
08:     std::println("x: {}", x);
09: 
10:     malZweiByReference(x);
11:     std::println("x: {}", x);
12: }
```

*Ausgabe*:<br />

```
x: 10
x: 20
x: 40
```

## Realisierung in Python

```python
01: def malZwei(a):
02:     a = 2 * a
03: 
04: x = 10
05: print(f"x: {x}")
06: 
07: malZwei(x)
08: print(f"x: {x}")
```


*Ausgabe*:<br />

```
x: 10
x: 10
```

Warum gibt der Python-Code 10 aus?

  * Eine Neuzuweisung erzeugt ein neues Objekt: Innerhalb der Funktion `malZwei` erstellt die Zeile `a = 2 * a` ein vollkommen neues Integer-Objekt.
  * Die lokale Variable wird neu gebunden: Der lokale Name `a` verweist nun auf dieses neue Objekt, während die ursprüngliche Variable `x` außerhalb der Funktion unverändert bleibt.


---

[Zurück](../../Readme.md)

---
