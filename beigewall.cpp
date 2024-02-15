// Alonso Vazquez Tena & Jacob Aguilar
// Benchmark - Project 4: Render Your Scene With Primitives
// CST-310: Computer Graphics Lecture & Lab
// February 11, 2024
// This is our own work.

#include <GL/glut.h>
#include <cmath>

void drawCylinder(float radiusX, float radiusY, float height, int slices, float xOffset, float yOffset) 
{
    glBegin(GL_TRIANGLE_FAN);

      // Center of the ellipse at the bottom
      glVertex3f(xOffset, yOffset, 0.0);

      // Draw the ellipse at the bottom
      for (int i = 0; i <= slices; ++i) 
      {
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
      for (int i = 0; i <= slices; ++i) 
      {
        float theta = static_cast<float>(i) / slices * 2.0f * M_PI;
        float x = xOffset + radiusX * cos(theta);
        float y = yOffset + radiusY * sin(theta);
        glVertex3f(x, y, height);
      }

    glEnd();

    // Draw the ellipse outline
    glColor3f(0.0f, 0.0f, 0.0f);  // RGB values for black
    
    glBegin(GL_LINE_LOOP);

      for (int i = 0; i <= slices; ++i) 
      {
        float theta = static_cast<float>(i) / slices * 2.0f * M_PI;
        float x = xOffset + radiusX * cos(theta);
        float y = yOffset + radiusY * sin(theta);
        glVertex3f(x, y, 0.0);
      }

    glEnd();

    glBegin(GL_LINE_LOOP);

      for (int i = 0; i <= slices; ++i) 
      {
        float theta = static_cast<float>(i) / slices * 2.0f * M_PI;
        float x = xOffset + radiusX * cos(theta);
        float y = yOffset + radiusY * sin(theta);
        glVertex3f(x, y, height);
      }

    glEnd();

    // Draw lines connecting corresponding points on the top and bottom ellipses
    glBegin(GL_LINES);

      for (int i = 0; i <= slices; ++i) 
      {
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


void display() 
{
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
    
    // Indent at top left
    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_TRIANGLES);
      glVertex2f(-2.0f, 1.0f); // top left
      glVertex2f(-2.0f, 0.7f); // bottom left
      glVertex2f(-1.8f, 1.0f); // right
    glEnd();
    
    // outline
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES);
      glVertex2f(-2.0f, 1.0f); // top left
      glVertex2f(-2.0f, 0.7f); // bottom left
      
      glVertex2f(-2.0f, 0.7f); // bottom left
      glVertex2f(-1.8f, 1.0f); // right

      glVertex2f(-1.8f, 1.0f); // right
      glVertex2f(-2.0f, 1.0f); // top left
      
    glEnd();
    
    // Indent at top middle 
    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_TRIANGLES);
      glVertex2f(0.2f,1.0f); // top right
      glVertex2f(0.2f,0.7f); // bottom right
      glVertex2f(0.0f,1.0f); // left 
    glEnd();
    
    // outline
    
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES); 
    
      glVertex2f(0.2f,1.0f); // top right
      glVertex2f(0.2f,0.7f); // bottom right 
      
      glVertex2f(0.2f,0.7f); // bottom right
      glVertex2f(0.0f,1.0f); // left 

      glVertex2f(0.0f,1.0f); // left 
      glVertex2f(0.2f,1.0f); // top right
      
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
      glVertex2f(1.525f, -0.55f); // top right
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
   
    // This is the dark gray carpet.
    glColor3f(0.35f, 0.35f, 0.35f);
    glBegin(GL_QUADS);
      glVertex2f(-2.0f, -5.0f); // bottom left
      glVertex2f(2.0f, -5.0f); // bottom right
      glVertex2f(2.0f, -4.0f); // top right
      glVertex2f(-2.0f, -4.0f); // top left
    glEnd();
    
    // This is the outline of the dark gray carpet.
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES);
      glVertex2f(-2.0f, -5.0f); // bottom left
      glVertex2f(2.0f, -5.0f); // bottom right  
      glVertex2f(2.0f, -5.0f); // bottom right
      glVertex2f(2.0f, -4.0f); // top right  
      glVertex2f(2.0f, -4.0f); // top right
      glVertex2f(-2.0f, -4.0f); // top left  
      glVertex2f(-2.0f, -4.0f); // top left
      glVertex2f(-2.0f, -5.0f); // bottom left
    glEnd();
    
   
    // This is the vault door wall.
    glColor3f(0.65f, 0.65f, 0.65f);
    glBegin(GL_QUADS);
      glVertex2f(-1.75f, -4.0f); // bottom left
      glVertex2f(0.0f, -4.0f); // bottom right
      glVertex2f(0.0f, -1.0f); // top right
      glVertex2f(-1.75f, -1.0f); // top left
    glEnd();
    
    // This is the outline of the vault door wall.
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES);
      glVertex2f(-1.75f, -4.0f); // bottom left
      glVertex2f(0.0f, -4.0f); // bottom right  
      glVertex2f(0.0f, -4.0f); // bottom right
      glVertex2f(0.0f, -1.0f); // top right  
      glVertex2f(0.0f, -1.0f); // top right
      glVertex2f(-1.75f, -1.0f); // top left  
      glVertex2f(-1.75f, -1.0f); // top left
      glVertex2f(-1.75f, -4.0f); // bottom left
    glEnd();
   
    // This is the vault doorway.
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
      glVertex2f(-1.35f, -4.0f); // bottom left
      glVertex2f(-0.4f, -4.0f); // bottom right
      glVertex2f(-0.4f, -1.5f); // top right
      glVertex2f(-1.35f, -1.5f); // top left
    glEnd();
    
    // This is the outline of the vault doorway.
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES);
      glVertex2f(-1.35f, -4.0f); // bottom left
      glVertex2f(-0.4f, -4.0f); // bottom right  
      glVertex2f(-0.4f, -4.0f); // bottom right
      glVertex2f(-0.4f, -1.5f); // top right  
      glVertex2f(-0.4f, -1.5f); // top right
      glVertex2f(-1.35f, -1.5f); // top left  
      glVertex2f(-1.35f, -1.5f); // top left
      glVertex2f(-1.35f, -4.0f); // bottom left
    glEnd();
   
    // This is the vault hinges.
    glColor3f(0.65f, 0.65f, 0.65f);
    glBegin(GL_QUADS);
      glVertex2f(-0.5f, -4.0f); // bottom left
      glVertex2f(-0.4f, -4.0f); // bottom right
      glVertex2f(-0.4f, -1.5f); // top right
      glVertex2f(-0.5f, -1.5f); // top left
    glEnd();
    
    // This is the outline of the vault hinges.
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES);
      glVertex2f(-0.5f, -4.0f); // bottom left
      glVertex2f(-0.4f, -4.0f); // bottom right  
      glVertex2f(-0.4f, -4.0f); // bottom right
      glVertex2f(-0.4f, -1.5f); // top right  
      glVertex2f(-0.4f, -1.5f); // top right
      glVertex2f(-0.5f, -1.5f); // top left  
      glVertex2f(-0.5f, -1.5f); // top left
      glVertex2f(-0.5f, -4.0f); // bottom left
    glEnd();
   
    // This is the vault door.
    glColor3f(0.55f, 0.55f, 0.55f);
    glBegin(GL_QUADS);
      glVertex2f(-1.15f, -4.10f); // bottom left
      glVertex2f(-0.5f, -4.0f); // bottom right
      glVertex2f(-0.5f, -1.5f); // top right
      glVertex2f(-1.15f, -1.4f); // top left
    glEnd();
    
    // This is the outline of the vault door.
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES);
      glVertex2f(-1.15f, -4.10f); // bottom left
      glVertex2f(-0.5f, -4.0f); // bottom right  
      glVertex2f(-0.5f, -4.0f); // bottom right
      glVertex2f(-0.5f, -1.5f); // top right  
      glVertex2f(-0.5f, -1.5f); // top right
      glVertex2f(-1.15f, -1.4f); // top left  
      glVertex2f(-1.15f, -1.4f); // top left
      glVertex2f(-1.15f, -4.10f); // bottom left
    glEnd();
    
    // This is the vault door edge.
    glColor3f(0.35f, 0.35f, 0.35f);
    glBegin(GL_QUADS);
      glVertex2f(-1.25f, -4.00f); // bottom left 
      glVertex2f(-1.15f, -4.10f); // bottom right
      glVertex2f(-1.15f, -1.4f); // top right
      glVertex2f(-1.25f, -1.5f); // top left
    glEnd();
    
    // This is the outline of the vault door edge.
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES);
      glVertex2f(-1.25f, -4.00f); // bottom left
      glVertex2f(-1.15f, -4.10f); // bottom right  
      glVertex2f(-1.15f, -4.10f); // bottom right
      glVertex2f(-1.15f, -1.4f); // top right  
      glVertex2f(-1.15f, -1.4f); // top right
      glVertex2f(-1.25f, -1.5f); // top left  
      glVertex2f(-1.25f, -1.5f); // top left
      glVertex2f(-1.25f, -4.00f); // bottom left
    glEnd();
    
    // This is the long vault hinge.
    glColor3f(0.60f, 0.60f, 0.60f);
    glBegin(GL_QUADS);
      glVertex2f(-0.5f, -4.0f); // bottom left 
      glVertex2f(-0.4f, -4.0f); // bottom right
      glVertex2f(-0.4f, -1.5f); // top right
      glVertex2f(-0.5f, -1.5f); // top left
    glEnd();
    
    // This is the outline of the long vault hinge.
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES);
      glVertex2f(-0.5f, -4.0f); // bottom left
      glVertex2f(-0.4f, -4.0f); // bottom right  
      glVertex2f(-0.4f, -4.0f); // bottom right
      glVertex2f(-0.4f, -1.5f); // top right  
      glVertex2f(-0.4f, -1.5f); // top right
      glVertex2f(-0.5f, -1.5f); // top left  
      glVertex2f(-0.5f, -1.5f); // top left
      glVertex2f(-0.5f, -4.0f); // bottom left
    glEnd();
    
    // This is an extension to the outline of the long vault hinge.
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES);
      glVertex2f(-0.5f, -2.00f); // bottom left
      glVertex2f(-0.4f, -2.00f); // bottom right  
      glVertex2f(-0.4f, -2.00f); // bottom right
      glVertex2f(-0.4f, -1.80f); // top right  
      glVertex2f(-0.4f, -1.80f); // top right
      glVertex2f(-0.5f, -1.80f); // top left  
      glVertex2f(-0.5f, -1.80f); // top left
      glVertex2f(-0.5f, -2.00f); // bottom left
    glEnd();
    
     // This is the vault hinge 1.
    glColor3f(0.60f, 0.60f, 0.60f);
    glBegin(GL_QUADS);
      glVertex2f(-0.75f, -1.80f); // bottom left 
      glVertex2f(-0.4f, -1.80f); // bottom right
      glVertex2f(-0.4f, -1.55f); // top right
      glVertex2f(-0.75f, -1.55f); // top left
    glEnd();
    
    // This is the outline of the vault hinge 1.
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES);
      glVertex2f(-0.75f, -1.80f); // bottom left
      glVertex2f(-0.4f, -1.80f); // bottom right  
      glVertex2f(-0.4f, -1.80f); // bottom right
      glVertex2f(-0.4f, -1.55f); // top right  
      glVertex2f(-0.4f, -1.55f); // top right
      glVertex2f(-0.75f, -1.55f); // top left  
      glVertex2f(-0.75f, -1.55f); // top left
      glVertex2f(-0.75f, -1.80f); // bottom left
    glEnd();
    
    // This is the vault hinge 2.
    glColor3f(0.60f, 0.60f, 0.60f);
    glBegin(GL_QUADS);
      glVertex2f(-0.75f, -3.75f); // bottom left 
      glVertex2f(-0.4f, -3.75f); // bottom right
      glVertex2f(-0.4f, -3.5f); // top right
      glVertex2f(-0.75f, -3.5f); // top left
    glEnd();
    
    // This is the outline of the vault hinge 2.
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES);
      glVertex2f(-0.75f, -3.75f); // bottom left
      glVertex2f(-0.4f, -3.75f); // bottom right  
      glVertex2f(-0.4f, -3.75f); // bottom right
      glVertex2f(-0.4f, -3.5f); // top right  
      glVertex2f(-0.4f, -3.5f); // top right
      glVertex2f(-0.75f, -3.5f); // top left  
      glVertex2f(-0.75f, -3.5f); // top left
      glVertex2f(-0.75f, -3.75f); // bottom left
    glEnd();
    
    // This is the vault bar #1.
    glColor3f(0.50f, 0.50f, 0.50f);
    glBegin(GL_QUADS);
      glVertex2f(-0.85f, -3.00f); // bottom left 
      glVertex2f(-0.685f, -2.655f); // bottom right
      glVertex2f(-0.72f, -2.65f); // top right
      glVertex2f(-0.875f, -2.95f); // top left
    glEnd();
    
    // This is the outline of the vault bar #1.
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES);
      glVertex2f(-0.85f, -3.00f); // bottom left
      glVertex2f(-0.685f, -2.655f); // bottom right  
      glVertex2f(-0.685f, -2.655f); // bottom right
      glVertex2f(-0.72f, -2.65f); // top right  
      glVertex2f(-0.72f, -2.65f); // top right
      glVertex2f(-0.875f, -2.95f); // top left  
      glVertex2f(-0.875f, -2.95f); // top left
      glVertex2f(-0.85f, -3.00f); // bottom left
    glEnd();
    
    // This is the vault bar #2.
    glColor3f(0.50f, 0.50f, 0.50f);
    glBegin(GL_QUADS);
      glVertex2f(-0.85f, -3.00f); // bottom left 
      glVertex2f(-0.765f, -3.3f); // bottom right
      glVertex2f(-0.74f, -3.26f); // top right
      glVertex2f(-0.815f, -2.98f); // top left
    glEnd();
    
    // This is the outline of the vault bar #2.
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES);
      glVertex2f(-0.85f, -3.00f); // bottom left
      glVertex2f(-0.765f, -3.3f); // bottom right  
      glVertex2f(-0.765f, -3.3f); // bottom right
      glVertex2f(-0.74f, -3.26f); // top right  
      glVertex2f(-0.74f, -3.26f); // top right
      glVertex2f(-0.815f, -2.98f); // top left  
      glVertex2f(-0.815f, -2.98f); // top left
      glVertex2f(-0.85f, -3.00f); // bottom left
    glEnd();
    
    // This is the vault bar #3.
    glColor3f(0.50f, 0.50f, 0.50f);
    glBegin(GL_QUADS);
      glVertex2f(-1.05f, -2.98f); // bottom left 
      glVertex2f(-0.85f, -3.00f); // bottom right
      glVertex2f(-0.85f, -2.95f); // top right
      glVertex2f(-1.05f, -2.93f); // top left
    glEnd();
    
    // This is the outline of the vault bar #3.
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES);
      glVertex2f(-1.05f, -2.98f); // bottom left
      glVertex2f(-0.85f, -3.00f); // bottom right  
      glVertex2f(-0.85f, -3.00f); // bottom right
      glVertex2f(-0.85f, -2.95f); // top right  
      glVertex2f(-0.85f, -2.95f); // top right
      glVertex2f(-1.05f, -2.93f); // top left  
      glVertex2f(-1.05f, -2.93f); // top left
      glVertex2f(-1.05f, -2.98f); // bottom left
    glEnd();
    
    // This is the base for the vault lock.
    glColor3f(0.5f, 0.5f, 0.5f);
    drawCylinder(0.05f, 0.075f, 0.0f, 1000, -0.85f, -2.95f);
    glEnd();
    
    // This is the top small lock.
    glColor3f(0.50f, 0.50f, 0.50f);
    drawCylinder(0.025f, 0.04f, 0.0f, 1000, -0.85f, -2.55f);
    glEnd();
    
    // This is the bottom small lock.
    glColor3f(0.50f, 0.50f, 0.50f);
    drawCylinder(0.025f, 0.04f, 0.0f, 1000, -0.85f, -2.75f);
    glEnd();

