#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

char *readline() {
    const size_t BSIZE = 100;
    char *line = NULL;
    size_t capacity = 0;

    do {
        // Priprav dostatok pamate.
        capacity += BSIZE;

        // Alokuj miesto na capacity + '\0'.
        line = (char *) realloc(line, (capacity + 1) * sizeof(char));
        if (line == NULL)
            return line;

        // Nacitaj zo vstupu riadok (resp. jeho zvysok).
        if (fgets(line + capacity - BSIZE, BSIZE + 1, stdin) == NULL) {
            free(line);
            return NULL; // doslo k chybe citania alebo sme narazili na EOF
        }
        // Opakuj, pokym sa nenacita cely riadok.
        // Indikacia, ze zostal zvysok riadku:
        //   1. je naplnena cela BSIZE
        //   2. na konci nie je '\n'
    } while (strlen(line + capacity - BSIZE) >= BSIZE
             && line[capacity - 1] != '\n');
    // nacitany riadok obsahuje na konci znak '\n'
    return line;
}

void velke(char *c){
    int len = strlen(c);
    for(int i = 0; i <= len; i++) {
        if(c[i] >= 'a' && c[i] <= 'z') c[i] = toupper(c[i]); // ak najdem znak, ktory je velký (od A po Z) tak ho funkciou zmenim na maly
    }
}

void alpha(char *c){
    int i = 0; int len = strlen(c) - 1;
    for(; i <= len; i++)
    {
        if(!isalpha(c[i]) && c[i] != '\n') c[i] = ' '; // ak najdem znak ktory nie je z abecedy tak ho prepišem na medzeru
    }
}

void compress(char *c){
    int i = 0, j = 0; int len = strlen(c);
    for(; i <= len; i++)
    {
        if(isalpha(c[i]) || c[i] == '\n') // idem znak po znaku a ak najdem pismeno alebo znak noveho riadka tak ho posuniem na j-ty index
        {
            c[j] = c[i];
            j++;
        }
    }
    c[j] = '\0';
}

void male(char *c){
    int len = strlen(c);
    for(int i = 0; i <= len; i++) {
        if(c[i] >= 'A' && c[i] <= 'Z') c[i] = tolower(c[i]); // ak najdem znak, ktory je velký (od A po Z) tak ho funkciou zmenim na maly
    }
}

char* vymena(char* riadok, char* hladaj, char* zamen)
{
    char* zmenaRiadok = malloc(strlen(riadok)); // alokujem si pamäť na novy string, najskôr mu dám velkosť akú mal načítaný riadok
    int i = 0, k = 0;
    int lenZamen = strlen(zamen), lenHladaj = strlen(hladaj);
    for(; riadok[i] != '\0'; i++){ // idem hladať string z non-option argumentu, idem až pokiaľ nenarazím na koniec riadka
        if(strstr(riadok+i, hladaj) != NULL){ // ak funkcia strstr nevráti NULL, našiel som zhodu a pripíšem si ju do premennej k
            k++;
            i += lenHladaj; // posuniem sa o dlzku hladaneho slova, kedze túto čast stringu už kontrolovať nemusim, bola zhoda
        }
    }
    // teraz potrebujem zväčšiť/zmenšiť alokovanu pamäť, k = kolko krát som našiel zhodu, + 1 = kvôli znaku \0
    zmenaRiadok = realloc(zmenaRiadok,i + k * (lenZamen - lenHladaj) + 1); i = 0;
    while(*riadok != '\0'){ // teraz naplňam string zmenaRiadok až pokým nedojdem na koniec načitaneho riadka
        if(strstr(riadok, hladaj) == riadok){
            strcpy(&zmenaRiadok[i], zamen); // ak ukazujem na miesto kde je hladany string tak prekopirujem tuto časť do zmenaRiadok
            i += lenZamen;
            riadok += lenHladaj; // pointer posuniem o dlžku hladaneho stringu
        }
        else zmenaRiadok[i] = *riadok, i++, riadok++; // ak som nenasiel hladany string, iba prekopirujem dany znak a posuniem sa
    }
    zmenaRiadok[i] = '\0'; // znak 0 na koniec stringu
    return zmenaRiadok; // vratim cely novy zmeneny string
}
void vymena2(char *c, char* ar){
    int len = strlen(c); int lenA = strlen(ar);
    for(int i = 0; i < len; i++){ // idem znak po znaku
        if(memcmp(ar, c, lenA) == 0){ // ak sa obe časti pamäte zhodujú v dlžke hladaneho argumentu memcmp vrati 0
            memset(c,'*',lenA); // ak sa pamäte zhodovali tak na riadku prepíšem pamäť "*" na dlžku non-opt argumentu
        }
        c++;
    }
}

int main(int argc, char* argv[]) {
    char* riadok = NULL; char* rArg = NULL; int opt;
    int a = 0, c = 0, u = 0, l = 0, r = 0, pozor = 0;
    while((opt = getopt(argc, argv, ":aculr:")) != -1){
        if(opt == ':') return 2;
        if(opt == '?') return 1;
        if(opt == 'u') {
            if(pozor == 1) return 3;
            else pozor = 1;
        }
        if(opt == 'l') {
            if(pozor == 1) return 3;
            else pozor = 1;
        }
    }
    optind = 1;
    while ((riadok = readline()) != NULL) {
        if (*riadok == '\n') return 0;
        while ((opt = getopt(argc, argv, ":aculr:")) != -1){
            switch (opt) {
                case 'a':
                    a = 1;
                    break;
                case 'c':
                    c = 1;
                    break;
                case 'u':
                    u = 1;
                    break;
                case 'l':
                    l = 1;
                    break;
                case 'r':
                    r = 1;
                    rArg = malloc(strlen(optarg));
                    strcpy(rArg, optarg);
                    break;
            }
        }
        if (a == 1) alpha(riadok);
        if (c == 1) compress(riadok);
        if (u == 1) velke(riadok);
        if (l == 1) male(riadok);
        if(r == 0 && optind < argc){
            for(int i=optind;i<argc;i++){
                vymena2(riadok, argv[i]);
            }
        }
        if(r == 1){
            for(int j=optind;j<argc;j++){
                riadok = vymena(riadok, argv[j], rArg);
            }
        }
        printf("%s",riadok);
        free(riadok), optind = 1;
    }
}