#include "Button.hpp"

Button::Button(const sf::Vector2f v) {
  outher.setFillColor(sf::Color(105, 105, 105));
  outher.setSize(v);

  inner.setFillColor(sf::Color(169, 169, 169));
  inner.setSize(sf::Vector2f(v.x - 4, v.y - 4));
}

void Button::draw(sf::RenderWindow &window) {
  window.draw(outher);
  window.draw(inner);
}

void Button::setPosition(sf::Vector2f v) {
  outher.setPosition(v);
  inner.setPosition(sf::Vector2f(v.x + 2, v.y + 2));
}

void Button::setSize(sf::Vector2f v) {
  outher.setSize(v);
  inner.setSize(sf::Vector2f(v.x - 4, v.y - 4));
}

void Button::event(const sf::Event &event) {
  sf::FloatRect temp = outher.getGlobalBounds();

  if (event.type == sf::Event::MouseMoved) {
    if (temp.contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y)) &&
        hover) {
      hover = false;
      outher.setFillColor(sf::Color(128, 128, 128));
      hoverAction();
    } else if (!temp.contains(
                   sf::Vector2f(event.mouseMove.x, event.mouseMove.y))) {
      hover = true;
      outher.setFillColor(sf::Color(105, 105, 105));
    }
  }

  if (event.type == sf::Event::MouseButtonPressed) {
    if (temp.contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) &&
        click) {
      clickAction();
      outher.setFillColor(sf::Color(112, 112, 160));
      click = false;
    }
  } else if (event.type == sf::Event::MouseButtonReleased) {
    if (temp.contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
      click = true;
      outher.setFillColor(sf::Color(105, 105, 105));
    }
  }
}

void Button::setClickAction(std::function<void()> click) {
  clickAction = click;
}

void Button::setHoverAction(std::function<void()> hover) {
  hoverAction = hover;
}