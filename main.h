#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include "Pelota.h"
#include "TFormRadio.h"
<<<<<<< HEAD

=======
<<<<<<< HEAD
>>>>>>> origin/Rama-de-Isma
#include "Lista.h"
#include "Obstaculo.h"
#include "Triangulo.h"

#include "TFormVelocidad.h"
<<<<<<< HEAD

=======
>>>>>>> origin/Rama-de-Alvaro
>>>>>>> origin/Rama-de-Isma

#include <gl\gl.h>
#include <gl\glu.h>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *Salir1;
        TMenuItem *NuevaPelota1;
        TMenuItem *AvanzarMenu;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall FormPaint(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall FormClick(TObject *Sender);
        void __fastcall NuevaPelota1Click(TObject *Sender);
        void __fastcall Salir1Click(TObject *Sender);
        void __fastcall AvanzarMenuClick(TObject *Sender);
        void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
private:
        HDC hdc;
        HGLRC hrc;
 //definen el tamaño del volumen de vista
        GLfloat xLeft,xRight,yTop,yBot;
 //guarda el radio del puerto de vista
        GLfloat RatioViewPort;
        void __fastcall SetPixelFormatDescriptor();
        void __fastcall GLScene();
        bool inicio;
        bool direccion;
        
        GLdouble xCentro;
        GLdouble yCentro;
        GLdouble radio;
        Pelota *pelota;
        Lista<Obstaculo*> *obstaculos;
        
public:		// User declarations
        __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
