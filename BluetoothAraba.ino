#include "deneyap.h"
#include "BluetoothSerial.h"
BluetoothSerial SerialBT;
void ileriGit();
void geriGit();
void sagaDon();
void solaDon();
void dur();

// Pinler constexpr kullanılarak tanımlandığında, derleme zamanında sabit oldukları için kodun daha verimli çalışmasını sağlar
constexpr int sagTekerlekIleriPin = D15;
constexpr int sagTekerlekGeriPin = D14;
constexpr int solTekerlekIleriPin = D13;
constexpr int solTekerlekGeriPin = D12;

// Gerekli hareketleri fonksiyon halinde yazıyoruz
void ileriGit() {
  digitalWrite(sagTekerlekIleriPin, HIGH);
  digitalWrite(sagTekerlekGeriPin, LOW);
  digitalWrite(solTekerlekIleriPin, HIGH);
  digitalWrite(solTekerlekGeriPin, LOW);
}

void geriGit() {
  digitalWrite(sagTekerlekIleriPin, LOW);
  digitalWrite(sagTekerlekGeriPin, HIGH);
  digitalWrite(solTekerlekIleriPin, LOW);
  digitalWrite(solTekerlekGeriPin, HIGH);
}

void solaDon() {
  digitalWrite(sagTekerlekIleriPin, HIGH);
  digitalWrite(sagTekerlekGeriPin, LOW);
  digitalWrite(solTekerlekIleriPin, LOW);
  digitalWrite(solTekerlekGeriPin, HIGH);
}

void sagaDon() {
  digitalWrite(sagTekerlekIleriPin, LOW);
  digitalWrite(sagTekerlekGeriPin, HIGH);
  digitalWrite(solTekerlekIleriPin, HIGH);
  digitalWrite(solTekerlekGeriPin, LOW);
}

void dur() {
  digitalWrite(sagTekerlekIleriPin, LOW);
  digitalWrite(sagTekerlekGeriPin, LOW);
  digitalWrite(solTekerlekIleriPin, LOW);
  digitalWrite(solTekerlekGeriPin, LOW);
}

void setup() {
  SerialBT.begin("DeneyapKartim");
  pinMode(sagTekerlekIleriPin, OUTPUT);
  pinMode(sagTekerlekGeriPin, OUTPUT);
  pinMode(solTekerlekIleriPin, OUTPUT);
  pinMode(solTekerlekGeriPin, OUTPUT);

  digitalWrite(sagTekerlekIleriPin, LOW);
  digitalWrite(sagTekerlekGeriPin, LOW);
  digitalWrite(solTekerlekIleriPin, LOW);
  digitalWrite(solTekerlekGeriPin, LOW);
}

void loop() {
  if (SerialBT.available()) {
    char deger = SerialBT.read();

    /* !! BİLGİLENDİRME : Burada değer değişkenimiz cihazınızda yüklü olan bluetooth uygulamasından 
    aldığımız sinyali ifade eder. Bu nedenle uygulama ayarlarından istediğiniz komutları koda göre 
    değiştirebilir veya kodu uygulama ayarlarınıza göre düzenleyebilirsiniz. !! */

    switch (deger) {
      case 'F':
        ileriGit();
        break;
      case 'B':
        geriGit();
        break;
      case 'L':
        solaDon();
        break;
      case 'R':
        sagaDon();
        break;
      case 'S':
        dur();
        break;
      default:
        // Beklenmeyen bir karakter ise yapmak istediğiniz işlemi buraya girebilirsiniz
        break;
    }
  }
}
