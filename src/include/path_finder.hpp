#ifndef path_finder_hpp
#define path_finder_hpp

#include "point.hpp"
#include "world.hpp"

#include <vector>

class PathFinder {
  public:
    PathFinder();

    /**
     * Find the shortest path between two points in a 2D grid with obstacles. Movement is restricted to horizontal and vertical only (no diagonal).
     */
    int findPath(const Point start,
                 const Point target,
                 const World& world,
                 const unsigned int worldWidth,
                 const unsigned int worldHeight,
                 std::vector<Point>& path,
                 const unsigned int maxLength);

  private:
    int calcHCost(const int fromX, const int fromY, const int nTargetX, const int nTargetY);
    bool isValidTile(const int posX, const int posY, const int nMapWidth, const int nMapHeight, const World& world);
};


#endif // path_finder_hpp
