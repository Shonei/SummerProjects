#include <SFML/Graphics.hpp>
#include "BUtton.hpp"

Button::Button(const sf::Vector2f v) {
  outher.setFillColor(sf::Color(105, 105, 105));
  outher.setSize(v);

  inner.setFillColor(sf::Color(169, 169, 169));
  inner.setSize(sf::Vector2f(v.x - 4, v.y - 4));

  if (!font.loadFromFile("FeFCrm2.ttf")) {
    // error
  }

  text.setFont(font);
  text.setCharacterSize(11);
  text.setFillColor(sf::Color(40, 40, 40));
  text.setString("Button");
}

Button::Button(const sf::Vector2f v, const std::string s) {
  outher.setFillColor(sf::Color(105, 105, 105));
  outher.setSize(v);

  inner.setFillColor(sf::Color(169, 169, 169));
  inner.setSize(sf::Vector2f(v.x - 4, v.y - 4));

  if (!font.loadFromFile("FeFCrm2.ttf")) {
    // error
  }

  text.setFont(font);
  text.setCharacterSize(11);
  text.setFillColor(sf::Color(40, 40, 40));
  text.setString(s);
  this->resizeButtonToText();
}

void Button::draw(sf::RenderWindow &window) {
  window.draw(outher);
  window.draw(inner);
  window.draw(text);
}

void Button::setPosition(sf::Vector2f v) {
  outher.setPosition(v);
  inner.setPosition(sf::Vector2f(v.x + 2, v.y + 2));
  this->setTextPosition();
}

void Button::setTextPosition() {
  sf::FloatRect temp = inner.getGlobalBounds();
  sf::FloatRect temp1 = text.getGlobalBounds();
  int w = temp.width - temp1.width;
  int h = temp.height - temp1.height;
  text.setPosition(sf::Vector2f(temp.left + w / 2, temp.top - 2 + h / 2));
}

void Button::setSize(sf::Vector2f v) {
  outher.setSize(v);
  inner.setSize(sf::Vector2f(v.x - 4, v.y - 4));
  this->resizeButtonToText();
  this->setTextPosition();
}

void Button::event(const sf::Event &event) {
  sf::FloatRect temp = outher.getGlobalBounds();

  if (event.type == sf::Event::MouseMoved) {
    if (temp.contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y)) && hover) {
      hover = false;
      outher.setFillColor(sf::Color(128, 128, 128));
      text.setFillColor(sf::Color(88, 88, 88));
      hoverAction();
    } else if (!temp.contains( sf::Vector2f(event.mouseMove.x, event.mouseMove.y))) {
      hover = true;
      outher.setFillColor(sf::Color(105, 105, 105));
      text.setFillColor(sf::Color(40, 40, 40));
    }
    return;
  }

  if (event.type == sf::Event::MouseButtonPressed) {
    if (temp.contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) && click) {
      clickAction();
      outher.setFillColor(sf::Color(112, 112, 160));
      text.setFillColor(sf::Color(72, 72, 120));
      click = false;
    }
  } else if (event.type == sf::Event::MouseButtonReleased) {
    if (temp.contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
      click = true;
      outher.setFillColor(sf::Color(105, 105, 105));
      text.setFillColor(sf::Color(40, 40, 40));
    }
  }
}

void Button::setClickAction(std::function<void()> click) {
  clickAction = click;
}

void Button::setHoverAction(std::function<void()> hover) {
  hoverAction = hover;
}

void Button::resizeButtonToText() {
  sf::FloatRect r = text.getGlobalBounds();
  if (inner.getGlobalBounds().width < r.width) {
    this->setSize(sf::Vector2f(r.width + 20, outher.getSize().y));
  }
}

void Button::setText(const std::string s) {
  text.setString(s);
  this->resizeButtonToText();
  this->setTextPosition();
}