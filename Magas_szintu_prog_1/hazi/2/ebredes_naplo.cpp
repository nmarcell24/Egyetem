#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Ebredes {
    char nap[9];
    int ido;
};

int main() {
    char napok[7][20] = {"Hétfő", "Kedd", "Szerda", "Csütörtök", "Péntek", "Szombat", "Vasárnap"};
    Ebredes ebredesek[7];

    srand(time(NULL));

    for (int i = 0; i < 7; i++) {
        int randomTimeIndex = rand() % 24;
        strcpy(ebredesek[i].nap, napok[i]);
        ebredesek[i].ido = randomTimeIndex;
    }
    
    for (int i = 0; i < 7; i++) {
        printf("%s: %d:00\n", ebredesek[i].nap, ebredesek[i].ido);
    }

    return 0;
}
