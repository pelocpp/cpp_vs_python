# =====================================================================================
# Strings.py
# =====================================================================================

def strings_demo():
    s = "12345"
    print(f"String: {s}")

    # len
    length = len(s)
    empty = len(s) == 0
    print(f"Length: {length} - Empty: {empty}")

    # find
    pos = s.find("3")
    print(f"Pos: {pos}")

    # replace
    s = s.replace("3", "ABABA")
    print(f"String: {s}")
    
    # count
    count = s.count("A");
    print(f"Count: {count}")
  
    # startswith
    n = s.startswith("12")
    print(f"startswith: {n}")

    # endswith
    n = s.endswith("X")
    print(f"endswith: {n}")

    # insert
    s = s[:5] + "XYZ" + s[5:]
    print(f"String: {s}")
    
    # append
    s += "!!!"
    print(f"String: {s}")
    
    # equals
    s1 = "12345"
    s2 = "12345"
    s3 = "123456"

    n = (s1 == s2)
    print(f"equals s1==s2: {n}")
    n = (s1 == s3)
    print(f"equals s1==s2: {n}")

    number = "123"
    value = int(number)
    print(f"Number: {number}")
    
strings_demo()

# =====================================================================================
# End-of-File
# =====================================================================================
