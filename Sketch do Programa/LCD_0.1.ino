#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

SoftwareSerial BT (11,10); // RX, TX

#define endereco  0x27
#define colunas   16
#define linhas    2

LiquidCrystal_I2C lcd (endereco, colunas, linhas);

char texto;

void setup() {

  BT.begin(9600);
  
  lcd.init(); 
  lcd.backlight();  

  lcd.print("Iniciando");
  delay(2000); 
  lcd.clear(); 

  lcd.setCursor(4, 0);
  lcd.print("Projeto");
  lcd.setCursor(1, 1);
  lcd.print("Greifen - 2021");
}

void loop() {

  if (BT.available()) {

     texto = BT.read();
     lcd.print(texto);
    
       if(texto=='@'){
       lcd.clear();}
      
       if(texto=='#'){
       lcd.backlight();
       lcd.clear();}
  
       if(texto=='$'){ 
       lcd.noBacklight();
       lcd.clear();}

       if(texto=='.'){ 
       lcd.setCursor(0, 1);}
       
     }         
}
