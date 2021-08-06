class ServoGo {
    int updateInterval;
    unsigned long lastUpdate;
    int pos;
    int increment;
    int servo;
    bool langkah;
    bool logici;
    int fromOri;
    int toOri;

  public:
    ServoGo(int channel, int interval, int setep) // channel dan speed
    {
      updateInterval = interval;
      increment = setep;
      servo = channel;
    }

    bool getLangkah () {
      return langkah;
    }

    void setLogic (bool nilai) {
      logici = nilai;
    }

    bool getLogic() {
      return logici;
    }

    void setupStart(int nilai) {
      nilai = map(nilai, 0, 180, 500, 2500);
      pwm.writeMicroseconds(servo, nilai); // 90 derajat pas setup
    }

    void goTo(int from, int to) {
      if (logici == true) {
        fromOri = map(from, 0, 180, 500, 2500);
        toOri = map(to, 0, 180, 500, 2500);
        pos = fromOri;
        Serial.println("its supposed to be once");
        logici = false;
      }
      while (logici == false) {
        int stepL = toOri - pos;
        if (!(stepL <= 5 && stepL >= -5)) {
          langkah = false;
          if ((millis() - lastUpdate) > updateInterval) {
            lastUpdate = millis();
            if (fromOri < toOri) {
              pwm.writeMicroseconds(servo, pos);
              pos += increment;
              Serial.println(pos);
            }
            if (fromOri > toOri) {
              pwm.writeMicroseconds(servo, pos);
              pos -= increment;
              Serial.println(pos);
            }
          }
        }
        else {
          langkah = true;
          Serial.println("Lanjut");
          break;
        }
      }
    }
};


void gerak(int i, int a, int b, float spid) //(nomor servo, sudut sblumnya, sudut tujuan, kecepatan)
{
  float A = map(a, 0, 180, 500, 2500);
  float B = map(b, 0, 180, 500, 2500);

  if (A > B) {
    for (float microsec = A; microsec > B; microsec = microsec - spid) {
      pwm.writeMicroseconds(i, microsec);
      Serial.println("empat");
    }
  }
  if (A < B) {
    for (float microsec = A; microsec < B; microsec = microsec + spid) {
      pwm.writeMicroseconds(i, microsec);
      Serial.println("empat");
    }
  }
}
