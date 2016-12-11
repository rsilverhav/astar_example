#ifndef point_hpp
#define point_hpp

class Point{
  public:
    Point(const unsigned x, const unsigned y);

    const unsigned getX() const;

    const unsigned getY() const;

  private:
    unsigned x_;
    unsigned y_;
}; // class Point

#endif // point_hpp
