#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;

extern ofstream myfile("puntos.txt", ofstream::trunc);

void printProcessingInfo(int x, int y){
    cout<<"BufferedReader reader;\n""String line;\n\n";
    cout<<"void setup(){\n    size("<<x<<","<<y<<");\n";
    cout<<"    background(255,255,255);\n";
    // ACA SE DEBE DE PONER EL PATH PROPIO DE DONDE SE GUARDÓ EL TXT
    cout<<"    reader = createReader(\"/Users/danielbejarano/Desktop/Análisis de Algoritmos/Casos/Caso 4/AnalisisCaso4/puntos.txt\");\n}\n\n";
    cout<<"void draw(){\n    try {\n        line = reader.readLine();\n    } catch (IOException e) {\n";
    cout<<"        e.printStackTrace();\n        line = null;\n    }\n    if (line == null) {\n";
    cout<<"        noLoop();\n    } else {\n        printPoint(line);\n    }\n}\n\n";

    cout<<"void printPoint(String linea){\n  String str = \"\";\n  int i = 0;\n  int x = 0;\n  int y = 0;\n";
    cout<<"  while(i < linea.length()){\n    char number = linea.charAt(i);\n    if(number != ' '){\n";
    cout<<"      str += linea.charAt(i);\n    }else{\n      if(number == ' '){\n";
    cout<<"        x = Integer.valueOf(str);\n        str = \"\";\n      }else{\n        str += linea.charAt(i);\n";
    cout<<"      }\n    }\n    i++;\n  }\n  y = Integer.valueOf(str);\n  point(x, y);\n}\n\n";

}



// Funcion para imprimir las coordenadas de los pixeles deseados
// Se basa en la simetria de un circulo y el hecho de que tiene 8 octantes de 45 grados cada uno. 
void drawCircle(int xc, int yc, int x, int y)
{
    if(myfile.is_open()){
        string str = to_string(xc+x)+" "+to_string(yc+y);
        myfile<<str<<endl;
        str = to_string(xc-x)+" "+to_string(yc+y);
        myfile<<str<<endl;
        str = to_string(xc+x)+" "+to_string(yc-y);
        myfile<<str<<endl;
        str = to_string(xc-x)+" "+to_string(yc-y);
        myfile<<str<<endl;
        str = to_string(xc+y)+" "+to_string(yc+x);
        myfile<<str<<endl;
        str = to_string(xc-y)+" "+to_string(yc+x);
        myfile<<str<<endl;
        str = to_string(xc+y)+" "+to_string(yc-x);
        myfile<<str<<endl;
        str = to_string(xc-y)+" "+to_string(yc-x);
        myfile<<str<<endl;
    }
    else cout<<"Unable to open file";
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
P = cantidad de pixeles en el primer octante del circulo
N = cantidad de círculos por dibujar (radio del circulo más grande) * la cantidad de pixeles en el primer octante del circulo
N = C * P

= 9 + (29 * ( N/C * N/P ) )
= 9 + (29 * N^2/CP)
= 9 + (29 * N^2/N )

f(n) = 29N + 9
O(n)
*/

int main(){

    int xc, yc, xc1, yc1; //declaraciones de los parametros 

    cout << "Ingrese el alto del primer canvas: ";
    cin >> yc;
    cout << "Ingrese el ancho del primer canvas: ";
    cin >> xc;
    cout << endl;

    printProcessingInfo(xc, yc);
    algoritmoPatron(xc, yc);    // se llama el algoritmo principal para la primera prueba

    // aca se debe ir y cambiar el nombre del punto.txt que se creó, si no se va a overwrite y se pierde
    // cuando se cambia el nombre del archivo, claramente tambien se debe de modificar el path que se lee en el código que pegamos en processing
   
    cout << "Ingrese el alto del segundo canvas: ";
    cin >> yc1;
    cout << "Ingrese el ancho del segundo canvas: ";
    cin >> xc1;
    cout << endl;

    printProcessingInfo(xc1, yc1);
    algoritmoPatron(xc1, yc1);    // se llama el algoritmo principal para le segunda prueba

    myfile.close();

    return 0;
}