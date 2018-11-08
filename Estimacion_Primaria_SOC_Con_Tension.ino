
void Estimacion_SOC()
{
// int V_bateria=12;
int Capacidad [21]={0, 5, 10, 15 ,20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100};
float Voltaje [21]={9.82, 10.83, 11.06, 11.12, 11.18, 11.24, 11.3, 11.36, 11.39, 11.45, 11.51, 11.56, 11.62, 11.74, 11.86, 11.95, 12.07, 12.25, 12.33, 12.45, 12.6};

float Error[21];
    for (int i=0; i<=21; i++)
    {
      Error[i]=Voltaje[i]-V_bateria;
    }
float Error_Absoluto=fabs(Error);
    Serial.println(Error_Absoluto);
    delay(2000);
    }


