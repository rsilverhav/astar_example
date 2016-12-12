#include "path_finder.hpp"
#include "path_node.hpp"
#include "point.hpp"
#include "simple_world_renderer.hpp"
#include "world.hpp"

#include <iostream>
#include <vector>

int main( int argc, const char* argv[] ) {

  const unsigned int worldWidth = 10;
  const unsigned int worldHeight = 10;

  SimpleWorldRenderer worldRenderer;
  World world(worldWidth, worldHeight);

  PathNode pathNode(nullptr, 1, 1, 0, 14);
  
  const Point start = {1, 1};
  const Point target = {8, 1};
  const unsigned int maxLength = 25;

  std::vector<Point> path;
  PathFinder pathFinder;

  pathFinder.findPath(start, target, world, worldWidth, worldHeight, path, maxLength);


  worldRenderer.renderWorld(worldWidth, worldHeight, world, path, start, target);

  //PathFinder pathFinder(&worldRenderer);
}