//////////////////////////////////

    // Desk
    glColor3f(1.0f, 1.0f, 1.0f); // RGB for white
    glBegin(GL_QUADS);
      glVertex2f(1.0f, -5.0f); // bottom left
      glVertex2f(2.0f, -5.0f); // bottom right
      glVertex2f(2.0f, -3.5f); // top right
      glVertex2f(1.0f, -3.5f); // top left 
    glEnd();
   
    // Desk top
    glColor3f(0.9f, 0.9f, 0.9f); // RGB for white
    glBegin(GL_QUADS);
      glVertex2f(1.0f, -3.7f); // bottom left
      glVertex2f(2.0f, -3.7f); // bottom right
      glVertex2f(2.0f, -3.5f); // top right
      glVertex2f(1.0f, -3.5f); // top left 
    glEnd();
   
    // outline
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES);
      glVertex2f(1.0f,-3.7f); // bottom left
      glVertex2f(2.0f, -3.7f); // bottom right  
      glVertex2f(2.0f, -3.7f); // bottom right
      glVertex2f(2.0f, -3.5f); // top right  
      glVertex2f(2.0f, -3.5f); // top right
      glVertex2f(1.0f, -3.5f); // top left  
      glVertex2f(1.0f, -3.5f); // top left
      glVertex2f(1.0f,-3.7f); // bottom left 
    glEnd();
   
    // Box
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
      glVertex2f(1.0f, -3.5f); // bottom left
      glVertex2f(1.9f, -3.5f); // bottom right
      glVertex2f(1.9f, -2.9f); // top right
      glVertex2f(1.0f, -2.9f); // top left 
    glEnd();
    
    // outline
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
      glVertex2f(1.0f, -3.5f); // bottom left
      glVertex2f(1.9f, -3.5f); // bottom right
        
      glVertex2f(1.9f, -3.5f); // bottom right
      glVertex2f(1.9f, -2.9f); // top right
        
      glVertex2f(1.9f, -2.9f); // top right
      glVertex2f(1.0f, -2.9f); // top left 
       
      glVertex2f(1.0f, -2.9f); // top left
      glVertex2f(1.0f, -3.5f); // bottom left  
      
    glEnd();
    
    // Box tape 
    glColor3f(0.9f, 0.85f, 0.8f);
    glBegin(GL_QUADS);
      glVertex2f(1.0f,-3.1f); // bottom left
      glVertex2f(1.7f,-3.1f); // bottom right
      glVertex2f(1.7f,-3.0f); // top right
      glVertex2f(1.0f,-3.0f); // top left 
    glEnd();
    
    // outline
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES);
    
      glVertex2f(1.0f,-3.1f); // bottom left
      glVertex2f(1.7f,-3.1f); // bottom right
    
      glVertex2f(1.7f,-3.1f); // bottom right
      glVertex2f(1.7f,-3.0f); // top right
      
      glVertex2f(1.7f,-3.0f); // top right
      glVertex2f(1.0f,-3.0f); // top left 
    
      glVertex2f(1.0f,-3.0f); // top left 
      glVertex2f(1.0f,-3.1f); // bottom left
      
    glEnd(); 
    
    // Box tape 2
    glColor3f(0.9f, 0.85f, 0.8f);
    glBegin(GL_QUADS);
      glVertex2f(1.5f,-3.45f); // bottom left
      glVertex2f(1.7f,-3.45f); // bottom right
      glVertex2f(1.7f,-3.35f); // top right
      glVertex2f(1.5f,-3.35f); // top left
    glEnd();
    
    // outline
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES);
      
      glVertex2f(1.5f,-3.45f); // bottom left
      glVertex2f(1.7f,-3.45f); // bottom right
      
      glVertex2f(1.7f,-3.45f); // bottom right
      glVertex2f(1.7f,-3.35f); // top right
      
      glVertex2f(1.7f,-3.35f); // top right
      glVertex2f(1.5f,-3.35f); // top left

      glVertex2f(1.5f,-3.35f); // top left
      glVertex2f(1.5f,-3.45f); // bottom left
      
    glEnd();
    
    // Box tape middle 1
    glColor3f(0.9f, 0.85f, 0.8f);
    glBegin(GL_QUADS);
      glVertex2f(1.3f,-3.2f); // bottom left
      glVertex2f(1.5f,-3.2f); // bottom right 
      glVertex2f(1.5f,-3.15f); // top right
      glVertex2f(1.3f,-3.15f); // top left
    glEnd();
    
    // outline 
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES);
      
      glVertex2f(1.3f,-3.2f); // bottom left
      glVertex2f(1.5f,-3.2f); // bottom right 
      
      glVertex2f(1.5f,-3.2f); // bottom right 
      glVertex2f(1.5f,-3.15f); // top right
      
      glVertex2f(1.5f,-3.15f); // top right
      glVertex2f(1.3f,-3.15f); // top left

      glVertex2f(1.3f,-3.15f); // top left
      glVertex2f(1.3f,-3.2f); // bottom left
      
    glEnd();
    
    // Box tape middle 2
    glColor3f(0.9f, 0.85f, 0.8f);
    glBegin(GL_QUADS);
      glVertex2f(1.3f,-3.29f); // bottom left
      glVertex2f(1.5f,-3.29f); // bottom right
      glVertex2f(1.5f,-3.24f); // top right
      glVertex2f(1.3f,-3.24f); // top left
    glEnd();
    
    // outline
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES);
    
      glVertex2f(1.3f,-3.29f); // bottom left
      glVertex2f(1.5f,-3.29f); // bottom right
      
      glVertex2f(1.5f,-3.29f); // bottom right
      glVertex2f(1.5f,-3.24f); // top right
      
      glVertex2f(1.5f,-3.24f); // top right
      glVertex2f(1.3f,-3.24f); // top left

      glVertex2f(1.3f,-3.24f); // top left
      glVertex2f(1.3f,-3.29f); // bottom left
      
    glEnd();
      
   
    // Desk bar door pt 1
    glColor3f(1.0f, 1.0f, 1.0f); // white
    glBegin(GL_QUADS);
      glVertex2f(0.9f, -5.0f); // bottom left
      glVertex2f(1.0f, -5.0f); // bottom right
      glVertex2f(1.0f, -2.8f); // top right
      glVertex2f(0.9f, -2.8f); // top left 
    glEnd();
    
    // outline
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
      glVertex2f(0.9f, -5.0f); // bottom left
      glVertex2f(1.0f, -5.0f); // bottom right  
      glVertex2f(1.0f, -5.0f); // bottom right
      glVertex2f(1.0f, -2.8f); // top right  
      glVertex2f(1.0f, -2.8f); // top right
      glVertex2f(0.9f, -2.8f); // top left  
      glVertex2f(0.9f, -2.8f); // top left
      glVertex2f(0.9f, -5.0f); // bottom left  
    glEnd();
    
    // Desk bar door pt 2
    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_QUADS);
      glVertex2f(0.4f,-4.0); // bottom left
      glVertex2f(0.9f, -5.0f); // bottom right
      glVertex2f(0.9f, -2.8f); // top right
      glVertex2f(0.4f, -2.5f); // top left
    glEnd();
    
    // Door outline
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES);
    
      glVertex2f(0.5f,-2.55f); // top 
      glVertex2f(0.5f,-4.2f); // bottom 
      
      glVertex2f(0.7f,-2.65f); // top
      glVertex2f(0.7f, -4.6f); // bottom
    
    glEnd();
    
       // Door hinge 1
    glColor3f(0.65f, 0.65f, 0.65f);
    glBegin(GL_QUADS);
      glVertex2f(0.46f, -2.85f); // bottom left
      glVertex2f(0.53f, -2.85f); // bottom right
      glVertex2f(0.53f, -2.65f); // top right
      glVertex2f(0.46f, -2.65f); // top left 
      
    glEnd();
    
    // Hinge outline
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES);
    
      glVertex2f(0.46f, -2.85f); // bottom left
      glVertex2f(0.53f, -2.85f); // bottom right
      
      glVertex2f(0.53f, -2.85f); // bottom right
      glVertex2f(0.53f, -2.65f); // top right
      
      glVertex2f(0.53f, -2.65f); // top right
      glVertex2f(0.46f, -2.65f); // top left 
      
      glVertex2f(0.46f, -2.65f); // top left 
      glVertex2f(0.46f, -2.85f); // bottom left
      
    glEnd();
    
    // Door hinge 2
    glColor3f(0.65f, 0.65f, 0.65f);
    glBegin(GL_QUADS);
      glVertex2f(0.46f, -3.85f); // bottom left
      glVertex2f(0.53f, -3.85f); // bottom right
      glVertex2f(0.53f, -3.65f); // top right
      glVertex2f(0.46f, -3.65f); // top left 
      
    glEnd();
    
    // Hine outline 2
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES);
    
      glVertex2f(0.46f, -3.85f); // bottom left
      glVertex2f(0.53f, -3.85f); // bottom right
      
      glVertex2f(0.53f, -3.85f); // bottom right
      glVertex2f(0.53f, -3.65f); // top right
      
      glVertex2f(0.53f, -3.65f); // top right
      glVertex2f(0.46f, -3.65f); // top left 

      glVertex2f(0.46f, -3.65f); // top left 
      glVertex2f(0.46f, -3.85f); // bottom left
      
    glEnd();
      
      
    
    // desk bar pt 2 outline
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES);
      glVertex2f(0.4f,-4.0); // bottom left
      glVertex2f(0.9f, -5.0f); // bottom right 
      glVertex2f(0.9f, -5.0f); // bottom right
      glVertex2f(0.9f, -2.8f); // top right  
      glVertex2f(0.9f, -2.8f); // top right
      glVertex2f(0.4f, -2.5f); // top left  
      glVertex2f(0.4f, -2.5f); // top left
      glVertex2f(0.4f,-4.0); // bottom left  
    glEnd();
    
    // Top of desk door
    glColor3f(0.7f, 0.7f ,0.7f);
    glBegin(GL_QUADS);
      glVertex2f(0.9f, -2.8f); // bottom left
      glVertex2f(1.0f, -2.8f); // bottom right
      glVertex2f(0.5f,-2.5f); // top right
      glVertex2f(0.4f, -2.5f); // top left  
    glEnd();
    
    // outline 
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES);
      glVertex2f(0.9f, -2.8f); // bottom left
      glVertex2f(1.0f, -2.8f); // bottom right  
      glVertex2f(1.0f, -2.8f); // bottom right
      glVertex2f(0.5f,-2.5f); // top right  
      glVertex2f(0.5f,-2.5f); // top right
      glVertex2f(0.4f, -2.5f); // top left  
      glVertex2f(0.4f, -2.5f); // top left
      glVertex2f(0.9f, -2.8f); // bottom left  
    glEnd();
    
