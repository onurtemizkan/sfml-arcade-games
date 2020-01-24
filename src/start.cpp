#include "game/arkanoid/Arkanoid.cpp"
#include "game/pong/Pong.cpp"
#include <iostream>

using namespace std;

constexpr int frameRateLimit{60};
constexpr int windowWidth{800}, windowHeight{600};

int main() {
  RenderWindow window{{windowWidth, windowHeight}, "Hola"};
  window.setFramerateLimit(frameRateLimit);

  Pong pong;
  pong.start(window);
  // Arkanoid arkanoid;
  // arkanoid.start(window);
}
