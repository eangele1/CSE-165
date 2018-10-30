#include "App.h"
//#include <SFML/Audio.hpp>

int main(int argc, char** argv) {
	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    
    // Instantiate a new App
    App* myApp = new App("Tic Tac Toe", 50, 50, 600, 600);
    
    //Instantiate a new audio file
    //sf::Music* music = new sf::Music();
    
    //if music file not found, will throw error in console.
    //if (!music->openFromFile("audio/BGM.ogg")){}
    
    //makes audio loop (only loops from beginning to end, not at loop points)
    //music->setLoop(true);
    
    //music->setVolume(70);
    
    //plays the audio file
    //music->play();
    
	// Start the app
    myApp->run();
}