//////////////////////////////////
    
    // Far right ceiling light
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
      glVertex2f(1.6f,-1.2f); // bottom left 
      glVertex2f(2.0f,-1.2f); // bottom right 
      glVertex2f(2.0f,-1.0f); // top right
      glVertex2f(1.6f,-1.0f); // top left  
    glEnd();
    
    // outline
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES);
      glVertex2f(1.6f,-1.2f); // bottom left 
      glVertex2f(2.0f,-1.2f); // bottom right 
      glVertex2f(2.0f,-1.2f); // bottom right
      glVertex2f(2.0f,-1.0f); // top right  
      glVertex2f(2.0f,-1.0f); // top right
      glVertex2f(1.6f,-1.0f); // top left  
      glVertex2f(1.6f,-1.0f); // top left
      glVertex2f(1.6f,-1.2f); // bottom left
    glEnd();
    
    // Side of light
    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_QUADS);
      glVertex2f(1.5f,-1.25f); // bottom left
      glVertex2f(1.6f,-1.2f); // bottom right
      glVertex2f(1.6f,-1.0f); // top right
      glVertex2f(1.5f, -1.0f); // top left  
    glEnd();
    
    // outline
    
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES);
      glVertex2f(1.5f,-1.25f); // bottom left
      glVertex2f(1.6f,-1.2f); // bottom right  
      glVertex2f(1.6f,-1.2f); // bottom right
      glVertex2f(1.6f,-1.0f); // top right  
      glVertex2f(1.6f,-1.0f); // top right
      glVertex2f(1.5f, -1.0f); // top left  
      glVertex2f(1.5f, -1.0f); // top left
      glVertex2f(1.5f,-1.25f); // bottom left
    glEnd();
    
    // Bottom of light
    glColor3f(0.7f, 0.7f, 0.7f);
    glBegin(GL_QUADS);
      glVertex2f(1.5f, -1.25f); // bottom left
      glVertex2f(2.0f,-1.25f); // bottom right
      glVertex2f(2.0f,-1.2f); // top right
      glVertex2f(1.6f,-1.2f); // top left  
    glEnd();
    
    // outline
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES);
      glVertex2f(1.5f, -1.25f); // bottom left
      glVertex2f(2.0f,-1.25f); // bottom right  
      glVertex2f(2.0f,-1.25f); // bottom right
      glVertex2f(2.0f,-1.2f); // top right  
      glVertex2f(2.0f,-1.2f); // top right
      glVertex2f(1.6f,-1.2f); // top left
      glVertex2f(1.6f,-1.2f); // top left
      glVertex2f(1.5f, -1.25f); // bottom left  
    glEnd();
    
