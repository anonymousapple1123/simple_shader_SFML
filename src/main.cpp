#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <cmath>

// Settings
const int GRID_SPACING = 40; // Pixels between grid lines
const int POINT_RADIUS = 6;
const sf::Color GRID_COLOR(220, 220, 220);

sf::Vector2f toWindowCoords(float x, float y, const sf::Vector2u& winSize) {
    float centerX = winSize.x / 2.0f;
    float centerY = winSize.y / 2.0f;
    return {centerX + x * GRID_SPACING, centerY - y * GRID_SPACING};
}

void plotPoints(sf::RenderWindow& window, const std::vector<float>& xCoords, const std::vector<float>& yCoords, const sf::Vector2u& winSize) {
    size_t count = std::min(xCoords.size(), yCoords.size());
    for (size_t i = 0; i < count; ++i) {
        sf::CircleShape dot(POINT_RADIUS);
        dot.setFillColor(sf::Color::Red);
        dot.setOrigin(POINT_RADIUS, POINT_RADIUS);
        dot.setPosition(toWindowCoords(xCoords[i], yCoords[i], winSize));
        window.draw(dot);
    }
}

void drawGrid(sf::RenderWindow& window, const sf::Font& font, const sf::Vector2u& winSize) {
    int cols = winSize.x / GRID_SPACING;
    int rows = winSize.y / GRID_SPACING;
    float centerX = winSize.x / 2.0f;
    float centerY = winSize.y / 2.0f;

    // Grid lines
    sf::Vertex line[2];
    for (int x = 0; x <= winSize.x; x += GRID_SPACING) {
        line[0] = sf::Vertex(sf::Vector2f(x, 0), GRID_COLOR);
        line[1] = sf::Vertex(sf::Vector2f(x, winSize.y), GRID_COLOR);
        window.draw(line, 2, sf::Lines);
    }
    for (int y = 0; y <= winSize.y; y += GRID_SPACING) {
        line[0] = sf::Vertex(sf::Vector2f(0, y), GRID_COLOR);
        line[1] = sf::Vertex(sf::Vector2f(winSize.x, y), GRID_COLOR);
        window.draw(line, 2, sf::Lines);
    }

    // Axes
    sf::Vertex xAxis[] = {
        sf::Vertex(sf::Vector2f(0, centerY), sf::Color::Black),
        sf::Vertex(sf::Vector2f(winSize.x, centerY), sf::Color::Black)
    };
    sf::Vertex yAxis[] = {
        sf::Vertex(sf::Vector2f(centerX, 0), sf::Color::Black),
        sf::Vertex(sf::Vector2f(centerX, winSize.y), sf::Color::Black)
    };
    window.draw(xAxis, 2, sf::Lines);
    window.draw(yAxis, 2, sf::Lines);

    // Axis labels
    for (int i = -cols / 2; i <= cols / 2; ++i) {
        if (i == 0) continue;
        sf::Text text(std::to_string(i), font, 12);
        text.setFillColor(sf::Color::Black);
        text.setPosition(centerX + i * GRID_SPACING - 5, centerY + 5);
        window.draw(text);
    }

    for (int i = -rows / 2; i <= rows / 2; ++i) {
        if (i == 0) continue;
        sf::Text text(std::to_string(i), font, 12);
        text.setFillColor(sf::Color::Black);
        text.setPosition(centerX + 5, centerY - i * GRID_SPACING - 8);
        window.draw(text);
    }

    // Origin label
    sf::Text origin("O", font, 14);
    origin.setFillColor(sf::Color::Black);
    origin.setPosition(centerX + 4, centerY + 4);
    window.draw(origin);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Math Grid", sf::Style::Default);
    window.setFramerateLimit(60);

    // Use view to prevent distortion when resizing
    sf::View view(sf::FloatRect(0, 0, 800, 600));
    window.setView(view);

    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf")) {
        return -1;
    }

    std::vector<float> xCoords = {1, -3, 0, 2.5};
    std::vector<float> yCoords = {2, 1, -2, -1.5};

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::Resized) {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }
        }

        sf::Vector2u winSize = window.getSize();

        window.clear(sf::Color::White);

        drawGrid(window, font, winSize);
        plotPoints(window, xCoords, yCoords, winSize);

        window.display();
    }

    return 0;
}
