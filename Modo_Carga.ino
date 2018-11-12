void Modo_Carga () {
Serial.println("Calculando SOC");
  if (V_bateria > Umbral_Positivo)   // Recalibración del estado de carga lleno
  {
      Actualizacion_Umbral_Maximo_Tension();
      // Salir del bucle
  } else {
    // Determinacion del SOC con Coulumb Counting
    Periodo_Array_Corriente_Subrutina = 350;
      Serial.println("check 1 ");

    Array_Corriente_Subrutina ();
    // Imprimo el array de corrientes
    //*****eliminar esta impresion en el scketch final
    Serial.println("Los valores de las muestras de las corrientes son: ");
    int i = 0;
      for (i = 0; i <= 9; i++)
      {
       Serial.print(Array_Corriente[i]);
       Serial.print("mA  ");
       delay(100);
      }
      Serial.println(" ");
      Serial.println("---------");

     Array_Trapecios();
    /*Serial.println("El valor del área total es: ");
      Serial.print(Delta_Q);
      Serial.println(" C");

      Serial.print(" ");
      Serial.println("---------");*/

    /* En este modo el contador de coulumbs se presenta por Q_ganado, expresado en la siguite fórmula
      que representa la cantidad de cargas acumulada en T */
    Q_ganado += Delta_Q;

    float Q_nominal = 9360; //Capacidad nominal (en Coulumb)
    /* La capacidad nominal de la batería se calcula teniendo en cuenta la capacidad nominal en mAh,
        de la hoja de datos tenemos que la capadidad es 2.6 Ah para una sola bateria,
        pero como están conectadas en serie, el pack de tres baterias tiene la misma capacidad.
        Teniendo en cuenta la relación entre amper y coulumbs hacemos: 2.6 Ah = 2.6 (C/s)*3600 s =9360 C
    */

    float Delta_SOC = 100 * Q_ganado / Q_nominal;
    SOC += Delta_SOC;
    SOC_Ultimo = SOC;

    Valor_SOC_Coulumb_Counting();

  }
  return 0;
}
