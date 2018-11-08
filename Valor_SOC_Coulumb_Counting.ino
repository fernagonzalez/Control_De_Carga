void Valor_SOC_Coulumb_Counting(){
  // 12.1 hacer variable Tension_Maxima_Nominal
  if (SOC > 100 && V_bateria > 12.1) {
    Serial.println("SOC: ");
    Serial.print(100);
    Serial.println("% ");

    Serial.print(" ");
    Serial.println("---------"); //Imprimir el SOC en 100 %
    
    Actualizacion_Umbral_Maximo_Tension();
    
    } else{
    Serial.println("SOC: ");
    Serial.print(SOC);
    Serial.println("% ");

    Serial.print(" ");
    Serial.println("---------");
    }    
}

