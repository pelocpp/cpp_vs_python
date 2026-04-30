# =====================================================================================
# BankAccount.py
# =====================================================================================

class BankAccount:
    # Statische Variable (Klassenvariable)
    s_next_account_number = 10000

    def __init__(self, balance=0.0):
        # Initialisierung
        self._number = BankAccount.s_next_account_number
        self._balance = balance
        
        # Statischen Zaehler erhoehen
        BankAccount.s_next_account_number += 1

    # Getter
    def get_account_number(self):
        return self._number

    def get_balance(self):
        return self._balance

    # Public Interface
    def deposit(self, amount):
        self._balance += amount

    def withdraw(self, amount):
        if self._balance >= amount:
            self._balance -= amount

    def equals(self, other):
        if not isinstance(other, BankAccount):
            return False
        return self._balance == other._balance

    # Operatoren (Vergleich)
    def __eq__(self, other):
        if isinstance(other, BankAccount):
            return self._balance == other._balance
        return False

    def __ne__(self, other):
        return not self.__eq__(other)

    def __lt__(self, other):
        return self._balance < other._balance

    def __le__(self, other):
        return self.__lt__(other) or self.__eq__(other)

    def __gt__(self, other):
        return not self.__le__(other)

    def __ge__(self, other):
        return not self.__lt__(other)

    # Output Operator (entspricht std::ostream& operator<<)
    def __str__(self):
        return f"BankAccount Nr.: {self._number}: Balance = {self._balance:0.2f}"

# Test des Codes:
def example_bank_account():
    # BankAccount myAccount{ 50 };
    my_account = BankAccount(50)
    my_account.deposit(50)
    my_account.withdraw(25)
    print(my_account)

    # BankAccount firstAccount{};
    first_account = BankAccount()
    print(first_account)

    # BankAccount secondAccount{};
    second_account = BankAccount()
    second_account.deposit(50)
    second_account.withdraw(25)
    print(second_account)

    # if (firstAccount.equals(secondAccount))
    if first_account.equals(second_account):
        print("Same Balance")
    else:
        print("Different Balances")

if __name__ == "__main__":
    example_bank_account()

# =====================================================================================
# End-of-File
# =====================================================================================
