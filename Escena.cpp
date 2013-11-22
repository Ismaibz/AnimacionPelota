//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Escena.h"
#include "Triangulo.h"

//---------------------------------------------------------------------------


void Escena::step()
{
        bool exitoG = false;
        GLdouble thitG = pelota->velocidad;
        PV2D *nG;
        bool exitoL = false;
        GLdouble thitL = 0;
        PV2D *nL;
        for (int i = 0; i < nObstaculos; i++){

                exitoL = obstaculos[i]->interseccion(pelota->centro, pelota->vector,thitL,nL);
                if (exitoL && thitL >0 && thitL <= (pelota->velocidad)*1.1) exitoL = true;
                else exitoL = false;

                if (exitoL && thitL < thitG){
                        thitG = thitL;
                        nG = new PV2D (*nL);
                }
                exitoG |= exitoL;
        }



        if (!exitoG) pelota->movimiento(1);
        else {
                pelota->movimiento(thitG);
                pelota->rebota(nG);
        }
}

void Escena::aniadirObstaculo(Obstaculo *o)
{
        obstaculos[nObstaculos] = o;
        nObstaculos++;
}

void Escena::draw()
{
     glBegin(GL_POLYGON);
     for (int i = 0; i < MAX_LADOS; i++)
     {
        glVertex2d(pelota->circulo[i]->x,pelota->circulo[i]->y);
     }
     glEnd();
     for (int i=0; i < nObstaculos; i++)
     {
        obstaculos[i]->draw();
     }
     glColor3f(1.0,1.0,1.0);
     glBegin(GL_POINTS);
        glVertex2d(pelota->centro->x,pelota->centro->y);
     glEnd();
     glColor3f(0,0,0);


     

}



#pragma package(smart_init)
