#include "objects/Tangga.h"

Tangga::Tangga(){}

void Tangga::drawStep(float w, float h, float d, float r, float g, float b){
    glPushMatrix();
    glColor3f(r, g, b);
    glTranslatef(w / 2.0f, h / 2.0f, 0.0f);
    glScalef(w, h, d);
    glutSolidCube(1.0);
    glPopMatrix();
}

void Tangga::drawPole(float radius, float h, float r, float g, float b){
    glPushMatrix();
    glColor3f(r, g, b);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // Tegakkan silinder
    
    GLUquadric* quad = gluNewQuadric();
    gluCylinder(quad, radius, radius, h, 16, 1);
    gluDeleteQuadric(quad);
    
    glPopMatrix();
}

void Tangga::draw(float posX, float posY, float posZ){
    int jumlahAnakTangga = 18; 
    float tinggiPerStep = 0.22f; 
    float sudutPerStep = 20.0f; // Putaran tangga
    
    glPushMatrix();
    glTranslatef(posX, posY, posZ);

    // 1. Gambar tiang utama
    drawPole(0.15f, jumlahAnakTangga * tinggiPerStep, 0.4f, 0.4f, 0.4f);

    // 2. Looping anak tangga
    for(int i = 0; i < jumlahAnakTangga; i++) {
        glPushMatrix();
        // Naik, lalu putar
        glTranslatef(0.0f, i * tinggiPerStep, 0.0f);
        glRotatef(i * sudutPerStep, 0.0f, 1.0f, 0.0f);
        
        // Gambar pijakan (warna abu-abu semen)
        drawStep(1.2f, 0.05f, 0.4f, 0.6f, 0.6f, 0.6f); 
        glPopMatrix();
    }
    
    glPopMatrix();
}