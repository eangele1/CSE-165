#include "Game.h"
#include "App.h"
#include "Rectangle.h"

//Constructor
Game::Game(){
    //x starts first
    playerturn = 1;
    
    onePlayer = false;
    twoPlayer = false;
    
    pushRects = true;
    
    isPlayerCPU = false;
    
    gameOn = false;
    
    result = -1;
    
    //clear the matrix
    for(int i = 0; i <= 2; i++){
        for(int j = 0; j <= 2; j++){
            matrix[i][j] = 0;
        }
    }
}

void Game::drawScreen(std::vector<std::vector<Rect*> > &rects, float mx, float my){
    //gives the text the color white
    glColor3f(1, 1, 1);
    
    //shows text at the start of program to let player know of which mode to choose
    if(onePlayer == false && twoPlayer == false){
        drawString(GLUT_BITMAP_HELVETICA_18, "One Player or Two Player? (1/2)", -.45, -.9);
        drawLines();
    }
    
    //1P mode
    if(onePlayer == true && twoPlayer == false){
        
        //makes player 2 the cpu
        isPlayerCPU = true;
        
        //starts the game
        gameOn = true;
        
        //displayes current player turn
        if(playerturn == 1 && gameover == false)
            drawString(GLUT_BITMAP_HELVETICA_18, "Your turn.", -.2, -.9);
        else if (playerturn == 3 && gameover == false)
            drawString(GLUT_BITMAP_HELVETICA_18, "Computer's turn.", -.2, -.9);
        
        //draws the board
        drawLines();
        //draws the x's and o's when player clicks on rectangle
        drawXO(rects);
        
        //makes the rectangles from inside the vector collection
        for(int i = 0; i <= 2; i++){
            for(int j = 0; j <= 2; j++){
                rects[i][j]->makeRect(mx, my);
            }
        }
        
        //checks if there's a win
        if(checkIfWin() == true){
            
            //the player who made the previous move is the winner
            if(playerturn == 1){
                gameover = true;
                //player 2 wins
                result = 4;
            }
            else{
                gameover = true;
                //player 1 wins
                result = 3;
            }
        }
        else if(checkIfDraw() == true){
            gameover = true;
            result = 0;
        }
        
        //checks to see if the game is over
        if(gameover == true){
            
            //gives the text the color white
            glColor3f(1, 1, 1);
            
            //checks the result and displays message accordingly; then asks player to continue or quit
            if(result == 0){
                drawString(GLUT_BITMAP_HELVETICA_18, "Draw. Nobody wins.", -.2, -.85);
            }
            if(result == 3){
                drawString(GLUT_BITMAP_HELVETICA_18, "You win!", -.2, -.85);
            }
            if(result == 4){
                drawString(GLUT_BITMAP_HELVETICA_18, "Computer wins!", -.2, -.85);
            }
            
            drawString(GLUT_BITMAP_HELVETICA_18, "Continue? (Y/N)", -.2, -.95);
        }
        
        //This if-statement contains the algorithm for CPU to make moves; AI is on easy difficulty, which means it only does moves on a random basis as it goes through the 2D matrix.
        if (playerturn == 3 && gameover == false){
            int min = 0;
            int max = 2;
            
            while(1){
                
                int i = (min + (rand() % (int)(max - min + 1)));
                int j = (min + (rand() % (int)(max - min + 1)));
                
                if(matrix[i][j] == 0){
                    matrix[i][j] = 2;
                    playerturn = 1;
                    break;
                }
                
            }
            
        }
        
    }
    
    //2P mode
    if (onePlayer == false && twoPlayer == true) {
        
        gameOn = true;
        
        if(playerturn == 1 && gameover == false)
            drawString(GLUT_BITMAP_HELVETICA_18, "Player 1's turn.", -.2, -.9);
        else if (playerturn == 2 && gameover == false)
            drawString(GLUT_BITMAP_HELVETICA_18, "Player 2's turn.", -.2, -.9);
        
        drawLines();
        drawXO(rects);
        
        for(int i = 0; i <= 2; i++){
            for(int j = 0; j <= 2; j++){
                rects[i][j]->makeRect(mx, my);
            }
        }
        
        if(checkIfWin() == true){
            
            //the player who made the previous move is the winner
            if(playerturn == 1){
                gameover = true;
                //player 2 wins
                result = 2;
            }
            else{
                gameover = true;
                //player 1 wins
                result = 1;
            }
        }
        else if(checkIfDraw() == true){
            gameover = true;
            result = 0;
        }
        
        if(gameover == true){
            
            //gives the text the color white
            glColor3f(1, 1, 1);
            
            if(result == 0){
                drawString(GLUT_BITMAP_HELVETICA_18, "Draw. Nobody wins.", -.2, -.85);
            }
            if(result == 1){
                drawString(GLUT_BITMAP_HELVETICA_18, "Player 1 wins!", -.2, -.85);
            }
            if(result == 2){
                drawString(GLUT_BITMAP_HELVETICA_18, "Player 2 wins!", -.2, -.85);
            }
            
            drawString(GLUT_BITMAP_HELVETICA_18, "Continue? (Y/N)", -.2, -.95);
        }
    }
}

