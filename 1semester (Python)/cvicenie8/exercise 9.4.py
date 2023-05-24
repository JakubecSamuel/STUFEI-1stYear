def uses_only(word, string):
    for l in word:
        je = False
        for b in string:
            if b == l:
                je = True
        if je == False:
            return False
    return True

print(uses_only("anabeakaf", "anbfke"))
            
                
