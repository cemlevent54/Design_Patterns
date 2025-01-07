#include <iostream>
using namespace std;
// Singleton 
// ilk çağrıldığında nesneyi oluşturur, sonraki çağrılarda aynı nesneyi döndürür
class ChocolateBoiler {
private:
    bool empty;
    bool boiled;
    static ChocolateBoiler* uniqueInstance; // yalnızca bir kez oluşturulur

    // Private Constructor: Sınıfın dışında nesne oluşturulmasını engeller
    ChocolateBoiler() {
        empty = true;
        boiled = false;
    }

public:
    // Singleton Instance Alıcı
    // Aynı nesneye global erişim sağlar
    static ChocolateBoiler* getInstance() {
        if (uniqueInstance == NULL) {
            uniqueInstance = new ChocolateBoiler();
        }
        return uniqueInstance;
    }

    // Boiler'ı doldur
    void fill() {
        if (isEmpty()) {
            empty = false;
            boiled = false;
            cout << "Boiler is filled with milk and chocolate mixture." << endl;
        }
        else {
            cout << "Boiler is already filled!" << endl;
        }
    }

    // Karışımı kaynat
    void boil() {
        if (!isEmpty() && !isBoiled()) {
            boiled = true;
            cout << "Boiler is boiling the mixture." << endl;
        }
        else if (isBoiled()) {
            cout << "Boiler is already boiled!" << endl;
        }
        else {
            cout << "Cannot boil an empty boiler!" << endl;
        }
    }

    // Karışımı boşalt
    void drain() {
        if (!isEmpty() && isBoiled()) {
            empty = true;
            cout << "Boiler is drained." << endl;
        }
        else if (isEmpty()) {
            cout << "Boiler is already empty!" << endl;
        }
        else {
            cout << "Cannot drain without boiling!" << endl;
        }
    }

    // Boiler boş mu?
    bool isEmpty() {
        return empty;
    }

    // Boiler kaynadı mı?
    bool isBoiled() {
        return boiled;
    }
};

// Singleton Nesnesi Başlatma
ChocolateBoiler* ChocolateBoiler::uniqueInstance = NULL;

// Main Fonksiyonu
int main() {
    ChocolateBoiler* boiler = ChocolateBoiler::getInstance();
    boiler->fill();
    boiler->boil();
    boiler->drain();

    // Aynı örneği döndürdüğünü kontrol edelim
    ChocolateBoiler* boiler2 = ChocolateBoiler::getInstance();
    if (boiler == boiler2)
        cout << "Got the same boiler instance." << endl;
    else
        cout << "Oh oh! Got a different boiler instance." << endl;

    return 0;
}
