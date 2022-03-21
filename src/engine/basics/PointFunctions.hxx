#ifndef POINTFUNCTIONS_HXX_
#define POINTFUNCTIONS_HXX_

#include "point.hxx"
#include "../../util/LOG.hxx"
#include "betterEnums.hxx"
#include <vector>

BETTER_ENUM(NeighbourNodesPosition, unsigned char, BOTOM_LEFT = 1U << 6, LEFT = 1U << 2, TOP_LEFT = 1U << 4, BOTTOM = 1U << 1,
            CENTAR = 0U, TOP = 1U, BOTOM_RIGHT = 1U << 7, RIGHT = 1U << 3, TOP_RIGHT = 1U << 5);


class PointFunctions
{
public:
  /** \brief Creates a line between two points using the Bresenham Line algorithm
* Creates a line between two points using the Bresenham Line algorithm
* @param Point() - start coordinates
* @param Point() - end coordinates
* @return std::vector<Point>() - contains coordinates for each tile between start and end coordinates, including start and end
*/
  static std::vector<Point> getLine(Point isoCoordinatesStart, Point end);

  /** \brief Gets all nodes in a straight line from start and end point
* Gets all nodes in a straight line between start and end point
* @param Point() - start coordinates
* @param Point() - end coordinates
* @return std::vector<Point>() - contains coordinates for each tile between start and end coordinates, including start and end
*/
  static std::vector<Point> getStraightLine(const Point &isoCoordinatesStart, const Point &isoCoordinatesEnd);

  /** \brief Gets all nodes in a rectangular area between start and end point
* Gets all nodes in a rectangle between start and end point
* @param Point() - start coordinates
* @param Point() - end coordinates
* @return std::vector<Point>() - contains coordinates for each tile between start and end coordinates, including start and end
*/
  static std::vector<Point> getArea(const Point &isoCoordinatesStart, const Point &isoCoordinatesEnd);

  /** \brief Get all neighboring coordinate from provided map node isocoordinate.
  * @param isoCoordinates iso coordinates.
  * @param includeCentralNode if set to true include the central node in the result.
  * @return std::vector<Point>() - All neighboring node coordinates.
  */
  static std::vector<Point> getNeighbors(const Point &isoCoordinates, const bool includeCentralNode);

    /** \brief Get all neighboring coordinate from provided map node isocoordinate.
  * @param isoCoordinates iso coordinates.
  * @param includeCentralNode if set to true include the central node in the result.
  * @return std::vector<Point>() - All neighboring node coordinates.
  */
  static NeighbourNodesPosition getNeighborPositionToOrigin(const Point &neighboringPoint, const Point &originPoint);
};

#endif