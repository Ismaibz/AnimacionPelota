//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Escena.h"

//---------------------------------------------------------------------------


void Escena::step()
{
        bool exitoG = false;
        GLdouble thitG = 2.0;
        PV2D *nG;
        bool exitoL = false;

        GLdouble thitL = 0;
        PV2D *nL;
        for (int i = 0; i < nObstaculos; i++){
                exitoL = obstaculos[i]->interseccion(pelota->centro, pelota->vector,thitL,nL);

                if (exitoL && thitL >0 && thitL <= 1) exitoL = true;
                else exitoL = false;

                if (exitoL && thitL < thitG){
                        thitG = thitL;
                        nG = nL;
                }
        }

        exitoG |= exitoL;

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

}



#pragma package(smart_init)
