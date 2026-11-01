# =====================================================================================
# Value_vs_Reference_Semantics.py
# =====================================================================================

import copy

class Person:
    def __init__(self, name = "", last = "", age = 0):
        self.name = name
        self.last = last
        self.age  = age

    def __str__(self):
        return (f"Person: {self.name} {self.last}, "
                f"Alter: {self.age}")   

def main():
    empty = None
    print(empty)
    hans = Person("Hans", "Meier", 30)
    print(hans) 

def main_copy():
    hans = Person("Hans", "Meier", 30)
    print(hans)
    copy_hans = copy.deepcopy(hans) 
    print(copy)

    hans.age = 31
    print(hans)
    print(copy_hans)

main()
main_copy()

# =====================================================================================
# End-of-File
# =====================================================================================
