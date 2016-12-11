#include "simple_map_renderer.hpp"

#include <iostream>

int main( int argc, const char* argv[] ) {
  SimpleMapRenderer mapRenderer;
  mapRenderer.renderMap(5, 5);
  return 0;
}
