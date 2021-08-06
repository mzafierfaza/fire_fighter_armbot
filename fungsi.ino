
void deklarasi() {
  for (int i; i < 4; i++) {
    pinMode(btn_pin[i], INPUT_PULLUP);
  }
  pinMode(flameKananPin, INPUT);
  pinMode(flameDepanPin, INPUT);
  pinMode(flameKiriPin, INPUT);
  pinMode(garis, INPUT);
  pinMode(inA1, OUTPUT);
  pinMode(inB1, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(inA2, OUTPUT);
  pinMode(inB2, OUTPUT);
  pinMode(inA3, OUTPUT);
  pinMode(inB3, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(trig_pin_1, OUTPUT);
  pinMode(trig_pin_2, OUTPUT);
  pinMode(trig_pin_3, OUTPUT);
  pinMode(echo_pin_1, INPUT);
  pinMode(echo_pin_2, INPUT);
  pinMode(echo_pin_3, INPUT);
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  pinMode(OutputSensor, INPUT);

  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  gerbang.attach(servo_gerbang);
  gerbang.write(0);
}

void bacaGaris() {
  isGaris = digitalRead(garis);
}

void semprotOff() {
  digitalWrite(inA3, LOW);
  digitalWrite(inB3, LOW);
}

void semprotOn() {
  digitalWrite(inA3, HIGH);
  digitalWrite(inB3, LOW);
}

void maju(int speed) {  // (kiri, -kanan);
  motor(speed, -speed);
}

void kanan(int speed) {
  motor(speed, speed / -3);
}

void kiri(int speed) {
  motor(speed / 3, -speed);
}

void patahKanan(int speed) {
  motor(speed , speed);
}

void patahKiri(int speed) {
  motor(-speed, -speed);
}

void bacaSuhu() {
  suhu = mlx.readObjectTempC();
  suhu = suhu += 3;
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC());
  Serial.print("*C\tObject = "); Serial.print(mlx.readObjectTempC()); Serial.println("*C");
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempF());
  Serial.print("*F\tObject = "); Serial.print(mlx.readObjectTempF()); Serial.println("*F");
}
void motor(int kiri, int kanan) {
  if (kanan > 0) {
    digitalWrite(inA1, HIGH);
    digitalWrite(inB1, LOW);
    analogWrite(pwm1, kanan);
  }
  if (kanan <= 0) {
    digitalWrite(inA1, LOW);
    digitalWrite(inB1, HIGH);
    kanan = abs(kanan);
    analogWrite(pwm1, kanan);
  }
  if (kiri > 0) {
    digitalWrite(inA2, HIGH);
    digitalWrite(inB2, LOW);
    analogWrite(pwm2, kiri);
  }
  if (kiri <= 0) {
    digitalWrite(inA2, LOW);
    digitalWrite(inB2, HIGH);
    kiri = abs(kiri);
    analogWrite(pwm2, kiri);
  }
}

void bacaApi() {
  apiL = digitalRead(flameKiriPin);
  apiF = digitalRead(flameDepanPin);
  apiR = digitalRead(flameKananPin);
}


void bacaBtn() {
  upL = digitalRead(btn_pin[0]);
  downL = digitalRead(btn_pin[1]);
  ok = digitalRead(btn_pin[2]);
  back = digitalRead(btn_pin[3]);
}

void jarakGerbang() {
  digitalWrite(trig_pin_3, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin_3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin_3, LOW);
  const unsigned long duration1 = pulseIn(echo_pin_3, HIGH);
  distanceGerbang = duration1 / 29 / 2;
}

void jarakKiri() {
  digitalWrite(trig_pin_1, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin_1, LOW);
  const unsigned long duration1 = pulseIn(echo_pin_1, HIGH);
  distanceKiri = duration1 / 29 / 2;
}

void jarakDepan() {
  digitalWrite(trig_pin_2, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin_2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin_2, LOW);
  const unsigned long duration1 = pulseIn(echo_pin_2, HIGH);
  distanceDepan = duration1 / 29 / 2;
}


void cekBtn() {
  bacaBtn();
  Serial.println(String() + "downL = " + downL);
  Serial.println(String() + "upL   = " + upL);
  Serial.println(String() + "ok    = " + ok);
  Serial.println(String() + "back  = " + back);
}

void susurKiri() {
  if (distanceKiri >= 10 && distanceKiri <= 13 && distanceDepan >= 25) {
    maju(190); // jalann
    kondisi = "^";
  }
  else if (distanceKiri < 10 && distanceDepan >= 25) {
    kondisi = ">";
    kanan(230); // kanan_maju
  }
  else if (distanceKiri > 13 && distanceKiri <= 35 && distanceDepan >= 25) {
    kondisi = "<";
    kiri(230); // kiri_maju
  }
  else if (distanceKiri > 35 && distanceDepan >= 25) {
    kondisi = "<<";
    patahKiri(220); // kiri_maju
  }
  else if (distanceDepan <= 25) {
    kondisi = ">>";
    patahKanan(220);
    delay(1500);
  }
  else {
    kondisi = "S";
    motor(0, 0);
  }
}
