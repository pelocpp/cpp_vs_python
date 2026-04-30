# =====================================================================================
# Zinsrechnung.py
# =====================================================================================

def main_zinsrechnung():
    capital_stock = 1000.0
    start_capital_stock = capital_stock
    interest_rate = 5.0
    number_years = 10

    print(f"Zinstabelle fuer Grundkapital {capital_stock:.2f}")
    print(f"Verzinsung:                   {interest_rate:.2f}%")
    print("=====================================")
    print()
    print("Kapitalstand zum Jahresende:")

    year = 0

    while year < number_years:
        interest = (capital_stock / 100.0) * interest_rate
        capital_stock += interest
        print(f"Jahr: {year + 1:2}    Kapital: {capital_stock:.2f}")
        year += 1

    print()
    print(f"Aus {start_capital_stock:.2f} Grundkapital wurden in {year} Jahren {capital_stock:.2f} Euro.\n")

if __name__ == "__main__":
    main_zinsrechnung()

# =====================================================================================
# End-of-File
# =====================================================================================
