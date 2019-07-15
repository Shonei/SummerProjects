#include <SFML/Graphics.hpp>
#include <iostream>
#include "Button.hpp"
#include "RoundedRec.hpp"

int main() {
  sf::RenderWindow window(sf::VideoMode(300, 500), "Too Deep");
  Button button(sf::Vector2f(500, 20), "hello it is me");
  button.setPosition(sf::Vector2f(100, 100));
  button.setClickAction([]() { std::cout << "click" << std::endl; });

  button.setPosition(sf::Vector2f(10, 300));
  button.setSize(sf::Vector2f(50, 20));
  button.setText("Click!");

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
    }

    button.event(event);

    window.clear(sf::Color::Black);
    button.draw(window);
    window.display();
  }
  return 0;
}