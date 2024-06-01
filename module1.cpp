//============================================================================
// Name        : Snake
// Author      : Muhammad Noor
// Version     :
// Copyright   : (c) Reserved
// Description : Basic game of Snake
//============================================================================
#ifndef TETRIS_CPP_
#define TETRIS_CPP_
#include "util.h"
#include <iostream>
#include <vector>
#include <algorithm>
// #include<cstdlib>
#include <ctime>
#include <string>
// #include<sys/wait.h>
// #include<stdlib.h>
// #include<stdio.h>
#include <unistd.h>
#include <sstream>
#include <cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/*
 * Main Canvas drawing function.
 * */
double startx = 320, starty = 400;
double sq_startx = 330, sq_starty = 400;
double sq2_startx = 340, sq2_starty = 400;
double sq3_startx = 350, sq3_starty = 400;
double sq4_startx = 360, sq4_starty = 400;
double sq5_startx = 370, sq5_starty = 400;
double sq6_startx = 390, sq6_starty = 400;
double sq7_startx = 400, sq7_starty = 400;
double sq8_startx = 410, sq8_starty = 400;
double sq9_startx = 420, sq9_starty = 400;

void Display()
{
    // set the background color using function glClearColotgr.
    // to change the background play with the red, green and blue values below.
    // Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

    glClearColor(0 /*Red Component*/, 0.0 /*Green Component*/,
                 0.0 /*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
    glClear(GL_COLOR_BUFFER_BIT);                                // Update the colors

    DrawSquare(320, 400, 10, colors[10]); // This will draw a square shape of size 100x100  at x=320 and y=400

    DrawSquare(330, 400, 10, colors[10]); // This will draw a square shape of size 100x100 at x=330and y = 400

    DrawSquare(340, 400, 10, colors[10]); // This will draw a square shape of size 100x100  at x=340 and y=400

    DrawSquare(350, 400, 10, colors[10]); // This will draw a square shape of size 100x100  at x=350 and y=400

    DrawSquare(360, 10, 10, colors[10]); // This will draw a square shape of size 100x100  at x=360 and y=400

    DrawSquare(370, 400, 10, colors[10]); // This will draw a square shape of size 100x100  at x=370 and y=400

    DrawSquare(380, 400, 10, colors[10]); // This will draw a square shape of size 100x100  at x=380 and y=400

    DrawSquare(390, 400, 10, colors[10]); // This will draw a square shape of size 100x100  at x=390 and y=400
    DrawSquare(400, 400, 10, colors[10]); // This will draw a square shape of size 100x100  at x=400 and y=400

    DrawSquare(410, 400, 10, colors[10]); // This will draw a square shape of size 100x100  at x=410 and y=400
    DrawSquare(350, 400, 10, colors[10]); // This will draw a square shape of size 100x100  at x=420 and y=400

    //  DrawString( 50, 600, "Here are some are basic shapes", colors[MISTY_ROSE]); // this will print given string at x=50 , y=600
    //  DrawString( 50, 570, "You will use these to make your game", colors[MISTY_ROSE]); // this will print given string at x=50 , y=570
    DrawString(50, 570, "Score:", colors[MISTY_ROSE]); // this will print given string at x=50 , y=570
    DrawCircle(230, 300, 9, colors[5]);                // This will draw a circle at x=200,y=200 of radius 50

    //                    v1( x,y )   v2( x,y )  , v3( x,y )
    DrawTriangle(300, 50, 500, 50, 400, 250, colors[MISTY_ROSE]); // Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)

    // DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
    DrawLine(550, 50, 550, 600, 20, colors[MISTY_ROSE]);

    glutSwapBuffers(); // do not modify this line..
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y)
{
    if (key == GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/)
    {
        // what to do when left key is pressed...
    }
    else if (key == GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/)
    {
    }
    else if (key == GLUT_KEY_UP) /*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/
    {
    }
    else if (key == GLUT_KEY_DOWN) /*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/
    {
    }

    /* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
     * this function*/
    glutPostRedisplay();
}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y)
{
    if (key == KEY_ESC /* Escape key ASCII*/)
    {
        exit(1); // exit the program when escape key is pressed.
    }
    if (key == 'R' || key == 'r' /* Escape key ASCII*/)
    {
        // exit(1); // exit the program when escape key is pressed.
        // aswangle+=90;
    }

    else if (int(key) == 13)
    {
    }

    glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */

void Timer(int m)
{

    // implement your functionality here
    glutPostRedisplay();
    // once again we tell the library to call our Timer function after next 1000/FPS
    glutTimerFunc(1000.0 / FPS, Timer, 0);
}

/*
 * our gateway main function
 * */
int main(int argc, char *argv[])
{
    int width = 800, height = 600; // i have set my window size to be 800 x 600
    InitRandomizer();              // seed the random number generator...
    glutInit(&argc, argv);         // initialize the graphics library...

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
    glutInitWindowPosition(50, 50);               // set the initial position of our window
    glutInitWindowSize(width, height);            // set the size of our window
    glutCreateWindow("PF's Snake Game");          // set the title of our game window
    SetCanvasSize(width, height);                 // set the number of pixels...

    // Register your functions to the library,
    // you are telling the library names of function to call for different tasks.
    // glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
    glutDisplayFunc(Display);          // tell library which function to call for drawing Canvas.
    glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
    glutKeyboardFunc(PrintableKeys);   // tell library which function to call for printable ASCII characters
                                       // This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
    glutTimerFunc(5.0 / FPS, Timer, 0);

    // now handle the control to library and it will call our registered functions when
    // it deems necessary...
    glutMainLoop();
    return 1;
}
#endif /* Snake Game */
