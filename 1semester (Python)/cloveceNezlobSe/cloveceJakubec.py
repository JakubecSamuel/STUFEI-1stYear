import random


#Funkcia, ktorá vráti vygenerovaný list sachovnica,
#kde sú uložené jednotlivé políčka
def gensachovnica(n):
    #Potrebujeme list v liste aby sme mali prístup k hodnotám
    #aj na riadkoch aj stĺpcoch, napr. [2][4]
    sachovnica = []
    for i in range(n):
        sachovnica.append([])
    prazdne = n-3
    #Samotný for cyklus, ktorý prechádza stĺpcami a ďalej aj riadkami
    #a zapisuje do listu sachovnica hodnoty
    #ktoré tam majú byť, napr. prázdne políčko, domček alebo samostatná cesta
    for i in range(n):
        #Keďže viem, že na prvom a poslednom riadku sa nachádzajú
        #isté hodnoty tak som pre tento riadok spravil isté zapisovanie hodnôt
        if i == 0 or i == n-1:
            for b in range(n):
                if b < prazdne/2 or b > (prazdne/2)+2:
                    sachovnica[i].append(" ")
                else:
                    sachovnica[i].append("*")
        #V prostredných 3 riadkoch sú domčeky alebo cesty, tento if hovorí
        #o bočných kde sú vlastne všade cesty okrem strednej kde je domček
        elif i == prazdne/2 or i == (prazdne/2)+2:
            for b in range(n):
                if b == (n-1)/2:
                    sachovnica[i].append("D")
                else:
                    sachovnica[i].append("*")
        #Tu sa naplňuje horná a dolná časť šachovnice, kde sú
        #prázdne miesta, cesty alebo domčeky
        elif i <= (n-5)/2 or i > ((n-5)/2)+2:
            for b in range(n):
                if b == (n-1)/2:
                    sachovnica[i].append("D")
                elif b < prazdne/2 or b > (prazdne/2)+2:
                    sachovnica[i].append(" ")
                elif b == prazdne/2 or (prazdne/2)+2:
                    sachovnica[i].append("*")
        #Tu sa naplňuje prostredný riadok, ktorý je ako jediný RIADOK unikátny
        elif i == (n-1)/2:
            for b in range(n):
                if b == 0 or b == n-1:
                    sachovnica[i].append("*")
                elif i == (n-1)/2 and b == (n-1)/2:
                    sachovnica[i].append("X")
                else:
                    sachovnica[i].append("D")
    return sachovnica


#Jednoduchá funkcia, ktorá nevracia žiadnu hodnotu, len printami vykresluje
#ako daná šachovnica vyzerá zobrazená graficky (vykreslí ju)
def tlacsachovnicu(sachovnica):
    print(end="  ")
    for i in range(len(sachovnica)):
        if i == 0:
                for c in range(len(sachovnica)):
                    if c >= 10:
                        print(c-10, end=" ")
                    else:
                        print(c, end=" ")
        print("\n", end="")
        if i >= 10:
            print(i-10, end=" ")
        else:
            print(i, end=" ")
        for b in range(len(sachovnica)):
            print(sachovnica[i][b], end=" ")
    print("\n")


#Posun hráča
def posun(hod, sachovnica, x, y, domceky, hrac):
    dlzka = len(sachovnica)
    stop = False
    #Staré pozície x,y keby panačik nemôže spraviť pohyb
    #ostane na týchto pozíciach
    staraX = x
    staraY = y
    for i in range(hod):
        if hrac == "A":
            #Pozerám či sa náchadzam s možnosťou ísť do domčeka,
            #teda či som nad ním
            if x == dlzka // 2 and y != dlzka-1:
                if (sachovnica[y+1][x] == "D" or (sachovnica[y+1][x] == "A" and i != hod-1)) and stop == False:
                    y += 1
                    stop = True
                #Ak má byť ďalšia pozícia už mimo domčeka (X) alebo je ďalšia
                #pozícia už zabraná (je tam A a zároveň je to posledný pohyb)
                #tak sa hráč nepohne
                elif (sachovnica[y+1][x] == "X" or (sachovnica[y+1][x] == "A" and i == hod-1)) and stop == False:
                    x = staraX
                    y = staraY
                    stop = True
                    break
            #Ak sa hráč nenachádza nad domčekom, hýbe sa po trati
            elif stop == False:
                if x < dlzka // 2:
                    if y > 0 and (sachovnica[y-1][x] == "*" or (sachovnica[y-1][x] == "B" and x != (dlzka-1)/2) or sachovnica[y-1][x] == "A"):
                        y -= 1
                        stop = True
                elif stop == False:
                    if y < dlzka-1 and (sachovnica[y+1][x] == "*" or sachovnica[y+1][x] == "B" or sachovnica[y+1][x] == "A"):
                        y += 1
                        stop = True
                if y < dlzka // 2 and stop == False:
                    if x < dlzka-1 and (sachovnica[y][x+1] == "*" or sachovnica[y][x+1] == "B" or (sachovnica[y][x+1] == "A" and x != (dlzka-2)/2)):
                        x += 1
                        stop = True
                elif stop == False:
                    if x > 0 and (sachovnica[y][x-1] == "*" or (sachovnica[y][x-1] == "B" and x != (dlzka+1)/2) or (sachovnica[y][x-1] == "B" and (x == (dlzka+1)/2 and y == dlzka-1)) or sachovnica[y][x-1] == "A"):
                        x -= 1
            stop = False
        elif hrac == "B":
            #Pozerám či sa náchadzam s možnosťou ísť do domčeka,
            #teda či som nad ním
            if x == dlzka // 2 and y != 0:
                if (sachovnica[y-1][x] == "D" or (sachovnica[y-1][x] == "B" and i != hod-1)) and stop == False:
                    y -= 1
                    stop = True
                #Ak má byť ďalšia pozícia už mimo domčeka (X) alebo je ďalšia
                #pozícia už zabraná (je tam B a zároveň je to posledný pohyb)
                #tak sa hráč nepohne
                elif (sachovnica[y-1][x] == "X" or (sachovnica[y-1][x] == "B" and i == hod-1)) and stop == False:
                    x = staraX
                    y = staraY
                    stop = True
                    break
            #Ak sa hráč nenachádza nad domčekom, hýbe sa po trati
            elif stop == False:
                if x < dlzka // 2:
                    if y > 0 and (sachovnica[y-1][x] == "*" or sachovnica[y-1][x] == "A" or sachovnica[y-1][x] == "B"):
                        y -= 1
                        stop = True
                elif stop == False:
                    if y < dlzka-1 and (sachovnica[y+1][x] == "*" or (sachovnica[y+1][x] == "A" and x != (dlzka-1)/2) or sachovnica[y+1][x] == "B"):
                        y += 1
                        stop = True
                if y < dlzka // 2 and stop == False:
                    if x < dlzka-1 and (sachovnica[y][x+1] == "*" or (sachovnica[y][x+1] == "A" and x != (dlzka-2)/2) or (sachovnica[y][x+1] == "A" and (x == (dlzka-2)/2 and y == 0)) or sachovnica[y][x+1] == "B"):
                        x += 1
                        stop = True
                elif stop == False:
                    if x > 0 and (sachovnica[y][x-1] == "*" or sachovnica[y][x-1] == "A" or (sachovnica[y][x-1] == "B" and x != (dlzka+1)/2)):
                        x -= 1
            stop = False
    return x, y


