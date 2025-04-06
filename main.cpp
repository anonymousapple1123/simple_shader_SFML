#include <SFML/Graphics.hpp>

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Animation Example");

    // Create a circle
    sf::CircleShape circle(50);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(100, 100); // Start position

    // Clock to control the frame rate and animation
    sf::Clock clock;

    // Main loop
    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart(); // Restart clock and get time passed

        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Move the circle horizontally over time
        circle.move(100.0f * deltaTime.asSeconds(), 0); // 100 units per second

        // Clear the window, draw the circle, and display it
        window.clear();
        window.draw(circle);
        window.display();
    }

    return 0;
}
