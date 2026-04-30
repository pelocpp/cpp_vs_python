# Klasse `BankAccount`


[Zurück](../../Readme.md)

---

## Realisierung in C++

Wir benötigen zur Realisierung einer Klasse zwei Dateien:

*Header*-Datei:

```cpp
01: class BankAccount
02: {
03: private:
04:     std::size_t m_number;
05:     double      m_balance;
06: 
07: public:
08:     // c'tor
09:     BankAccount();
10:     BankAccount(double start);
11: 
12:     // getter / setter
13:     std::size_t getAccountNumber() const;
14:     double      getBalance() const;
15: 
16:     // public interface
17:     void deposit(double amount);
18:     void withdraw(double amount);
19:     bool equals(const BankAccount& other) const;
20: 
21:     // operators
22:     bool operator== (const BankAccount& other);
23:     bool operator!= (const BankAccount& other);
24:     bool operator<  (const BankAccount& other);
25:     bool operator<= (const BankAccount& other);
26:     bool operator>  (const BankAccount& other);
27:     bool operator>= (const BankAccount& other);
28: 
29: private:
30:     inline static std::size_t s_nextAccountNumber = 10'000;;
31: };
32: 
33: // output operator
34: std::ostream& operator<< (std::ostream& os, const BankAccount& other);
```

*Implementierungs*-Datei:

```cpp
01: // c'tor
02: BankAccount::BankAccount(double balance) 
03:     : m_number{ s_nextAccountNumber }, m_balance{ balance }
04: {
05:     // move to next available account number
06:     s_nextAccountNumber++;
07: }
08: 
09: BankAccount::BankAccount() : BankAccount{ 0.0 } {}
10: 
11: // getter / setter
12: std::size_t BankAccount::getAccountNumber() const
13: {
14:     return m_number;
15: }
16: 
17: double BankAccount::getBalance() const
18: {
19:     return m_balance;
20: }
21: 
22: // public interface
23: void BankAccount::deposit(double amount)
24: {
25:     m_balance += amount;
26: }
27: 
28: void BankAccount::withdraw(double amount)
29: {
30:     if (m_balance < amount)
31:         return;
32: 
33:     m_balance -= amount;
34: }
35: 
36: bool BankAccount::equals(const BankAccount& other) const
37: {
38:     if (m_balance == other.m_balance) {
39:         return true;
40:     }
41:     else {
42:         return false;
43:     }
44: }
45: 
46: // operators
47: bool BankAccount::operator== (const BankAccount& other) {
48: 
49:     if (m_balance == other.m_balance) {
50:         return true;
51:     }
52:     else {
53:         return false;
54:     }
55: }
56: 
57: bool BankAccount::operator!= (const BankAccount& other) {
58: 
59:     return !(*this == other);
60: }
61: 
62: bool BankAccount::operator<  (const BankAccount& other) {
63: 
64:     if (m_balance < other.m_balance) {
65:         return true;
66:     }
67:     else {
68:         return false;
69:     }
70: }
71: 
72: bool BankAccount::operator<= (const BankAccount& other) {
73: 
74:     return (*this < other || *this == other);
75: }
76: 
77: bool BankAccount::operator>  (const BankAccount& other) {
78: 
79:     return !(*this <= other);
80: }
81: 
82: bool BankAccount::operator>= (const BankAccount& other) {
83: 
84:     return !(*this < other);
85: }
86: 
87: // output operator
88: std::ostream& operator<< (std::ostream& os, const BankAccount& other)
89: {
90:     os << "BankAccount Nr.: " << other.getAccountNumber() << ":";
91:     os << std::fixed << std::setprecision(2);
92:     os << " Balance = " << std::setw(2) << std::setfill('0') << other.getBalance();
93:     return os;
94: }
```

Ein kleines Beispiel für eine Anwendung der Klasse `BankAccount`:

```cpp
01: void example_bank_account()
02: {
03:     BankAccount myAccount{ 50 };
04:     myAccount.deposit(50);
05:     myAccount.withdraw(25);
06:     std::cout << myAccount << std::endl;
07: 
08:     BankAccount firstAccount{};
09:     std::cout << firstAccount << std::endl;
10: 
11:     BankAccount secondAccount{};
12:     secondAccount.deposit(50);
13:     secondAccount.withdraw(25);
14:     std::cout << secondAccount << std::endl;
15: 
16:     if (firstAccount.equals(secondAccount)) {
17:         std::cout << "Same Balance" << std::endl;
18:     }
19:     else {
20:         std::cout << "Different Balances" << std::endl;
21:     }
22: }
```

## Realisierung in Python

