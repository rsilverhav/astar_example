#include "path_finder.hpp"
#include "path_node.hpp"

#include <queue>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
#include <memory>

using namespace std;

PathFinder::PathFinder() {
}

int PathFinder::findPath(const int nStartX, const int nStartY,
    const int nTargetX, const int nTargetY, 
    const unsigned char* pMap, const int nMapWidth, const int nMapHeight,
    int* pOutBuffer, const int nOutBufferSize)
{


  priority_queue<pair<int, shared_ptr<PathNode>>, vector<pair<int, shared_ptr<PathNode>>>, std::greater<pair<int, shared_ptr<PathNode>>>> searchQueue;

  map<int, shared_ptr<PathNode>> openSet;
  map<int, shared_ptr<PathNode>> closedSet;


  if(pOutBuffer == 0){
    return -1;
  }

  if(nStartX == nTargetX && nStartY == nTargetY){
    return -1;
  }


  int xLimMin, xLimMax, checkPosX, checkPosY, index;

  shared_ptr<PathNode> addNode = make_shared<PathNode>(nullptr, nStartX, nStartY, 0, calcHCost(nStartX, nStartY, nTargetX, nTargetY));
  searchQueue.emplace(addNode->getFCost(), addNode);
  openSet[nStartX + nStartY*nMapWidth] = addNode;

  shared_ptr<PathNode> currentNodeShrPtr;
  PathNode* currentNode;

  while(!searchQueue.empty()){

    // getting the node with the lowest f-cose from the open set
    currentNodeShrPtr = searchQueue.top().second;
    currentNode = currentNodeShrPtr.get();
    searchQueue.pop();

    // adding the node that is currently being explored to the closed set
    closedSet[currentNode->getPosX() + currentNode->getPosY()*nMapWidth] = currentNodeShrPtr;

    // goal found, setting path and returning length
    if(currentNode->getPosX() == nTargetX && currentNode->getPosY() == nTargetY){
      int distance = currentNode->setBufferToPath(&pOutBuffer, nMapWidth, nStartX, nStartY);

      return distance;
    }


    // looping through neighbours
    for(int y = -1; y <= 1; y++){
      if(y == 0){
        xLimMin = -1;
        xLimMax = 1;
      }else{
        xLimMin = 0;
        xLimMax = 1;
      }
      for( int x = xLimMin; x <= xLimMax; x+=2){
        // calculates the position and the index of a neighbour
        checkPosX = currentNode->getPosX()+x;
        checkPosY = currentNode->getPosY()+y;
        index = checkPosX + checkPosY*nMapWidth;

        // if the neighbours position is valid and is not in the closed set, continue evaluating
        if(isValidTile(checkPosX, checkPosY, nMapWidth, nMapHeight, pMap) && closedSet.find(checkPosX + checkPosY*nMapWidth) == closedSet.end()){

          int newGCost = currentNode->getGCost() + 1;

          // ignore this neighbour if the distance is longer than max path length
          if(newGCost > nOutBufferSize){
            continue;
          }
          int newHCost = calcHCost(checkPosX, checkPosY, nTargetX, nTargetY);
          if(openSet.find(index) == openSet.end() || newGCost + newHCost < openSet[index]->getFCost()){
            addNode = make_shared<PathNode>(currentNode, checkPosX, checkPosY, newGCost, calcHCost(checkPosX, checkPosY, nTargetX, nTargetY));
  searchQueue.emplace(addNode->getFCost(), addNode);
            openSet[index] = addNode;
            searchQueue.emplace(addNode->getFCost(), addNode);
          }
        }
      }
    }

  }

  return -1;
}

/**
 *  Calculates the H-cost of a node using manhattan distance.
 *
 *  Returns: the manhattan distance between grid positions
 */
int PathFinder::calcHCost(const int fromX, const int fromY, const int nTargetX, const int nTargetY){
  return abs(nTargetX - fromX) + abs(nTargetY - fromY);
}

/**
 * Used to see if a path node can be created at a tile on the map
 *
 * Returns: true if posX and posY is inside the map and not on a wall
 */
bool PathFinder::isValidTile(const int posX, const int posY, const int nMapWidth, const int nMapHeight, const unsigned char* pMap){

  if((posX < 0 || posX >= nMapWidth) || (posY < 0 || posY >= nMapHeight) || pMap[posX+posY*nMapWidth] == 0){
    return false;
  }
  return true;

}