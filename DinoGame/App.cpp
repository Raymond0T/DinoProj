#include <iostream>
#include "App.h"

App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){
    
    addComponent(new Game());
    addComponent(new Ad("", ""));
    
    fullscreen = false;
}

void App::draw() const {
    for (std::vector<AppComponent*>::const_iterator i = components.begin(); i != components.end(); ++i) {
        (*i)->draw();
    }
}

void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);
    }
    else if (key == 'f'){
        toggleFullScreen();
    }
    else{
        for (std::vector<AppComponent*>::iterator i = components.begin(); i != components.end(); ++i) {
            (*i)->handleKeyDown(key, x, y);
        }
    }
}

void App::keyUp(unsigned char key, float x, float y) {
	for (std::vector<AppComponent*>::iterator i = components.begin(); i != components.end(); ++i) {
		(*i)->handleKeyUp(key, x, y);
	}
}

App::~App(){    
    for (std::vector<AppComponent*>::iterator i = components.begin(); i != components.end(); ++i) {
        delete *i;
    }
    std::cout << "Exiting..." << std::endl;
}
