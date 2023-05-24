def has_no_e():
    fin = open("words.txt")
    e = 0
    for line in fin:
        has_e = False
        word = line.strip() 
        for l in word:
            if l == "e":
                has_e = True
        if has_e == False:
            e = e + 1
    percent = (e/113809) * 100
    print(round(percent, 2),"% words are without e.")


has_no_e()
