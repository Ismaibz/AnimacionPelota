//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("AnimacionPelota.res");
USEFORM("main.cpp", MainForm);
USEFORM("TFormRadio.cpp", FormRadio);
<<<<<<< HEAD
USEUNIT("Obstaculo.cpp");
USEUNIT("Triangulo.cpp");
USEUNIT("Circulo.cpp");
=======
USEUNIT("Lapiz.cpp");
USEUNIT("Pelota.cpp");
USEUNIT("PV2D.cpp");
USEFORM("TFormVelocidad.cpp", FormVelocidad);
>>>>>>> origin/Rama-de-Alvaro
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TMainForm), &MainForm);
                 Application->CreateForm(__classid(TFormRadio), &FormRadio);
                 Application->CreateForm(__classid(TFormVelocidad), &FormVelocidad);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
