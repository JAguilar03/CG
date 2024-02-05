// Computer Graphics Project
// Code by Jacob Aguilar and Alonso Vazquez Tena

#include <GL/glut.h>
#include <cmath>


void drawCylinder(float radiusX, float radiusY, float height, int slices, float xOffset, float yOffset) {
    glBegin(GL_TRIANGLE_FAN);

    // Center of the ellipse at the bottom
    glVertex3f(xOffset, yOffset, 0.0);

    // Draw the ellipse at the bottom
    for (int i = 0; i <= slices; ++i) {
        float theta = static_cast<float>(i) / slices * 2.0f * M_PI;
        float x = xOffset + radiusX * cos(theta);
        float y = yOffset + radiusY * sin(theta);

        glVertex3f(x, y, 0.0);
    }

    glEnd();

    glBegin(GL_TRIANGLE_FAN);

    // Center of the ellipse at the top
    glVertex3f(xOffset, yOffset, height);

    // Draw the ellipse at the top
    for (int i = 0; i <= slices; ++i) {
        float theta = static_cast<float>(i) / slices * 2.0f * M_PI;
        float x = xOffset + radiusX * cos(theta);
        float y = yOffset + radiusY * sin(theta);

        glVertex3f(x, y, height);
    }

    glEnd();

    // Draw the ellipse outline
    glColor3f(0.0f, 0.0f, 0.0f);  // RGB values for black
    glBegin(GL_LINE_LOOP);

    for (int i = 0; i <= slices; ++i) {
        float theta = static_cast<float>(i) / slices * 2.0f * M_PI;
        float x = xOffset + radiusX * cos(theta);
        float y = yOffset + radiusY * sin(theta);

        glVertex3f(x, y, 0.0);
    }

    glEnd();

    glBegin(GL_LINE_LOOP);

    for (int i = 0; i <= slices; ++i) {
        float theta = static_cast<float>(i) / slices * 2.0f * M_PI;
        float x = xOffset + radiusX * cos(theta);
        float y = yOffset + radiusY * sin(theta);

        glVertex3f(x, y, height);
    }

    glEnd();

    // Draw lines connecting corresponding points on the top and bottom ellipses
    glBegin(GL_LINES);

    for (int i = 0; i <= slices; ++i) {
        float theta = static_cast<float>(i) / slices * 2.0f * M_PI;
        float xBottom = xOffset + radiusX * cos(theta);
        float yBottom = yOffset + radiusY * sin(theta);
        float xTop = xOffset + radiusX * cos(theta);
        float yTop = yOffset + radiusY * sin(theta);

        glVertex3f(xBottom, yBottom, 0.0);
        glVertex3f(xTop, yTop, height);
    }

    glEnd();
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Set up projection matrix for 2D
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    gluOrtho2D(-6.0, 6.0, -5.0, 5.0);
    
    //gluOrtho2D(-2.0, 2.0, -5.0, 1.0);
    //gluOrtho2D(-5.0, 5.0, -4.0, 4.0);
    
    //gluOrtho2D(-2.0, 2.0, -7.0, 1.0);
    
    //gluOrtho2D(-3.0, 3.0, -2.0, 2.0); original 
    // -7 7 -6 6
    
    // Set up model-view matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Draw wall
    glColor3f(0.9f, 0.9f, 0.9f);  // RGB values for slight white
    glBegin(GL_QUADS);
    
        glVertex2f(-2.0f, -1.0f); // bottom left
        glVertex2f(2.0f, -1.0f); // bottom right
        glVertex2f(2.0f, 1.0f); // top right
        glVertex2f(-2.0f, 1.0f); // top left
        
    glEnd();
    
    // outline for bottom of wall
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    
        glVertex2f(-2.0f, -1.0f); // bottom left
        glVertex2f(2.0f, -1.0f); // bottom right
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
  	
  	glVertex2f(1.1f, -0.7f); // bottom left
        glVertex2f(1.9f, -0.7f); // bottom right
        glVertex2f(1.9f, -0.65f); // top right
        glVertex2f(1.1f, -0.65f); // top left 
        
    glEnd();
    
    // Bottom horizontal bar
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);  // RGB values for white
  	
  	glVertex2f(1.1f, -0.85f); // bottom left
  	glVertex2f(1.9f, -0.85f); // bottom right
  	glVertex2f(1.9f, -0.8f); // top right
        glVertex2f(1.1f, -0.8f); // top left 
        
    glEnd();
    
    // outline of frame
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
   
        glVertex2f(1.0f, -1.0f); // bottom left
        glVertex2f(2.0f, -1.0f); // bottom right 
   
        glVertex2f(2.0f, -1.0f); // bottom right
        glVertex2f(2.0f, -0.5f);  // top right
   
        glVertex2f(2.0f, -0.5f);  // top right
        glVertex2f(1.0f, -0.5f);  // top left
   
        glVertex2f(1.0f, -0.5f);  // top left
        glVertex2f(1.0f, -1.0f); // bottom left
        
   glEnd();
    
