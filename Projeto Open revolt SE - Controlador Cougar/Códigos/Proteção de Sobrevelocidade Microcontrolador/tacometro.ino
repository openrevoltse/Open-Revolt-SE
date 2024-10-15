#include <Wire.h> //INCLUSÃO DE BIBLIOTECA
#include <LiquidCrystal_I2C.h> //INCLUSÃO DE BIBLIOTECA


LiquidCrystal_I2C lcd(0x27,20,4);  //ENDEREÇO DO I2C E DEMAIS INFORMAÇÕES

long rev=0;
unsigned int rpm;


void contar(){
 
  rev++;
}

void setup() {
  lcd.init(); 
  
  lcd.setBacklight(HIGH); //LIGA O BACKLIGHT (LUZ DE FUNDO)
  Serial.begin(9600);
  rev=0;
  rpm=0;
   
  lcd.setCursor(0,0); //SETA A POSIÇÃO DO CURSOR
      lcd.print("  OpenRevolt"); //IMPRIME O TEXTO NO DISPLAY LCD
            lcd.setCursor(0,1); //SETA A POSIÇÃO DO CURSOR
      lcd.print("RPM:");
}

void loop() {

    rev=0;
      lcd.clear();
      lcd.setCursor(0,0); //SETA A POSIÇÃO DO CURSOR
      lcd.print("  OpenRevolt"); //IMPRIME O TEXTO NO DISPLAY LCD
            lcd.setCursor(0,1); //SETA A POSIÇÃO DO CURSOR
      lcd.print("RPM:");
      lcd.setCursor(5,1);
        lcd.print(rpm);
    attachInterrupt(0, contar, RISING);
    delay(1000);
    detachInterrupt(0);
    rpm = rev * (60/12); // 60 a dividir pelo nº de interrupções (12 lâminas)
    Serial.println(rpm); //IMPRIME O TEXTO NO DISPLAY LCD
    delay(100);
   
    
    
  }
