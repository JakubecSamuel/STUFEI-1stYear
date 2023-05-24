def funkcia(n):
    if (n == 1):
        return 1
    else:
        return n + funkcia(n-1)

a=funkcia(7)
print(a)
    
    
    
