#ifndef path_node_hpp
#define path_node_hpp

/**
 *  PathNode objects are used to represent a tile in the 2D grid.
 */
class PathNode {

  public:
    PathNode(PathNode* parent, int posX, int posY, int gCost, int hCost);

    /**
     * Sets the path from this node the start, excluding the start node
     */
    int setBufferToPath(int** pOutBuffer, const int nMapWidth, const int nStartX, const int nStartY);

  PathNode* getParent();

  void updateNode(PathNode* parent, const int posX, const int posY, const int gCost, const int hCost);

  const int getPosX() const;

  const int getPosY() const;

  const int getGCost() const;

  const int getHCost() const;

  const float getFCost() const;


  private:
    PathNode* parent_;
    int posX_;
    int posY_;
    int gCost_;
    int hCost_;
};

#endif // path_node_hpp
