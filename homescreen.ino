void homescreen() {
  while (1) {
    bacaBtn();
    motor(0, 0);
    if (!upL) {
      if (++mode_no_home > 5) mode_no_home = 0;
      delay(200);
    }
    if (!downL) {
      if (--mode_no_home < 0) mode_no_home = 5;
      delay(200);
    }
    switch (mode_no_home) {
      case 0:
        lcd.setCursor(0, 0); lcd.print("> Mode_1 Rahman ");
        lcd.setCursor(0, 1); lcd.print("  Mode_2 Dea    ");
        if (!ok) modeRahman(); // Mode 1 Rahman MLX sensor
        break;
      case 1:
        lcd.setCursor(0, 0); lcd.print("  Mode_1 Rahman ");
        lcd.setCursor(0, 1); lcd.print("> Mode_2 Dea    ");
        if (!ok) modeDea();  // Mode 2 Dea Refill botol
        break;
      case 2:
        lcd.setCursor(0, 0); lcd.print("> Mode_3 Sabrina");
        lcd.setCursor(0, 1); lcd.print("  Ubah Setpoint ");
        if (!ok) modeSabrina(); // Mode 3 Shabrina robot api
        break;
      case 3:
        lcd.setCursor(0, 0); lcd.print("  Mode_3 Sabrina");
        lcd.setCursor(0, 1); lcd.print("> Ubah Setpoint ");
        if (!ok) cek_gerbang();  // Mode 3 Shabrina robot api
        break;
      case 4:
        lcd.setCursor(0, 0); lcd.print("> Cek Sensor    ");
        lcd.setCursor(0, 1); lcd.print("  Cek Motor     ");
        if (!ok) cekSensor();
        break;
      case 5:
        lcd.setCursor(0, 0); lcd.print("  Cek Sensor    ");
        lcd.setCursor(0, 1); lcd.print("> Cek Motor     ");
        if (!ok) cekMotor();
        break;
    }
  }
}

void cekMotor() {
  lcd.clear();
  delay(200);
  while (1) {
    bacaBtn();
    if (!upL) {
      if (++mode_no_motor > 5) mode_no_motor = 0;
      delay(200);
    }
    if (!downL) {
      if (--mode_no_motor < 0) mode_no_motor = 5;
      delay(200);
    }
    switch (mode_no_motor) {
      case 0:
        lcd.setCursor(0, 0); lcd.print("> Motor Kiri D  ");
        lcd.setCursor(0, 1); lcd.print("  Motor Kiri B  ");
        if (!ok) {
          motor(250, 0);
        }
        else {
          motor(0, 0);
        }
        break;
      case 1:
        lcd.setCursor(0, 0); lcd.print("  Motor Kiri D  ");
        lcd.setCursor(0, 1); lcd.print("> Motor Kiri B  ");
        if (!ok) {
          motor(-250, 0);
        }
        else {
          motor(0, 0);
        }
        break;
      case 2:
        lcd.setCursor(0, 0); lcd.print("> Motor Kanan D ");
        lcd.setCursor(0, 1); lcd.print("  Motor Kanan B ");
        if (!ok) {
          motor(0, 250);
        }
        else {
          motor(0, 0);
        }
        break;
      case 3:
        lcd.setCursor(0, 0); lcd.print("  Motor Kanan D ");
        lcd.setCursor(0, 1); lcd.print("> Motor Kanan B ");
        if (!ok) {
          motor(0, -250);
        }
        else {
          motor(0, 0);
        }
        break;
      case 4:
        lcd.setCursor(0, 0); lcd.print("> Motor Pump    ");
        lcd.setCursor(0, 1); lcd.print("  Gerakan Servo ");
        if (!ok) {
          semprotOn();
        }
        else {
          semprotOff();
        }
        break;
      case 5:
        lcd.setCursor(0, 0); lcd.print("  Motor Pump    ");
        lcd.setCursor(0, 1); lcd.print("> Gerakan Servo ");
        if (!ok) cekServo();
        break;
    }
    if (!back) break;
  }
  delay(200);
  lcd.clear();
}


