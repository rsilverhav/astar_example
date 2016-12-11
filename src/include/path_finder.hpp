#ifndef path_finder_hpp
#define path_finder_hpp

class PathFinder {
  public:
    PathFinder();

    int findPath(const int nStartX, const int nStartY,
                 const int nTargetX, const int nTargetY, 
                 const unsigned char* pMap, const int nMapWidth, const int nMapHeight,
                 int* pOutBuffer, const int nOutBufferSize);

  private:
    int calcHCost(const int fromX, const int fromY, const int nTargetX, const int nTargetY);
    bool isValidTile(const int posX, const int posY, const int nMapWidth, const int nMapHeight, const unsigned char* pMap);
};


#endif // path_finder_hpp
