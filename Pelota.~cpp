//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Pelota.h"
#include "Lapiz.h"

//---------------------------------------------------------------------------

Pelota::Pelota(PV2D* centron, GLdouble radion){

        centro = new PV2D(*centron);
        radio = radion;
        delete centron;

        GLdouble alfa = (2.0*PI) / 50.0;
        GLdouble beta = (PI - alfa) / 2.0;
        GLdouble lado = 2.0 * cos(beta) * radio;

        Lapiz* lapiz = new Lapiz(centro,0);
        lapiz->forward(radio,false);
        circulo[0] = new PV2D(*lapiz->pos);
        lapiz->turn(PI - beta);
        for (int i = 1; i < MAX_LADOS; i++)
        {
           lapiz->forward(lado,false);
           circulo[i] = new PV2D(*lapiz->pos);
           lapiz->turn(alfa);
        }
}


void Pelota::poner_vector(PV2D* vectorn){

        vector = new PV2D(*vectorn);
        delete vectorn;
}

#pragma package(smart_init)
