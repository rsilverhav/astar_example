#include "path_finder.hpp"
#include "path_node.hpp"
#include "point.hpp"
#include "simple_world_renderer.hpp"
#include "world.hpp"
#include "world_renderer_interface.hpp"

#include <iostream>
#include <vector>

int main( int argc, const char* argv[] ) {

  // Height and width are based on the map in the file
  const unsigned int worldWidth = 20;
  const unsigned int worldHeight = 20;

  const std::string worldFileName = "world.txt";

  // Creating a renderer from the WorldRendererInterface.
  Interface::WorldRendererInterface* worldRenderer = new SimpleWorldRenderer();

  World world(worldWidth, worldHeight, worldFileName);

  // setting start point and target
  const Point start = {1, 1};
  const Point target = {10, 15};
  std::vector<Point> path;

  // printing map witout path
  std::cout << std::endl << std::endl << "------ The world to solve ------" << std::endl << std::endl;
  worldRenderer->renderWorld(worldWidth, worldHeight, world, path, start, target);

  // some padding the rendering
  std::cout << std::endl << "-----------------------------------------" << std::endl;
  std::cout << "------ The world with closest path ------" << std::endl << std::endl;
  
  // max length just to be safe!
  const unsigned int maxLength = 64;

  // creates a pathfinder and sets the path in the vector 'path' from start to target
  PathFinder pathFinder;
  pathFinder.findPath(start, target, world, worldWidth, worldHeight, path, maxLength);

  // draws the map with the path
  worldRenderer->renderWorld(worldWidth, worldHeight, world, path, start, target);

  // cleaning up memory
  delete worldRenderer;

}
