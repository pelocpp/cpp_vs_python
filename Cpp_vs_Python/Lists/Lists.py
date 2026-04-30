# =====================================================================================
# Lists.py
# =====================================================================================

# Homogenitaet: Identische Datentypen in einer Liste
list = [1, 2, 3, 4, 5]
print(list) 

# Heterogenitaet: Verschiedene Datentypen in einer Liste
list = ["Hans", 123, "Sepp", 123]
print(list) 

# List Comprehension
numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
result = [x*x for x in numbers if x % 2 == 0]
print(result)

# Listen traversieren

## Loop Through List Items with For Loop
numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
for x in numbers:
    print(x, end = " ")

## Loop Through List Items with Index
indices = range(len(numbers))
for i in indices:
   print ("numbers[{}]: ".format(i), numbers[i])

## Iterate using List Comprehension
[print(x, end = " - ") for x in numbers]


## Iterate using the enumerate() Function
for index, x in enumerate(numbers):
   print(index, x, end = " - ")


# =====================================================================================
# End-of-File
# =====================================================================================
