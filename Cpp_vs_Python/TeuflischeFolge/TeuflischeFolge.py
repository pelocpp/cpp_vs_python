# =====================================================================================
# TeuflischeFolge.py
# =====================================================================================

def example_teuflische_folge(start_number=7):
    print("Teuflische Zahlenfolge\n")
    print("======================\n")

    number = start_number   # Startzahl
    n = 1                   # Zaehler fuer die Laenge der Folge

    print(f"Startzahl: {number}")
    print()

    while number != 1:
        if number % 2 == 0:
            number //= 2                # Ganzzahl-Division
        else:
            number = 3 * number + 1

        print(f"Schritt {n:3}: Zahl = {number}")
        n += 1

if __name__ == "__main__":
    example_teuflische_folge(7)

if __name__ == "__main__":
    # Benutzereingabe in eine int-Variable umwandeln
    value = int(input("Startzahl: "))
    example_teuflische_folge(value)

# =====================================================================================
# End-of-File
# =====================================================================================
