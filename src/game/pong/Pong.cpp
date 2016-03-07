//
// Created by onur on 07/03/16.
//
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Pong {
public:
    void start(RenderWindow& window) {
        Ball ball{windowWidth/2, windowHeight/2};
        Paddle paddlePl{windowWidth/2, windowHeight - 50};
        Paddle paddleAi{windowWidth/2, 50};

        /*
         * Game Loop
         * */
        while(true) {
            window.clear(Color::Black);
            testCollision(paddlePl, ball);
            testCollision(paddleAi, ball);
            if(Keyboard::isKeyPressed(Keyboard::Key::Escape)) break;
            ball.update();
            paddlePl.update();
            paddleAi.aiMove(ball);

            window.draw(paddlePl.shape);
            window.draw(paddleAi.shape);
            window.draw(ball.shape);
            window.display();
        }
    }

protected:

    static constexpr int windowWidth{800}, windowHeight{600};
    static constexpr float ballRadius{10.f}, ballVelocity{8.f};
    static constexpr float paddleWidth{60.f}, paddleHeight{20.f}, paddleVelocity{7.f};

    struct Ball {
        CircleShape shape;
        Vector2f velocity{-ballVelocity, -ballVelocity};
        Ball(float mX, float mY) {
            shape.setPosition(mX, mY);
            shape.setRadius(ballRadius);
            shape.setFillColor(Color::Yellow);
            shape.setOrigin(ballRadius, ballRadius);
        }
        void update() {
            shape.move(velocity);

            if(left() < 0) velocity.x = ballVelocity;
            else if(right() > windowWidth) velocity.x = -ballVelocity;

            if(top() < 0) velocity.y = ballVelocity;
            else if (bottom() > windowHeight) velocity.y = -ballVelocity;
        }

        float x() { return shape.getPosition().x; }
        float y() { return shape.getPosition().y; }
        float left() { return x() - shape.getRadius(); }
        float right() { return x() + shape.getRadius(); }
        float top() { return y() - shape.getRadius(); }
        float bottom() { return y() + shape.getRadius(); }
    };

    struct Paddle {
        RectangleShape shape;
        Vector2f velocity;

        Paddle(float mX, float mY) {
            shape.setPosition(mX, mY);
            shape.setSize({paddleWidth, paddleHeight});
            shape.setFillColor(Color::Green);
            shape.setOrigin(paddleWidth/2.f, paddleHeight/2.f);
        }

        void update() {
            shape.move(velocity);

            if(Keyboard::isKeyPressed(Keyboard::Key::Left) && left() > 0) { velocity.x = -paddleVelocity; }
            else if(Keyboard::isKeyPressed(Keyboard::Key::Right) && right() < windowWidth) { velocity.x = paddleVelocity; }
            else velocity.x = 0;
        }

        void aiMove(Ball& mBall) {
            shape.move(velocity);

            if(mBall.shape.getPosition().x > shape.getPosition().x) { velocity.x = paddleVelocity; }
            else { velocity.x = -paddleVelocity; }
        }

        float x() { return shape.getPosition().x; }
        float y() { return shape.getPosition().y; }
        float left() { return x() - shape.getSize().x / 2.f; }
        float right() { return x() + shape.getSize().x / 2.f; }
        float top() { return y() - shape.getSize().y / 2.f; }
        float bottom() { return y() + shape.getSize().y / 2.f; }
    };

    template<class T1, class T2>
    bool isIntersecting(T1& mA, T2& mB) {
        return mA.right() >= mB.left() &&
               mA.left() <= mB.right() &&
               mA.bottom() >= mB.top() &&
               mA.top() <= mB.bottom();
    };

    void testCollision(Paddle& mPaddle, Ball& mBall) {
        if(!isIntersecting(mPaddle, mBall)) return;

        mBall.velocity.y = -ballVelocity;
        if(mBall.x() < mPaddle.x()) mBall.velocity.x = -ballVelocity;
        else mBall.velocity.x = ballVelocity;
    }

};