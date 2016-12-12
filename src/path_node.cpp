#include "path_node.hpp"

PathNode::PathNode(PathNode* parent, unsigned int posX, unsigned int posY, int gCost, int hCost) : parent_(parent), posX_(posX), posY_(posY), gCost_(gCost), hCost_(hCost) {

}


int PathNode::setBufferToPath(std::vector<Point>& path) {
  PathNode* currentNode = this;
  int distance = getGCost();
  while(currentNode->getParent() != 0){
    path.push_back({currentNode->getPosX(), currentNode->getPosY()});
//(*pOutBuffer)[currentNode->getGCost()-1] = currentNode->getPosX() + currentNode->getPosY()*nMapWidth;
    currentNode = currentNode->getParent();
  }
  return distance;
}

PathNode* PathNode::getParent() {
  return parent_;
}

void PathNode::updateNode(PathNode* parent, const unsigned int posX, const unsigned int posY, const int gCost, const int hCost){
  parent_ = parent;
  posX_ = posX;
  posY_ = posY;
  gCost_ = gCost;
  hCost_ = hCost;
}

const unsigned int PathNode::getPosX() const{
  return posX_;
}

const unsigned int PathNode::getPosY() const{
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

bool PathNode::isEqual(const Point &other) const {
  return posX_ == other.getX() && posY_ == other.getY();
}
