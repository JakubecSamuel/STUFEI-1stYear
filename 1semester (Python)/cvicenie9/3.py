def sucet(listt):
    b = 1
    result = 0
    for i in listt:
        if b%2 == 0:
            result += i
        b += 1
    return result
        


print(sucet([4, 2, 3, 5, 3, 8]))

