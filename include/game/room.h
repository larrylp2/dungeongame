//
// Created by Larry Peng on 4/18/21.
//

#pragma once

#include <vector>
#include <tuple>
#include "entity/portal.h"
#include "entity/obstacle.h"

namespace finalproject {

/**
 * Class that represents a room within the game that the player can explore.
 * (need to adjust entities/portals to fit onto tiles to make easier)
 */
class Room {
 public:
  /**
   * Default constructor for a room
   */
  Room();

  /**
   * Constructor for a room of a certain size
   * @param width the width of the room
   * @param height the height of the room
   * @param margin the margin between room edges and the window edges
   */
  Room(double width, double height, double margin);

  /**
   * Displays the room within the game
   */
  void Display() const;

  /**
   * Adds an obstacle to this room
   *
   * @param obstacle to add
   */
  void DesignateObstacles(const std::vector<std::tuple<size_t, size_t>>& coordinates);


  /**
   * Adds a portal to this room
   *
   * @param portal the portal to add to this room
   */
  void AddPortal(Portal& portal);

  /**
   * Gets the obstacles within the room
   */
  std::vector<std::vector<Obstacle>> GetObstacles() const;

  /**
   * Gets the portals within the room
   */
  std::vector<std::vector<Portal>> GetPortals() const;

  /**
   * Gets the grid side size
   */
  double GetGridSize() const;

 private:
  //The obstacles within this room
  std::vector<std::vector<Obstacle>> obstacles_;

  //The portals within this room
  std::vector<std::vector<Portal>> portals_;

  //The width of this room in grid positions
  double width_;

  //The height of this room in grid positions
  double height_;

  //The side length of one grid square
  double kGridSide = 40;

  //The margin from this room to the edge of the game window
  double margin_;
};


}