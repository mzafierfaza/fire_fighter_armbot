void modeDea() {
  lcd.clear();
  delay(500);
  int step_step = 0;
  int i = 0;
  while (1) {
    bacaBtn();
    switch (step_step) {
      case 0:
        // gerakan standby
        for (i; i < step_step + 1; i++) {
          dof2.setLogic(true);
          dof3.setLogic(true);
        }
        dof2.goTo(90, 40);
        dof3.goTo(90, 40);
        if (dof2.getLangkah() == true && dof3.getLangkah() == true) step_step += 1;
        break;
      case 1:
        bacaWarna();
        cocokWarna();
        lcd.setCursor(0, 0); lcd.print(" Scanning :     ");
        lcd.setCursor(0, 1); lcd.print(warna); lcd.print("  ");
        if (warna == "Merah" || !ok) step_step = 11;
        else if (warna == "Hijau" || !upL) step_step = 21;
        else if (warna == "Biru" || !downL) step_step = 31;
        else step_step = 1;
        break;
      // ---------------- MERAH ---------------
      case 11:
        lcd.setCursor(0, 0); lcd.print("Merah Terdeteksi");
        lcd.setCursor(0, 1); lcd.print("Pengisian 60 ml ");
        for (i; i < step_step + 1; i++) {
          dof6.setLogic(true);
          dof1.setLogic(true);
          dof2.setLogic(true);
          dof3.setLogic(true);
        }
        dof1.goTo(70, 10);
        dof6.goTo(100, 90);
        dof2.goTo(40, 60);
        dof3.goTo(40, 100);
        if (dof6.getLangkah() == true && dof1.getLangkah() == true) step_step += 1;
        break;
      case 12:
        lcd.clear();
        semprotOn();
        lcd.setCursor(0, 0); lcd.print("Merah Terdeteksi");
        lcd.setCursor(0, 1); lcd.print("Menunggu .... ");
        for (int i = 13; i > 0; i--) {
          lcd.setCursor(14, 1); lcd.print(i); lcd.print(" ");
          delay(1000);
        }
        semprotOff();
        lcd.setCursor(0, 1); lcd.print("Selesai         ");
        delay(1000);
        step_step += 1;
        break;
      case 13:
        lcd.clear();
        for (i; i < step_step + 1; i++) {
          dof6.setLogic(true);
          dof1.setLogic(true);
          dof2.setLogic(true);
          dof3.setLogic(true);
        }
        dof1.goTo(10, 70);
        dof6.goTo(90, 100);
        dof2.goTo(60, 40);
        dof3.goTo(100, 40);
        if (dof6.getLangkah() == true && dof1.getLangkah() == true) {
          i = 0;
          step_step = 1;
        }
        break;
      // ---------------- HIJAU ---------------
      case 21:
        lcd.setCursor(0, 0); lcd.print("Hijau Terdeteksi");
        lcd.setCursor(0, 1); lcd.print("Pengisian 100 ml");
        for (i; i < step_step + 1; i++) {
          dof6.setLogic(true);
          dof1.setLogic(true);
        }
        dof1.goTo(70, 10);
        dof6.goTo(100, 140);
        if (dof6.getLangkah() == true && dof1.getLangkah() == true) step_step += 1;
        break;
      case 22:
        lcd.clear();
        semprotOn();
        lcd.setCursor(0, 0); lcd.print("Hijau Terdeteksi");
        lcd.setCursor(0, 1); lcd.print("Menunggu .... ");
        for (int i = 21; i > 0; i--) {
          lcd.setCursor(14, 1); lcd.print(i); lcd.print(" ");
          delay(1000);
        }
        semprotOff();
        lcd.setCursor(0, 1); lcd.print("Selesai         ");
        delay(1000);
        step_step += 1;
        break;
      case 23:
        for (i; i < step_step + 1; i++) {
          dof6.setLogic(true);
          dof1.setLogic(true);
        }
        dof1.goTo(10, 70);
        dof6.goTo(140, 100);
        if (dof6.getLangkah() == true && dof1.getLangkah() == true) {
          i = 0;
          step_step = 1;
        }
        break;
      // ---------------- BIRU ---------------
      case 31:
        lcd.setCursor(0, 0); lcd.print(" Biru Terdeteksi");
        lcd.setCursor(0, 1); lcd.print("Pengisian 250 ml");
        for (i; i < step_step + 1; i++) {
          dof6.setLogic(true);
          dof1.setLogic(true);
        }
        dof1.goTo(70, 10);
        dof6.goTo(100, 140);
        if (dof6.getLangkah() == true && dof1.getLangkah() == true) step_step += 1;
        break;
      case 32:
        lcd.clear();
        semprotOn();
        lcd.setCursor(0, 0); lcd.print(" Biru Terdeteksi");
        lcd.setCursor(0, 1); lcd.print("Menunggu .... ");
        for (int i = 50; i > 0; i--) {
          lcd.setCursor(14, 1); lcd.print(i); lcd.print(" ");
          delay(1000);
        }
        semprotOff();
        lcd.setCursor(0, 1); lcd.print("Selesai         ");
        delay(1000);
        step_step += 1;
        break;
      case 33:
        for (i; i < step_step + 1; i++) {
          dof6.setLogic(true);
          dof1.setLogic(true);
        }
        dof1.goTo(10, 70);
        dof6.goTo(140, 100);
        if (dof6.getLangkah() == true && dof1.getLangkah() == true) {
          i = 0;
          step_step = 1;
        }
        break;
    }
  }
}
