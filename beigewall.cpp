#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Set up projection matrix for 2D
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-3.0, 3.0, -2.0, 2.0);  // Adjust these values based on your needs
    
    // Set up model-view matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Draw wall
    glColor3f(0.9f, 0.9f, 0.9f);  // RGB values for slight white
    glBegin(GL_QUADS);
    
        glVertex2f(-2.0f, -1.0f);
        glVertex2f(2.0f, -1.0f);
        glVertex2f(2.0f, 1.0f);
        glVertex2f(-2.0f, 1.0f);
    glEnd();
    
    // Draw frame
    glColor3f(1.0f, 1.0f, 1.0f);  // RGB values for white
    glBegin(GL_QUADS);
    
     	glVertex2f(1.0f, -1.0f); // bottom left
        glVertex2f(2.0f, -1.0f); // bottom right
        glVertex2f(2.0f, -0.5f);  // top right
        glVertex2f(1.0f, -0.5f);  // top left
    glEnd();
             
	// Inside vent
	
	glColor3f(0.0f, 0.0f, 0.0f);  // RGB values for black
	glBegin(GL_QUADS);
	
        glVertex2f(1.1f, -0.95f); // bottom left 
        glVertex2f(1.9f, -0.95f); // bottom right
        glVertex2f(1.9f, -0.55f); // top right
        glVertex2f(1.1f, -0.55f); // top left
    glEnd();

	// Middle bar
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);  // RGB values for white
	
	glVertex2f(1.475f, -0.95f); // bottom left 
	glVertex2f(1.525f, -0.95f); // bottom right
    	glVertex2f(1.525f, -0.55f);   // top right
    	glVertex2f(1.475f, -0.55f); // top left 
    glEnd();
  
  
  	// Left side first verticle bar
  	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);  // RGB values for white
	
	glVertex2f(1.2f, -0.95f); // bottom left
    	glVertex2f(1.25f, -0.95f); // bottom right
    	glVertex2f(1.25f, -0.55f); // top right
    	glVertex2f(1.2f, -0.55f); // top left
    glEnd();
    
  	// Left side second verticle bar
  	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);  // RGB values for white
	glVertex2f(1.35f, -0.95f); // bottom left
    	glVertex2f(1.4f, -0.95f); // bottom right
    	glVertex2f(1.4f, -0.55f); // top right
    	glVertex2f(1.35f, -0.55f); // top left
    glEnd();
    
  	// Right side first verticle bar
  	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);  // RGB values for white
	
	glVertex2f(1.65f, -0.95f); // bottom left
    	glVertex2f(1.6f, -0.95f); // bottom right
    	glVertex2f(1.6f, -0.55f); // top right
    	glVertex2f(1.65f, -0.55f); // top left
    glEnd();
    
  	// Right side second verticle bar
  	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);  // RGB values for white
	
	glVertex2f(1.8f, -0.95f); // bottom left
    	glVertex2f(1.75f, -0.95f); // bottom right
    	glVertex2f(1.75f, -0.55f); // top right
    	glVertex2f(1.8f, -0.55f); // top left
    glEnd();
  	
  	// Top horizontal bar
  	glBegin(GL_QUADS);
  	glColor3f(1.0f, 1.0f, 1.0f);  // RGB values for white
  	
        glVertex2f(1.9f, -0.7f); // bottom right
        glVertex2f(1.1f, -0.7f); // bottom left
        glVertex2f(1.1f, -0.65f); // top left 
        glVertex2f(1.9f, -0.65f); // top right
    glEnd();
    
  	// Bottom horizontal bar
	glBegin(GL_QUADS);
  	glColor3f(1.0f, 1.0f, 1.0f);  // RGB values for white
  	
  	glVertex2f(1.9f, -0.85f); // bottom right
        glVertex2f(1.1f, -0.85f); // bottom left
        glVertex2f(1.1f, -0.8f); // top left 
        glVertex2f(1.9f, -0.8f); // top right
    glEnd();
    // Swap buffers
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    
    glutCreateWindow("Project");
    
    // Set window size and position
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    
    // Register the display function
    glutDisplayFunc(display);
    
    // Enter the GLUT event processing loop
    glutMainLoop();
    
    return 0;
}

