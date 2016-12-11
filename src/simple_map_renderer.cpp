#include "simple_map_renderer.hpp"

#include <iostream>

SimpleMapRenderer::SimpleMapRenderer() {

}

void SimpleMapRenderer::renderMap(const int width, const int height) {
  for(unsigned y = 0; y < height; ++y) {
    for(unsigned x = 0; x < width; ++x) {
      std::cout << "#";
    }
    std::cout << std::endl;
  }

}
