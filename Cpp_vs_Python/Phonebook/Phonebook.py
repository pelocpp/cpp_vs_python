# =====================================================================================
# Phonebook.py
# =====================================================================================


# Da du von C++ kommst, ist der wichtigste Unterschied,
# dass Python-Klassen dynamischer sind und wir oft Dictionaries verwenden,
# um Daten effizient zu speichern.

from typing import Optional

class PhoneBook:
    def __init__(self):
        # Wir nutzen ein Dictionary. Der Key ist ein Tuple (Vorname, Nachname)
        # Das ermöglicht einen O(1) Zugriff, ähnlich wie eine Hashmap.
        self._entries = {}

    def size(self) -> int:
        return len(self._entries)

    def insert(self, first: str, last: str, number: int) -> bool:
        if (first, last) in self._entries:
            return False
        self._entries[(first, last)] = number
        return True

    def update(self, first: str, last: str, number: int) -> bool:
        if (first, last) not in self._entries:
            return False
        self._entries[(first, last)] = number
        return True

    def search(self, first: str, last: str) -> Optional[int]:
        # Dictionary.get() gibt None zurück, wenn der Key nicht existiert
        # Das entspricht deinem std::optional
        return self._entries.get((first, last))

    def remove(self, first: str, last: str) -> bool:
        if (first, last) in self._entries:
            del self._entries[(first, last)]
            return True
        return False

    def contains(self, first: str, last: str) -> bool:
        return (first, last) in self._entries

    def print(self):
        print("--- Phonebook Content ---")
        for (first, last), number in self._entries.items():
            print(f"{first} {last}: {number}")
        print("-------------------------")




# Wenn wir eine Liste (ähnlich wie std::vector) statt eines Dictionaries nutzen,
# müssen wir die Einträge manuell suchen. Das ist eine super Übung, um zu verstehen,
# wie Python mit Objekten in Listen umgeht.Da wir jetzt keine Key-Value-Paare mehr haben,
# bietet es sich an, eine kleine Hilfsklasse für den einzelnen Eintrag zu erstellen

# Umsetzung mit einer Liste (std::vector Stil)

from typing import Optional

# Hilfsklasse für einen einzelnen Eintrag
class Entry:
    def __init__(self, first: str, last: str, number: int):
        self.first = first
        self.last = last
        self.number = number

class PhoneBook:
    def __init__(self):
        # Hier nutzen wir nun eine Liste statt eines Dictionaries
        self._entries = []

    def size(self) -> int:
        return len(self._entries)

    def _find_index(self, first: str, last: str) -> Optional[int]:
        """Interne Hilfsmethode, um den Index eines Namens zu finden."""
        for i, entry in enumerate(self._entries):
            if entry.first == first and entry.last == last:
                return i
        return None

    def insert(self, first: str, last: str, number: int) -> bool:
        if self.contains(first, last):
            return False
        self._entries.append(Entry(first, last, number))
        return True

    def update(self, first: str, last: str, number: int) -> bool:
        idx = self._find_index(first, last)
        if idx is not None:
            self._entries[idx].number = number
            return True
        return False

    def search(self, first: str, last: str) -> Optional[int]:
        idx = self._find_index(first, last)
        if idx is not None:
            return self._entries[idx].number
        return None

    def remove(self, first: str, last: str) -> bool:
        idx = self._find_index(first, last)
        if idx is not None:
            self._entries.pop(idx) # Entfernt das Element am Index
            return True
        return False

    def contains(self, first: str, last: str) -> bool:
        return self._find_index(first, last) is not None

    def print(self):
        print("--- Phonebook (List-based) ---")
        for entry in self._entries:
            print(f"{entry.first} {entry.last}: {entry.number}")
        print("------------------------------")


def test_exercise():
    book = PhoneBook()

    # testing insert
    book.insert("Franz", "Schneider", 8483)
    book.insert("Hans", "Mueller", 5326)
    book.insert("Sepp", "Meier", 7561)
    book.insert("Anton", "Huber", 4899)
    book.print()

    # testing invalid insertion
    succeeded = book.insert("Franz", "Schneider", 4321)
    if not succeeded:
        print("Franz Schneider already in Phonebook!")

    # testing 'update'
    print("Updating phone number of Franz Schneider:")
    succeeded = book.update("Franz", "Schneider", 1234)
    book.print()

    # testing 'remove'
    print("Removing Anton Huber:")
    succeeded = book.remove("Anton", "Huber")
    book.print()

    # testing 'contains'
    found = book.contains("Sepp", "Meier")
    print(f"Found Sepp Meier: {found}")
    found = book.contains("Otto", "Meier")
    print(f"Found Otto Meier: {found}")

    # testing 'search'
    number_meier = book.search("Sepp", "Meier")
    if number_meier is not None:
        print(f"Sepp Meier: {number_meier}")

if __name__ == "__main__":
    test_exercise()



# Soll ich dir zeigen, wie man die Klasse so erweitert,
# dass man sie wie eine echte Python-Liste mit len(book) oder print(book)
# (statt book.print()) benutzen kann?

class PhoneBook:
    def __init__(self):
        self._entries = []

    # Ersetzt book.size() -> erlaubt len(book)
    def __len__(self):
        return len(self._entries)

    # Ersetzt book.print() -> erlaubt print(book)
    def __str__(self):
        if not self._entries:
            return "Phonebook is empty."
        header = "--- Phonebook Content ---\n"
        lines = [f"{e.first} {e.last}: {e.number}" for e in self._entries]
        return header + "\n".join(lines) + "\n-------------------------"

    # Bonus: Erlaubt Iteration -> for entry in book:
    def __iter__(self):
        return iter(self._entries)

    # Die restliche Logik (insert, update, search, remove) bleibt gleich ...
    def _find_index(self, first: str, last: str):
        for i, entry in enumerate(self._entries):
            if entry.first == first and entry.last == last:
                return i
        return None

    def insert(self, first, last, number):
        if self._find_index(first, last) is not None: return False
        self._entries.append(Entry(first, last, number))
        return True


if __name__ == "__main__":
    # Benutzereingabe in eine int-Variable umwandeln
    value = int(input("Startzahl: "))
    example_teuflische_folge(value)

# =====================================================================================
# End-of-File
# =====================================================================================
