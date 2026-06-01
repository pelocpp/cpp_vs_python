# =====================================================================================
# Strings.py
# =====================================================================================

def strings_demo():
    s = "12345"
    print(s)

    length = len(s)
    empty = len(s) == 0  # Or simply: empty = not s

    # Strings are immutable; we recreate them via slicing
    s = s[:2] + "ABC" + s[2:]
    s += "!!!"

    s1 = "12345"
    s2 = "12345"
    s3 = "123456"

    b = (s1 == s2)
    b = (s1 == s3)

    # Substring uses slicing: s[start:end] (end index is exclusive)
    sub = s1[1:4]

    # Modifying a character requires reconstruction
    s = s[:2] + '?' + s[3:]
    ch = s[0]

    result = s1 + s3

    number = "123"
    value = int(number)

# =====================================================================================
# End-of-File
# =====================================================================================