void cekSensor() {
  lcd.clear();
  delay(200);
  while (1) {
    bacaBtn();
    if (!upL) {
      if (++mode_no_sensor > 3) mode_no_sensor = 0;
      delay(200);
    }
    if (!downL) {
      if (--mode_no_sensor < 0) mode_no_sensor = 3;
      delay(200);
    }
    switch (mode_no_sensor) {
      case 0:
        lcd.setCursor(0, 0); lcd.print("> Sensor Jarak  ");
        lcd.setCursor(0, 1); lcd.print("  Sensor Flame  ");
        if (!ok) cek_jarak();
        break;
      case 1:
        lcd.setCursor(0, 0); lcd.print("  Sensor Jarak  ");
        lcd.setCursor(0, 1); lcd.print("> Sensor Flame  ");
        if (!ok) cek_flame();
        break;
      case 2:
        lcd.setCursor(0, 0); lcd.print("> Sensor Warna  ");
        lcd.setCursor(0, 1); lcd.print("  Sensor MLX    ");
        if (!ok) cek_warna();
        break;
      case 3:
        lcd.setCursor(0, 0); lcd.print("  Sensor Warna  ");
        lcd.setCursor(0, 1); lcd.print("> Sensor MLX    ");
        if (!ok) cek_suhu();
        break;
    }
    if (!back) break;
  }
  delay(200);
  lcd.clear();
}



void cekServo() {
  lcd.clear();
  delay(200);
  while (1) {
    bacaBtn();
    if (!upL) {
      if (++mode_no_servo > 3) mode_no_servo = 0;
      delay(200);
    }
    if (!downL) {
      if (--mode_no_servo < 0) mode_no_servo = 3;
      delay(200);
    }
    switch (mode_no_sensor) {
      case 0:
        lcd.setCursor(0, 0); lcd.print("> Matikan Api   ");
        lcd.setCursor(0, 1); lcd.print("  Refill Botol  ");
        //        if (!ok) matikanApi();
        break;
      case 1:
        lcd.setCursor(0, 0); lcd.print("  Matikan Api   ");
        lcd.setCursor(0, 1); lcd.print("> Refill Botol  ");
        //        if (!ok) cek_flame();
        break;
      case 2:
        lcd.setCursor(0, 0); lcd.print(">  Sanitizer    ");
        lcd.setCursor(0, 1); lcd.print("  Cek Suhu Tubuh");
        //        if (!btn) cek_tcs();
        break;
      case 3:
        lcd.setCursor(0, 0); lcd.print("  Sanitizer     ");
        lcd.setCursor(0, 1); lcd.print("> Cek Suhu Tubuh");
        //        if (!btn) cek_tcs();
        break;
    }
    if (!back) break;
  }
  delay(200);
  lcd.clear();
}

void cek_flame() {
  lcd.clear();
  delay(200);
  while (1) {
    bacaApi();
    bacaBtn();
    lcd.setCursor(0, 0); lcd.print("Kiri Depan Kanan");
    lcd.setCursor(0, 1); lcd.print("  ");
    lcd.print(apiL); lcd.print("     ");
    lcd.print(apiF); lcd.print("     ");
    lcd.print(apiR);
    if (!back) break;
  }
  delay(200);
  lcd.clear();
}



void cek_gerbang() {
  lcd.clear();
  delay(200);
  while (1) {
    bacaBtn();
    jarakGerbang();
    lcd.setCursor(0, 0); lcd.print("Jarak Gerbang : ");
    lcd.setCursor(0, 1); lcd.print(distanceGerbang);lcd.print("   ");lcd.print("CM");
    if (!back) break;
  }
  delay(200);
  lcd.clear();
}



