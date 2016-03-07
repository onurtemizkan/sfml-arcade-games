//
// Created by onur on 07/03/16.
//
#include <iostream>
#include "game/pong/Pong.cpp"
#include "game/arkanoid/Arkanoid.cpp"

using namespace std;

constexpr int frameRateLimit{60};
constexpr int windowWidth{800}, windowHeight{600} ;

int main() {
    RenderWindow window{{windowWidth, windowHeight}, "Hola"};
    window.setFramerateLimit(frameRateLimit);

//    Pong pong;
//    pong.start(window);
    Arkanoid arkanoid;
    arkanoid.start(window);
}