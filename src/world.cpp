#include "world.hpp"

World::World(const unsigned width, const unsigned height) 
: width_(width),
  height_(height),
  mapData_(new unsigned[width_ + height_*width_]) {
  for(unsigned y = 0; y < height_; ++y) {
    for(unsigned x = 0; x < width; ++x) {
      if(x == 0 || y == 0 || x == width_-1 || y == height_-1) {
        mapData_[x + y*width_] = 0u; // wall
      } else {
        mapData_[x + y*width_] = 1u; // wall
      }
    }
  }
}

World::~World() {
  delete mapData_;
}


const unsigned World::getWidth() const {
  return width_;
}

const unsigned World::getHeight() const {
  return height_;
}

void World::putMapData(const unsigned x, const unsigned y, const unsigned value){
  mapData_[x + y*width_] = value;
}

const unsigned World::getMapData(const unsigned x, const unsigned y) const {
  return mapData_[x + y*width_];
}
