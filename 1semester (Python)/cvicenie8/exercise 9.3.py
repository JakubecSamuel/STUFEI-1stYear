def avoids(word, s):
    good = 0
    for i in word:
        for b in s:
            if i == b:
                return False
        good = good + 1
    if good == len(word):
        return True
    
print(avoids("fiba", "pbg"))
    
    
