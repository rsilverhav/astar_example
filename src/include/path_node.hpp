#ifndef path_node_hpp
#define path_node_hpp

#include "point.hpp"

#include <vector>

/**
 *  PathNode objects are used to represent a tile in the 2D grid.
 */
class PathNode {

  public:
    PathNode(PathNode* parent, unsigned int posX, unsigned int posY, int gCost, int hCost);

    /**
     * Sets the path from this node the start, excluding the start node
     */
    int setBufferToPath(std::vector<Point>& path);

  PathNode* getParent();

  void updateNode(PathNode* parent, const unsigned int posX, const unsigned int posY, const int gCost, const int hCost);

  const unsigned int getPosX() const;

  const unsigned int getPosY() const;

  const int getGCost() const;

  const int getHCost() const;

  const float getFCost() const;

  bool isEqual(const Point& other) const;

  private:
    PathNode* parent_;
    unsigned int posX_;
    unsigned int posY_;
    int gCost_;
    int hCost_;
};

#endif // path_node_hpp
