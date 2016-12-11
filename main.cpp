#include "simple_world_renderer.hpp"
#include "world.hpp"

#include <iostream>

int main( int argc, const char* argv[] ) {

  const unsigned worldWidth = 10;
  const unsigned worldHeight = 10;

  SimpleWorldRenderer worldRenderer;
  World world(worldWidth, worldHeight);


  worldRenderer.renderWorld(worldWidth, worldHeight, world);

  //PathFinder pathFinder(&worldRenderer);
  return 0;
}
