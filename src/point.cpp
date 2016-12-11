#include "point.hpp"

Point::Point(const unsigned x, const unsigned y) 
: x_(x),
  y_(y) {

}

const unsigned Point::getX() const {
  return x_;
}

const unsigned Point::getY() const {
  return y_;
}
