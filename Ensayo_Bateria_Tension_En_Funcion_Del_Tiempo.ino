// Objetivo: Código para el ensayo de una bateria, mediante el cual conocemos los valores de tension en funcion del tiempo
// correspondientes a los estados complentamente descargado y cargado.

// Concepto:
// La idea consiste en realizar un ensayo a la batería, para determinar las curvas de tension en funcion del tiempo
// y mediante inspeccion determinar los picos y el tiempo que trancurre entre ambos, tanto de carga como de descarga.
// De esta manera, por ejemplo, cuando conectamos una bateria de la cual no sabemos cual es su SOC inicial
// midiendo el tiempo y registrando los valores de tension, por comparación podremos tener una estimación 
// del SOC inicial.

// Éste ensayo debe realizarse antes de implemtar el circuito, para conocer la bateria con la que estamos trabajando.
// Luego, si se registra un ciclo completo de carga y descarga, se podrá actualizar la curva, ya que la baterias se degradan con el tiempo
// y la curva se modificará de acuerdo al desgaste, por lo que es un aspecto a tener en cuenta.


https://www.luisllamas.es/medir-nivel-luz-con-arduino-y-fotoresistencia-ldr/
https://www.luisllamas.es/tarjeta-micro-sd-arduino/

long Tiempo_Previo = 0;
long Intervalo = 1000;

void setup(){

}

void loop(){
 
  unsigned long Tiempo_Actual = millis();
 
  if(Tiempo_Actual - Tiempo_Previo > Intervalo) {
    previousMillis = currentMillis;  
    }
    // ver pagina 61  del trabajo de cisneros
    // estimacion de un ciclo de carga/descarga: 485 minutos
    // tener en cuenta que la corriente de carga varia
    // tener en cuenta que se carga hasta un soc de 60 y se descarga hasta el 10%
}
