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
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(100,50));
    rect.setOutlineColor(sf::Color::Green);
    rect.setOutlineThickness(5);
    rect.setPosition(0,20);
    std::vector<sf::RectangleShape> rectangles;
    sf::RectangleShape left;
    left.setSize(sf::Vector2f(25,100));
    left.setFillColor(sf::Color::White);
    left.setPosition(25, 100);
    sf::RectangleShape;
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
        window.clear();
        window.draw(left);


        // Update the window
        window.display();

    }

    return EXIT_SUCCESS;
}
