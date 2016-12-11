#include "simple_world_renderer.hpp"

#include <iostream>

SimpleWorldRenderer::SimpleWorldRenderer() {

}

void SimpleWorldRenderer::renderWorld(const int width, const int height, const World& world) const {
  for(unsigned y = 0; y < height; ++y) {
    for(unsigned x = 0; x < width; ++x) {
      const unsigned index = x + y*width;
      
      // if the maps contains a wall
      if(world.getMapData(x, y) == 0u) {
        std::cout << "#";
      // if the maps contains a floor
      } else if (world.getMapData(x, y) == 1u) {
        std::cout << " ";
      }
    }
    std::cout << std::endl;
  }

}
