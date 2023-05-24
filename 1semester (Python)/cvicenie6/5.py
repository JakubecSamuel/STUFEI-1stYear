def funkcia5():
    x=int(input())
    pred=x
    i=0
    while True:
        x=int(input())
        if x > pred:
            i=i+1
        pred=x
        if x == 0:
            break
    print(i)

funkcia5()

            
        
