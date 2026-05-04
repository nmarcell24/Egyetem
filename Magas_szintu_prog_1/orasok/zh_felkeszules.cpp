#include <fstream>
#include <algorithm>
#include <iostream>
#include <array>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;
    // ZH FELKESZULES - Hasonlo feladatok mint a zh_gyak.cpp alapjan
    // ================================================================

    // 1. feladat: Onbejaro ciklus
    //    - Irj egy fuggvenyt, amely megkapja a also es felso hatart (a, b),
    //      es visszaadja a legnagyobb [a, b] intervallumba eso 3-mal oszthato szamot.
    //      Ha nincs ilyen, adjon vissza -1-et.
    //      Hasznalj while ciklust (ne for-t)!
    int legnagyobb3mal(int a, int b) {
        int legn = 1;
        while(a <= b) {
            if(a % 3 == 0) {
                legn = a;
            }
            a++;
        }
        
        return legn;
    }

    // 2. feladat: Programozasi tetel megvalositasa
    //    - Irj egy fuggvenyt, amely megkap egy 5x5-os int tombort,
    //      es visszaad egy 5 elemu double tombot (array<double,5>),
    //      amely az egyes oszlopok atlagat tartalmazza.
    array<double, 5> oszlopatlag(int tomb[5][5]) {
        array<double, 5> atlagok;

        for(int i = 0; i < 5; i++) {
            double sum = 0;
            for(int j = 0; j < 5; j++) {
                sum += tomb[j][i];
            }
            atlagok[i] = sum / 5.0;
        }

        return atlagok;
    }

    // 3. feladat: & fuggveny irasa
    //    - Irj egy fuggvenyt:
    //      amely a tomb elemeinek osszeget az 'eredmeny' referencian keresztul adja vissza.
    void osszead(int& eredmeny, int tomb[], int meret) {
        for(int i = 0; i < meret; i++) {
            eredmeny += tomb[i];
        }

    }

    // 4
    bool prim_e(int n) {
        if (n < 2) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;

        for(int i = 3; i <= sqrt(n); i += 2) {
            if(n % i == 0) {
                return false;
            }
        }

        return true;
    }

    //5
    struct Diak {
        string nev;
        int jegy; 
    };

    int main() {
        //1
        cout << legnagyobb3mal(1,6) << endl;

        //2
        int tomb2d[5][5] = {{1,2,3,4,5}, {5,6,7,8,9}, {9,10,11,12,13}, {13,14,15,16,17}, {18, 19, 20, 21, 22}};

        for(double atlag: oszlopatlag(tomb2d)){
            cout << atlag << ", ";
        }

        cout << endl;

        //3
        int szamok[] = {3, 7, 2, 8, 5};
        int eredmeny = 0;

        osszead(eredmeny, szamok, 5);

        cout << "Osszeg: " << eredmeny << endl;  // 25
        cout << endl;


        // 4. feladat: Programozasi tetel megvalositasa bekeressel
        //    - Kerj be n db egesz szamot a felhasznalotol.
        //      Hatarozd meg, hogy van-e kozottuk prim szam!
        //      Irasd ki: "Van prim: igen" vagy "Van prim: nem"
        int db;
        cout << "Mennyi szamot kersz be:" << endl;
        cin >> db;
        
        int szamokk[db];

        for(int i = 0; i < db; i++){
            cin >> szamokk[i];
        }

        cout << "Van prim: ";
        bool van_e = false;
        for (int szam: szamokk) {
            if ( prim_e(szam) ) {
                van_e = true;
                break;
            }
        }

        cout << (van_e ? "van" : "nincs") << endl;

        // 5. feladat: Programozasi tetel megvalositasa (struct)
        //    - Adott egy Diak struct (nev string, jegy int).
        //      Van egy 6 elemu tomb belole.
        //      Szamold meg, hanyan kaptak jelest (jegy == 5).
        //      Irasd ki az eredmenyt!
        Diak diakok[6] = {{"a", 1}, {"b", 5}, {"c", 4}, {"d", 1}, {"e", 5}, {"f", 3}};

        int dbJegy = 0;

        for(Diak d: diakok) {
            if(d.jegy == 5){
                dbJegy++;
            }
        }

        cout << dbJegy << " ember kapott 5-ös osztályzatot." << endl;


        // 6. feladat: Filebol olvasas + fileba kiiras
        //    - Olvasd be a "pontszamok.txt" fajlt, amely soronkent egy nevet
        //      es egy egesz szamot (0-100) tartalmaz.
        //      Irasd ki az "atment.txt" fajlba azokat a neveket, akik >= 50 pontot kaptak,
        //      es a "megbukott.txt" fajlba akik < 50 pontot kaptak.
        ifstream in("pontszamok.txt");
        ofstream out_pass("atment.txt");
        ofstream out_failed("megbukott.txt");

        string line;

        while(getline(in, line)) {
            stringstream ss(line);
            string nev;
            int pont;

            if(ss >> nev >> pont) {
                if(pont >= 50) {
                    out_pass << nev << " " << pont << endl;
                } else {
                    out_failed << nev << " " << pont << endl;
                }
            }
        };

        cout << "Kesz! Eredmenyek kimentve az atment.txt es megbukott.txt fajlokba." << endl;
        in.close();
        out_failed.close();
        out_pass.close();

        return 1;
    }