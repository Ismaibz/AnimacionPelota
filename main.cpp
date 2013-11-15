//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
    hdc = GetDC(Handle);
    SetPixelFormatDescriptor();
    hrc = wglCreateContext(hdc);
    if(hrc == NULL)
    	ShowMessage(":-)~ hrc == NULL");
    if(wglMakeCurrent(hdc, hrc) == false)
    	ShowMessage("Could not MakeCurrent");
    //Cor de fondo de la ventana
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    //inicialización del volumen de vista
    xRight=200.0; xLeft=-xRight;
    yTop=xRight; yBot=-yTop;
    //Radio del volumen de vista == 1

    //inicialización del puerto de vista
    //ClientWidth=400;
    //ClientHeight=400;
    RatioViewPort=1.0;

    // inicialización de las variables del programa
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SetPixelFormatDescriptor()
{
    PIXELFORMATDESCRIPTOR pfd = {
    	sizeof(PIXELFORMATDESCRIPTOR),
        1,
        PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
        PFD_TYPE_RGBA,
        32,
        0,0,0,0,0,0,
        0,0,
        0,0,0,0,0,
        32,
        0,
        0,
        PFD_MAIN_PLANE,
        0,
        0,0,0
    };
    int PixelFormat = ChoosePixelFormat(hdc, &pfd);
    SetPixelFormat(hdc, PixelFormat, &pfd);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormResize(TObject *Sender)
{

 //se actualiza puerto de vista y su radio
  if ((ClientWidth<=1)||(ClientHeight<=1)){
     ClientWidth=400;
     ClientHeight=400;
     RatioViewPort=1.0;
     }
  else RatioViewPort= (float)ClientWidth/(float)ClientHeight;

  glViewport(0,0,ClientWidth,ClientHeight);

  // se actualiza el volumen de vista
  // para que su radio coincida con ratioViewPort
  GLfloat WidthVolVista = xRight-xLeft;
  GLfloat HeightVolVista = yTop-yBot;
  GLfloat RatioVolVista = (xRight-xLeft)/(yTop-yBot);

  if (RatioVolVista>=RatioViewPort){
     //Aumentamos yTop-yBot
     GLfloat newHeight = WidthVolVista/RatioViewPort;
     GLfloat yMiddle = (yTop+yBot)/2.0;
     yTop= yMiddle+newHeight/2.0;
     yBot= yMiddle-newHeight/2.0;
     }
  else{
     //Aumentamos xRight-xLeft
     GLfloat newWidth = HeightVolVista*RatioViewPort;
     GLfloat xMiddle = (xLeft+xRight)/2.0;
     xRight= xMiddle+newWidth/2.0;
     xLeft= xMiddle-newWidth/2.0;
     }

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(xLeft,xRight, yBot,yTop);


  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  GLScene();

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::GLScene()
{
        glClear(GL_COLOR_BUFFER_BIT);
        //drawScene();
        if (pelota != NULL){
                glBegin(GL_POLYGON);
                for (int i = 0; i < MAX_LADOS; i++)
                {
                         glVertex2d(pelota->circulo[i]->x,pelota->circulo[i]->y);
                }
                glEnd();
        }
        glFlush();
        SwapBuffers(hdc);
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::FormPaint(TObject *Sender)
{
  GLScene();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormDestroy(TObject *Sender)
{
    ReleaseDC(Handle,hdc);
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hrc);
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::FormClick(TObject *Sender)
{
        if (inicio == true)
          {     /*
                GLfloat escalaAncho = (xRight - xLeft) / ClientWidth;
                GLfloat escalaAlto = (yTop - yBot) / ClientHeight;
                TPoint p;
                GetCursorPos(&p);
                //xCentro = (p.x - this->Left) - ClientWidth / 2;
                yCentro = ClientHeight / 2 - (p.y - this->Top);
                inicio = false;
                //GLfloat xAbs =  (xCentro * escalaAncho);
                GLfloat xAbs = p.x / (ClientWidth / (xRight - xLeft)) - this->Left + xLeft;
                //GLfloat yAbs =  (yCentro * escalaAlto);
                GLfloat yAbs = -(p.y / (ClientHeight / (yTop - yBot)) + yBot);

                pelota = new Pelota(new PV2D(xAbs,yAbs),radio);

                GLScene();
                ShowMessage("Presione un punto para la direccion de la pelota");
                direccion = true;
                */
                GLfloat escalaAncho = ClientWidth / (xRight - xLeft);
                GLfloat escalaAlto = ClientHeight / (yTop - yBot);
                TPoint p;
                GetCursorPos(&p);
                xCentro = (p.x) / escalaAncho - (ClientWidth) / 2 - this->Left;
                yCentro = (ClientHeight - p.y) / escalaAlto + (this->Top + this->Height);
                pelota = new Pelota(new PV2D(xCentro,0),radio);
                inicio = false;
                GLScene();
                ShowMessage("Presione un punto para la direccion de la pelota");
                direccion = true;
          } else{
        if (direccion == true){
                direccion = false;
                GLfloat escalaAncho = (xRight - xLeft) / ClientWidth;
                GLfloat escalaAlto = (yTop - yBot) / ClientHeight;
                TPoint p;
                GetCursorPos(&p);
                //xCentro = (p.x - this->Left) - ClientWidth / 2;
                yCentro = ClientHeight / 2 - (p.y - this->Top);
                //GLfloat xAbs =  (xCentro * escalaAncho);
                GLfloat xAbs = p.x / (ClientWidth / (xRight - xLeft)) - this->Left + xLeft;
                //GLfloat yAbs =  (yCentro * escalaAlto);
                GLfloat yAbs = -(p.y / (ClientHeight / (yTop - yBot)) + yBot);

                pelota->poner_vector(new PV2D(xAbs - pelota->centro->x, yAbs - pelota->centro->y));

                TFormVelocidad* FormVelocidad;
                FormVelocidad = new TFormVelocidad(NULL);
                FormVelocidad->ShowModal();
                AnsiString vel = FormVelocidad->EditVelocidad->Text;
                pelota->ponerVelocidad(atoi(vel.c_str()));
        }
        };
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::NuevaPelota1Click(TObject *Sender)
{
       TFormRadio* FormRadio;
       FormRadio = new TFormRadio(NULL);
       FormRadio->ShowModal();
       AnsiString rad = FormRadio->EditRadio->Text;
       radio = atoi(rad.c_str());
       ShowMessage("Presione un punto para colocar la pelota");
       inicio = true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Salir1Click(TObject *Sender)
{
        exit(-1);        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::AvanzarMenuClick(TObject *Sender)
{
        pelota->movimiento();
        GLScene();        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if (inicio == true)
          {
                GLfloat escalaAncho = ClientWidth / (xRight - xLeft);
                GLfloat escalaAlto = ClientHeight / (yTop - yBot);
                xCentro = (X + xLeft * escalaAncho) / escalaAncho;
                yCentro = (ClientHeight/2 - Y) / escalaAlto;
                pelota = new Pelota(new PV2D(xCentro,yCentro),radio);
                inicio = false;
                GLScene();
                ShowMessage("Presione un punto para la direccion de la pelota");
                direccion = true;
          } else{
                if (direccion == true){
                        direccion = false;
                        GLfloat escalaAncho = ClientWidth / (xRight - xLeft);
                        GLfloat escalaAlto = ClientHeight / (yTop - yBot);
                        xCentro = (X + xLeft * escalaAncho) / escalaAncho;
                        yCentro = (ClientHeight/2 - Y) / escalaAlto;
                        pelota->poner_vector(new PV2D(xCentro - pelota->centro->x, yCentro - pelota->centro->y));

                        TFormVelocidad* FormVelocidad;
                        FormVelocidad = new TFormVelocidad(NULL);
                        FormVelocidad->ShowModal();
                        AnsiString vel = FormVelocidad->EditVelocidad->Text;
                        pelota->ponerVelocidad(atoi(vel.c_str()));
                }
        };
}
//---------------------------------------------------------------------------

