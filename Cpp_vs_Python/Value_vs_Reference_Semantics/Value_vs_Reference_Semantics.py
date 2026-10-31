# =====================================================================================
# Value_vs_Reference_Semantics.py
# =====================================================================================

class Person:
    def __init__(self, name = "", last = "", age = 0):
        self.name = name
        self.last = last
        self.age  = age

    def __str__(self):
        return f"Person: {self.name} {self.last}, Alter: {self.age}"        

def value_vs_reference_semantics_demo():
    hans = Person("Hans", "Meier", 30

    empty = Person()

    print(hans)

value_vs_reference_semantics_demo()

# =====================================================================================
# End-of-File
# =====================================================================================
