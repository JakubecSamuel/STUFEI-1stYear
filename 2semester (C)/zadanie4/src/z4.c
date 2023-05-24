#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "rng.h"
#include <string.h>

// TODO: miesto pre implementaciu vasich vlastnych funkcii, datovych
//  typov a vlastne makra.

int najdiNajmensieHP(Unit vojsko[], int velkost){
    int min = 0;
    for(int i =  0; i < velkost; i++){
        if(vojsko[i].hp > 0){
            min = i;
            break;
        }
    }
    for(int i = 0; i < velkost; i++){
        if((vojsko[i].hp < vojsko[min].hp) && vojsko[i].hp > 0) min = i;
    }
    return min;
}

int vypocetDMG(int attack_level, int attack_hp, int attack_att, int def_level, int def_hp, int def_deff){
    int base = 0, sila = 0, obrana = 0;
    base = 30 + attack_level - def_level;
    sila = 100 + rnd(1, attack_hp) + attack_att;
    obrana = 100 + rnd(1, def_hp) + def_deff;
    return (base * sila) / obrana;
}

int main(int argc, char *argv[]) {
    int seed = strtol(argv[3], NULL, 0), i = 0, vojskoS = strtol(argv[2], NULL, 0);
    Unit *vojsko; int r = 0, lowest = 0, damage = 0, vyhra = 0, aktualneV = vojskoS, totalMON = 0, totalVOJ = 0, ch = 0;
    srnd(seed);
    if(argc > 4){
        FILE *subor;
        subor = fopen(argv[5],"r");
        if(subor == NULL) return 2;
        for(int i = 0; i < ENEMY_TYPE_COUNT; i++){
            fscanf (subor, "%s", enemy_types[i].name);
            fscanf (subor, "%i", &enemy_types[i].att);
            fscanf (subor, "%i", &enemy_types[i].def);
        }
        fclose(subor);
    }
    // MONSTRUM
    for(; i < 3; i++){
        if(strcmp(argv[1], monster_types[i].name) == 0){
            ch++;
            break;
        }
    }
    if (ch != 1) return 1;
    Unit monstrum = {&monster_types[i], MONSTER_INITIAL_HP, 0};
    printf("%s, ATT:%d, DEF:%d, HP:%d, LVL:%d\n", monstrum.type->name, monstrum.type->att, monstrum.type->def,
           monstrum.hp, monstrum.level);
    // VOJSKO
    vojsko = malloc(sizeof(Unit) * vojskoS);
    for(int j = 0; j < vojskoS; j++){
        r = rnd(0, 7);
        vojsko[j].type = &enemy_types[r];
        r = rnd(ENEMY_MIN_INIT_HP, ENEMY_MAX_INIT_HP);
        vojsko[j].hp = r;
        r = rnd(0, UNIT_MAX_LEVEL);
        vojsko[j].level = r;
        printf("[%d] %s, ATT:%d, DEF:%d, HP:%d, LVL:%d\n", j, vojsko[j].type->name, vojsko[j].type->att,
               vojsko[j].type->def, vojsko[j].hp, vojsko[j].level);
    }
    printf("\n");
    // SUBOJ
    while(vyhra != 1){
        lowest = najdiNajmensieHP(vojsko, vojskoS);
        damage = vypocetDMG(monstrum.level, monstrum.hp, monstrum.type->att, vojsko[lowest].level, vojsko[lowest].hp,
                            vojsko[lowest].type->def);
        vojsko[lowest].hp -= damage;
        totalMON += damage;
        printf("%s => %d => [%d] %s\n", monstrum.type->name, damage, lowest, vojsko[lowest].type->name);
        if(vojsko[lowest].hp <= 0) aktualneV--;
        if(aktualneV == 0) vyhra = 1;
        if(vyhra != 1){
            for(int j = 0; j < vojskoS; j++){
                if(vojsko[j].hp > 0){
                    damage = vypocetDMG(vojsko[j].level, vojsko[j].hp, vojsko[j].type->att, monstrum.level, monstrum.hp,
                                        monstrum.type->def);
                    monstrum.hp -= damage;
                    totalVOJ += damage;
                    printf("[%d] %s => %d => %s\n", j, vojsko[j].type->name, damage, monstrum.type->name);
                    if(monstrum.hp <= 0){
                        vyhra = 1;
                        break;
                    }
                }
            }
        }
        printf("\n");
        if(monstrum.hp > 0 && monstrum.level != 10) monstrum.level++;
        printf("%s, ATT:%d, DEF:%d, HP:%d, LVL:%d\n", monstrum.type->name, monstrum.type->att, monstrum.type->def,
               monstrum.hp, monstrum.level);
        for(int j = 0; j < vojskoS; j++){
            printf("[%d] %s, ATT:%d, DEF:%d, HP:%d, LVL:%d\n", j, vojsko[j].type->name, vojsko[j].type->att,
                   vojsko[j].type->def, vojsko[j].hp, vojsko[j].level);
        }
        printf("\n");
    }
    if (monstrum.hp > 0) printf("Winner: %s\n", monstrum.type->name);
    else printf("Winner: Enemy\n");
    printf("Total monster DMG: %d\n", totalMON);
    printf("Total enemies DMG: %d", totalVOJ);
}