#include "path_node.hpp"

PathNode::PathNode(PathNode* parent, int posX, int posY, int gCost, int hCost) : parent_(parent), posX_(posX), posY_(posY), gCost_(gCost), hCost_(hCost) {

}


int PathNode::setBufferToPath(int** pOutBuffer, const int nMapWidth, const int nStartX, const int nStartY) {
  PathNode* currentNode = this;
  int distance = getGCost();
  while(currentNode->getParent() != 0){
    (*pOutBuffer)[currentNode->getGCost()-1] = currentNode->getPosX() + currentNode->getPosY()*nMapWidth;
    currentNode = currentNode->getParent();
  }
  return distance;
}

PathNode* PathNode::getParent() {
  return parent_;
}

void PathNode::updateNode(PathNode* parent, const int posX, const int posY, const int gCost, const int hCost){
  parent_ = parent;
  posX_ = posX;
  posY_ = posY;
  gCost_ = gCost;
  hCost_ = hCost;
}

const int PathNode::getPosX() const{
  return posX_;
}

const int PathNode::getPosY() const{
  return posY_;
}

const int PathNode::getGCost() const{
  return gCost_;
}

const int PathNode::getHCost() const{
  return hCost_;
}

const float PathNode::getFCost() const{
  return gCost_ + hCost_;
}
