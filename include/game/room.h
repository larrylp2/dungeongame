//
// Created by Larry Peng on 4/18/21.
//

#pragma once

#include <vector>
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
  void AddObstacle(const Obstacle& obstacle);

  /**
   * Checks if there is an obstacle near a location.
   *
   * @param location the location to check
   * @return a boolean if there is an obstacle at that location within the room
   */
  bool CheckObstacle(const glm::vec2& location) const;

  /**
   * Adds a portal to this room
   *
   * @param portal the portal to add to this room
   */
  void AddPortal(Portal& portal);

  /**
   * Gets the portals within the room
   */
  std::vector<Portal> GetPortals() const;

 private:
  //The obstacles within this room
  std::vector<Obstacle> obstacles_;

  //The portals within this room
  std::vector<Portal> portals_;

  //The width of this room
  double width_;

  //The height of this room
  double height_;

  //The margin from this room to the edge of the game window
  double margin_;
};


}