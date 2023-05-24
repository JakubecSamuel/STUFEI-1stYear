def vacsie(listt):
    a = 0
    res = 0
    last = 0
    for i in listt[0:-1]: 
        if i > listt[a+1] and i > last:
            res += 1
        a += 1
        last = i
    if listt[len(listt)-1] > last:
        res += 1
    return res
        

print(vacsie([4, 2, 3, 5, 3, 8, 5, 7, 10, 5, 6, 4, 10]))


