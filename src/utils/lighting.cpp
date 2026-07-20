#include "utils/lighting.h"

Lighting::Lighting()
{

}
void Lighting::initialize()
{
    glEnable(GL_LIGHTING);

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);

    glEnable(GL_COLOR_MATERIAL);

    glColorMaterial(
        GL_FRONT_AND_BACK,
        GL_AMBIENT_AND_DIFFUSE);

    glEnable(GL_NORMALIZE);

    glShadeModel(GL_SMOOTH);
}
void Lighting::update()
{
    setupFloor1Light();
    setupFloor1DownlightWastafel();

    setupFloor2Light();
    setupFloor2RightLight();
    setupFloor2OutdoorLight();

    setupFloor3Light();
    setupFloor3LightOutdoor();

}

void Lighting::setupFloor1Light()

{
    GLfloat position[] =
    {
        -2.0f,
        3.4f,
        0.0f,
        1.0f
    };

    GLfloat ambient[] =
    {
        0.7f,
        0.7f,
        0.7f,
        1.0f
    };

    GLfloat diffuse[] =
    {
        1.3f,
        1.3f,
        1.3f,
        1.3f
    };

    GLfloat specular[] =
    {
        1.0f,
        1.0f,
        1.0f,
        1.0f
    };

    glLightfv(GL_LIGHT0, GL_POSITION, position);

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);

    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);

    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0f);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.005f);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.005f);
}

void Lighting::setupFloor1DownlightWastafel(){
     GLfloat position[] =
    {
        4.5f,    // ubah sesuai posisi wastafel
        3.40f,
        0.0f,
        1.0f
    };

    GLfloat ambient[] =
    {
        0.05f,
        0.05f,
        0.05f,
        1.0f
    };

    GLfloat diffuse[] =
    {
        0.45f,
        0.45f,
        0.45f,
        1.0f
    };

    GLfloat specular[] =
    {
        0.20f,
        0.20f,
        0.20f,
        1.0f
    };

    glLightfv(GL_LIGHT1, GL_POSITION, position);
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specular);

    glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.0f);
    glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.02f);
    glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.02f);
}

void Lighting::setupFloor1downlightWc(){
    GLfloat position[] =
    {
        3.8f,
        3.40f,
        -3.5f,
        1.0f
    };

    GLfloat ambient[] =
    {
        0.10f,0.10f,0.10f,1.0f
    };

    GLfloat diffuse[] =
    {
        0.60f,0.60f,0.60f,1.0f
    };

    GLfloat specular[] =
    {
        0.3f,0.3f,0.3f,1.0f
    };

    glLightfv(GL_LIGHT2, GL_POSITION, position);
    glLightfv(GL_LIGHT2, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT2, GL_SPECULAR, specular);

    glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION,1.0f);
    glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION,0.025f);
    glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION,0.012f);
}
void Lighting::setupFloor1downlightOutdoor(){
    float position[] =
    {
        4.0f,
        3.40f,
        3.5f,
        1.0f
    };

    GLfloat ambient[] =
    {
        0.08f,0.08f,0.08f,1.0f
    };

    GLfloat diffuse[] =
    {
        0.45f,0.45f,0.45f,1.0f
    };

    GLfloat specular[] =
    {
        0.2f,0.2f,0.2f,1.0f
    };

    glLightfv(GL_LIGHT3, GL_POSITION, position);
    glLightfv(GL_LIGHT3, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT3, GL_SPECULAR, specular);

    glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION,1.0f);
    glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION,0.03f);
    glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION,0.015f);
}
void Lighting::setupFloor1downlightOutdoor2(){
    GLfloat position[] =
    {
        0.2f,
        3.40f,
        4.0f,
        1.0f
    };

    GLfloat ambient[] =
    {
        0.08f,0.08f,0.08f,1.0f
    };

    GLfloat diffuse[] =
    {
        0.45f,0.45f,0.45f,1.0f
    };

    GLfloat specular[] =
    {
        0.2f,0.2f,0.2f,1.0f
    };

    glLightfv(GL_LIGHT4, GL_POSITION, position);
    glLightfv(GL_LIGHT4, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT4, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT4, GL_SPECULAR, specular);

    glLightf(GL_LIGHT4, GL_CONSTANT_ATTENUATION,1.0f);
    glLightf(GL_LIGHT4, GL_LINEAR_ATTENUATION,0.03f);
    glLightf(GL_LIGHT4, GL_QUADRATIC_ATTENUATION,0.015f);
}


void Lighting::setupFloor2Light()
{
    GLfloat position[] =
    {
    -1.0f,
    7.30f,
    0.0f,
    1.0f
    };

     GLfloat ambient[] =
    {
        0.7f,
        0.7f,
        0.7f,
        1.0f
    };

    GLfloat diffuse[] =
    {
        1.3f,
        1.3f,
        1.3f,
        1.3f
    };

    GLfloat specular[] =
    {
        1.0f,
        1.0f,
        1.0f,
        1.0f
    };

    glLightfv(GL_LIGHT0, GL_POSITION, position);

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);

    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);

    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0f);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.005f);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.005f);
}
void Lighting::setupFloor2RightLight(){
    GLfloat position[] =
    {
    4.4f,
    7.4f,
    -2.0f,
    1.0f
    };

     GLfloat ambient[] =
    {
        0.7f,
        0.7f,
        0.7f,
        1.0f
    };

    GLfloat diffuse[] =
    {
        1.3f,
        1.3f,
        1.3f,
        1.3f
    };

    GLfloat specular[] =
    {
        1.0f,
        1.0f,
        1.0f,
        1.0f
    };

    glLightfv(GL_LIGHT0, GL_POSITION, position);

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);

    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);

    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0f);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.005f);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.005f);
}
void Lighting::setupFloor2OutdoorLight(){
    float position[] =
    {
        -1.6f,
        7.4f,
        5.8f,
        1.0f
    };

     GLfloat ambient[] =
    {
        0.7f,
        0.7f,
        0.7f,
        1.0f
    };

    GLfloat diffuse[] =
    {
        1.3f,
        1.3f,
        1.3f,
        1.3f
    };

    GLfloat specular[] =
    {
        1.0f,
        1.0f,
        1.0f,
        1.0f
    };

    glLightfv(GL_LIGHT0, GL_POSITION, position);

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);

    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);

    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0f);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.005f);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.005f);
}

void Lighting::setupFloor3Light()
{
    GLfloat position[] =
{
    -0.4f,
    11.30f,
    -0.8f,
    1.0f
};
    
     GLfloat ambient[] =
    {
        0.7f,
        0.7f,
        0.7f,
        1.0f
    };

    GLfloat diffuse[] =
    {
        1.3f,
        1.3f,
        1.3f,
        1.3f
    };

    GLfloat specular[] =
    {
        1.0f,
        1.0f,
        1.0f,
        1.0f
    };

    glLightfv(GL_LIGHT0, GL_POSITION, position);

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);

    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);

    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0f);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.005f);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.005f);
}
void Lighting::setupFloor3LightOutdoor(){
    GLfloat position[] =
    {
        -4.0f,
        13.6f,
        5.5f,
        1.0f
    };
 GLfloat ambient[] =
    {
        0.7f,
        0.7f,
        0.7f,
        1.0f
    };

    GLfloat diffuse[] =
    {
        1.3f,
        1.3f,
        1.3f,
        1.3f
    };

    GLfloat specular[] =
    {
        1.0f,
        1.0f,
        1.0f,
        1.0f
    };

    glLightfv(GL_LIGHT0, GL_POSITION, position);

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);

    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);

    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0f);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.005f);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.005f);
}