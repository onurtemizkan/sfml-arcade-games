#include <iostream>
#include <thread>
#include <list>
#include <deque>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>



using namespace std;
using namespace sf;

constexpr int windowWidth{800}, windowHeight{600};
constexpr float snakeNodeSize{10.f};
constexpr int initialSnakeLength{5};
constexpr float snakeVelocity{6.f};

struct SnakeNode {
    RectangleShape shape;
    Vector2f velocity {snakeVelocity, 0};

    SnakeNode(float posX, float posY) {
        shape.setPosition(posX, posY);
        shape.setSize({snakeNodeSize, snakeNodeSize});
        shape.setFillColor(Color::White);
    }

    void update() {
        shape.move(velocity);
        shape.setPosition(posX(), posY());
    }

    float posX() { return int(shape.getPosition().x) % windowWidth; }
    float posY() { return int(shape.getPosition().y) % windowHeight; }
};

struct Food {

};

void moveSnake(){

}

/*int main() {
    RenderWindow window{{windowWidth, windowHeight}, "Snake Game"};
    window.setFramerateLimit(60);

    deque<SnakeNode> snake;
    thread moveSnakeThread();
    for(int i{0}; i<initialSnakeLength; i++) {
        snake.emplace_front(-(i+1) * (snakeNodeSize), float(windowHeight/2));
    }

    while(true) {
        window.clear(Color::Black);

        if(Keyboard::isKeyPressed(Keyboard::Key::Up)) {snake.front().velocity = {0, -snakeVelocity};}
        else if(Keyboard::isKeyPressed(Keyboard::Key::Down)) {snake.front().velocity = {0, snakeVelocity};}
        else if(Keyboard::isKeyPressed(Keyboard::Key::Left)) {snake.front().velocity = {-snakeVelocity, 0};}
        else if(Keyboard::isKeyPressed(Keyboard::Key::Right)) {snake.front().velocity = {snakeVelocity, 0};}

        if(true) {
            snake.emplace_front(snake.back().posX() + snakeNodeSize, snake.front().posY());
            snake.pop_back();
        }

        for(SnakeNode& node: snake) { window.draw(node.shape); }
        if(Keyboard::isKeyPressed(Keyboard::Key::Escape)) break;
        window.display();
    }
}

 */