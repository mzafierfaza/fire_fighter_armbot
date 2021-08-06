#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <EEPROM.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_MLX90614.h>
#include <Servo.h>

#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates
#include "ServoGo.h"

#define S0 51
#define S1 49
#define S2 47
#define S3 45
#define OutputSensor 43

#define pwm1 7
#define inA1 6
#define inB1 5
#define inA2 4
#define inB2 3
#define pwm2 2
#define inA3 30 // 30 dan 28 gabung te short
#define inB3 34

unsigned long previousMillis = 0;        // will store last time LED was updated
int i = 0;
int step_step = 0;
// constants won't change:
const long interval = 1000;           // interval at which to blink (milliseconds)
const int servo_gerbang = 25;
const int trig_pin_1 = 42;  // KIRI
const int echo_pin_1 = 40;  // KIRI
const int trig_pin_2 = 46;  // DEPAN
const int echo_pin_2 = 44;  // DEPAN
const int trig_pin_3 = 48;  // Gerbang
const int echo_pin_3 = 50;  // Gerbang
const int flameKiriPin = A0;
const int flameKananPin = A1;
const int flameDepanPin = A3;
const int garis = A5;
const int btn_pin[] = {31, 33, 35, 37}; // downL - upL - ok - back
String kondisi;
String warna = "Null";
int red, green, blue;
float suhu;
int apiL, apiF, apiR;
int isGaris;
int distanceKiri, distanceDepan, distanceGerbang;
int upL, downL, ok, back;
int mode_no_home, mode_no_sensor, mode_no_motor, mode_no_setpoint, mode_no_servo, mode_no_savewarna;
bool anu, cek_mp3, cek_mlx;


// =========================== VARIABLE EEPPROM WARNA BAWAH =======================
int MerahLowerRed, MerahUpperRed, MerahLowerGreen, MerahUpperGreen, MerahLowerBlue, MerahUpperBlue;
int HijauLowerRed, HijauUpperRed, HijauLowerGreen, HijauUpperGreen, HijauLowerBlue, HijauUpperBlue;
int BiruLowerRed, BiruUpperRed, BiruLowerGreen, BiruUpperGreen, BiruLowerBlue, BiruUpperBlue;
int KuningLowerRed, KuningUpperRed, KuningLowerGreen, KuningUpperGreen, KuningLowerBlue, KuningUpperBlue;
int A_MerahLowerRed = 10; int A_MerahUpperRed = 11; int A_MerahLowerGreen = 12; int A_MerahUpperGreen = 13; int A_MerahLowerBlue = 14; int A_MerahUpperBlue = 15;
int A_HijauLowerRed = 20; int A_HijauUpperRed = 31; int A_HijauLowerGreen = 22; int A_HijauUpperGreen = 23; int A_HijauLowerBlue = 24; int A_HijauUpperBlue = 25;
int A_BiruLowerRed = 30; int A_BiruUpperRed = 41; int A_BiruLowerGreen = 32; int A_BiruUpperGreen = 33; int A_BiruLowerBlue = 34; int A_BiruUpperBlue = 35;
int A_KuningLowerRed = 40; int A_KuningUpperRed = 51; int A_KuningLowerGreen = 42; int A_KuningUpperGreen = 43; int A_KuningLowerBlue = 44; int A_KuningUpperBlue = 45;


DFRobotDFPlayerMini myDFPlayer;
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

Servo gerbang;
LiquidCrystal_I2C lcd(0x27, 16, 2);


ServoGo dof1 = ServoGo(0, 20, 5); // channel, interval, step
ServoGo dof2 = ServoGo(1, 10, 5);
ServoGo dof3 = ServoGo(2, 10, 5);
ServoGo dof4 = ServoGo(3, 10, 5);
ServoGo dof5 = ServoGo(4, 10, 5);
ServoGo dof6 = ServoGo(5, 10, 5);

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  deklarasi();
  lcd.init();
  lcd.backlight();

  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates
  lcd.setCursor(0, 0); lcd.print("    Arm Robot   ");
  lcd.setCursor(0, 1); lcd.print("Teknik Komputer ");
  (!myDFPlayer.begin(Serial1)) ? cek_mp3 = false : cek_mp3 = true;
  (!mlx.begin()) ? cek_mlx = false : cek_mlx = true;
  myDFPlayer.setTimeOut(500);
  myDFPlayer.volume(30); //Set volume value (0~30)
  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);
  gerbang.write(90);
  loadWarna();
  // ---- setup start -----
  dof1.setupStart(70);  // dof1 : semakin tinggi semakin ke kiri  | 70 posisi untuk jalan
  dof2.setupStart(90);  // dof2 : semakin tinggi semakin mundur  | 110 posisi untuk jalan
  dof3.setupStart(90); // dof3 : semakin tinggi semakin ke bawah  | 50 posisi untuk jalan
  dof4.setupStart(85); // dof4 : semakin tinggi semakin kiri
  dof5.setupStart(30);  // dof5 : semakin tinggi semakin ke kanan | center nya 30 gakperlu diubah
  dof6.setupStart(100);  // dof6 : semakin tinggi semakin ke bawah | center nya 90
  delay(500);
  lcd.clear();
}

void loop() {
  //  Servo_Gerak();
  homescreen() ;
  //  bacaWarna();
}