```python
01: class BankAccount:
02:     # Statische Variable (Klassenvariable)
03:     s_next_account_number = 10000
04: 
05:     def __init__(self, balance=0.0):
06:         # Initialisierung
07:         self._number = BankAccount.s_next_account_number
08:         self._balance = balance
09:         
10:         # Statischen Zaehler erhoehen
11:         BankAccount.s_next_account_number += 1
12: 
13:     # Getter
14:     def get_account_number(self):
15:         return self._number
16: 
17:     def get_balance(self):
18:         return self._balance
19: 
20:     # Public Interface
21:     def deposit(self, amount):
22:         self._balance += amount
23: 
24:     def withdraw(self, amount):
25:         if self._balance >= amount:
26:             self._balance -= amount
27: 
28:     def equals(self, other):
29:         if not isinstance(other, BankAccount):
30:             return False
31:         return self._balance == other._balance
32: 
33:     # Operatoren (Vergleich)
34:     def __eq__(self, other):
35:         if isinstance(other, BankAccount):
36:             return self._balance == other._balance
37:         return False
38: 
39:     def __ne__(self, other):
40:         return not self.__eq__(other)
41: 
42:     def __lt__(self, other):
43:         return self._balance < other._balance
44: 
45:     def __le__(self, other):
46:         return self.__lt__(other) or self.__eq__(other)
47: 
48:     def __gt__(self, other):
49:         return not self.__le__(other)
50: 
51:     def __ge__(self, other):
52:         return not self.__lt__(other)
53: 
54:     # Output Operator (entspricht std::ostream& operator<<)
55:     def __str__(self):
56:         return f"BankAccount Nr.: {self._number}: Balance = {self._balance:0.2f}"
57: 
58: # Test des Codes:
59: def example_bank_account():
60:     # BankAccount myAccount{ 50 };
61:     my_account = BankAccount(50)
62:     my_account.deposit(50)
63:     my_account.withdraw(25)
64:     print(my_account)
65: 
66:     # BankAccount firstAccount{};
67:     first_account = BankAccount()
68:     print(first_account)
69: 
70:     # BankAccount secondAccount{};
71:     second_account = BankAccount()
72:     second_account.deposit(50)
73:     second_account.withdraw(25)
74:     print(second_account)
75: 
76:     # if (firstAccount.equals(secondAccount))
77:     if first_account.equals(second_account):
78:         print("Same Balance")
79:     else:
80:         print("Different Balances")
81: 
82: if __name__ == "__main__":
83:     example_bank_account()
```

*Hinweise*:

  * Statische Variablen (Klassenveriablen) werden in Python direkt unter dem Klassennamen definiert.,
  siehe hier das Beispiel `s_next_account_number`.
  In `__init__` greifen wir über `BankAccount.s_next_account_number` darauf zu.

  
  * Python unterstützt keine mehrfachen Konstruktoren, also keine überladenen Konstruktoren.
  Wir lösen das Problem über einen Standardwert (`balance = 0.0`), was so beide C++ Konstruktoren abdeckt.

Zum Vergleichen von Objekten kennt Python so genannte &bdquo;Rich Comparison Methods&rdquo;.
Das sind spezielle *Dunder*-Methoden (Double Underscore) in Python, mit denen man festlegt,
wie Objekte einer Klasse mit Vergleichsoperatoren (wie `==`, `<`, `>`) interagieren.


| Operator  | Methode | Bedeutung |
| :- | :- | :- |
| `==` | `__eq__(self, other)` | Gleichheit (*Equal*) |
| `!=` | `__ne__(self, other)` | Ungleichheit (*Not Equal*) |
| `<`  | `__lt__(self, other)` | Kleiner als (*Less Than*) |
| `<=` | `__le__(self, other)` | Kleiner oder gleich (*Less or Equal*) |
| `>`  | `__gt__(self, other)` | Größer als (*Greater Than*) |
| `>=` | `__ge__(self, other)` | Größer oder gleich (*Greater or Equal*) |

*Tabelle* 1: Die 6 &bdquo;Rich Comparison Methods&rdquo;.

*Wichtige Merkmale*:

  * Automatischer Aufruf: Wenn man `a < b` schreibt, ruft Python im Hintergrund `a.__lt__(b)` auf.
  * Rückgabewerte: Üblicherweise geben die Operatoren `True` oder `False` zurück.
    Wenn ein Vergleich mit einem bestimmten Typ nicht unterstützt wird,
    sollte die Methode `NotImplemented` zurückgeben, damit Python alternative Wege (z. B. den Operator beim Partnerobjekt) prüfen kann.


Python kennt keinen Ausgabeoperator `<<` im Stile von C++.
Dafür gibt es eine Methode `__str__`, die aufgerufen wird,
wenn man `print(objekt)` nutzt oder das Objekt in einen String umwandeln möchte.
Das Format `:0.2f` entspricht dem von `std::fixed` und `setprecision(2)`.

Zu den Namenskonvention: `m_number` wurde zu `_number`.
Der führende Unterstrich ist in Python der Standard, um zu signalisieren,
dass eine Variable  &bdquo;protected&rdquo; (intern) ist.

---

[Zurück](../../Readme.md)

---
