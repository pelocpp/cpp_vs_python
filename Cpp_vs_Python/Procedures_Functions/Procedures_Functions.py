# =====================================================================================
# Procedures_Functions.py
# =====================================================================================

def say_hello(count: int, message: str) -> None:
    for _ in range(count):
        print(message)
    print()


def example_procedures_functions_01() -> None:
    say_hello(2, "I'm saying Hello :)")
    say_hello(3, "I'm saying Hello :)")


def power_of(base: int, exponent: int) -> int:
    result = 1
    for _ in range(exponent):
        result *= base
    return result


def example_procedures_functions_02() -> None:
    base = 2
    exponent = 5
    
    result = power_of(base, exponent)
    print(f"{base} to the power of {exponent}: {result}")


# Aufruf der Beispiel-Funktionen wie im C++ Code
if __name__ == "__main__":
    example_procedures_functions_01()
    example_procedures_functions_02()


# =====================================================================================
# End-of-File
# =====================================================================================
