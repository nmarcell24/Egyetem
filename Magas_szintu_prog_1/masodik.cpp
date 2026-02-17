#include <iostream>
using namespace std;

int main() {
    // logikai operátorok
    // && ||! - és, vagy, negáció
    bool b = 60 > 5;
    cout << !b << " " << (b && true) << " " << ((60>5) || false) << endl;
    
    // bitműveletek
    // & | ^ << >>
    // bitenkénti és, vagy, XOR, eltolás balra, eltolás jobbra
    
    // bit szinten:
    // A = 60
    // B = 13
    // A = 0 0 1 1 1 1 0 0
    // B = 1 0 1 1 0 0 0 0 + kép

    int A = 60;
    int B = 13;

    cout << (A & B) << " " << (A | B) << endl;

    // bitenkénti eltolás
    cout << (A << 2) << endl;

    // értékadó operátorok
    // = += -= *= /= %= <<= >>= &= |= ^=    
    // a += 2  ==> a = a + 2
    // B >>= 2 ==> B = B >> 2

    // tömbök
    int tomb[5] = {1, 2, 3, 4, 5};
    // 5x 4 byteot kell lefoglalni
    cout << tomb[0] << endl;
    cout << tomb[120] << endl; // 120x4bájt

    char sztring[] = "Hello, world!";
    sztring[0] = 'h';
    cout << sztring << endl;

    string cppstring  = "Hello, world!";
    cppstring[0] = 'h';
    cout << cppstring << endl;

    cout << cppstring.length() << endl;
    cout << cppstring.size() << endl;

    // implicit típuskonverzió (bővítés)
    int num = 92;
    double d = num; // 92.00000

    // (szűkítés)
    d = 11.1123;
    num = d;

    // explicit típuskonverzió
    num = int(d);

    // elágazás
    if (21 > 10) {
        cout << "nagyobb" << endl;
    } else if (10 == 21){
        cout << "egyenlő" << endl;
    } else {
        cout << "kisebb" << endl;
    }

    if (10 > 9) {
        if (2 < 3) {
            cout << "belső if" << endl;
        }
    }

    // ternális operátor
    int tern = 10 < 9 ? 1 : 0;
    cout << tern << endl;
    
    int x1 = 1;
    int y1 = 10;
    // string eredmeny;
    // eredmeny = (x1 == y1) ? "egyenlő" : "nem egyenlő";
    // cout << eredmeny << endl;
 
    // feladat

    // x1 > y1 
    // x1 == y1 
    // x1 < y1 
    string eredmeny = (x1 == y1) ? "egyenlő" : ((x1 > y1) ? "nagyobb" : "kisebb");   
    cout << eredmeny;
    if (x1 = 2) {
        cout << "belép" << endl;
    };

    int nap = 7;
    switch (nap) {
        case 6:
            cout << "szombat" << endl;
            break;
        case 7:
            cout << "vasárnap" << endl;
            break;
        default:
            cout << "mindjárt hétvége" << endl;
            break;
    };

    // ciklusok

    // előterjesztett ciklus
    // int i = 0;
    // while (i < 10) {
    //     cout << i << " ";
    //     i++;
    // }
    // cout << endl;

    // 10-től 5-ig
    double i = 10;

    while (i > 5) {
        cout << i << " ";
        i -= 0.1;
    }

    cout << endl;


    char c = 'a';
    while (c <= 'z') {
        cout << c << " " << int(c) << endl;
        c++;
    }

    return 0;
}