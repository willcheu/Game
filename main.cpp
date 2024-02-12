//
// Created by William Cheung on 3/2/2024.
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

void recMove();

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    // Load a sprite to display
    sf::Texture texture;

    sf::RectangleShape left(sf::Vector2f(25,100));

    left.setFillColor(sf::Color::White);
    left.setPosition(0, 250);
    sf::RectangleShape right(sf::Vector2f(25,100));
    right.setPosition(775,250);
    left.setFillColor(sf::Color::White);

    sf::RectangleShape ball(sf::Vector2f(20, 20));
    ball.setPosition(390, 290);
    float move_x = 0.1f;
    float move_y = 0;


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
            ball.setPosition(390,290);
        }

        ball.move(move_x, move_y);

        window.clear();
        window.draw(left);
        window.draw(right);
        window.draw(ball);
        // Update the window
        window.display();

    }

    return EXIT_SUCCESS;
}