//////////////////////////////////
    
   // High Beam on Roof
   glColor3f(0.545f, 0.271f, 0.075f);  // Slightly darker brown
   glBegin(GL_QUADS);
     
        glVertex2f(0.2f, 0.5f); // bottom left
        glVertex2f(0.4f, 0.5f); // bottom right
        glVertex2f(0.7f, 1.0f); // top right
        glVertex2f(0.5f, 1.0f); // top left
        
    glEnd();
    
    // outline
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(2);
    glBegin(GL_LINES);
    
       glVertex2f(0.4f, 0.5f); // bottom right
       glVertex2f(0.2f, 0.5f); // bottom left
     
       glVertex2f(0.2f, 0.5f); // bottom left
       glVertex2f(0.5f, 1.0f); // top left
     
       glVertex2f(0.5f, 1.0f); // top left
       glVertex2f(0.7f, 1.0f); // top right
     
       glVertex2f(0.7f, 1.0f); // top right
       glVertex2f(0.4f, 0.5f); // bottom right
     
    glEnd();
    
    // Triangle part of beam
    glBegin(GL_TRIANGLES);
    glColor3f(0.545f, 0.271f, 0.075f);  // Slightly darker brown

       glVertex2f(0.2f, 0.5f); // bottom left 
       glVertex2f(0.2f, 1.0f); // top left
       glVertex2f(0.5f, 1.0f); // top right
       
    glEnd();
    
    // outline 
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES);
    
       glVertex2f(0.2f, 0.5f); // bottom left 
       glVertex2f(0.2f, 1.0f); // top left
    
       glVertex2f(0.2f, 1.0f); // top left
       glVertex2f(0.5f, 1.0f); // top right
       
       
    glEnd();
    
//////////////////////////////////
    
    // Cylinder light base
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    
       glVertex2f(-0.6f, 0.6f);// bottom right
       glVertex2f(-1.0f, 0.6f); // bottom left
       glVertex2f(-1.0f, 1.0f); // top left
       glVertex2f(-0.6f, 1.0f); // top right
       
    glEnd();
    
    // outline 
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES);
   
      glVertex2f(-0.6f, 0.6f);// bottom right
      glVertex2f(-1.0f, 0.6f); // bottom left
   
      glVertex2f(-1.0f, 0.6f); // bottom left
      glVertex2f(-1.0f, 1.0f); // top left
     
      glVertex2f(-1.0f, 1.0f); // top left
      glVertex2f(-0.6f, 1.0f); // top right

      glVertex2f(-0.6f, 1.0f); // top right
      glVertex2f(-0.6f, 0.6f);// bottom right
   
    glEnd();
    
    // Ellipse of the cylinder light
    glColor3f(0.8f, 0.8f, 0.8f);
    
    // Draw the cylinder at the new position (2 units to the right and 1 unit up)
    drawCylinder(0.2, 0.1, 0.8, 30, -0.8, 0.6); 



//////////////////////////////////
//////////////////////////////////

    // Second half of image
    
    glColor3f(0.8f, 0.8f, 0.8f);  // RGB values for slight white
    glBegin(GL_QUADS);
    
    	glVertex2f(-2.0f, -5.0f); // bottom left 
        glVertex2f(2.0f, -5.0f); // bottom right
        glVertex2f(2.0f, -1.0f); // top right
        glVertex2f(-2.0f, -1.0f); // top left
        
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