//draws the x and o's
void Game::drawXO(std::vector<std::vector<Rect*> > &rects){
    for(int i = 0; i <= 2; i++){
        for(int j = 0; j <= 2; j++){
            //if it's 1, then draw x
            if(matrix[i][j] == 1){
                float x = rects[i][j]->getX();
                float y = rects[i][j]->getY();
                
                std::string s = "X";
                
                long n = s.length();
                
                // declaring character array
                char char_array[n + 1];
                
                // copying the contents of the string to char array
                strcpy(char_array, s.c_str());
                
                
                drawString(GLUT_BITMAP_HELVETICA_18, char_array, x+.25, y-.25);
                
            }
            //if it''s 2, then draw o
            else if(matrix[i][j] == 2){
                
                float x = rects[i][j]->getX();
                float y = rects[i][j]->getY();
                
                std::string s = "O";
                
                long n = s.length();
                
                // declaring character array
                char char_array[n + 1];
                
                // copying the contents of the string to char array
                strcpy(char_array, s.c_str());
                
                drawString(GLUT_BITMAP_HELVETICA_18, char_array, x+.25, y-.25);
                
            }
        }
    }
}

void Game::initGame(){
    
    //x starts first
    playerturn = 1;
    
    onePlayer = false;
    twoPlayer = false;
    
    isPlayerCPU = false;
    
    gameOn = false;
    
    result = -1;
    
    //clear the matrix
    for(int i = 0; i <= 2; i++){
        for(int j = 0; j <= 2; j++){
            matrix[i][j] = 0;
        }
    }
}

//used to write text in the window
void Game::drawString (void * font, char *s, float x, float y){
    unsigned int i;
    glRasterPos2f(x, y);
    for (i = 0; i < strlen (s); i++)
        glutBitmapCharacter (font, s[i]);
}

//draws the lines to make Tic Tac Toe board
void Game::drawLines(){
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    //2 vertical lines
    glVertex2f(-.25, .75);
    glVertex2f(-.25, -.75);
    glVertex2f(.25, .75);
    glVertex2f(.25, -.75);
    //2 horizontal lines
    glVertex2f(.75, .25);
    glVertex2f(-.75, .25);
    glVertex2f(.75, -.25);
    glVertex2f(-.75, -.25);
    glEnd();
}

//checks if there is any winner
bool Game::checkIfWin(){
    int i, j;
    
    //check if there is any horizontal win. In other words, if there's any row that has same value, then there's a win
    for(i = 0; i <= 2; i++){
        for(j = 1; j <= 2; j++){
            if(matrix[i][0] != 0 && matrix[i][0] == matrix[i][j]){
                if(j == 2)
                    return true;
            }
            else{
                break;
            }
        }
    }
    
    //check if there is any vertical win. In other words, if there's any column that has same value, then there's a win
    for(i = 0; i <= 2; i++){
        for(j = 1; j <= 2; j++){
            if(matrix[0][i] != 0 && matrix[0][i] == matrix[j][i]){
                if(j == 2)
                    return true;
            }
            else
                break;
        }
    }
    
    //next two for loops check if there is any diagonal win. In other words, if there are any diagonals that has same value, then there's a win
    for(i = 1; i <= 2; i++){
        if(matrix[0][0] != 0 && matrix[0][0] == matrix[i][i]){
            if(i == 2)
                return true;
        }
        else{
            break;
        }
    }
    for(i = 1; i <= 2; i++){
        if(matrix[2][0] != 0 && matrix[2][0] == matrix[2 - i][i]){
            if(i == 2)
                return true;
        }
        else{
            break;
        }
    }
    return false;
}

//checks if the match is a draw. In other words, it returns false if there is at least one empty box, otherwise it returns true
bool Game::checkIfDraw(){
    
    for(int i = 0; i <= 2; i++){
        for(int j = 0; j <= 2; j++){
            if(matrix[i][j] == 0)
                return false;
        }
    }
    return true;
}

//Destructor
Game::~Game(){}
