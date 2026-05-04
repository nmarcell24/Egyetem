#include <iostream>

using namespace std;

//eljaras
void print(int a, int b) {
    cout << a << " " << b << endl;
}

void println(int a) {
    cout << a << endl;
}

void csere(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void tombkiir(int t[5]) {
    for (int i = 0; i < 5; i++) {
        cout << t[i] << " ";
    }
    cout << endl;
}

int min(int* tomb, int meret) {
    int m = tomb[0];
    for(int i = 1; i < meret; i++) {
        if(tomb[i] < m) {
            m = tomb[i];
        }
    }
    return m;
}

// int factorial(int n) {
//    int sum = 1;

//    for(int i = n; i > 1; i--){
//     sum *= i;
//    }

//    return sum;
// }

int factorial(int n) {
    if(n == 1) {
        return 1;
    }

    return n * factorial(n-1);
}

int fibonacci(int n) {
    if(n <= 1) {
        return n; 
    }

    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    //stack memoria (nem tananyag)
    int a;
    int t[5];

    //heap memoria (nem tananyag)
    int* p = new int;
    int* tp = new int[5];

    int* p2 = new(nothrow) int;

    if(!p2) {
        cout << "Sikertelen memoria all" << endl;
    } else {
        *p2 = 32;
    }

    float* f = new float(3.58);

    for(int i = 0; i < 5; i++) {
        t[i] = i;
        cout << tp[i] << " ";
    }
    cout << endl;

    delete p;
    delete[] tp;
    delete p2;
    delete f;


    //fvg
    int x = 6;
    int y = 7;

    print(x, y);

    tombkiir(t);

    int tomb[5] = {1,2,3,4,5};

    int m = min(tomb, 5);

    println(m);
    
    println(factorial(4));

    println(factorial(4));
}