//////////////////////////////////

    // Back wall on right
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_QUADS);
      glVertex2f(0.1f,-1.1f); // bottom left
      glVertex2f(1.5f,-1.1f); // bottom right 
      glVertex2f(1.5f,-1.0f); // top right
      glVertex2f(0.1f,-1.0f); // top left 
    glEnd();
      
    // outline
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES);
      glVertex2f(0.1f,-1.1f); // bottom left
      glVertex2f(1.5f,-1.1f); // bottom right 
      
      glVertex2f(1.5f,-1.1f); // bottom right 
      glVertex2f(1.5f,-1.0f); // top right
      
      glVertex2f(1.5f,-1.0f); // top right
      glVertex2f(0.1f,-1.0f); // top left 

      glVertex2f(0.1f,-1.0f); // top left 
      glVertex2f(0.1f,-1.1f); // bottom left
      
    glEnd();  
    
    // Lines
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES);
      glVertex2f(0.4f,-1.0f); // top
      glVertex2f(0.3f,-1.1f); //bottom  
      
      glVertex2f(0.7f, -1.0f); // top
      glVertex2f(0.6f, -1.1f); // bottom
      
      glVertex2f(1.0f, -1.0f); // top
      glVertex2f(0.9f, -1.1f); // bottom
      
      glVertex2f(1.3f, -1.0f); // top 
      glVertex2f(1.2f, -1.1f); // bottom
      
    glEnd();
     
