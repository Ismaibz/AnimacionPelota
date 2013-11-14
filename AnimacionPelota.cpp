//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("AnimacionPelota.res");
USEFORM("main.cpp", MainForm);
USEUNIT("\\10.10.69.107\GitHub\AnimacionPelota\Lapiz.cpp");
USEUNIT("\\10.10.69.107\GitHub\AnimacionPelota\PV2D.cpp");
USEUNIT("Pelota.cpp");
USEFORM("TFormRadio.cpp", FormRadio);
USEUNIT("Obstaculo.cpp");
USEUNIT("Triangulo.cpp");
USEUNIT("Circulo.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TMainForm), &MainForm);
                 Application->CreateForm(__classid(TFormRadio), &FormRadio);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
