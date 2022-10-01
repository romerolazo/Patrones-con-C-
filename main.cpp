#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <stdlib.h>

//paleta de colores basicos para ir llamando con punteros

float blanco[]={1,1,1};
float negro[]={0,0,0},azul[]={0,0,1};
float rojo[]={1,0,0},verde[]={0,1,0}, amarillo[]={1,1,0};
float cyan[]={0,1,1}, rosa[]={1,0.5,0.5}, naranja[]={1,0.8,0}, gris[]={0.6,0.6,0.6};

//funcion para trabajar con mas valores en pantalla y no restringido a -1 a 1


void pantalla()
{
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-11,11,-11,11);

}

void cuadrado(float x, float y, float lado, float *color, float grosor,int pat)
{
    glEnable(GL_LINE_STIPPLE);
        glLineWidth(grosor);
        glLineStipple(3,pat);
        glBegin(GL_LINE_LOOP);
            glVertex2d(x,y);
            glVertex2d(x+lado,y);
            glVertex2d(x+lado,y-lado);
            glVertex2d(x,y-lado);
        glEnd();

        glDisable(GL_LINE_STIPPLE);

    glEnd();
}
void linea_vertical (float x, float y,float lado)
{
            glVertex2d(x,y);
            glVertex2d(x,y+lado);


}
void linea_horizontal (float x, float y,float lado)
{
            glVertex2d(x,y);
            glVertex2d(x+lado,y);


}
void linea_diagonal1 (float x, float y,float lado)
{
            glVertex2d(x,y);
            glVertex2d(x+lado,y+lado);
}

void linea_diagonal2 (float x, float y,float lado)
{
            glVertex2d(x,y);
            glVertex2d(x+lado,y-lado);
}


void patrones_vertical (float x, float y, float lado, float *color, int grosor, int pattern )
{   glColor3fv(color);
    int pat;
    switch (pattern)
    {
        case 0:
            pat=0x0101;
        break;
        case 1:
            pat=0xAAAA;
        break;
        case 2:
            pat=0x00FF;
        break;
        case 3:
            pat=0x0C0F;
        break;
        case 4:
            pat=0x01C47;
        break;
    }
    //cuadrado(x,y,lado,color,grosor,pat);
    glEnable(GL_LINE_STIPPLE);
        glLineWidth(grosor);
        glLineStipple(1,pat);


        glBegin(GL_LINES);
            linea_vertical(x,y,lado);
        glEnd();

        glDisable(GL_LINE_STIPPLE);

}

void patrones_horizontal (float x, float y, float lado, float *color, int grosor, int pattern )
{   glColor3fv(color);
    int pat;
    switch (pattern)
    {
        case 0:
            pat=0x0101;
        break;
        case 1:
            pat=0xAAAA;
        break;
        case 2:
            pat=0x00FF;
        break;
        case 3:
            pat=0x0C0F;
        break;
        case 4:
            pat=0x01C47;
        break;
    }
    //cuadrado(x,y,lado,color,grosor,pat);
    glEnable(GL_LINE_STIPPLE);
        glLineWidth(grosor);
        glLineStipple(1,pat);


        glBegin(GL_LINES);
            linea_horizontal(x,y,lado);
        glEnd();

        glDisable(GL_LINE_STIPPLE);

}

