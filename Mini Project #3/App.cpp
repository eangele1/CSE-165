#include "App.h"
#include "Rectangle.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include "Game.h"

//make rectangle 2D vector collection
std::vector<std::vector<Rect*> > rects;
std::vector<Rect*> myRow;

//puts rectangles in heap memory
Rect* rect0x0 = new Rect(-.75, .75, 0.5, 0.5);
Rect* rect0x1 = new Rect(-.25, .75, 0.5, 0.5);
Rect* rect0x2 = new Rect(.25, .75, 0.5, 0.5);
Rect* rect1x0 = new Rect(-.75, .25, 0.5, 0.5);
Rect* rect1x1 = new Rect(-.25, .25, 0.5, 0.5);
Rect* rect1x2 = new Rect(.25, .25, 0.5, 0.5);
Rect* rect2x0 = new Rect(-.75, -.25, 0.5, 0.5);
Rect* rect2x1 = new Rect(-.25, -.25, 0.5, 0.5);
Rect* rect2x2 = new Rect(.25, -.25, 0.5, 0.5);

//initializes a new game
Game* tictactoe = new Game();

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    mx = 0.0;
    my = 0.0;
}

void App::draw() {

    //pushes all of the invisible rectangles into a 2D vector collection
    if (tictactoe->pushRects == true){
        
        rects.clear();
        
        myRow.push_back(rect0x0);
        myRow.push_back(rect0x1);
        myRow.push_back(rect0x2);
        
        rects.push_back(myRow);
        
        myRow.clear();
        
        myRow.push_back(rect1x0);
        myRow.push_back(rect1x1);
        myRow.push_back(rect1x2);
        
        rects.push_back(myRow);
        
        myRow.clear();
        
        myRow.push_back(rect2x0);
        myRow.push_back(rect2x1);
        myRow.push_back(rect2x2);
        
        rects.push_back(myRow);
        
        myRow.clear();
        
        tictactoe->pushRects = false;
    }
    
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    tictactoe->drawScreen(rects, mx, my);
    
    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}

void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    //on initial state, will not do anything if mouse is exactly at (0, 0)
    if(mx == 0 && my == 0){
        //Do nothing...
    }
    
    //checks to see if gameOn is true to allow any updates to table.
    if (tictactoe->gameOn == true) {
        //checks to see if gameover is false to allow any updates to table.
        if(tictactoe->gameover == false){
            //if it's player one's turn, then changes tic tac toe box
            if(tictactoe->playerturn == 1){
                for(int i = 0; i <= 2; i++){
                    for(int j = 0; j <= 2; j++){
                        //if mouse is inside box and matrix at box is 0, then changes it to player 1's box
                        if(rects[i][j]->contains(mx, my) && tictactoe->matrix[i][j] == 0){
                            tictactoe->matrix[i][j] = 1;
                            
                            //if cpu is on, then changes turn to cpu
                            if (tictactoe->isPlayerCPU) {
                                tictactoe->playerturn = 3;
                            }
                            else{
                                tictactoe->playerturn = 2;
                            }
                        }
                    }
                }
            }
            else if(tictactoe->playerturn == 2){
                for(int i = 0; i <= 2; i++){
                    for(int j = 0; j <= 2; j++){
                        if(rects[i][j]->contains(mx, my) && tictactoe->matrix[i][j] == 0){
                            tictactoe->matrix[i][j] = 2;
                            tictactoe->playerturn = 1;
                        }
                    }
                }
            }
        }
    }
    
    // Redraw the scene
    redraw();
}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    // Redraw the scene
    redraw();
}

void App::keyPress(unsigned char key) {
    switch(key){
        case 49:
            //starts one player game
            tictactoe->onePlayer = true;
            break;
        case 50:
            //starts two player game
            tictactoe->twoPlayer = true;
            break;
        case 'y':
            //resets game
            if(tictactoe->gameover == true){
                tictactoe->gameover = false;
                tictactoe->initGame();
            }
            break;
        case 'n':
            //exits window
            if(tictactoe->gameover == true){
                
                delete rect0x0;
                delete rect0x1;
                delete rect0x2;
                delete rect1x0;
                delete rect1x1;
                delete rect1x2;
                delete rect2x0;
                delete rect2x1;
                delete rect2x2;
                
                delete tictactoe;
                exit(0);
            }
            break;
        case 27:
            //brute exits window
            
            delete rect0x0;
            delete rect0x1;
            delete rect0x2;
            delete rect1x0;
            delete rect1x1;
            delete rect1x2;
            delete rect2x0;
            delete rect2x1;
            delete rect2x2;
            
            delete tictactoe;
            exit(0);
    }

}
