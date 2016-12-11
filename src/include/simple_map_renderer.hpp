#ifndef simple_map_renderer_hpp
#define simple_map_renderer_hpp

#include "map_renderer_interface.hpp"

/*
 * SimpleMapRenderer is a simple renderer that only prints the map in ascii-code in the terminal.
 */

class SimpleMapRenderer : public Interface::MapRendererInterface{
  public:
    SimpleMapRenderer();
    virtual void renderMap(const int width, const int height);

}; // class SimpleMapRenderer

#endif // map_renderer_interface_hpp
