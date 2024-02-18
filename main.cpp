//
// Created by William Cheung on 3/2/2024.
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <string>



int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pong");
    // Load a sprite to display
    sf::Texture texture;
    sf::Font pfont;
    pfont.loadFromFile("/Users/willcheung/Downloads/bit5x3.ttf");
    sf::Text score_l;
    score_l.setFont(pfont);
    score_l.setString("0");
    score_l.setCharacterSize(80);
    score_l.setPosition(sf::Vector2f(300, 50));

    sf::Text score_r;
    score_r.setFont(pfont);
    score_r.setString("0");
    score_r.setCharacterSize(80);
    score_r.setPosition(sf::Vector2f(500, 50));

    sf::RectangleShape left(sf::Vector2f(25,100));

    left.setFillColor(sf::Color::White);
    left.setPosition(0, 250);
    sf::RectangleShape right(sf::Vector2f(25,100));
    right.setPosition(775,250);
    left.setFillColor(sf::Color::White);

    sf::RectangleShape ball(sf::Vector2f(20, 20));
    ball.setPosition(390, 290);
    float move_x = 0.1f;
    float move_y = 0.1f;
    int r_score = 0;
    int l_score = 0;


    float width = 0;
    bool start = false;

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen

        if (right.getPosition().y <= 0) {
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            right.move(0, -0.1);
        }

        if (right.getPosition().y >= 500) ;

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            right.move(0, 0.1);
        }

        if (left.getPosition().y <= 0) {
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            left.move(0, -0.1);
        }

        if (left.getPosition().y >= 500) ;

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            left.move(0, 0.1);
        }
        if (ball.getPosition().x >= 800 || ball.getPosition().x <= 0) {
            if (ball.getPosition().x <= 800) {
                r_score++;
                std::string a = std::to_string(r_score);
                score_r.setString(a);
            }
            else {
                l_score++;
                std::string b = std::to_string(l_score);
                score_l.setString(b);
            }
            ball.setPosition(390,290);
        }
        if (ball.getPosition().y <= 0) {
            move_y = 0.1f;
        }
        if (ball.getPosition().y >= 600) {
            move_y = -0.1f;
        }
        if (ball.getPosition().x < (left.getPosition().x + 25) && (left.getPosition().y < ball.getPosition().y && (ball.getPosition().y < left.getPosition().y + 100))) {
            int v1 = rand() % 2;
            if (v1 == 0) {
                move_y = 0.1f;
                move_x = 0.1f;
            }
            else {
                move_y = -0.1f;
                move_x = 0.1f;
            }

        }
        if (ball.getPosition().x + 20 > (right.getPosition().x) && (right.getPosition().y < ball.getPosition().y && right.getPosition().y + 100 > ball.getPosition().y)) {
            int v1 = rand() % 2;
            if (v1 == 0) {
                move_y = 0.1f;
                move_x = -0.1f;
            }
            else {
                move_y = -0.1f;
                move_x = -0.1f;
            }
        }
        ball.move(move_x, move_y);

        window.clear();
        window.draw(left);
        window.draw(right);
        window.draw(ball);
        window.draw(score_l);
        window.draw(score_r);
        // Update the window
        window.display();

    }

    return EXIT_SUCCESS;
}

