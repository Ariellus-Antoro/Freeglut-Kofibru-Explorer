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

    // setupFloor2Light();

    // setupFloor3Light();
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

// void Lighting::setupFloor2Light()
// {
//     GLfloat position[] =
//     {
//     0.0f,
//     7.0f,
//     0.0f,
//     1.0f
//     };

//     GLfloat ambient[] =
//     {
//         0.2f,
//         0.2f,
//         0.2f,
//         1.0f
//     };

//     GLfloat diffuse[] =
//     {
//         1.0f,
//         1.0f,
//         1.0f,
//         1.0f
//     };

//     GLfloat specular[] =
//     {
//         1.0f,
//         1.0f,
//         1.0f,
//         1.0f
//     };

//     glLightfv(GL_LIGHT0, GL_POSITION, position);

//     glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);

//     glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);

//     glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
// }

// void Lighting::setupFloor3Light()
// {
//     GLfloat position[] =
// {
//     5.0f,
//     3.4f,
//     -3.0f,
//     1.0f
// };
    
//     GLfloat ambient[] =
//     {
//         0.2f,
//         0.2f,
//         0.2f,
//         1.0f
//     };

//     GLfloat diffuse[] =
//     {
//         1.0f,
//         1.0f,
//         1.0f,
//         1.0f
//     };

//     GLfloat specular[] =
//     {
//         1.0f,
//         1.0f,
//         1.0f,
//         1.0f
//     };

//     glLightfv(GL_LIGHT0, GL_POSITION, position);

//     glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);

//     glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);

//     glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
// }