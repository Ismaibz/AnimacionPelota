//---------------------------------------------------------------------------

#ifndef CirculoH
#define CirculoH
//---------------------------------------------------------------------------

#include "Obstaculo.h"

const int MAX_LADOS = 500;

class Circulo : public Obstaculo{

        public:
		PV2D* centro;
                GLdouble radio;
                GLdouble radio2;
                PV2D* contorno[MAX_LADOS];
                bool interseccion(PV2D* P, PV2D* v, double &thit, PV2D* &normalIn);  
                void draw(){};


	Circulo();
	Circulo(PV2D* centron, GLdouble radion);
        

};

#endif
