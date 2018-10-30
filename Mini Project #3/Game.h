#ifndef Game_hpp
#define Game_hpp

//only used for drawXO
#include "Rectangle.h"
#include <vector>

class Game{
public:

	//stores the x and o's of the game; a value of 0 is blank, 1 is x and 2 is o
	int matrix[3][3];

    //if it's 1 then it's player 1's turn, otherwise if it's 2 then it's player 2's turn
	int playerturn = 1; 

    //if it's 0 then the game is a draw; if it's 1 then player 1 wins; if it's 2 then player 2 wins
	int result = -1; 

    //if it's false then its not gameover, otherwise if it's true then its gameover
	bool gameover = false;

	//stores player modes.
	bool onePlayer = false;
	bool twoPlayer = false;

	//stores if player 2 is CPU
	bool isPlayerCPU = false;

	//makes rectangles go inside the first time. turns to false afterwards.
	bool pushRects = true;

	//stores if game is going on
	bool gameOn = false;

	Game();

	//only used if game is reset.
	void initGame();

	//graphics of the game
	void drawString (void * font, char *s, float x, float y);
	void drawLines();
	void drawXO(std::vector<std::vector<Rect*> > &rects);
    void drawScreen(std::vector<std::vector<Rect*> > &rects, float mx, float my);

	//checks if there's a win or a draw
	bool checkIfWin();
	bool checkIfDraw();

	~Game();

};

#endif
