#include "path_finder.hpp"
#include "path_node.hpp"
#include "point.hpp"
#include "simple_world_renderer.hpp"
#include "world.hpp"

#include <iostream>
#include <vector>

int main( int argc, const char* argv[] ) {

  const unsigned worldWidth = 10;
  const unsigned worldHeight = 10;

  SimpleWorldRenderer worldRenderer;
  World world(worldWidth, worldHeight);

  PathNode pathNode(nullptr, 1, 1, 0, 14);
  
  std::vector<Point> path;
  for(int i = 2; i < 5; ++i) {
    Point p(i, 3);
    path.push_back(p);
  }

  for(int i = 3; i < 7; ++i) {
    Point p(4, i);
    path.push_back(p);
  }

  PathFinder pathFinder;


  worldRenderer.renderWorld(worldWidth, worldHeight, world, path);

  //PathFinder pathFinder(&worldRenderer);
}
