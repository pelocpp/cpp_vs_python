# =====================================================================================
# Enumeration.py
# =====================================================================================

cities = [
    "Berlin",
    "Hamburg",
    "Muenchen",
    "Koeln"
]

print(cities)  # printing the list directly
print()

# =====================================================================================
# enumerating a list

enumerated_cities = enumerate(cities)
list_enumerated_cities = list(enumerated_cities)
print(list_enumerated_cities)
print()

enumerated_cities = enumerate(cities, start = 1)
list_enumerated_cities = list(enumerated_cities)
print(list_enumerated_cities)
print()

# =====================================================================================
# enumerating a list without creating another list object

enumerated_cities = enumerate(cities)
print(next(enumerated_cities))
print(next(enumerated_cities))
print(next(enumerated_cities))
print(next(enumerated_cities))
print()

# =====================================================================================
# enumerating through a list with a for-Loop

for item in enumerate(cities):
  print(item)
print()

for item in cities:
  print(item)
print()

print(cities)

# =====================================================================================
# End-of-File
# =====================================================================================
