#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>

int main(){
    sf::RenderWindow window(sf::VideoMode({800,600}), "Bar chart");

    sf::RectangleShape topLeft({200.f,100.f});
    topLeft.setFillColor(sf::Color::Red);

    sf::RectangleShape topRight({200.f,100.f});
    topRight.setFillColor(sf::Color::Blue);
    topRight.setOrigin({200.f,0.f});


    // sf::RectangleShape topLeft({200.f,100.f});
    // sf::RectangleShape topLeft({200.f,100.f});

    // rectangle.setPosition({200.f,100.f});
    // rectangle.setFillColor(sf::Color::Red);
    while(window.isOpen()){
        topRight.setPosition({static_cast<float>(window.getSize().x),0.f});
        while(const std::optional event = window.pollEvent()){

            if(event->is<sf::Event::Closed>()){
                window.close();
            }else if (event->is<sf::Event::Resized>()) {
                std::cout<<"Window : "<<window.getSize().x<<" x "<<window.getSize().y<<std::endl;
                std::cout<<"Window : "<<window.getView().getSize().x<<" x "<<window.getView().getSize().y<<std::endl;

                sf::View view({400.f,300.}, sf::Vector2f(window.getSize()));
                window.setView(view);

            }
        }
        window.clear(sf::Color(96,96,96));
        window.draw(topLeft);
        window.draw(topRight);
        window.display();

    }
    return 0;
}
