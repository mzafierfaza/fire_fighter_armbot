
void modeSabrina() {
  lcd.clear();
  delay(500);
  int step_step = 0;
  int i = 0;
  dof3.setupStart(70); // dof3 : semakin tinggi semakin ke bawah  | 50 posisi untuk jalan

  while (1) {
    bacaBtn();
    lcd.setCursor(0, 0); lcd.print(apiL); lcd.print("|");
    lcd.print(apiF); lcd.print("|");
    lcd.print(apiR); lcd.print(" | ");
    lcd.print(distanceKiri); lcd.print(" ");
    lcd.print(distanceDepan); lcd.print(" ");
    lcd.setCursor(0, 1); lcd.print("Case = "); lcd.print(step_step);
    lcd.print(" | "); lcd.print(kondisi); lcd.print("    ");
    // ---- setup start -----
    //    dof1.setupStart(70);  // dof1 : semakin tinggi semakin ke kiri  | 70 posisi untuk jalan
    //    dof2.setupStart(90);  // dof2 : semakin tinggi semakin mundur  | 110 posisi untuk jalan
    //    dof3.setupStart(90); // dof3 : semakin tinggi semakin ke bawah  | 50 posisi untuk jalan
    //    dof4.setupStart(90); // dof4 : semakin tinggi semakin kanan
    //    dof5.setupStart(30);  // dof5 : semakin tinggi semakin ke kanan | center nya 30 gakperlu diubah
    //    dof6.setupStart(100);  // dof6 : semakin tinggi semakin ke bawah | center nya 90

    switch (step_step) {
      case 0:
        bacaApi();
        jarakKiri();
        jarakDepan();
        susurKiri();
        if (apiF && distanceDepan <= 30 ) step_step += 1;
        //        lcd.setCursor(0, 0); lcd.print("Testingg");
        //        delay(2000);
        //        step_step += 1;
        break;
      case 1:
        motor(0, 0);
        delay(1000);
        for (i; i < step_step + 1; i++) {
          dof2.setLogic(true);
          dof3.setLogic(true);
          dof6.setLogic(true);
        }
        dof2.goTo(90, 60);
        dof3.goTo(70, 40);
        if (dof2.getLangkah() == true && dof3.getLangkah() == true) step_step += 1;
        break;
      case 2:
        semprotOn();
        for (i; i < step_step + 1; i++) {
          dof1.setLogic(true);
        }
        dof1.goTo(70, 50);
        if (dof1.getLangkah() == true) step_step += 1;
        break;
      case 3:
        for (i; i < step_step + 1; i++) {
          dof1.setLogic(true);
        }
        dof1.goTo(50, 90);
        if (dof1.getLangkah() == true) step_step += 1;
        break;
      case 4:
        for (i; i < step_step + 1; i++) {
          dof1.setLogic(true);
          dof6.setLogic(true);
        }
        dof6.goTo(110, 70);
        dof1.goTo(90, 50);
        if (dof1.getLangkah() == true && dof6.getLangkah() == true) step_step += 1;
        break;
      case 5:
        for (i; i < step_step + 1; i++) {
          dof1.setLogic(true);
          dof6.setLogic(true);
        }
        dof6.goTo(70, 70);
        dof1.goTo(50, 90);
        if (dof1.getLangkah() == true && dof6.getLangkah() == true) step_step += 1;
        break;
      case 6:
        for (i; i < step_step + 1; i++) {
          dof1.setLogic(true);
          dof6.setLogic(true);
        }
        dof6.goTo(70, 110);
        dof1.goTo(90, 50);
        if (dof1.getLangkah() == true && dof6.getLangkah() == true) step_step += 1;
        break;
      case 7:
        for (i; i < step_step + 1; i++) {
          dof1.setLogic(true);
          dof6.setLogic(true);
        }
        dof6.goTo(110, 110);
        dof1.goTo(50, 90);
        if (dof1.getLangkah() == true && dof6.getLangkah() == true) step_step += 1;
        break;
      case 8:
        for (i; i < step_step + 1; i++) {
          dof1.setLogic(true);
          dof6.setLogic(true);
        }
        dof6.goTo(110, 70);
        dof1.goTo(90, 50);
        if (dof1.getLangkah() == true && dof6.getLangkah() == true) step_step += 1;
        break;
      case 9:
        for (i; i < step_step + 1; i++) {
          dof1.setLogic(true);
          dof6.setLogic(true);
        }
        dof6.goTo(70, 100);
        dof1.goTo(50, 70);
        semprotOff();
        if (dof1.getLangkah() == true && dof6.getLangkah() == true) step_step += 1;
        break;
      case 10:
        bacaApi();
        if (apiF) {
          step_step = 2;
          i = 0;
        }
        else if (!apiF) {
          step_step += 1;
        }
        break;
      case 11:
        for (i; i < step_step + 1; i++) {
          dof2.setLogic(true);
          dof3.setLogic(true);
        }
        lcd.setCursor(0, 0); lcd.print("   Api Telah   ");
        lcd.setCursor(0, 1); lcd.print("   Disemprot   ");
        dof2.goTo(40, 90);
        dof3.goTo(40, 70);
        delay(2000);
        lcd.setCursor(0, 0); lcd.print("Kembali ke Home");
        lcd.setCursor(0, 1); lcd.print(" Mencari Garis ");
        delay(2000);
        if (dof2.getLangkah() == true && dof3.getLangkah() == true) step_step += 1;
        break;
      case 12:
        bacaApi();
        jarakKiri();
        jarakDepan();
        susurKiri();
        bacaGaris();
        if (apiF || apiL || apiR) {
          i = 0;
          step_step = 1;
        }
        if (isGaris) step_step += 1;
        break;
      case 13:
        motor(0, 0);
        lcd.setCursor(0, 0); lcd.print("    Selesai    ");
        lcd.setCursor(0, 1); lcd.print("   Dah Sampai  ");
        break;
    }
  }
}