//////////////////////////////////

    // Left ceiling light
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
      glVertex2f(-1.25f,-1.2f); // bottom left
      glVertex2f(0.1f,-1.2f); // bottom right
      glVertex2f(0.1f,-1.0f); // top right
      glVertex2f(-1.25f,-1.0f); // top left  
    glEnd();
    
    // outline
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES);
      glVertex2f(-1.25f,-1.2f); // bottom left
      glVertex2f(0.1f,-1.2f); // bottom right
        
      glVertex2f(0.1f,-1.2f); // bottom right
      glVertex2f(0.1f,-1.0f); // top right 
       
      glVertex2f(0.1f,-1.0f); // top right
      glVertex2f(-1.25f,-1.0f); // top left
      
      glVertex2f(-1.25f,-1.0f); // top left
      glVertex2f(-1.25f,-1.2f); // bottom left  
      
    glEnd();
    
    // Back wall on left
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_QUADS);  
      glVertex2f(-2.0f,-1.1f); // bottom left
      glVertex2f(-1.25f,-1.1f); // bottom right
      glVertex2f(-1.25f,-1.0f); // top right
      glVertex2f(-2.0f,-1.0f); // top left
    glEnd();
    
    // outline
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES);
      glVertex2f(-2.0f,-1.1f); // bottom left
      glVertex2f(-1.25f,-1.1f); // bottom right
      
      glVertex2f(-1.25f,-1.1f); // bottom right
      glVertex2f(-1.25f,-1.0f); // top right
      
      glVertex2f(-1.25f,-1.0f); // top right
      glVertex2f(-2.0f,-1.0f); // top left

      glVertex2f(-2.0f,-1.0f); // top left
      glVertex2f(-1.25f,-1.0f); // top right
      
    glEnd();   
    
