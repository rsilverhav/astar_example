#include "simple_world_renderer.hpp"

#include <iostream>

SimpleWorldRenderer::SimpleWorldRenderer() {

}

void SimpleWorldRenderer::renderWorld(const int width, const int height, const World& world, std::vector<Point> path) const {
  for(unsigned int y = 0; y < height; ++y) {
    for(unsigned int x = 0; x < width; ++x) {

      const unsigned int index = x + y*width;
      int pointIndex = isPointInPath(x, y, path);

      if(pointIndex == 0){
        std::cout << "S ";
      } else if(pointIndex == path.size() - 1) {
        std::cout << "E ";
      } else if(pointIndex > 0) {
        std::cout << "o ";
      } else {
        // if the maps contains a wall
        if(world.getMapData(x, y) == 0u) {
          std::cout << "# ";
          // if the maps contains a floor
        } else if (world.getMapData(x, y) == 1u) {
          std::cout << "  ";
        }
      }
    }
    std::cout << std::endl;
  }

}

int SimpleWorldRenderer::isPointInPath(const unsigned int x, const unsigned int y, const std::vector<Point> path) const {
  for(int index = 0; index < path.size(); ++index) {
    if(path.at(index).getX() == x && path.at(index).getY() == y) {
      return index;
    }
  }
  return -1;
}
