//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Recubrimiento.h"

//---------------------------------------------------------------------------

Recubrimiento::Recubrimiento(double rad, PV2D* v0, PV2D* v1, PV2D* v2){
        Lapiz* lapiz = new Lapiz(v0,0);
        lapiz->lookAt(v1);
        lapiz->turn(-0.5);
        lapiz->forward(rad,false);
        vertices[0] = lapiz->pos;
        lapiz->turn(0.5);
        lapiz->forward(modulo(v1->restaVertices(0)),false);
        vertices[1] = lapiz->pos;
        lapiz->moveTo(v1,false);
        //Continuar
}

void Recubrimiento::draw(){}

double Recubrimiento::modulo(PV2D * v){
        return sqrt(pow(v->x,2) + pow(v->y,2));
};

#pragma package(smart_init)
