void Array_Corriente_Subrutina () {
  int i = 0;
  for (i = 0; i <= 9; i++) 
  {
    Array_Corriente[i] = ina219.getCurrent_mA();
    delay(Periodo_Array_Corriente_Subrutina);
    // El array tarda 3150 ms en formarse con 10 valores
  }

  Serial.println("check 2");
    return 0;
}

