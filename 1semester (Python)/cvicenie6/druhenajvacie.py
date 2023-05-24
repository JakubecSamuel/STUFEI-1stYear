def funkcia(n):
    maxi = 0
    max2 = 0
    prvecislo = 0
    for i in range(n):
        cislo = int(input("zadaj cislo "))
        if i == 0:
            prvecislo = cislo
            maxi = cislo
        elif i == 1:
            if cislo >= prvecislo:
                maxi = cislo
                max2 = prvecislo
            else:
                max2 = cislo
        if i >= 2:
            if cislo >= maxi:
                max2 = maxi
                maxi = cislo
            elif cislo >= max2:
                max2 = cislo
    print("druhe najvacsie cislo je", max2)

funkcia(4)
