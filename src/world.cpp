#include "world.hpp"

#include <fstream>
#include <sstream>

World::World(const unsigned int width, const unsigned int height, const std::string worldFileName) 
: width_(width),
  height_(height),
  mapData_(new unsigned int[width_ + height_*width_]) {
  loadWorldFromFile(worldFileName);
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
  return getMapData(x, y) == 1;
}


void World::loadWorldFromFile(const std::string fileName) {

  std::ifstream infile(fileName);

  std::string line;
  unsigned int y = 0;

  while (std::getline(infile, line))
  {
    std::istringstream iss(line);
    unsigned int x = 0;
    for(char& c : line) {
      if(c == '1') {
        putMapData(x, y, 1u); // adding a wall
      } else {
        putMapData(x, y, 0u); // adding a wall
      }
      x++;
    }
    y++;
  }
}
