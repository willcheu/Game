//
// Created by William Cheung on 3/2/2024.
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

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


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            right.move(0, 100);
            std::cout << "m";
        }
        window.clear();
        window.draw(left);
        window.draw(right);
        // Update the window
        window.display();

    }

    return EXIT_SUCCESS;
}