//////////////////////////////////

    // Broken camera
    glColor3f(0.6f, 0.6f, 0.6f);
    glBegin(GL_QUADS);
      glVertex2f(0.2f, -4.0f); // bottom left
      glVertex2f(0.3f, -4.0f); // bottom right
      glVertex2f(0.3f, -3.9f); // top right
      glVertex2f(0.2f, -3.9f); // top left
    glEnd();
    
    // outline
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES);
      glVertex2f(0.2f, -4.0f); // bottom left
      glVertex2f(0.3f, -4.0f); // bottom right  
      glVertex2f(0.3f, -4.0f); // bottom right
      glVertex2f(0.3f, -3.9f); // top right
      glVertex2f(0.3f, -3.9f); // top right
      glVertex2f(0.2f, -3.9f); // top left
      glVertex2f(0.2f, -3.9f); // top left
      glVertex2f(0.2f, -4.0f); // bottom left  
    glEnd();    
    
    // Camera lens
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCylinder(0.03, 0.03, 0.8, 35, .25, -3.96);
    glEnd();
    
//////////////////////////////////

    // Outline for bottom part of second wall
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1);
    glBegin(GL_LINES);
    
      glVertex2f(-2.0f, -3.8f); // Left
      glVertex2f(-1.75f, -3.8f); // right
      
      glVertex2f(0.0f,-3.8f); // Left
      glVertex2f(0.4f,-3.8f); // Right    
    
    
    glEnd();
    
    // Swap buffers
    glutSwapBuffers();
}

int main(int argc, char** argv) 
{
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
