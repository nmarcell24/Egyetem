#include <iostream>
#include <vector>

using namespace std;

// tulterheles - korai kotes - statikus kotes - forditas ideju polimorfizmus - fuggetlen polimorfizmus
int absolute(int i) {
    if(i < 0) {
        return -i;
    }
    return i;
}

float absolute(float f) {
    if(f < 0) {
        return -f;
    }
    return f;
}

vector<int>& operator<<(vector<int>& v, int i) {
    v.push_back(i);
    return v;
}


vector<int> operator+(vector<int> v, vector<int> w) {
    vector<int> ossz;
    for(int i : v) {
        ossz << i;
    }
    for(int i : w) {
        ossz << i;
    }
    return ossz;
}


void operator++(vector<int> v){
    for(int i : v) {
        cout << i << " ";
    }
    cout << endl;
}


struct szemely {
    string nev;
    int kor;

    void operator()(string n, int e) {
        nev = n;
        kor = e;
    }

};

ostream& operator<<(ostream& os, struct szemely& s) {
    os << s.nev << " " << s.kor;
    return os;
}


int main() {
    absolute(5);
    absolute(5.5f);
    
    vector<int> v = {0,1,2};
    v.push_back(3);
    v << 4;
    ++v;

    v << 5 << 6 << 7;
    ++v;

    szemely sz1;
    sz1.nev = "Kitti";
    sz1.kor = 20;
    
    szemely sz2;
    sz2("Bence", 21);

    
    cout << sz1 << " " << sz2 << endl;

}