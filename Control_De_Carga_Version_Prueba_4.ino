#include <Wire.h>
#include <Adafruit_INA219.h>
#include <LiquidCrystal_I2C.h>

Adafruit_INA219 ina219;
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

// Variables globales

float Array_Corriente[10] = {};
float Array_Integral_Parcial[9] = {};

float Q_ganado = 0; // Establezco cero como valor arbitrario de referencia
float Delta_Q = 0;



float SOC = 0;
float V_bateria = 0;

float Actualizacion_Umbral_Positivo = 0;
// Actualización del valor máximo de tensión (en caso de ser necesario).
float Umbral_Positivo = 12.1;

int Periodo_Array_Corriente_Subrutina = 0;

void setup()
{
  Serial.begin(9600);
  lcd.begin(20, 4);
  ina219.begin();
  uint32_t currentFrequency;
}


void loop()
{
  // Cada 5 seg tenemos una estimacion del SOC
  //888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888

  V_bateria = ina219.getBusVoltage_V();

  // Imprimo el dato de la tensión
  Serial.print("La tensión en la batería es: ");
  Serial.print(V_bateria);
  Serial.print("V  ");
  Serial.println(" ");
  Serial.println("---------");

  // Adquisición premilinar de i_bateria
  float i_bateria = 0;
  i_bateria = Adquisicion_Preliminar_I();

  // Imprimo el dato de la corriente
  Serial.print("La corriente en la batería es: ");
  Serial.print(i_bateria);
  Serial.print("mA  ");
  Serial.println(" ");
  Serial.println("---------");

  //888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888


  // Condicionales para determinar modos (carga, descarga, auto-descarga)

  if (i_bateria > -2 && i_bateria < 2)
  {
    Serial.println("Modo: Auto-descarga");
    Serial.println("---------");
  }

  if (i_bateria < -2)
  {
    Serial.println("Modo: Descarga");
    Serial.println("---------");
  }

  if (i_bateria > 2)
  {
    Serial.println("Modo: Carga");
    Serial.println("---------");

    Modo_Carga();

  }


}
