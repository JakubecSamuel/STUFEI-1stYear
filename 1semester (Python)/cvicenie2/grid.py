def grid(n):
    for i in range(n):
        for i in range(n):
            print("+ - - - - ", end="")
        print("+")
        for i in range(n*2):
            for i in range(n):
                print("|         ", end="")
            print("|")
    for i in range(n):
        print("+ - - - - ", end="")
    print("+")

a = int(input("Koľko riadkový a stĺpcový grid chceš? "))
grid(a)
    
