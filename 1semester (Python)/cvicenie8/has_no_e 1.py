def has_no_e(s):
    for l in s:
        if l == "e":
            return False
    return True

kokot = "kokot"
print(has_no_e(kokot))
