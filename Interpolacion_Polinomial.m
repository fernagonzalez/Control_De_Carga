clear
% Cargo los valores
x = [9.82 10.83 11.06 11.12 11.18 11.24 11.3 11.36 11.39 11.45 11.51 11.56 11.62 11.74 11.86 11.95 12.07 12.25 12.33 12.45 12.6];
y = [100 95 90 85 80 75 70 65 60 55 50 45 40 35 30 25 20 15 10 5 0];

% Determino el polinomio
p = polyfit(x,y,9); % Coeficientes de un polinomio de grado 9

% Grafico en el rango que me interesa
x1=[9:0.1:13];
f =polyval(p,x1);
plot(xD,f), xlim([9.8 12.6]), ylim([0 100])