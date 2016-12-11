#include "point.hpp"

Point::Point(const unsigned int x, const unsigned int y) 
: x_(x),
  y_(y) {

}

const unsigned int Point::getX() const {
  return x_;
}

const unsigned int Point::getY() const {
  return y_;
}
