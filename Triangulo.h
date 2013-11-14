//---------------------------------------------------------------------------

#ifndef TrianguloH
#define TrianguloH

#include "Obstaculo.h"

class Triangulo : public Obstaculo{

        public:
                //PV2D* vertices[3];
                Triangulo(PV2D* p0,PV2D* p1,PV2D* p2);
                bool colision(PV2D* P, PV2D* v, double &thit, PV2D* &normalIn);

};

//---------------------------------------------------------------------------
#endif
