//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Recubrimiento.h"

//---------------------------------------------------------------------------

Recubrimiento::Recubrimiento(double rad, PV2D* v0, PV2D* v1, PV2D* v2){

        //Segmento de v0 a v1
        int actual = 0;
        Lapiz* lapiz = new Lapiz(v0,0);
        lapiz->lookAt(v1);
        lapiz->turn(-0.5*PI);
        lapiz->forward(rad,false);
        vertices[0] = new PV2D(*lapiz->pos);
        lapiz->turn(0.5*PI);
        lapiz->forward(modulo(v1->restaVertices(v0)),false);
        vertices[1] = new PV2D(*lapiz->pos);
        lapiz->moveTo(v1,false);
        lapiz->lookAt(vertices[1]);


        //Circulo en v1
        PV2D* ve1 = new PV2D(v1->x - v2->x, v1->y - v2->y);
        PV2D* ve2 = new PV2D(v1->x - v0->x, v1->y - v0->y);
        GLdouble angulo = PI - acos((ve1->dot(ve2))/(modulo(ve1)*modulo(ve2)));
        GLdouble alfa = (angulo) / MAX_ANGULO;
        GLdouble beta = (PI - alfa) / 2.0;
        GLdouble lado = 2.0 * cos(beta) * rad;

        lapiz->forward(rad,false);
        lapiz->turn(PI - beta);
        actual = 2;
        int i;
        for (i = actual; i < actual+MAX_ANGULO; i++)
        {
           lapiz->forward(lado,false);
           vertices[i] = new PV2D(*lapiz->pos);
           lapiz->turn(alfa);
        }
        actual = i;

        //Segmento de v1 a v2
        lapiz->moveTo(v1,false);
        lapiz->lookAt(v2);
        lapiz->moveTo(vertices[actual-1],false);
        lapiz->forward(modulo(v1->restaVertices(v2)),false);
        vertices[actual] = new PV2D(*lapiz->pos);
        actual++;

        //Circulo en v2
        ve1 = new PV2D(v2->x - v0->x, v2->y - v0->y);
        ve2 = new PV2D(v2->x - v1->x, v2->y - v1->y);
        angulo = PI - acos((ve1->dot(ve2))/(modulo(ve1)*modulo(ve2)));
        alfa = (angulo) / MAX_ANGULO;
        beta = (PI - alfa) / 2.0;
        lado = 2.0 * cos(beta) * rad;

        lapiz->moveTo(v2,false);
        lapiz->lookAt(vertices[actual-1]);
        lapiz->forward(rad,false);
        lapiz->turn(PI - beta);
        for (i = actual; i < actual+MAX_ANGULO; i++)
        {
           lapiz->forward(lado,false);
           vertices[i] = new PV2D(*lapiz->pos);
           lapiz->turn(alfa);
        }
        actual = i;

        //Segmento de v2 a v0
        lapiz->moveTo(v2,false);
        lapiz->lookAt(v0);
        lapiz->moveTo(vertices[actual-1],false);
        lapiz->forward(modulo(v2->restaVertices(v0)),false);
        vertices[actual] = new PV2D(*lapiz->pos);
        actual++;

        //Circulo en v0
        ve1 = new PV2D(v0->x - v1->x, v0->y - v1->y);
        ve2 = new PV2D(v0->x - v2->x, v0->y - v2->y);
        angulo = PI - acos((ve1->dot(ve2))/(modulo(ve1)*modulo(ve2)));
        alfa = (angulo) / MAX_ANGULO;
        beta = (PI - alfa) / 2.0;
        lado = 2.0 * cos(beta) * rad;

        lapiz->moveTo(v0,false);
        lapiz->lookAt(vertices[actual-1]);
        lapiz->forward(rad,false);
        lapiz->turn(PI - beta);
        for (i = actual; i < actual+MAX_ANGULO; i++)
        {
           lapiz->forward(lado,false);
           vertices[i] = new PV2D(*lapiz->pos);
           lapiz->turn(alfa);
        }
        actual = i;
}

void Recubrimiento::draw(){}

double Recubrimiento::modulo(PV2D * v){
        return sqrt(pow(v->x,2) + pow(v->y,2));
};

#pragma package(smart_init)
