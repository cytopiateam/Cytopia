#pragma once

#ifndef POINT_HXX_
#define POINT_HXX_

class Point
{
public:
  /**
   * The x coordinate.
   */
  int x;

  /**
   * The y coordinate.
   */
  int y;

  /**
   * The z coordinate.
   */
  int z;

  /**
   * The height level.
   */
  int height;

  bool operator==(const Point& p) { return x == p.x && y == p.y && z == p.z && height == p.height; }
  bool operator!=(const Point &p) { return !(*this == p); }
};

const Point UNDEFINED_POINT = {-1, -1, -1, -1};

#endif