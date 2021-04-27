//
// Created by Larry Peng on 4/18/21.
//

#pragma once

#include <vector>
#include <tuple>
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
   * @param height the height of the room
   * @param width the width of the room
   * @param margin the margin between room edges and the window edges
   * @param order the order of the room within a level
   */
  Room(double height, double width, double margin, size_t order);

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
  //void AddPortal(Portal& portal);

  /**
   * Gets the obstacles within the room
   */
  std::vector<std::vector<Obstacle>> GetObstacles() const;

  /**
   * Gets the portals within the room
   */
  //std::vector<std::vector<Portal>> GetPortals() const;

  /**
   * Gets the grid side size
   */
  double GetGridSize() const;

  /**
   * Gets the index of this room within a level
   */
  size_t GetOrder() const;


  /**
   * Gets the height of this room
   *
   * @return the height
   */
  size_t GetHeight() const;


  /**
   * Gets the width of this room
   *
   * @return the width
   */
  size_t GetWidth() const;

 private:
  //The obstacles within this room
  std::vector<std::vector<Obstacle>> obstacles_; //Use obstacle pointers

  //The portals within this room
  //std::vector<std::vector<Portal>> portals_;

  //The width of this room in grid positions
  size_t width_;

  //The height of this room in grid positions
  size_t height_;

  //The side length of one grid square
  double kGridSide = 40;

  //The margin from this room to the edge of the game window
  double margin_;

  //The order this room is within the level
  size_t order_;
};


}