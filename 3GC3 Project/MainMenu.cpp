/*
3GC3 Final Project - Space Genesis

David Hobson / hobsondd / 001412317
Jack Snopek / snopekjt / 001408851
Susan Yuen / yuens2 / 001416198
Thien Trandinh / trandit / 001420634
*/

#include "MainMenu.h"

MainMenu::ButtonType currentHovering = MainMenu::Item1; //button that is hovered by default

//constructor
MainMenu::MainMenu()
{
}

void MainMenu::drawMenu()
{
    switch(currentHovering)  //highlights the button currentHovering by redrawing box in slightly different colour
    {
    case MainMenu::Item1:
        drawBox("Start",0.0f, 0.4f);
        break;
    case MainMenu::Item2:
        drawBox("Difficulty",0.9f, 0.4f);
        break;
    case MainMenu::Item3:
        drawBox("How To Play",1.8f, 0.4f);
        break;
    case MainMenu::Item4:
        drawBox("Exit",2.7f, 0.4f);
        break;
    }

    drawBox("Start",0.0f, 0.0f);
    drawBox("Difficulty",0.9f, 0.0f);
    drawBox("How To Play",1.8f, 0.0f);
    drawBox("Exit",2.7f, 0.0f);

    //print title text
    glColor3f(1, 1, 1);
    glRasterPos3f(1.5f, 2.5, 2);
    std::string startText = {"Space Genesis"};
    for(int i=0; i<startText.size(); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, startText[i]);
    }
}

void MainMenu::drawDifficulty(){
    switch(currentHovering){ //highlights the button currentHovering by redrawing box in slightly different colour
    case MainMenu::Item1:
        drawBox("Easy",0.0f, 0.4f);
        break;
    case MainMenu::Item2:
        drawBox("Medium",0.9f, 0.4f);
        break;
    case MainMenu::Item3:
        drawBox("Hard",1.8f, 0.4f);
        break;
    case MainMenu::Item4:
        drawBox("Return",2.7f, 0.4f);
        break;
    }

    drawBox("Easy",0.0f, 0.0f);
    drawBox("Medium",0.9f, 0.0f);
    drawBox("Hard",1.8f, 0.0f);
    drawBox("Return",2.7f, 0.0f);

    //print title text
    glColor3f(1, 1, 1);
    glRasterPos3f(1.5f, 2.5, 2);
    std::string startText = {"Space Genesis"};
    for(int i=0; i<startText.size(); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, startText[i]);
    }
}

//draw button box
void MainMenu::drawBox(std::string text, float position, float highlight)
{
    glBegin(GL_QUADS);

    //top face
    glColor3f(0.8f+highlight, 0.5f+highlight, 0.0f+highlight);     // orange
    glVertex3f( 2.0f,  1.3f-position, 0);
    glVertex3f( 0,  1.3f-position, 2.0f);
    glColor3f(  0, 0.0f, 0.0f);     // black
    glVertex3f( 0,  1.5f-position, 0.1f);
    glVertex3f( 0.1f,  1.5f-position, 0);

    // Front face
    glColor3f(0.9f+highlight, 0.5f+highlight, 0.0f+highlight);     // orange
    glVertex3f( 2.0f,  1.3f-position, 0);
    glVertex3f( 0,  1.3f-position, 2.0f);
    glVertex3f( 0,  0.8f-position, 2.0f);
    glVertex3f( 2.0f, 0.8f-position, 0);

    glEnd();  // End of drawing color-cube

    drawText(text, position);
}

//draw text
void MainMenu::drawText(std::string text, float position)
{
    float posX=1.1f;
    float posZ=1.3f;
    float posY=1.1-position+(position/18);
    glColor3f(0, 0, 0);
    glRasterPos3f(posX, posY, posZ);
    std::string startText = {text};
    for(int i=0; i<startText.size(); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, startText[i]);
    }
}

//cycle button downwards
void MainMenu::goDown()
{
    switch(currentHovering)
    {
    case MainMenu::Item1:
        currentHovering=Item2;
        break;
    case MainMenu::Item2:
        currentHovering=Item3;
        break;
    case MainMenu::Item3:
        currentHovering=Item4;
        break;
    case MainMenu::Item4:
        currentHovering=Item1;
        break;
    }
}

//cycle button upwards
void MainMenu::goUp()
{
    switch(currentHovering)
    {
    case MainMenu::Item1:
        currentHovering=Item4;
        break;
    case MainMenu::Item2:
        currentHovering=Item1;
        break;
    case MainMenu::Item3:
        currentHovering=Item2;
        break;
    case MainMenu::Item4:
        currentHovering=Item3;
        break;
    }
}

//returns the current button
MainMenu::ButtonType MainMenu::getCurrentButton()
{
    return currentHovering;
}