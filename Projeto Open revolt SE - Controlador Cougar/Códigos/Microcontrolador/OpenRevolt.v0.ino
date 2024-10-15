

// average - Corrente Media
// PWM - PWM do acionamento em porcentagem
#include <PID_v1.h>

double Setpoint, Input, Output;
//double Kp=1.7, Ki=170, Kd=0;
double Kp=600, Ki=0.1, Kd=0.0;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

#include <PWM.h>
const int analogInputPin = A0; // Define a porta analógica que você está usando (CORRENTE)
const int numReadings = 100;   // Número de leituras para a média
int32_t frequency = 15000;


int readings[numReadings];     // Array para armazenar as leituras
int index = 0;                 // Índice atual no array
long total = 0;                // Total das leituras
float average = 0;

float PWM = 0;
float acelerador = 0;             // Valor médio da corrente
const int analogInputPin1 = A1; // Define a porta analógica que você está usando (PWM)
const int pinoPWM = 9;
const int RESET = 10;
float startPWM = 0;

void setup() {
 InitTimersSafe(); 
 bool success = SetPinFrequencySafe(pinoPWM, frequency);

  // Inicializa a porta serial
  Serial.begin(9600);
   pinMode(pinoPWM, OUTPUT);
   pinMode(RESET, OUTPUT);
    startPWM = analogRead(analogInputPin1); 
    digitalWrite(RESET, LOW);
    delay(100);
    digitalWrite(RESET, HIGH);
  // Inicializa o array de leituras com 0
  for (int i = 0; i < numReadings; i++) {
    readings[i] = 0;
  }
}

void loop() {
  // Lê o valor da porta analógica
  
  
 
 
 int PWM = map(reading1, 0, 1023, 0, 100); 
 pwmWrite(pinoPWM,PWM*2.55);

  // Calcula a média
  // average = 13.4*(((float)total / numReadings)*5/1023)-7.2267 ;
  // average = 2.0967*pow(average,2)+5.2737*average;
  // Imprime a média no monitor serial
  // Serial.println(startPWM);


Serial.print("Média da Corrente: ");
Serial.print(corrente);
Serial.println(" A ");
delay(100);
Serial.print("PWM: ");
Serial.print(PWM);
Serial.println(" % ");

  // Aguarda um curto período de tempo antes de ler a próxima amostra
  delay(100);
}

double readVoutA5(){
  double corrente = analogRead(A5);
  corrente = corrente*5/1023;
  return corrente;
}

double readVinA1(){
  double Setpoint = analogRead(A1);
  Setpoint  = Setpoint*5 /1023;
  return Setpoint ;
}