#include <iostream>
using namespace std;


void drawCircle(int xc, int yc, int x, int y)
{
    cout << "point(" << xc+x << "," << yc+y << ");";
    cout << "point(" << xc-x << "," << yc+y << ");";
    cout << "point(" << xc+x << "," << yc-y << ");";
    cout << "point(" << xc-x << "," << yc-y << ");";
    cout << "point(" << xc+y << "," << yc+x << ");";
    cout << "point(" << xc-y << "," << yc+x << ");";
    cout << "point(" << xc+y << "," << yc-x << ");";
    cout << "point(" << xc-y << "," << yc-x << ");";
}
 
// Function for circle-generation
// using Bresenham's algorithm
void circleBres(int xc, int yc)
{
    int r = ((xc > yc) ? yc/2 : xc/2);
    xc = xc/2;
    yc = yc/2;
    
    while(r > 0)
    {
        int x = 0, y = r;
        int d = 3 - 2 * r;
      //  cout << "beginShape(POINTS);";
        drawCircle(xc, yc, x, y);
        while (y >= x)
        {
            // for each pixel we will
            // draw all eight pixels
                
            x++;

            // check for decision parameter
            // and correspondingly 
            // update d, x, y
            if (d > 0)
            {
                y--; 
                d = d + 4 * (x - y) + 10;
            }
            else
                d = d + 4 * x + 6;
            drawCircle(xc, yc, x, y);
        }
   // cout << "endShape();";
    r--;
    }
}

int main(){
    int xc, yc, xc1, yc1;

    cout << "Ingrese el alto del canvas: ";
    cin >> yc;
    cout << "Ingrese el ancho del canvas: ";
    cin >> xc;

  //  int xc = 100, yc = 100, r = 30;
    circleBres(xc, yc);    // function call


    return 0;
}