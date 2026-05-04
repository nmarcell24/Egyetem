// 1. feladat
// Változó Vlad
// Pointer Pete
// Xerox Chad
// Key Dealer Kevin
// Scope Sensei
// Gerenic Greg
// Recursion Rick

// 2. feladat
// A)
void valtoztat(int x) {
    x = 999;
}
int chad = 50; 
valtoztat(chad); // chad értéke még mindig: 50

// B)
int ertek = 55;
int* pete = &ertek;
*pete = 77;
printf("%d", ertek); // kimenet: 77

// C)
int osszeg(int n) {
    if (n == 0) return; // base case return n + osszeg(n - 1);
}
printf("%d", osszeg(4)); // = 4+3+2+1+0 = 10

// 3. feladat
// a) Segfault Samu - nullptr dereferálás
int* p = nullptr; printf("%d", *p);

// b) Memory Leak Miki - malloc de soha nem free
int* p = (int*)malloc(sizeof(int)); *p = 42;

// c) Stack Overflow Stan - nincs base case
int vegtelen(int n) {
    return vegtelen(n);
}

// 4. feladat
// Stack Steve - Stack memory
// LIFO működésű, automatikus helyfoglalás és felszabadítás
void fuggveny() {
    int a = 5;  // Rákerül a Stackre
    int b = 10; // Rákerül a Stack tetejére
} // Itt 'a' és 'b' AUTOMATIKUSAN törlődik a Stackről