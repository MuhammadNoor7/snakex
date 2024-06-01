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

int width = 650;
int height = 650;
double x = 320;
double y = 400;
char direction = 'W';
const int maxbreadth = 90;
int snake[maxbreadth][2];
int snakelen = 5;

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

void initsnake()
{
    for (int i = 0; i < snakelen; i++)
    {
        snake[i][0] = width / 2 - i * 10;
        snake[i][1] = height / 2;
    }
}

/*
 * Main Canvas drawing function.
 * */

int foodX = 0;
int foodY = 0;
int score = 0;
int food2X = 0;
int food2Y = 0;

// Function to generate random position for food
void generateFoodPosition()
{
    foodX = rand() % (width / 10) * 10;  // Random X position in steps of 10
    foodY = rand() % (height / 10) * 10; // Random Y position in steps of 10
    food2X = rand() % (width / 5) * 10;
    food2Y = rand() % (height / 5) * 10;
}

void playerscore()
{
    if (snake[0][0] == foodX && snake[0][1] == foodY)
    {
        score++;
    }
}

void Display()
{
    // set the background color using function glClearColor
    // to change the background play with the red, green and blue values below.
    // Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

    makegrid();
    box(25, 25);
    glClearColor(0.4, 0.0, 0.4, 0.0);

    glClear(GL_COLOR_BUFFER_BIT); // Update the colors

    DrawRoundRect(0, 0, 650, 650, 0, 15);

    // for drawing snake

    if (snake[0][0] < 0 || snake[0][0] >= width || snake[0][1] < 0 || snake[0][1] >= height)
    {
        cout << "Game Over - Collision with Walls!" << endl;
        exit(0);
    }

    /* for (int i = 1; i < snakelen; i++)
   //  {
         if (snake[0][0] == snake[i][0] && snake[0][1] == snake[i][1])
         {
             cout << "Game Over - Collision with Itself!" << endl;
             exit(0);
         }
     }
  */
    if (snake[0][0] == foodX && snake[0][1] == foodY)
    {
        snakelen++;
        playerscore();
        generateFoodPosition();
        cout << "Snake ate the food!" << endl;
    }

    if (snake[0][0] == food2X && snake[0][1] == food2Y)
    {
        snakelen++;
        playerscore();
        generateFoodPosition();
        cout << "Snake ate the food!" << endl;
    }

    // Draw the food
    DrawCircle(foodX + 5, foodY + 5, 5, colors[RED]);

    for (int i = 0; i < snakelen; i++)
        DrawSquare(snake[i][0], snake[i][1], 15, colors[YELLOW_GREEN]);

    for (int i = snakelen - 1; i > 0; i--)
    {

        snake[i][0] = snake[i - 1][0];
        snake[i][1] = snake[i - 1][1];
    }
    if ((direction == 'W'))
    {
        snake[0][1] += 10;
    }
    else if ((direction == 'A'))
    {
        snake[0][0] -= 10;
    }
    else if ((direction == 'S'))
    {
        snake[0][1] -= 10;
    }
    else if ((direction == 'D'))
    {
        snake[0][0] += 10;
    }

    for (int i = snakelen - 1; i > 0; i--)
    {
        snake[i][0] = snake[i - 1][0];
        snake[i][1] = snake[i - 1][1];
    }

    //  DrawString( 50, 600, "Here are some are basic shapes", colors[MISTY_ROSE]); // this will print given string at x=50 , y=600
    //  DrawString( 50, 570, "You will use these to make your game", colors[MISTY_ROSE]); // this will print given string at x=50 , y=570
    //  DrawString(50, 570,"Score:",colors[MISTY_ROSE]); // this will print Score at x=50 , y=570
    // DrawCircle(310, 405, 15, colors[YELLOW_GREEN]); // This will draw a circle at x=310,y=405 of radius 10

    //                    v1( x,y )   v2( x,y )  , v3( x,y )
    //  DrawTriangle(300,100,400,100,350,200,colors[MISTY_ROSE]);

    // DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
    //  DrawLine( 100,250,100,400,20,colors[MISTY_ROSE]);
    DrawCircle(foodX + 5, foodY + 5, 5, colors[RED]);

    // Draw the second food
    DrawCircle(food2X + 5, food2Y + 5, 5, colors[BLUE]);

    // Draw the snake
    for (int i = 0; i < snakelen; i++)
        DrawSquare(snake[i][0], snake[i][1], 15, colors[YELLOW_GREEN]);

    // Draw the score
    stringstream ss;
    ss << "Score: " << score;
    DrawString(50, 600, ss.str(), colors[MISTY_ROSE]);

    glutSwapBuffers();

    glutSwapBuffers(); // do not modify this line..
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
0*
 * */

void NonPrintableKeys(int key, int x, int y)
{
    if (key == GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/)
    {
        // what to do when left key is pressed...
        direction = 'A';
    }
    else if (key == GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/)
    {
        direction = 'D';
    }
    else if (key == GLUT_KEY_UP) /*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/
    {
        direction = 'W';
    }
    else if (key == GLUT_KEY_DOWN) /*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/
    {
        direction = 'S';
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

    InitRandomizer();      // seed the random number generator...
    glutInit(&argc, argv); // initialize the graphics library...

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
    glutInitWindowPosition(100, 100);             // Set the initial position of the window
    glutInitWindowSize(width, height);            // set the size of our window
    glutCreateWindow("Snake game");               // set the title of our game window
    SetCanvasSize(650, 650);                      // set the number of pixels...
                                                  // initsnake();
                                                  // initializegrid();

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
