
void bacaWarna() {
  red = getRed();
  delay(50);
  green = getGreen();
  delay(50);
  blue = getBlue();
  delay(50);
  cocokWarna();
}

int getRed() {
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  int f_red = pulseIn(OutputSensor, LOW);
  return f_red;
}

int getGreen() {
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  int f_green = pulseIn(OutputSensor, LOW);
  return f_green;
}

int getBlue() {
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  int f_blue = pulseIn(OutputSensor, LOW);
  return f_blue;
}

void cocokWarna() {
  // ------------- MERAHHH ---------    // ANGGA MERAH TITIK BERHENTI KERTAS KAMBING
  if ( red >= MerahLowerRed && red <= MerahUpperRed
       && green >= MerahLowerGreen && green <= MerahUpperGreen
       && blue >= MerahLowerBlue && blue <= MerahUpperBlue) {
    // ------------- MERAHHH ----------
    warna = "Merah";
  }
  // ------------- HIJAU  ----------
  else if ( red >= HijauLowerRed && red <= HijauUpperRed
            && green >= HijauLowerGreen && green <= HijauUpperGreen
            && blue >= HijauLowerBlue && blue <= HijauUpperBlue) {
    // ------------- HIJAU  ----------
    warna = "Hijau";
  }
  // ------------- BIRUU -----------
  else if ( red >= BiruLowerRed && red <= BiruUpperRed
            && green >= BiruLowerGreen && green <= BiruUpperGreen
            && blue >= BiruLowerBlue && blue <= BiruUpperBlue) {
    // ------------- BIRUU -----------
    warna = "Biru";
  }
  // ------------- KUNING -----------
  else if ( red >= KuningLowerRed && red <= KuningUpperRed
            && green >= KuningLowerGreen && green <= KuningUpperGreen
            && blue >= KuningLowerBlue && blue <= KuningUpperBlue) {

    warna = "Kuning";
  }
  else warna = "Null";
}


void saveWarna(String warna) {
  int integer;
  if (warna == "Merah") integer = 1;
  if (warna == "Hijau") integer = 2;
  if (warna == "Biru") integer = 3;
  if (warna == "Kuning") integer = 4;

  switch (integer) {
    case 1:
      MerahUpperRed = red + 20;
      MerahLowerRed = red - 20;
      MerahUpperGreen = green + 20;
      MerahLowerGreen = green - 20;
      MerahUpperBlue = blue + 20;
      MerahLowerBlue = blue - 20;
      EEPROM.write(A_MerahUpperRed, MerahUpperRed);
      EEPROM.write(A_MerahLowerRed, MerahLowerRed);
      EEPROM.write(A_MerahUpperGreen, MerahUpperGreen);
      EEPROM.write(A_MerahLowerGreen, MerahLowerGreen);
      EEPROM.write(A_MerahUpperBlue, MerahUpperBlue);
      EEPROM.write(A_MerahLowerBlue, MerahLowerBlue);
      break;
    case 2:
      HijauUpperRed = red + 20;
      HijauLowerRed = red - 20;
      HijauUpperGreen = green + 20;
      HijauLowerGreen = green - 20;
      HijauUpperBlue = blue + 20;
      HijauLowerBlue = blue - 20;

      EEPROM.write(A_HijauUpperRed, HijauUpperRed);
      EEPROM.write(A_HijauLowerRed, HijauLowerRed);
      EEPROM.write(A_HijauUpperGreen, HijauUpperGreen);
      EEPROM.write(A_HijauLowerGreen, HijauLowerGreen);
      EEPROM.write(A_HijauUpperBlue, HijauUpperBlue);
      EEPROM.write(A_HijauLowerBlue, HijauLowerBlue);
      break;
    case 3:
      BiruUpperRed = red + 20;
      BiruLowerRed = red - 20;
      BiruUpperGreen = green + 20;
      BiruLowerGreen = green - 20;
      BiruUpperBlue = blue + 20;
      BiruLowerBlue = blue - 20;

      EEPROM.write(A_BiruUpperRed, BiruUpperRed);
      EEPROM.write(A_BiruLowerRed, BiruLowerRed);
      EEPROM.write(A_BiruUpperGreen, BiruUpperGreen);
      EEPROM.write(A_BiruLowerGreen, BiruLowerGreen);
      EEPROM.write(A_BiruUpperBlue, BiruUpperBlue);
      EEPROM.write(A_BiruLowerBlue, BiruLowerBlue);
      break;
    case 4:
      KuningUpperRed = red + 20;
      KuningLowerRed = red - 20;
      KuningUpperGreen = green + 20;
      KuningLowerGreen = green - 20;
      KuningUpperBlue = blue + 20;
      KuningLowerBlue = blue - 20;

      EEPROM.write(A_KuningUpperRed, KuningUpperRed);
      EEPROM.write(A_KuningLowerRed, KuningLowerRed);
      EEPROM.write(A_KuningUpperGreen, KuningUpperGreen);
      EEPROM.write(A_KuningLowerGreen, KuningLowerGreen);
      EEPROM.write(A_KuningUpperBlue, KuningUpperBlue);
      EEPROM.write(A_KuningLowerBlue, KuningLowerBlue);
      break;
  }
}

void loadWarna() {
  // =========== MERAH ========
  MerahUpperRed = EEPROM.read(A_MerahUpperRed);
  MerahUpperGreen = EEPROM.read(A_MerahUpperGreen);
  MerahUpperBlue = EEPROM.read(A_MerahUpperBlue);
  // ========================== //
  MerahLowerRed = EEPROM.read(A_MerahLowerRed);
  MerahLowerGreen = EEPROM.read(A_MerahLowerGreen);
  MerahLowerBlue = EEPROM.read(A_MerahLowerBlue);


  // =========== HIJAU ========
  HijauUpperRed = EEPROM.read(A_HijauUpperRed);
  HijauUpperGreen = EEPROM.read(A_HijauUpperGreen);
  HijauUpperBlue = EEPROM.read(A_HijauUpperBlue);
  // ========================== //
  HijauLowerRed = EEPROM.read(A_HijauLowerRed);
  HijauLowerGreen = EEPROM.read(A_HijauLowerGreen);
  HijauLowerBlue = EEPROM.read(A_HijauLowerBlue);


  // =========== BIRU =========
  BiruUpperRed = EEPROM.read(A_BiruUpperRed);
  BiruUpperGreen = EEPROM.read(A_BiruUpperGreen);
  BiruUpperBlue = EEPROM.read(A_BiruUpperBlue);
  // ========================== //
  BiruLowerRed = EEPROM.read(A_BiruLowerRed);
  BiruLowerGreen = EEPROM.read(A_BiruLowerGreen);
  BiruLowerBlue = EEPROM.read(A_BiruLowerBlue);


  // =========== KUNING =========
  KuningUpperRed = EEPROM.read(A_KuningUpperRed);
  KuningUpperGreen = EEPROM.read(A_KuningUpperGreen);
  KuningUpperBlue = EEPROM.read(A_KuningUpperBlue);
  // ========================== //
  KuningLowerRed = EEPROM.read(A_KuningLowerRed);
  KuningLowerGreen = EEPROM.read(A_KuningLowerGreen);
  KuningLowerBlue = EEPROM.read(A_KuningLowerBlue);
}
