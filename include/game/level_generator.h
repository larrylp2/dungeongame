//
// Created by Larry Peng on 5/4/21.
//

#pragma once
#include "game/level.h"
#include "entity/enemy.h"
#include "entity/gate.h"

namespace finalproject {

/**
 * Class that helps randomly generate levels
 */
class LevelGenerator {
public:
  /**
   * Constructor for a LevelGenerator.
   *
   * @param window_width the width of the cinder app window
   * @param window_height the height of the cinder app window
   * @param grid_margin the length of one grid square in the game
   */
  LevelGenerator(double window_width, double window_height, double grid_margin);

  /**
   * Generates a level for the game.
   *
   * @return the generated level
   */
  Level* GenerateLevel() const;

private:
  //The number of rooms within each level
  size_t kLevelSize = 10;

  /**
   * Generates Rooms for a level.
   *
   * @param level the level to generate rooms
   */
  void GenerateRooms(Level* level) const;

  /**
   * Generates Portals for a level.
   *
   * @param level the level to generate portals
   */
  void GeneratePortals(Level* level) const;

  /**
   * Generates Enemies for a level.
   *
   * @param level the level to generate enemies
   */
  void GenerateEnemies(Level* level) const;

  /**
   * Generates Obstacles for a level.
   *
   * @param level the level to generate obstacles
   */
  void GenerateObstacles(Level* level) const;

  /**
   * Generates Items for a level.
   *
   * @param level the level to generate items
   */
  void GenerateItems(Level* level) const;

  //The width of the cinder app window
  double window_width_;

  //The height of the cinder app window
  double window_height_;

  //The length of a grid within the game
  double grid_margin_;

};

} // namespace finalproject