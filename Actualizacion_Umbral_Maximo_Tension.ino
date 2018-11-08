void Actualizacion_Umbral_Maximo_Tension() {
     
    Actualizacion_Umbral_Positivo = V_bateria - Umbral_Positivo;
    Umbral_Positivo = 12.1 + Actualizacion_Umbral_Positivo;
    /* En la página 40 dice que la tension máxima del pack es de 12.9
    sin embrago adopto 12.5 como valor base, para que se vaya actualizando desde ahí con la variable Actualizacion_Umbral_Positivo*/
    Serial.println("SOC: ");
    Serial.print(100);
    Serial.println("% ");

    Serial.print(" ");
    Serial.println("---------"); //Imprimir el SOC en 100 %

    Serial.println("Umbral positivo actualizado (Tensión Máxima): ");
    Serial.print(Umbral_Positivo);
    Serial.println(" V");

    Serial.print(" ");
    Serial.println("---------");

}

