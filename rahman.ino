

void modeRahman() {
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
        bacaSuhu();
        jarakGerbang();
        lcd.setCursor(0, 0); lcd.print(" Jarak :     ");
        lcd.setCursor(0, 1); lcd.print(distanceGerbang); lcd.print(" CM ");
        if (distanceGerbang <= 30) step_step += 1;
        break;
      case 2:
        lcd.setCursor(0, 0); lcd.print(" Selamat Datang ");
        if (!cek_mp3) {
          lcd.setCursor(0, 0); lcd.print(" Mp3 is Null   ");
        } else {
          myDFPlayer.play(4);
          lcd.setCursor(0, 0); lcd.print(" Mp3 is Playing");
        }
        for (i; i < step_step + 1; i++) {
          dof6.setLogic(true);
        }
        dof6.goTo(100, 10); //  Servo naik untuk baca sensor MLX
        if (dof6.getLangkah() == true) step_step += 1;
        break;
      case 3:
        bacaSuhu();
        lcd.setCursor(0, 0); lcd.print("Posisikan Tangan");
        lcd.setCursor(0, 1); lcd.print(" Anda      -- 5 ");
        delay(1000); lcd.setCursor(0, 1); lcd.print(" Anda      -- 4 ");
        delay(1000); lcd.setCursor(0, 1); lcd.print(" Anda      -- 3 ");
        delay(1000); lcd.setCursor(0, 1); lcd.print(" Anda      -- 2 ");
        delay(1000); lcd.setCursor(0, 1); lcd.print(" Anda      -- 1 ");
        step_step++;
        break;
      case 4:
        bacaSuhu();
        lcd.setCursor(0, 0); lcd.print("Suhu Tubuh Anda ");
        lcd.setCursor(0, 1); lcd.print(suhu); lcd.print(" C       ");
        delay(3000);
        lcd.clear();
        if (suhu <= 37.5) step_step += 1; // aman
        else step_step = 11;
        break;
      // -------------- SUHU AMAN ---------------
      case 5:
        myDFPlayer.play(0);
        lcd.setCursor(0, 0); lcd.print("Suhu Tubuh Anda ");
        lcd.setCursor(0, 1); lcd.print("Aman, Lanjut ~~ ");
        for (i; i < step_step + 1; i++) {
          dof6.setLogic(true);
          dof1.setLogic(true);
        }
        dof1.goTo(70, 0); //  Servo turun untuk semprot Sanitizer
        dof6.goTo(10, 130); //  Servo turun untuk semprot Sanitizer
        if (dof6.getLangkah() == true && dof1.getLangkah() == true) step_step += 1;
        break;
      case 6:
        lcd.setCursor(0, 0); lcd.print("Suhu Tubuh Aman ");
        lcd.setCursor(0, 1); lcd.print("  Semprot Sntzr ");
        delay(2000);
        semprotOn();
        delay(700);
        semprotOff();
        delay(2000);
        step_step += 1;
        break;
      case 7:
        myDFPlayer.play(2);   // bersiap untuk menyemprot
        lcd.setCursor(0, 0); lcd.print("Membuka Gerbang ");
        lcd.setCursor(0, 1); lcd.print("                ");
        gerbang.write(0);
        delay(5000);
        lcd.setCursor(0, 0); lcd.print("                ");
        lcd.setCursor(0, 1); lcd.print("Menutup Gerbang ");
        gerbang.write(90);
        delay(3000);
        for (i; i < step_step + 1; i++) {
          dof6.setLogic(true);
          dof1.setLogic(true);
          dof2.setLogic(true);
          dof3.setLogic(true);
        }
        dof1.goTo(0, 70); //  Servo turun untuk semprot Sanitizer
        dof6.goTo(130, 10); //  Servo turun untuk semprot Sanitizer
        dof6.goTo(40, 90); //  Servo turun untuk semprot Sanitizer
        dof6.goTo(40, 90); //  Servo turun untuk semprot Sanitizer
        if (dof6.getLangkah() == true && dof1.getLangkah() == true) {
          i = 0;
          step_step = 1;
        }
        break;
      // -------------- SUHU TIDAK AMAN ---------------
      case 11:
        myDFPlayer.play(3);
        lcd.setCursor(0, 0); lcd.print("Suhu Tubuh Anda ");
        lcd.setCursor(0, 1); lcd.print("Tidak Aman, Maaf");
        // mp3 Tidak amannnn
        delay(3000);
        i = 0;
        step_step = 1;
        break;
    }
  }
}
