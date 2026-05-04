// 1. feladat
// Osztály Olga
// Objektum Oszkár
// Konstruktor Kristóf
// Destruktor Dezső
// Öröklődő Olivér
// Early Binding Eddie
// Polimorf Péter
// Bezáró Bence
// Late Binding Lajos
// 2. feladat
// A)
class Auto {
    // konstruktor (inicializálja marka-t és foglalja le az ev-et heap-en)
    public: std::string marka; int* ev; 
    Auto(std::string m) {
        marka = m; 
        ev = new int(2024);
    } 
    // destruktor (szabadítsa fel ev-et)
    ~Auto() {
        delete ev;
    }
};

// B)
class BankSzamla {
    private: int egyenleg = 0; // Belülről látszik, kívülről nem
    protected: int hitelkeret = 50000; // Leszármazott is látja, kívülső nem
    public: void befizet(int x); // Mindenki hívhatja
};


// C)
Allat* allatok[] = {
    new Kutya(), 
    new Macska(), 
    new Kutya() 
};
// Kimenetek sorban: Vau , Meow , Vau
for (auto* a : allatok) a->hangotAd();

// 3. feladat
// X osztály - interfész, mert minden metódusa pure virtuális
class X {
    public: 
    virtual void mozog() = 0; 
    virtual void megall() = 0; 
    virtual ~X() = default; 
};
// Y osztály - absztrakt, mert van legalább egy pure virtuális metódusa
class Y {
    public: virtual void mozog() = 0; 
    void legzik() { /* van impl. */ }
    int energia = 100;
};


// 4. feladat
// Early
// Late
// Early
// Early
// Late

//5.feladat
class Karakter {
    private: int id;                  
    protected: std::string nev; int eletero;    

    public: Karakter(std::string n, int hp) : nev(n), eletero(hp), id(rand()) {}

    virtual void tamad() = 0;          
    virtual void bemutatja_magat() const {  
        std::cout << "Karakter: " << nev << ", HP: " << eletero << "\n";
    }

    virtual ~Karakter() {} 
};


class Harcos : public Karakter {
    protected: int tamadoEro;

    public: Harcos(std::string n, int hp, int atk) : Karakter(n, hp), tamadoEro(atk) {}

    virtual void tamad() = 0;
    void bemutatja_magat() const override {
        Karakter::bemutatja_magat();
        std::cout << "  Támadóerő: " << tamadoEro << "\n";
    }
};


class Lovag : public Harcos {
    private:std::string rendneve;

    public:Lovag(std::string n, std::string rend): Harcos(n, 150, 40), rendneve(rend) {}
    
    void tamad() override {
        std::cout << nev << " kardot sújt! (-" << tamadoEro << " HP)\n";
    }
    void bemutatja_magat() const override {
        Harcos::bemutatja_magat();
        std::cout << "  Rend: " << rendneve << "\n";
    }
};

