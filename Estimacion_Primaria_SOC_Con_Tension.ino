
void Estimacion_Primaria_SOC_Con_Tension()
{
// Polinomio calculado con MATLAB, que nos da el porcentaje de descarga
// en función de la tensión en bornes de la batería.
x = V_bateria;
Porcentaje_Descarga = 1.0e+09 * (-0.0010*x^5 + 0.0131*x^4 - 0.1150*x^3 + 0.6313*x^2 - 1.9766*x + 2.7039);
// Donde x es la tensión en bornes de la bateria.
float SOC_Inicial = SOC_Ultimo - Porcentaje_Descarga;

// En todos los modos se registra el último valor del SOC en la variable SOC_Ultimo
// para usar esta información en el próximo ciclo de uso.

return SOC = SOC_Inicial


    }
