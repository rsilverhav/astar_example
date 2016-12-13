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

int PathFinder::findPath(const Point start,
                         const Point target,
                         const World& world,
                         const unsigned int worldWidth,
                         const unsigned int worldHeight,
                         std::vector<Point>& path,
                         const unsigned int maxLength)
{


  // using a priority_queue for searchQueue as this will be really fast for getting the next node with the smallest cost
  priority_queue<pair<int, shared_ptr<PathNode>>, vector<pair<int, shared_ptr<PathNode>>>, std::greater<pair<int, shared_ptr<PathNode>>>> searchQueue;

  map<int, shared_ptr<PathNode>> openSet;
  map<int, shared_ptr<PathNode>> closedSet;


  if(start == target){
    return -1;
  }


  int xLimMin, xLimMax, checkPosX, checkPosY, index;

  // TODO: should be unique pointer, not shared pointer
  shared_ptr<PathNode> addNode = make_shared<PathNode>(nullptr, start.getX(), start.getY(), 0, calcHCost(start.getX(), start.getY(), target.getX(), target.getY()));
  searchQueue.emplace(addNode->getFCost(), addNode);
  openSet[start.getX() + start.getY()*worldWidth] = addNode;

  shared_ptr<PathNode> currentNodeShrPtr;
  PathNode* currentNode;

  while(!searchQueue.empty()){

    // getting the node with the lowest f-cose from the open set
    currentNodeShrPtr = searchQueue.top().second;
    currentNode = currentNodeShrPtr.get();
    searchQueue.pop();

    // adding the node that is currently being explored to the closed set
    closedSet[currentNode->getPosX() + currentNode->getPosY()*worldWidth] = currentNodeShrPtr;

    // goal found, setting path and returning length
    if(currentNode->isEqual(target)){
      int distance = currentNode->setBufferToPath(path);

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
        index = checkPosX + checkPosY*worldWidth;

        // if the neighbours position is valid and is not in the closed set, continue evaluating
        if(isValidTile(checkPosX, checkPosY, worldWidth, worldHeight, world) && closedSet.find(checkPosX + checkPosY*worldWidth) == closedSet.end()){

          int newGCost = currentNode->getGCost() + 1;

          // ignore this neighbour if the distance is longer than max path length
          if(newGCost > maxLength){
            continue;
          }
          int newHCost = calcHCost(checkPosX, checkPosY, target.getX(), target.getY());
          if(openSet.find(index) == openSet.end() || newGCost + newHCost < openSet[index]->getFCost()){
            addNode = make_shared<PathNode>(currentNode, checkPosX, checkPosY, newGCost, calcHCost(checkPosX, checkPosY, target.getX(), target.getY()));
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
  return fabs((float)nTargetX - fromX) + fabs((float)nTargetY - fromY);
}

/**
 * Used to see if a path node can be created at a tile on the map
 *
 * Returns: true if posX and posY is inside the map and not on a wall
 */
bool PathFinder::isValidTile(const int posX, const int posY, const int worldWidth, const int worldHeight, const World& world){

  if((posX < 0 || posX >= worldWidth) || (posY < 0 || posY >= worldHeight) || world.isWall(posX, posY)){
    return false;
  }
  return true;

}
