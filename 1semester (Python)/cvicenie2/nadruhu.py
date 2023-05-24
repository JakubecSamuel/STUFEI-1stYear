def sucetnadruhu(n):
    a=0
    for i in range(0,n+1):
        a=a+pow(i,2)
    return a
a=int(input("do kolko chces pocitat na druhu?\n"))

print(sucetnadruhu(a))
