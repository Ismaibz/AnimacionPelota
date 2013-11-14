//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Triangulo.h"

//---------------------------------------------------------------------------


Triangulo::Triangulo(PV2D* p0,PV2D* p1,PV2D* p2){

        vertices[0] = new PV2D(*p0);
        vertices[1] = new PV2D(*p1);
        vertices[2] = new PV2D(*p2);
        delete p0;
        delete p1;
        delete p2;
}


bool Triangulo::colision(PV2D* P, PV2D* v, double &thit, PV2D* &normalIn){
       return true;
}
#pragma package(smart_init)

