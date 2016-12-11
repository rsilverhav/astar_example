#ifndef map_renderer_interface_hpp
#define map_renderer_interface_hpp

namespace Interface {
  
/*
 * MapRendererInterface is an interface that is used for rendering the map that is used for the pathfinding.
 * This could be used to render the map in 3D or 2D using OpenGL or just with ascii-code in the terminal for simple debug output.
 */
class MapRendererInterface {
  public:
    /*
     * Is called to print the map when a path has been found from StartPoint to EndPoint.
     */
    virtual void renderMap(const int width, const int height) = 0;

}; // class MapRendererInterface

} // namespace Interface


#endif // map_renderer_interface_hpp
