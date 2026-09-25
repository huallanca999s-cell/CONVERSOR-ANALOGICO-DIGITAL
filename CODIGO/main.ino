// CODIGO DEL CONVERSOR DE ANALOGICO A DIGITAL CON ARDUINO

const int lm35Pin = A1;  // Pin del sensor LM35
const int dacPins[8] = {2, 3, 10, 5, 6, 7, 8, 9};  // Pines para el DAC0808
void setup() {
  Serial.begin(9600);  // Iniciar monitor serial

  for (int i = 0; i < 8; i++) {
    pinMode(dacPins[i], OUTPUT);
  }
}
void loop() {
  int analogValue = analogRead(lm35Pin);     // Lectura del LM35 (0–1023)
  float voltaje = analogValue * (5.0 / 1023.0);  // Conversión a voltios
  float tempC = voltaje * 100;              // Cada 10mV = 1 °C

  byte digital8bit = analogValue / 2;
  if (digital8bit > 255) digital8bit = 255;

  sendToDAC(digital8bit);

  // Mostrar voltaje para graficarlo
  Serial.print(voltaje);
  Serial.print("mV, °C");
  Serial.println(tempC);

  delay(100);  // Cada 100 ms
}
void sendToDAC(byte value) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(dacPins[i], bitRead(value, i));
  }
}
