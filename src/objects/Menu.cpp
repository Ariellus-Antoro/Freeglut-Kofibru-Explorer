#include "objects/Menu.h"

Menu::Menu()
{

}

void Menu::drawBlock(
    float width,
    float height,
    float depth,
    float r,
    float g,
    float b)
{
    glPushMatrix();

    glColor3f(r, g, b);

    glScalef(width, height, depth);

    glutSolidCube(1.0f);

    glPopMatrix();
}
void Menu::draw()
{
    //-------------------------
    // Papan depan
    //-------------------------
    glPushMatrix();

    glTranslatef(0.0f, 0.5f, 0.12f);

    // Miring ke belakang
    glRotatef(-15.0f, 1.0f, 0.0f, 0.0f);

    drawBlock(
        1.0f,   // lebar
        1.5f,   // tinggi
        0.05f,  // sangat tipis
        0.55f, 0.27f, 0.07f);

    glPopMatrix();


    //-------------------------
    // Papan belakang
    //-------------------------
    glPushMatrix();

    glTranslatef(0.0f, 0.5f, -0.12f);

    // Miring ke depan
    glRotatef(15.0f, 1.0f, 0.0f, 0.0f);

    drawBlock(
        1.0f,
        1.5f,
        0.05f,
        0.55f, 0.27f, 0.07f);

    glPopMatrix();


    //-------------------------
    // Alas bawah
    //-------------------------
    glPushMatrix();

    glTranslatef(0.0f, -0.2f, 0.0f);

    drawBlock(
        1.0f,
        0.08f,
        0.7f,
        0.2f,0.2f,0.2f);

    glPopMatrix();
}