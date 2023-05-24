def funkcia4():
    x=int(input())
    maxi=x
    maxicko=1
    i=1
    while x!=0:
        i=i+1
        x=int(input())
        if x >= maxi:
            maxi=x
            maxicko=i
    print(maxicko)

funkcia4()

            
        
