# C++ versus Python in Beispielen

## [Zinsrechnung](./Cpp_vs_Python/Zinsrechnung/Zinsrechnung.md)

## [Teuflische Folge](./Cpp_vs_Python/TeuflischeFolge/TeuflischeFolge.md)

## [Klasse `BankAccount`](./Cpp_vs_Python/BankAccount/BankAccount.md)

## [Listen](./Cpp_vs_Python/Lists/Lists.md)

## [Tuples](./Cpp_vs_Python/Tuples/Tuples.md)

## [Dictionaries](./Cpp_vs_Python/Dictionaries/Dictionaries.md)




"Berlin",
"Hamburg",
"Muenchen",
"Koeln",
"Frankfurt am Main",
"Stuttgart",
"Duesseldorf",
"Leipzig",
"Dortmund",
"Essen"

cities = [
    "Berlin",
    "Hamburg",
    "Muenchen",
    "Koeln",
    "Frankfurt am Main",
    "Stuttgart",
    "Duesseldorf",
    "Leipzig",
    "Dortmund",
    "Essen"
]


cities = [
    "Berlin",
    "Hamburg",
    "Muenchen",
    "Koeln",
    "Frankfurt am Main",
    "Stuttgart",
    "Duesseldorf",
    "Leipzig",
    "Dortmund",
    "Essen"
]

k = 0
while k < len(cities):
    print(cities[k])
    k += 1

for city in cities:
    print(city)

for i, city in enumerate(cities, start = 1):
    print(f"City {i:2}: {city}")

for city in reversed(cities):
    print(city)

for i, city in reversed(list(enumerate(cities, start = 1))):
    print(f"City {i:2}: {city}")

for i, city in enumerate(reversed(cities), start = 1):
    print(f"City {i:2}: {city}")

https://www.onlineide.pro/playground/python


