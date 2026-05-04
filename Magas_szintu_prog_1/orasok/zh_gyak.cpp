#include <fstream>
#include <algorithm>
#include <iostream>
#include <array>
#include <vector>
#include <sstream>

using namespace std;

int legnagyobbfibo(int a, int b) {
    //1. feladat
    int legnagyobb = -1;
    
    int x = 0;
    int y = 1;

    while (x <= b) {
        if(x >= a) {
            legnagyobb = x;
        }

        int kov = x + y;
        x = y;
        y = kov;
    }

    return legnagyobb;
}

//2.feladat
array<double, 4> soratlag(int t[4][4]) {
    array<double, 4> atlagok;

    for (int i = 0; i < 4; i++) {
        int osszeg = 0;
        for (int j = 0; j < 4; j++) {
            osszeg += t[i][j];
        }
        atlagok[i] = osszeg / 4.0;
    }
    return atlagok;
}

//3. feladat
void masolas(char& a, char ct[10], int b) {
    a = ct[b];
}

struct Doboz {
    int x;
    int y;
    int z;
};

int main() {
    cout << legnagyobbfibo(1, 10) << endl;
    int tomb2d[4][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};

    for(double d: soratlag(tomb2d)) {
        cout << d << " ";
    };
    cout << endl;


    //4.feladat
    int n;
    cout << "Adjon meg egy egesz szamot: " << endl;
    cin >> n;

    string st[n];

    cout << "Adjon meg " << n << " db szokoz nelkuli stringet: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> st[i];
    }

    string rovid = st[0];
    string hosszu = st[0];

    for (int i = 0; i < n; i++)
    {
        if(st[i].length() > hosszu.length()) {
            hosszu = st[i];
        }
        if(st[i].length() < rovid.length()) {
            rovid = st[i];
        }
    }

    cout << rovid << " " << hosszu << endl;

    //5. feladat
    Doboz dt[5] = {{1,7,3}, {12, 5, 1}, {62, 134, 2}, {51, 5 ,3}, {76, 4, 21}};
    int osszeg = 0;

    int ty = 0;
    for (int i = 0; i < 5; i++)
    {
        ty = dt[i].y;
    }

    cout << "A torony teljes magassaga: " << ty << endl;
     
    //6. feladat
    ifstream be("randomok.txt");
    ofstream ki("kisebb.txt");

    vector<vector<int>> adatok;

    string sor;

    while(getline(be, sor, " ")) {
        stringstream ss(sor);
        vector<int> egysor;
        int szam;

        while(ss >> szam) {
            egysor.push_back(szam);
        }

        adatok.push_back(egysor);
    }
    
    
    for (int i = 0; i < adatok.size(); i++){
        int osszeg = 0;
        for (int j = 0; j < adatok[i].size(); j++){
            osszeg += adatok[i][j];
        }
        
        double atlag = osszeg/adatok[i].size();

        if(atlag < 37) {
            ki << "Igen." << endl;
        } else {
            ki << "Nem." << endl;
        }

    }
    be.close();
    ki.close();
}