#Ak hráč, ktorý sa práve hýbal má v domčeku všetky figúrky
#tak hodnota vráti True a vtedy hra končí
def checkVyhra(sachovnica, vdomceku, domceky):                   
    vyhra = False
    if vdomceku == domceky:
        vyhra = True
    return vyhra


velkost = int(input("Aká veľká má byť hracia plocha?"))
sachovnica = gensachovnica(velkost)
domceky = (velkost-3)/2
vdomcekuA = 0
vdomcekuB = 0
#Počiatočná pozícia hráča A na osi x, y
y = 0
x = int((velkost+1)/2)
sachovnica[y][x] = "A"
#Počiatočná pozícia hráča B na osi x, y
y2 = velkost-1
x2 = int((velkost-2)/2)
sachovnica[y2][x2] = "B"
tlacsachovnicu(sachovnica) #Zobrazenie šachovnice
while True:
    ###### HRÁČ A ######
    while True:
        #Hodenie kockou a následovné vypísanie koľko sa hodilo
        hod = random.randint(1, 6)
        print("Hráč A hodil ", hod, "\n")
        #Pozíciu kde hráč bol musíme späť zmeniť na * lebo hráč sa odtiaľ posunie
        sachovnica[y][x] = "*"
        #Súradnice x,y kde sa má hráč A posunúť po hodení kockou
        x, y = posun(hod, sachovnica, x, y, domceky, "A")
        if sachovnica[y][x] == "D":
            vdomcekuA += 1
            sachovnica[y][x] = "A"
            y = 0
            x = int((velkost+1)/2)
            if vdomcekuA != domceky:
                sachovnica[y][x] = "A"
        elif sachovnica[y][x] == "B":
            sachovnica[y][x] = "A"
            y2 = velkost-1
            x2 = int((velkost-2)/2)
            sachovnica[y2][x2] = "B"
        else:
            sachovnica[y][x] = "A"
        tlacsachovnicu(sachovnica)
        if checkVyhra(sachovnica, vdomcekuA, domceky) == True:
            print("Vyhráva hráč A.")
            break
        if hod != 6:
            break
    #Tu musím ešte raz zavolať funkciu checkVyhra aby som breakol celú hru
    #lebo sme v nestovanom loope a nechcem aby mal ešte hráč B kolo
    if checkVyhra(sachovnica, vdomcekuA, domceky) == True:
        break
    ###### HRÁČ B ######
    while True:
        #Hodenie kockou a následovné vypísanie koľko sa hodilo
        hod = random.randint(1, 6)
        print("Hráč B hodil ", hod, "\n")
        #Pozíciu kde hráč bol musíme späť zmeniť na * lebo hráč sa odtiaľ posunie
        sachovnica[y2][x2] = "*"
        #Súradnice x,y kde sa má hráč B posunúť po hodení kockou
        x2, y2 = posun(hod, sachovnica, x2, y2, domceky, "B")
        if sachovnica[y2][x2] == "D":
            vdomcekuB += 1
            sachovnica[y2][x2] = "B"
            y2 = velkost-1
            x2 = int((velkost-2)/2)
            if vdomcekuB != domceky:
                sachovnica[y2][x2] = "B"
        elif sachovnica[y2][x2] == "A":
            sachovnica[y2][x2] = "B"
            y = 0
            x = int((velkost+1)/2)
            sachovnica[y][x] = "A"
        else:
            sachovnica[y2][x2] = "B"
        tlacsachovnicu(sachovnica)
        if checkVyhra(sachovnica, vdomcekuB, domceky) == True:
            print("Vyhráva hráč B.")
            break
        if hod != 6:
            break
    if checkVyhra(sachovnica, vdomcekuB, domceky) == True:
        break
