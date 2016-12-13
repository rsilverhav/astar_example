#ifndef simple_world_renderer_hpp
#define simple_world_renderer_hpp

#include "world_renderer_interface.hpp"

/*
 * SimpleWorldRenderer is a simple renderer that only prints the world in ascii-code in the terminal.
 */

class SimpleWorldRenderer : public Interface::WorldRendererInterface{
  public:
    SimpleWorldRenderer();
    ~SimpleWorldRenderer();

    virtual void renderWorld(const unsigned int width, const unsigned int height, const World& world, const std::vector<Point> path, const Point& start, const Point& target) const;

    int isPointInPath(const unsigned int x, const unsigned int y, const std::vector<Point> path) const;

}; // class SimpleWorldRenderer

#endif // simple_world_renderer_hpp
