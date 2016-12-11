#ifndef point_hpp
#define point_hpp

class Point{
  public:
    Point(const unsigned int x, const unsigned int y);

    const unsigned int getX() const;

    const unsigned int getY() const;

  private:
    unsigned int x_;
    unsigned int y_;
}; // class Point

#endif // point_hpp
