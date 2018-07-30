#include <SPI.h>
#include <SD.h>

File myFile;
#include <virtuabotixRTC.h> //Library used

virtuabotixRTC myRTC(7, 6, 5); //If you change the wiring change the pins here also
int ledy = 8;
int ledg = 9;           // the PWM pin the LED is attached to
int ledr = 10;

void setup() {
  Serial.begin(9600);
  pinMode(ledy, OUTPUT);
  pinMode(ledg, OUTPUT);
  pinMode(ledr, OUTPUT);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    digitalWrite(ledr, HIGH);
    while (1);
  }

  Serial.println("initialization done.");
  digitalWrite(ledr, HIGH);
  digitalWrite(ledg, HIGH);
  digitalWrite(ledy, HIGH);
  delay(100);
  digitalWrite(ledr, LOW);
  //  digitalWrite(ledg, LOW);
  // digitalWrite(ledy, LOW);
  delay(100);
  digitalWrite(ledr, HIGH);
  //  digitalWrite(ledg, HIGH);
  //  digitalWrite(ledy, HIGH);
  delay(100);
  //  digitalWrite(ledr, LOW);
  digitalWrite(ledg, LOW);
  //  digitalWrite(ledy, LOW);
  delay(100);
  //  digitalWrite(ledr, HIGH);
  digitalWrite(ledg, HIGH);
  //  digitalWrite(ledy, HIGH);
  delay(100);
  //digitalWrite(ledr, LOW);
  //  digitalWrite(ledg, LOW);
  digitalWrite(ledy, LOW);
  delay(100);
  digitalWrite(ledr, HIGH);
  digitalWrite(ledg, HIGH);
  digitalWrite(ledy, HIGH);
  delay(100);
  digitalWrite(ledr, LOW);
  digitalWrite(ledg, LOW);
  digitalWrite(ledy, LOW);
  delay(100);
  digitalWrite(ledr, HIGH);
  digitalWrite(ledg, HIGH);
  digitalWrite(ledy, HIGH);
  delay(100);
  digitalWrite(ledr, LOW);
  digitalWrite(ledg, LOW);
  digitalWrite(ledy, LOW);
  delay(100);
  digitalWrite(ledr, HIGH);
  digitalWrite(ledg, HIGH);
  digitalWrite(ledy, HIGH);
  delay(100);
  digitalWrite(ledr, LOW);
  digitalWrite(ledg, LOW);
  digitalWrite(ledy, LOW);
  delay(100);
  digitalWrite(ledr, HIGH);
  digitalWrite(ledg, HIGH);
  digitalWrite(ledy, HIGH);
  delay(100);
  digitalWrite(ledr, LOW);
  digitalWrite(ledg, LOW);
  // digitalWrite(ledy, LOW);
  delay(500);

  // Set the current date, and time in the following format:
  // seconds, minutes, hours, day of the week, day of the month, month, year
  // myRTC.setDS1302Time(30, 27, 14, 7, 30, 7, 2018); //Here you write your actual time/date as shown above
  //but remember to "comment/remove" this function once you're done
  //The setup is done only one time and the module will continue counting it automatically
}

void loop() {
  // This allows for the update of variables for time or accessing the individual elements.
  myRTC.updateTime();
  verifisd();
  // IMPRIME EM SERIAL MONITOR Y GUARDA EN TXT
  myFile = SD.open("9999.txt", FILE_WRITE);
  if (myFile) {
    // Start printing elements as individuals
    Serial.print("9999, ");
    Serial.print(myRTC.dayofmonth); //You can switch between day and month if you're using American system
    Serial.print("/");
    Serial.print(myRTC.month);
    Serial.print("/");
    Serial.print(myRTC.year);
    Serial.print(" ");
    Serial.print(myRTC.hours);
    Serial.print(":");
    Serial.print(myRTC.minutes);
    Serial.print(":");
    Serial.print(myRTC.seconds);
    Serial.println(", ");

    myFile.print("9999, ");
    myFile.print(myRTC.dayofmonth); //You can switch between day and month if you're using American system
    myFile.print("/");
    myFile.print(myRTC.month);
    myFile.print("/");
    myFile.print(myRTC.year);
    myFile.print(" ");
    myFile.print(myRTC.hours);
    myFile.print(":");
    myFile.print(myRTC.minutes);
    myFile.print(":");
    myFile.print(myRTC.seconds);
    myFile.println(", ");
    myFile.close();

    digitalWrite(ledg, HIGH);
    delay(500);
    digitalWrite(ledg, LOW);
    delay(500);
  }
  else {
    Serial.println("error abriendo archivo de texto");
    digitalWrite(ledr, HIGH);
  }
}
void verifisd() {
  if (!SD.begin(4)) {
    Serial.println("Error en MicroSD");
    digitalWrite(ledr, HIGH);
    while (1);
  }
}
