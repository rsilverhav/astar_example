#ifndef world_renderer_interface_hpp
#define world_renderer_interface_hpp

#include "point.hpp"
#include "world.hpp"

#include <vector>

namespace Interface {
  
/*
 * WorldRendererInterface is an interface that is used for rendering the world that is used for the pathfinding.
 * This could be used to render the world in 3D or 2D using OpenGL or just with ascii-code in the terminal for simple debug output.
 */
class WorldRendererInterface {
  public:
    /*
     * Is called to print the world when a path has been found from StartPoint to EndPoint.
     */
    virtual void renderWorld(const unsigned int width, const unsigned int height, const World& world, const std::vector<Point> path) const = 0;

}; // class WorldRendererInterface

} // namespace Interface


#endif // world_renderer_interface_hpp
