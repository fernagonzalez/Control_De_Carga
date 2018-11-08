float Array_Trapecios () {

  float f_a = 0; float f_b = 0;

  float b_a = Periodo_Array_Corriente_Subrutina;   //b-a es dato, es el intervalo entre muestras sucesivas
  int i = 0;
  for (i = 0; i < 9; i++)
  {
    f_a = Array_Corriente[i];
    f_b = Array_Corriente[i + 1];

    Array_Integral_Parcial [i] = b_a * 0.5 * (f_a + f_b); // Tiene 9 elementos de área
  }

  //Acá tenemos el array de trapecios listo, por ende solo resta sumar las areas
  // Eliminar la siguiente impresión en el sketch final
  Serial.println("Los valores de los áreas parciales son: ");
    for (i = 0; i < 9; i++) {
    Serial.print(Array_Integral_Parcial [i]);
    Serial.print("uC  ");
    delay(500);
    }
    Serial.println(" ");
    Serial.println("---------");
    Serial.println("check 2b");

  // Área total

  for (i = 0; i <= 8; i++)
  {
    Delta_Q += Array_Integral_Parcial[i];
  }
  Delta_Q = Delta_Q / 1000000; //paso de uC a C
    Serial.print(Delta_Q);
    Serial.print("C  ");

  return Delta_Q;
}

