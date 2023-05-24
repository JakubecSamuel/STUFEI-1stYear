def uses_all(word, string):
    for l in word:
            for b in string:
                if b == l:
                    string = string.replace(b, '')
                    print(string)
    if string == "":
        return True
    else:
        return False

print(uses_all("anabeakafafafaertdg", "abken"))

            
                
