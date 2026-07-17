# =====================================================================================
# Shallow_vs_Deep_Copy.py
# =====================================================================================

import copy

class Data :
    def __init__(self):
        self.number1 = 123
        self.number2 = 456
    def print(self):
        print(f"number1: {self.number1}")
        print(f"number2: {self.number2}")

def example_data_01():
    data1 = Data()
    data2 = data1
    data1.print()
    data2.print()
    data1.number1 = 999
    data1.print()
    data2.print()
    print()

def example_data_02():
    data1 = Data()
    data2 = copy.copy(data1) 
    data1.print()
    data2.print()
    data1.number1 = 999
    data1.print()
    data2.print()
    print()

def example_data_03():
    data1 = Data()
    data2 = copy.deepcopy(data1) 
    data1.print()
    data2.print()
    data1.number1 = 999
    data1.print()
    data2.print()
    print()

example_data_01()
example_data_02()
example_data_03()

# -------------------------------------------------------------------------------------

class MoreData :
    def __init__(self):
        self.number = 123
        self.numbers = [123, 456, 789]
    def print(self):
        print(f"number: {self.number}")
        print(f"numbers: {self.numbers}")

def example_more_data_01():
    data1 = MoreData()
    data2 = data1
    data1.print()
    data2.print()
    data1.number = 888
    data1.numbers[1] = 999
    data1.print()
    data2.print()
    print()

def example_more_data_02():
    data1 = MoreData()
    data2 = copy.copy(data1) 
    data1.print()
    data2.print()
    data1.number = 888
    data1.numbers[1] = 999
    data1.print()
    data2.print()
    print()

def example_more_data_03():
    data1 = MoreData()
    data2 = copy.deepcopy(data1) 
    data1.print()
    data2.print()
    data1.number = 888
    data1.numbers[1] = 999
    data1.print()
    data2.print()
    print()

example_more_data_01()
example_more_data_02()
example_more_data_03()

# =====================================================================================
# End-of-File
# =====================================================================================
