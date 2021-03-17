#include <iostream>
using namespace std;

// Funcion para imprimir las coordenadas de los pixeles deseados
// Se basa en la simetria de un circulo y el hecho de que tiene 8 octantes de 45 grados cada uno. 
void drawCircle(int xc, int yc, int x, int y)
{
     cout << "point(" << xc+x << "," << yc+y << ");";
     cout << "point(" << xc-x << "," << yc+y << ");";
    //cout << "line(" << xc+x << "," << yc+y << ","<< xc+y << "," << yc+x << ");";
     cout << "point(" << xc+x << "," << yc-y << ");";
     cout << "point(" << xc-x << "," << yc-y << ");";
    //cout << "line(" << xc+x << "," << yc-y << ","<< xc+y << "," << yc-x << ");";
     cout << "point(" << xc+y << "," << yc+x << ");";
     cout << "point(" << xc-y << "," << yc+x << ");";
     //cout << "line(" << xc-y << "," << yc-x << ","<< xc-x << "," << yc-y << ");";
     cout << "point(" << xc+y << "," << yc-x << ");";
     cout << "point(" << xc-y << "," << yc-x << ");";
    //cout << "line(" << xc-x << "," << yc+y << ","<< xc-y << "," << yc+x << ");";
}
 
// Funcion para crear el patrón visual, se utiliza el algortimo Bresenham para crear un circulo 
void algoritmoPatron(int xc, int yc)
{
    // el radio es mitad del parametro menor ingresado, de esta manera se asegura que el circulo
    // siempre cabe en el canvas a pintar
    int r = ((xc > yc) ? yc/2 : xc/2);  // --- 5 tiempos
    // las coordenadas del centro del circulo son el centro del canvas
    xc = xc/2;  // --- 2 tiempos
    yc = yc/2;  // --- 2 tiempos
    
    // loop para crear efecto túnel, se crean circulos cada vez con un radio menor
    while(r > 0) // --- 1 tiempo
    {
        //Se comienza en (0,R)
        int x = 0, y = r;     // --- 2 tiempos
        // d es un parametro de decision que se utiliza par decidir la ubicacion del próximo pixel a pintar
        int d = 3 - 2 * r;    // --- 3 tiempos

        // se imprimen las primeras 8 coordenadas para el primer pixel en el octante
        drawCircle(xc, yc, x, y);  // --- 5 tiempos 
        // esta condicion de para marca el final del primer octante de 45 grados
        while (y >= x)  // -- 1 tiempo
        {
            // para cada pixel en el primer cuadrante de 45 grados, se retorna una coordenadas para cada uno de los 8 octantes
            x++;  // --- 2 tiempos

            // Se revisa el parametro de decision y se actualizan las variables dependiendo del resultado
            if (d > 0) // --- 1 tiempo  , se toma en cuenta el "peor" caso
            {
                y--;   // --- 2 tiempos
                d = d + 4 * (x - y) + 10;   // --- 5 tiempos ,
            }
            else
                d = d + 4 * x + 6;  
            
            // se imprimen las 8 coordenadas para un pixel en (x,y), esto es gracias a la simetria de un circulo
            drawCircle(xc, yc, x, y); // --- 5 tiempos
        }
    // se disminuye el radio para repetir el ciclo con un circulo más pequeño y así crear el efecto visual
    r--;  // --- 2 tiempos
    }
}
/*
C = cantidad de círculos por dibujar
P = cantidad de pixeles en el primer cuadrante del circulo
N = cantidad de círculos por dibujar (radio del circulo más grande) * la cantidad de pixeles en el primer cuadrante del circulo
N = C * P

= 9 + (29 * ( N/C * N/P ) )
= 9 + (29 * N^2/CP)
= 9 + (29 * N^2/N )

f(n) = 29N + 9
O(n)
*/

int main(){
    int xc, yc, xc1, yc1;

    cout << "Ingrese el alto del canvas: ";
    cin >> yc;
    cout << "Ingrese el ancho del canvas: ";
    cin >> xc;

    algoritmoPatron(xc, yc);    // se llama la funcion


    return 0;
}