#ifndef world_hpp
#define world_hpp

class World{
  public:
    World(const unsigned width, const unsigned height);
    ~World();
    const unsigned getWidth() const;
    const unsigned getHeight() const;
    void putMapData(const unsigned x, const unsigned y, const unsigned value);
    const unsigned getMapData(const unsigned x, const unsigned y) const;

  private:
    const unsigned width_;
    const unsigned height_;
    unsigned* mapData_;
}; // class World

#endif // world_hpp
