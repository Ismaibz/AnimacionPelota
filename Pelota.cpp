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

        GLdouble alfa = (2.0*PI) / MAX_LADOS;
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

void Pelota::ponerVelocidad(GLdouble vel){
        velocidad = vel;
}

void Pelota::movimiento(GLdouble avance){

        //Buscar el vector unitario y multiplicarlo x velocidad / / avance
        GLdouble modulo = sqrt(pow(vector->x,2) + pow(vector->y,2));
        PV2D* unitario = new PV2D(vector->x/modulo, vector->y/modulo);
        PV2D* destino = new PV2D(centro->x + unitario->x*avance, centro->y + unitario->y*avance);
        centro = new PV2D(*destino);
        for (int i=0; i<MAX_LADOS; i++){
                circulo[i]->x = circulo[i]->x + unitario->x*avance;
                circulo[i]->y = circulo[i]->y + unitario->y*avance;
        }
}

void Pelota::rebota(PV2D *nG){

        vector = new PV2D (nG->x,nG->y);
}

#pragma package(smart_init)
