#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Set up projection matrix for 2D
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.5, 1.5, -1.0, 1.0);  // Adjust these values based on your needs
    
    // Set up model-view matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Draw frame
    glColor3f(1.0f, 1.0f, 1.0f);  // RGB values for white
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -0.5f);
        glVertex2f(1.0f, -0.5f);
        glVertex2f(1.0f, 0.5f);
        glVertex2f(-1.0f, 0.5f);
    glEnd();
             
	// Inside vent
	glColor3f(0.0f, 0.0f, 0.0f); 
	glBegin(GL_QUADS);
        glVertex2f(-0.8f, 0.4f);
        glVertex2f(0.8f, 0.4f);
        glVertex2f(0.8f, -0.4f);
        glVertex2f(-0.8f, -0.4f);
    glEnd();

	// Middle bar
	/*
	glVertex2f(-0.2f, 0.1f);
    	glVertex2f(0.2f, 0.1f);
    	glVertex2f(0.2f, -0.1f);
    	glVertex2f(-0.2f, -0.1f);
	*/
  

    // Swap buffers
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    
    glutCreateWindow("Rectangular Beige Wall with Vent");
    
    // Set window size and position
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    
    // Register the display function
    glutDisplayFunc(display);
    
    // Enter the GLUT event processing loop
    glutMainLoop();
    
    return 0;
}

