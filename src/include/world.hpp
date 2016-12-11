#ifndef world_hpp
#define world_hpp

class World{
  public:
    World(const unsigned int width, const unsigned int height);

    ~World();

    const unsigned int getWidth() const;

    const unsigned int getHeight() const;

    void putMapData(const unsigned int x, const unsigned int y, const unsigned int value);

    const unsigned int getMapData(const unsigned int x, const unsigned int y) const;

  private:
    const unsigned int width_;
    const unsigned int height_;
    unsigned int* mapData_;
}; // class World

#endif // world_hpp
