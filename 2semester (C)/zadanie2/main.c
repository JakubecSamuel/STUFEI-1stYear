#include <stdio.h>
#include <string.h>
#define Nmin 10
#define Nmax 100
#define R_MAX 2147483647
static long long unsigned int SEED = 0x1;

struct Hrac{
    int pos;
    int boost;
} hrac1, hrac2;

void srnd(int seed) {
    SEED = seed;
}

int rnd(int from, int to) {
    SEED = SEED * 16807 % R_MAX;
    return from + (int) SEED % (to - from + 1);
}

void generateMap(int n, int draha[n], int block, int boost){
    int random, i = 0, j = 0;
    for(int c = 0; c <= n; c++){
        draha[c] = 0;
    }
    if(block != 0){
        while (1 == 1){
            random = rnd(1, n-1);
            if(draha[random] == 0) draha[random] = 1, i++;
            if(i == block) break;
        }
    }
    if(boost != 0){
        while (1 == 1){
            random = rnd(1, n-1);
            if(draha[random] == 0) draha[random] = 2, j++;
            if(j == boost) break;
        }
    }
}

void vypisHodnot(int n, int draha[n]){
    printf("BLOCK:");
    for (int j = 0; j < n; j++){
        if (draha[j] == 1) printf("%d ", j);
    }
    printf("\nBOOST:");
    for (int j = 0; j < n; j++){
        if (draha[j] == 2) printf("%d ", j);
    }
    printf("\n");
}

void vymena(int *h1, int *h2){
    int i;
    i = *h1, *h1 = *h2, *h2 = i;
}

int max(int r1, int r2){
    if (r1 > r2) return r1;
    else return r2;
}

int main() {
    // 0 - prazdne, 1 - block, 2 - boost, 3 - hrac1, 4 - hrac2
    int seed, block, boost, r1, r2, d = 0, turn = 1, hot = 0;
    int n;
    scanf("%d %d %d %d", &seed, &n, &block, &boost);
    if ((block + boost > n/2) || (seed <= 0) || (n > Nmax) || (n < Nmin)) return 1;
    srnd(seed);
    int draha[n+1], hotspot[n+1];
    for(int c = 0; c <= n; c++){
        hotspot[c] = 0;
    }
    generateMap(n, draha, block, boost);
    vypisHodnot(n, draha);
    hrac1.pos = -1, hrac2.pos = -1, hrac1.boost = 0, hrac2.boost = 0;
    while (1 == 1){
        //vypocet d
        r1 = rnd(1,6), r2 = rnd(1,6);
        printf("[%d,1] [%d,%d] [%d,%d]", turn, hrac1.pos, hrac1.boost, r1, r2);
        if(hrac1.pos == -1){
            if(r1+r2 > 7) hrac1.pos = 0, d = r1+r2-7;
            else d = 0;
        }
        else if((hrac1.pos < hrac2.pos && hrac2.pos != -1) && (r1 == 6 && r2 == 6) ||
                (hrac1.pos > hrac2.pos && hrac2.pos != -1) && (r1 == 1 && r2 == 1)){
            vymena(&hrac1.pos, &hrac2.pos);
            draha[hrac1.pos] = 3, draha[hrac2.pos] = 4;
            hotspot[hrac2.pos]++;
            d = 0;
        }
        else d = max(r1,r2);
        //posun
        if(d > 0 && hrac1.pos < n){
            draha[hrac1.pos] = 0;
            hrac1.pos = hrac1.pos + d + hrac1.boost;
        }
        if(hrac1.pos != -1 && hrac1.pos < n && draha[hrac1.pos] == 2){
            draha[hrac1.pos] = 3, hrac1.boost++;
        }
        else if(hrac1.pos != -1 && hrac1.pos < n && draha[hrac1.pos] == 1){
            if(hrac1.boost > 0) hrac1.boost = 0, draha[hrac1.pos] = 3, hotspot[hrac1.pos]++;
            else draha[hrac1.pos] = 0, hotspot[hrac1.pos]++, hrac1.pos = -1;
        }
        else if(hrac1.pos != -1 && hrac1.pos < n && draha[hrac1.pos] == 4){
            hrac2.pos = -1, draha[hrac1.pos] = 3;
        }
        else if(hrac1.pos != -1 && hrac1.pos < n) draha[hrac1.pos] = 3;
        hotspot[hrac1.pos]++;
        printf(" [%d,%d]\n", hrac1.pos, hrac1.boost);
        if (hrac1.pos >= n){
            printf("WINNER:1\n");
            for(int i = 1;i < n; i++){
                if (hotspot[i] >= hot) hot = hotspot[i];
            }
            printf("HOTSPOT:%d", hot);
            return 0;
        }
        turn++;
        //vypocet d
        r1 = rnd(1,6), r2 = rnd(1,6);
        printf("[%d,2] [%d,%d] [%d,%d]", turn, hrac2.pos, hrac2.boost, r1, r2);
        if(hrac2.pos == -1){
            if(r1+r2 > 7) hrac2.pos = 0, d = r1+r2-7;
            else d = 0;
        }
        else if((hrac2.pos < hrac1.pos && hrac1.pos != -1) && (r1 == 6 && r2 == 6) ||
                (hrac2.pos > hrac1.pos && hrac1.pos != -1) && (r1 == 1 && r2 == 1)){
            vymena(&hrac1.pos, &hrac2.pos);
            draha[hrac1.pos] = 3, draha[hrac2.pos] = 4;
            hotspot[hrac1.pos]++;
            d = 0;
        }
        else d = max(r1,r2);
        //posun
        if(d > 0){
            draha[hrac2.pos] = 0;
            hrac2.pos = hrac2.pos + d + hrac2.boost;
        }
        if(hrac2.pos != -1 && hrac2.pos < n && draha[hrac2.pos] == 2){
            draha[hrac2.pos] = 4, hrac2.boost++;
        }
        else if(hrac2.pos != -1 && hrac2.pos < n && draha[hrac2.pos] == 1){
            if(hrac2.boost > 0) hrac2.boost = 0, draha[hrac2.pos] = 4, hotspot[hrac2.pos]++;
            else draha[hrac2.pos] = 0, hotspot[hrac2.pos]++, hrac2.pos = -1;
        }
        else if(hrac2.pos != -1 && hrac2.pos < n && draha[hrac2.pos] == 3) hrac1.pos = -1, draha[hrac2.pos] = 4;
        else if(hrac2.pos != -1 && hrac2.pos < n) draha[hrac2.pos] = 4;
        hotspot[hrac2.pos]++;
        turn++;
        printf(" [%d,%d]\n", hrac2.pos, hrac2.boost);
        if (hrac2.pos >= n){
            printf("WINNER:2\n");
            for(int i = 1; i < n; i++){
                if (hotspot[i] >= hot) hot = hotspot[i];
            }
            printf("HOTSPOT:%d", hot);
            return 0;
        }
    }
}