void patrones_diagonal1 (float x, float y, float lado, float *color, int grosor, int pattern )
{   glColor3fv(color);
    int pat;
    switch (pattern)
    {
        case 0:
            pat=0x0101;
        break;
        case 1:
            pat=0xAAAA;
        break;
        case 2:
            pat=0x00FF;
        break;
        case 3:
            pat=0x0C0F;
        break;
        case 4:
            pat=0x01C47;
        break;
    }
    //cuadrado(x,y,lado,color,grosor,pat);
    glEnable(GL_LINE_STIPPLE);
        glLineWidth(grosor);
        glLineStipple(1,pat);


        glBegin(GL_LINES);
            linea_diagonal1(x,y,lado);
        glEnd();

        glDisable(GL_LINE_STIPPLE);

}
void patrones_diagonal2 (float x, float y, float lado, float *color, int grosor, int pattern )
{   glColor3fv(color);
    int pat;
    switch (pattern)
    {
        case 0:
            pat=0x0101;
        break;
        case 1:
            pat=0xAAAA;
        break;
        case 2:
            pat=0x00FF;
        break;
        case 3:
            pat=0x0C0F;
        break;
        case 4:
            pat=0x01C47;
        break;
    }
    glEnable(GL_LINE_STIPPLE);
        glLineWidth(grosor);
        glLineStipple(1,pat);


        glBegin(GL_LINES);
            linea_diagonal2(x,y,lado);
        glEnd();

        glDisable(GL_LINE_STIPPLE);

}
void display(void)
{
glClearColor(0,0,0,0);//color de la ventana negro
glClear(GL_COLOR_BUFFER_BIT);

    patrones_vertical(-9,6,3,amarillo,2,2);
    patrones_vertical(-5,6,3,amarillo,2,2);
    patrones_vertical(-1,6,3,amarillo,2,2);
    patrones_vertical(3,6,3,amarillo,2,2);
    patrones_vertical(7,6,3,amarillo,2,2);

    patrones_vertical(-6,6,3,rojo,2,0);
    patrones_vertical(-2,6,3,rojo,2,0);
    patrones_vertical(2,6,3,rojo,2,0);
    patrones_vertical(6,6,3,rojo,2,0);
    patrones_vertical(10,6,3,rojo,2,0);

    patrones_horizontal(-5,9,3,rojo,3,1);
    patrones_horizontal(-1,9,3,rojo,3,1);
    patrones_horizontal(3,9,3,rojo,3,1);
    patrones_horizontal(7,9,3,rojo,3,1);

    patrones_horizontal(-5,6,3,gris,3,4);
    patrones_horizontal(-1,6,3,gris,3,4);
    patrones_horizontal(3,6,3,gris,3,4);
    patrones_horizontal(7,6,3,gris,3,4);

    patrones_horizontal(-9,5,3,naranja,4,3);
    patrones_horizontal(-5,5,3,rosa,4,3);
    patrones_horizontal(-1,5,3,naranja,4,3);
    patrones_horizontal(3,5,3,rojo,4,3);
    patrones_horizontal(7,5,3,naranja,4,3);

    patrones_horizontal(-9,2,3,amarillo,4,1);
    patrones_horizontal(-5,2,3,cyan,4,1);
    patrones_horizontal(-1,2,3,cyan,4,1);
    patrones_horizontal(3,2,3,blanco,4,1);
    patrones_horizontal(7,2,3,cyan,4,1);

    patrones_horizontal(-9,9,3,azul,3,1);
    patrones_horizontal(-9,6,3,azul,3,1);

    patrones_vertical(-9,2,3,blanco,5,2);
    patrones_vertical(-5,2,3,blanco,5,2);
    patrones_vertical(-1,2,3,verde,5,2);
    patrones_vertical(3,2,3,blanco,5,2);
    patrones_vertical(7,2,3,naranja,5,2);
    patrones_vertical(10,2,3,blanco,5,2);

    patrones_vertical(-6,2,3,verde,5,2);
    patrones_vertical(-2,2,3,blanco,5,2);
    patrones_vertical(2,2,3,cyan,5,2);
    patrones_vertical(6,2,3,blanco,5,2);

    patrones_diagonal1(-9,6,3,rosa,5,3);
    patrones_diagonal1(-5,6,3,rosa,5,3);
    patrones_diagonal1(-1,6,3,rosa,5,3);
    patrones_diagonal1(3,6,3,rosa,5,3);
    patrones_diagonal1(7,6,3,rosa,5,3);

    patrones_diagonal1(-9,2,3,amarillo,5,4);
    patrones_diagonal1(-5,2,3,rojo,5,4);
    patrones_diagonal1(-1,2,3,amarillo,5,4);
    patrones_diagonal1(3,2,3,azul,5,4);
    patrones_diagonal1(7,2,3,amarillo,5,4);

    patrones_diagonal2(-9,9,3,amarillo,5,0);
    patrones_diagonal2(-5,9,3,rojo,5,0);
    patrones_diagonal2(-1,9,3,azul,5,0);
    patrones_diagonal2(3,9,3,rojo,5,0);
    patrones_diagonal2(7,9,3,verde,5,0);

    patrones_diagonal2(-9,5,3,verde,5,3);
    patrones_diagonal2(-5,5,3,verde,5,3);
    patrones_diagonal2(-1,5,3,verde,5,3);
    patrones_diagonal2(3,5,3,verde,5,3);
    patrones_diagonal2(7,5,3,verde,5,3);




                    //glPointSize(7); //    incrementa el tamaño del punto
                    //glLineWidth(5);//incrementa el ancho de la linea



//////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

 glutSwapBuffers();                 // opcional funciona para algunos con esta funcion,... glFlush()
}






                            //funcion principal, siempre es de esa manera
int main(int argc, char *argv[])
{

    glutInit(&argc, argv);              //Sirve para inicializar mi ventana de opengl
    glutInitWindowPosition(0,0);        //parte la ventana en 4 partes y en (0,0) esta en el centro,posicion de mi ventana
    glutInitWindowSize(600,600);        //tamaño de mi ventana tamaño normal (600,600)
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);           //tipo de modo de visualizacion de la ventana

    glutCreateWindow("Primer programa");        //Colocar el nombre que se le da a la ventana
    glutDisplayFunc(display);                   //nombre de la función
    pantalla();
                            //glClearColor(1,1,1,1);//color de la ventana negro
    glutMainLoop();             //hace que aparezca la ventana
    return EXIT_SUCCESS;            //tambien se puede usar el return
}
