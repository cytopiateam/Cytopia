#ifndef POINT_HXX_
#define POINT_HXX_

#include "Settings.hxx"
class Point
{
public:
constexpr Point() : x(0), y(0), z(0), height(0) { };
constexpr Point(int x, int y) : x(x), y(y), z(0), height(0) { };
constexpr Point(int x, int y, int z) : x(x), y(y), z(z), height(0) { };
constexpr Point(int x, int y, int z, int height) : x(x), y(y), z(z), height(height) { };
  /// The x coordinate.
  int x;

  /// The y coordinate.
  int y;

  /// The z coordinate.
  int z;

  /// The height level.
  int height;

  //TODO: need to add z axis in the future, currently it is not supported.
  bool operator==(const Point &p) const { return x == p.x && y == p.y /*&& z == p.z*/; }
  bool operator!=(const Point &p) const { return !(*this == p); }

  static constexpr Point INVALID() { return {-1, -1, -1, -1}; }

  bool isWithinMapBoundaries() const
  {
    return (x >= 0 && x < Settings::instance().mapSize) && (y >= 0 && y < Settings::instance().mapSize);
  }
};

#endif
