//---------------------------------------------------------------------------

#ifndef CirculoH
#define CirculoH
//---------------------------------------------------------------------------

#include "Obstaculo.h"

<<<<<<< HEAD:Circulo.h
const int MAX_LADOS = 100;
=======
const int MAX_LADOS = 500;
>>>>>>> origin/Rama-de-Alvaro:Pelota.~h

class Circulo : public Obstaculo{

        public:
		PV2D* centro;
                GLdouble radio;
                PV2D* circulo[MAX_LADOS];
<<<<<<< HEAD:Circulo.h
                bool colision(PV2D* P, PV2D* v, double &thit, PV2D* &normalIn); 
=======
                GLdouble velocidad;


	Pelota();
	Pelota(PV2D* centron, GLdouble radion);
        void poner_vector(PV2D* vectorn);
        void ponerVelocidad(GLdouble vel);
        void movimiento();

	
>>>>>>> origin/Rama-de-Alvaro:Pelota.~h

};

#endif
