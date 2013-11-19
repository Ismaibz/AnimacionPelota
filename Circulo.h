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
                PV2D* circulo[MAX_LADOS];
                bool colision(PV2D* P, PV2D* v, double &thit, PV2D* &normalIn);  
                GLdouble velocidad;


	Pelota();
	Pelota(PV2D* centron, GLdouble radion);
        void poner_vector(PV2D* vectorn);
        void ponerVelocidad(GLdouble vel);
        void movimiento();

	


};

#endif