void cek_warna() {
  lcd.clear();
  delay(200);
  while (1) {
    bacaBtn();
    bacaWarna();
    cocokWarna();
    lcd.setCursor(0, 0); lcd.print("R: "); lcd.print(red); lcd.print(" ");
    lcd.setCursor(6, 0); lcd.print(" | ");
    lcd.setCursor(9, 0); lcd.print("G: "); lcd.print(green); lcd.print(" ");
    lcd.setCursor(0, 1); lcd.print("B: "); lcd.print(blue); lcd.print(" ");
    lcd.setCursor(6, 1); lcd.print(" | "); lcd.print(warna); lcd.print(" ");
    if (!ok) mode_saveWarna();
    if (!back) break;
  }
  delay(200);
  lcd.clear();
}



void mode_saveWarna() {
  lcd.clear();
  delay(2000);
  while (1) {
    bacaBtn();
    if (!upL) {
      if (++mode_no_savewarna > 3) mode_no_savewarna = 0;
      delay(200);
    }
    if (!downL) {
      if (--mode_no_savewarna < 0) mode_no_savewarna = 3;
      delay(200);
    }
    switch (mode_no_savewarna) {
      case 0:
        lcd.setCursor(0, 0); lcd.print("> Warna Merah  ");
        lcd.setCursor(0, 1); lcd.print("  Warna Hijau  ");
        if (!ok) {
          saveWarna("Merah");
          delay(500);
          cek_warna();
        }
        break;
      case 1:
        lcd.setCursor(0, 0); lcd.print("  Warna Merah  ");
        lcd.setCursor(0, 1); lcd.print("> Warna Hijau  ");
        if (!ok) {
          saveWarna("Hijau");
          delay(500);
          cek_warna();
        }
        break;
      case 2:
        lcd.setCursor(0, 0); lcd.print("> Warna Biru   ");
        lcd.setCursor(0, 1); lcd.print("  Warna Kuning ");
        if (!ok) {
          saveWarna("Biru");
          delay(500);
          cek_warna();
        }
        break;
      case 3:
        lcd.setCursor(0, 0); lcd.print("  Warna Biru   ");
        lcd.setCursor(0, 1); lcd.print("> Warna Kuning ");
        if (!ok) {
          saveWarna("Kuning");
          delay(500);
          cek_warna();
        }
        break;
    }
    if (!back) break;
  }
}


void cek_suhu() {
  lcd.clear();
  delay(200);
  while (1) {
    bacaSuhu();
    bacaBtn();
    lcd.setCursor(0, 0); lcd.print("Suhu Tubuh = ");
    lcd.setCursor(0, 1); lcd.print(suhu); lcd.print(" C");
    if (!back) break;
  }
  delay(200);
  lcd.clear();
}


void cek_jarak() {
  lcd.clear();
  delay(200);
  String konds;
  while (1) {
    jarakKiri();
    jarakDepan();
    bacaBtn();
    lcd.setCursor(0, 0); lcd.print("Kiri Depan | K  ");
    lcd.setCursor(0, 1); lcd.print("  ");
    lcd.print(distanceKiri); lcd.print("   ");
    lcd.print(distanceDepan); lcd.print("   ");
    lcd.print(konds); lcd.print("    ");
    if (distanceKiri >= 10 && distanceKiri <= 13 && distanceDepan >= 25) {
      konds = "^";
    }
    else if (distanceKiri < 10 && distanceDepan >= 25) {
      konds = ">";
    }
    else if (distanceKiri > 13 && distanceKiri <= 35 && distanceDepan >= 25) {
      konds = "<";
    }
    else if (distanceKiri > 60 && distanceKiri > 60 && distanceDepan >= 25) {
      konds = "<<";
    }
    else if (distanceDepan <= 25) {
      konds = ">>";
    }
    else {
      konds = "S";
    }
    if (!back) break;
  }
  delay(200);
  lcd.clear();
}
