//
// Created by Larry Peng on 4/18/21.
//

#pragma once

#include <vector>
#include <tuple>
#include "entity/obstacle.h"
#include "game/item.h"
#include "entity/enemy.h"
#include "entity/projectile.h"

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
  void Display();

  /**
   * Adds an obstacle to this room
   *
   * @param obstacle to add
   */
  void DesignateObstacles(const std::vector<std::tuple<size_t, size_t>>& coordinates);

  /**
   * Gets the obstacles within the room
   */
  std::vector<std::vector<Obstacle*>> GetObstacles() const;

  /**
   * Gets the items within the room
   */
  std::vector<std::vector<Item*>> GetItems() const;

  /**
   * Gets the enemies within the room
   */
  std::vector<std::vector<Enemy*>> GetEnemies() const;

  /**
   * Adds an item to the room at a certain position
   *
   * @param item the item to add to the room
   * @param row the row of the item
   * @param col the column of the item
   */
  void AddItem(Item* item, size_t row, size_t col);

  /**
   * Adds an enemy to the room at a certain position
   *
   * @param enemy the enemy to add to the room
   * @param row the row of the item
   * @param col the column of the item
   */
  void AddEnemy(Enemy* enemy, size_t row, size_t col);

  /**
   * Ads a projectile to the room.
   *
   * @param projectile the projectile to add to the room
   */
  void AddProjectile(Projectile* proj);

  /**
   * Removes an item from the room
   *
   * @param row the row location of the item
   * @param col the col location of the item
   */
  void RemoveItem(size_t row, size_t col);

  /**
   * Removes a projectile from the room
   *
   * @param index the projectile to remove
   */
  void RemoveProj(size_t index);

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
  std::vector<std::vector<Obstacle*>> obstacles_;

  //The items within this room
  std::vector<std::vector<Item*>> items_;

  //The enemies within this room
  std::vector<std::vector<Enemy*>> enemies_;

  //The projectiles within the room
  std::vector<Projectile*> projectiles_;

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