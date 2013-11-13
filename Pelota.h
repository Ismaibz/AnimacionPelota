//---------------------------------------------------------------------------

#ifndef PelotaH
#define PelotaH

#include <gl/GL.h>

class Pelota{

	public:
		PV2D * centro;
                GLdouble radio;


	Pelota();
	PV2D(PV2D* centro, GLdouble radio);
	PV2D(const PV2D &p);
	~PV2D();

};
//---------------------------------------------------------------------------
#endif
