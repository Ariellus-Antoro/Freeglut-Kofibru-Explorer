#include <GL/freeglut.h>

// Fungsi untuk menggambar di layar
void display() {
    // Bersihkan layar
    glClear(GL_COLOR_BUFFER_BIT);

    // Mulai menggambar Segitiga dengan gradasi warna
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f); // Merah di kiri bawah
        glVertex2f(-0.5f, -0.5f);
        
        glColor3f(0.0f, 1.0f, 0.0f); // Hijau di kanan bawah
        glVertex2f(0.5f, -0.5f);
        
        glColor3f(0.0f, 0.0f, 1.0f); // Biru di atas
        glVertex2f(0.0f, 0.5f);
    glEnd();

    // Tukar buffer untuk menampilkan gambar
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    // 1. Inisialisasi FreeGLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    
    // 2. Setup ukuran dan judul Window
    glutInitWindowSize(640, 480);
    glutCreateWindow("Tes");

    // 3. Daftarkan fungsi display ke sistem
    glutDisplayFunc(display);

    // 4. Masuk ke render loop tanpa henti
    glutMainLoop();
    
    return 0;
}