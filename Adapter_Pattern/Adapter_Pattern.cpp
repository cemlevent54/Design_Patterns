#include <iostream>
using namespace std;

// Hedef Arayüz (Target Interface): Avrupa tipi priz
class EuropeanPlug {
public:
    virtual ~EuropeanPlug() = default;
    virtual void connect() const = 0; // Bağlantı yapma fonksiyonu
};

// Adaptee (Uyumlanacak): İngiltere tipi priz
class UKPlug {
public:
    void specificConnect() const {
        cout << "Connected to a UK plug" << endl;
    }
};

// Adapter: UKPlug'u EuropeanPlug'a dönüştürür
class PlugAdapter : public EuropeanPlug {
private:
    const UKPlug* ukPlug; // İngiltere tipi fişi tutar
public:
    explicit PlugAdapter(const UKPlug* plug) : ukPlug(plug) {}

    void connect() const override {
        // UKPlug'un specificConnect fonksiyonunu çağırır
        ukPlug->specificConnect();
    }
};

// Client: Avrupa tipi prizi kullanan cihaz
class EuropeanDevice {
public:
    void powerOn(const EuropeanPlug* plug) {
        cout << "Device is powering on using: ";
        plug->connect();
    }
};

int main() {
    // İngiltere tipi fiş
    UKPlug* ukPlug = new UKPlug();

    // Adaptör: UKPlug'u EuropeanPlug'a çevirir
    PlugAdapter* adapter = new PlugAdapter(ukPlug);

    // Avrupa cihazı
    EuropeanDevice device;

    // Adaptör üzerinden İngiltere fişini Avrupa cihazına bağla
    device.powerOn(adapter);

    // Bellek temizleme
    delete ukPlug;
    delete adapter;

    return 0;
}
