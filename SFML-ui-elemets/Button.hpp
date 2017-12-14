#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <functional>
#include <iostream>
#include "RoundedRec.hpp"

class Button {
 public:
  explicit Button(const sf::Vector2f);
  void draw(sf::RenderWindow&);
  void setPosition(sf::Vector2f);
  void event(const sf::Event&);
  void setHoverAction(std::function<void()>);
  void setClickAction(std::function<void()>);
  void setSize(sf::Vector2f);

 private:
  RoundedRec inner;
  RoundedRec outher;
  bool hover = true;
  bool click = true;
  std::function<void()> hoverAction = []() {};
  std::function<void()> clickAction = []() {};
};

#endif