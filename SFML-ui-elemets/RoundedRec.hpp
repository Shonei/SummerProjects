#ifndef ROUNDEDREC_HPP
#define ROUNDEDREC_HPP

#include <SFML/Graphics/Shape.hpp>
#include <cmath>
#include <iostream>
#include <vector>

class RoundedRec : public sf::Shape {
 public:
  explicit RoundedRec(const sf::Vector2f v = sf::Vector2f(0, 0));
  std::size_t getPointCount() const;
  sf::Vector2f getPoint(std::size_t index) const;
  void setPosition(const sf::Vector2f);
  void setRadius(int);
  int getRadius() const;
  void setSize(const sf::Vector2f);
  sf::Vector2f getSize() const;

 private:
  void calculateCircle();
  std::vector<sf::Vector2f> points;
  const double pi2 = 6.28318530718;
  double step = 0.39269908169;
  sf::Vector2f size;
  sf::Vector2f pos;
  int radius = 6;
  int cornerPoints = 5;
};

#endif