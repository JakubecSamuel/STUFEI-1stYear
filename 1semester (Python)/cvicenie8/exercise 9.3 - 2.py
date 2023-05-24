def avoids(word, s):
    for i in word:
            if i == s:
                return False
    return True
    
fin = open("words.txt")
forbidden = input("Zadaj zakazane pismena: ")
without_forbidden = 0
for line in fin:
    word = line.strip()
    if avoids(word, forbidden) == True:
        without_forbidden = without_forbidden + 1
print(without_forbidden,"words were without the forbidden letters.")
        
    
