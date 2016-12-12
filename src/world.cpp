#include "world.hpp"

World::World(const unsigned int width, const unsigned int height) 
: width_(width),
  height_(height),
  mapData_(new unsigned int[width_ + height_*width_]) {
  for(unsigned int y = 0; y < height_; ++y) {
    for(unsigned int x = 0; x < width; ++x) {
      if(x == 0 || y == 0 || x == width_-1 || y == height_-1) {
        putMapData(x, y, 0u); // wall
      } else {
        putMapData(x, y, 1u); // floor
      }
    }
  }

  for(unsigned int index = 1; index < 3; ++index) {
    putMapData(5, index, 0u); // wall
  }
}

World::~World() {
  delete mapData_;
}


const unsigned int World::getWidth() const {
  return width_;
}

const unsigned int World::getHeight() const {
  return height_;
}

void World::putMapData(const unsigned int x, const unsigned int y, const unsigned int value){
  mapData_[x + y*width_] = value;
}

const unsigned int World::getMapData(const unsigned int x, const unsigned int y) const {
  return mapData_[x + y*width_];
}

const bool World::isWall(const unsigned int x, const unsigned int y) const {
  return getMapData(x, y) == 0;
}
