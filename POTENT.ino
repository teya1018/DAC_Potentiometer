/*======================================================
             Potentiometer
========================================================
Description:
This program reads an analog input from a potentiometer
on GPIO 36 using an 8-bit ADC resolution (0-255). It 
computes the input voltage, prints the ADC value and 
voltage to the Serial Monitor, and writes the value to 
DAC pin GPIO 25 to produce an analog voltage output.

Programmer: 
  Sergie D. Gomez

Date: 
  14 October 2026
-----------------------------------------------------*/
//GPIO pins

const byte POT = 36;
const byte DAC_PIN = 25;

//variable

int adc_val = 0;
float voltage_in = 0;

void setup() {
  pinMode(POT, INPUT);
  analogReadResolution(8);
  pinMode(DAC_PIN, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  adc_val = analogRead(POT);
  Serial.printf("ADC Numeric Value: %d\n", adc_val);
  delay(500);

  voltage_in = (adc_val/255.0)*3.3;
  Serial.printf("Input Voltage : % 2f\n ", voltage_in);
  delay(500);
  //
  dacWrite(DAC_PIN, adc_val);  
}
