//---------------------------------------------------------------------------

#ifndef PV2DH
#define PV2DH
//---------------------------------------------------------------------------

#include <gl/GL.h>

class PV2D{

	public:
		GLdouble x;
		GLdouble y;

	PV2D();
	PV2D(GLdouble xn, GLdouble yn);
	PV2D(const PV2D &p);
	~PV2D();

};


#endif
