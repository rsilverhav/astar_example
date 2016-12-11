#ifndef path_finder_hpp
#define path_finder_hpp

#include "point.hpp"

class PathFinder {
  public:
    PathFinder();

    /**
     * Find the shortest path between two points in a 2D grid with obstacles. Movement is restricted to horizontal and vertical only (no diagonal).
     */
    int findPath(const Point start,
                 const Point target,
                 const unsigned char* pMap, const int nMapWidth, const int nMapHeight,
                 int* pOutBuffer, const int nOutBufferSize);

  private:
    int calcHCost(const int fromX, const int fromY, const int nTargetX, const int nTargetY);
    bool isValidTile(const int posX, const int posY, const int nMapWidth, const int nMapHeight, const unsigned char* pMap);
};


#endif // path_finder_hpp
