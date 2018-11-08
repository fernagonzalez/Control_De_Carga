int Adquisicion_Preliminar_I() {
    //1.1 - Adquisición premilinar de i_bateria

  //Tomo un promedio para evitar flutuaciones de la medición en un período muy corto de tiempo
  int i = 0;
  int Periodo_Adquisicion_Preliminar = 250;
  float i_bateria = 0;
  float i_bateria_suma = 0;
// Posible mejora usando Array_Corriente_Subrutina con variable M con M igual al orden del array

    for (i = 0; i <= 5; i++)
  {
    Array_Corriente[i] = ina219.getCurrent_mA(); //variable global
    delay(Periodo_Adquisicion_Preliminar);
    // Al cabo de 1.5 segundos tendremos 6 mediciones de corriente colocadas en el array
  }

  // Saco un promedio de las mediciones
  for (i = 0; i <= 5; i++)
  {
    i_bateria_suma += Array_Corriente[i];
  }
  i_bateria = i_bateria_suma / 6;

  return i_bateria;  
}

