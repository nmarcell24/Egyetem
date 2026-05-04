#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};


    // Maximum kiválasztás

    int max = v[0];
    int maxind = 0;

    for (int i = 1; i < v.size(); i++) {
        if (v[i] > max) {
            max = v[i];
            maxind = i;
        }
    }

    cout << "A vektor maximuma: " << max << "a" << maxind << "pozícióban található." << endl;


    // Megszámlálás

    int count = 0;
    for(int i = 0; i < v.size(); i++) {
        if(v[i] == 2) {
            count++;
        }
    }

    cout << count << "db 2 van a vektorban" << endl;


    // Szétválogatás

    vector<int> paros;
    vector<int> paratlan;

    for(int i = 0; i < v.size(); i++) {
        if(v[i] % 2 == 0) {
            paros.push_back(v[i]);
        } else {
            paratlan.push_back(v[i]);
        }
    }

    cout << "Paros elemek: ";
    for(int i = 0; i < paros.size(); i++) {
        cout << paros[i] << " ";
    }
    cout << endl;

    cout << "Paratlan elemek: ";
    for(int i = 0; i < paratlan.size(); i++) {
        cout << paratlan[i] << " ";
    }
    cout << endl;


    return 0;
}