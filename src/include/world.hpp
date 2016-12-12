#ifndef world_hpp
#define world_hpp

#include <string>

class World{
  public:
    World(const unsigned int width, const unsigned int height, const std::string worldFileName);

    ~World();

    const unsigned int getWidth() const;

    const unsigned int getHeight() const;

    void putMapData(const unsigned int x, const unsigned int y, const unsigned int value);

    const unsigned int getMapData(const unsigned int x, const unsigned int y) const;

    const bool isWall(const unsigned int x, const unsigned int y) const;

  private:
    const unsigned int width_;
    const unsigned int height_;
    unsigned int* mapData_;

    void loadWorldFromFile(const std::string fileName);
}; // class World

#endif // world_hpp
