#include "RoundedRec.hpp"

RoundedRec::RoundedRec(const sf::Vector2f v) {
  size = v;
  this->calculateCircle();
  this->update();
}

std::size_t RoundedRec::getPointCount() const { return points.size(); }

sf::Vector2f RoundedRec::getPoint(std::size_t index) const {
  int i = index / 5;
  sf::Vector2f temp;
  switch (i) {
    case 0:
      temp.x = pos.x + size.x - radius;
      temp.y = pos.y + size.y - radius;
      break;
    case 1:
      temp.x = pos.x + radius;
      temp.y = pos.y + size.y - radius;
      break;
    case 2:
      temp.x = pos.x + radius;
      temp.y = pos.y + radius;
      break;
    case 3:
      temp.x = pos.x + size.x - radius;
      temp.y = pos.y + radius;
      break;
  }

  return sf::Vector2f(points[index].x + temp.x, points[index].y + temp.y);
}

void RoundedRec::setPosition(const sf::Vector2f v) {
  pos = v;
  this->update();
}

void RoundedRec::setRadius(int rad) {
  radius = rad;
  this->calculateCircle();
  this->update();
}

int RoundedRec::getRadius() const { return radius; }

void RoundedRec::calculateCircle() {
  int index = 1;
  int x = radius * cos(0);
  int y = radius * sin(0);

  points.clear();
  points.resize(cornerPoints * 4);
  points[0] = sf::Vector2f(x, y);
  points[cornerPoints * 4 - 1] = sf::Vector2f(x, y);

  for (double i = step; i < pi2; i += step) {
    x = radius * cos(i);
    y = radius * sin(i);
    points[index] = sf::Vector2f(x, y);
    if ((index + 1) % cornerPoints == 0) {
      index++;
      points[index] = sf::Vector2f(x, y);
    }
    index++;
  }
}

void RoundedRec::setSize(const sf::Vector2f v) {
  size = v;
  // this->calculateCircle();
  this->update();
}

sf::Vector2f RoundedRec::getSize() const {
  return size;
}