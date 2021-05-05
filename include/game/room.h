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
#include <time.h>
#include <random>

namespace finalproject {

/**
 * Class that represents a room within the game that the player can explore.
 */
class Room {
 public:
  /**
   * Constructor for a room of a certain size.
   *
   * @param height the height of the room
   * @param width the width of the room
   * @param margin the margin between room edges and the window edges
   * @param order the order of the room within a level
   * @param window_height the height of the window
   * @param window_width the width of the window
   */
  Room(double height, double width, double margin, size_t order, double window_height, double window_width);

  /**
   * Destructor for a room.
   */
  ~Room();

  /**
   * Displays the room within the game.
   */
  void Display();

  /**
   * Displays the player's health bar.
   */
  void DisplayHealth() const;

  /**
   * Adds an obstacle to this room.
   *
   * @param row the row of the obstacle
   * @param col the column fo the obstacle
   */
  void DesignateObstacle(size_t row, size_t col);

  /**
   * Gets the obstacles within the room.
   */
  std::vector<std::vector<Obstacle*>> GetObstacles() const;

  /**
   * Gets the items within the room.
   */
  std::vector<std::vector<Item*>> GetItems() const;

  /**
   * Gets the enemies within the room.
   */
  std::vector<std::vector<Enemy*>> GetEnemies() const;

  /**
   * Exectues the movements and attacks of enemies within the room.
   */
  void ExecuteEnemyActions();

  /**
   * Helper method that adds an enemy to an existing 2d vector of enemies.
   * Resolving potential conflicts if two enemies want to move to the save square.
   *
   * @param enemy the enemy to add
   * @param enemy_loc the 2D vector of other enemies locations
   * @param row the row
   * @param col the col
   * @return a boolean if the enemy's move coordinates were within the grid
   */
  bool AddEnemyTo2DVector(Enemy* enemy, std::vector<std::vector<Enemy*>>& enemy_loc, size_t row, size_t col);

  /**
   * Adds an item to the room at a certain position.
   *
   * @param item the item to add to the room
   * @param row the row of the item
   * @param col the column of the item
   */
  void AddItem(Item* item, size_t row, size_t col);

  /**
   * Adds an enemy to the room at a certain position.
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
   * Removes an item from the room.
   *
   * @param row the row location of the item
   * @param col the col location of the item
   */
  void RemoveItem(size_t row, size_t col);

  /**
   * Removes a projectile from the room.
   *
   * @param index the projectile to remove
   */
  void RemoveProj(size_t index);

  /**
   * Gets the grid side size
   */
  double GetGridSize() const;

  /**
   * Gets the index of this room within a level.
   */
  size_t GetOrder() const;

  /**
   * Updates the player's saved location.
   *
   * @param row the player's row
   * @param col the player's col
   */
  void UpdatePlayerLocation(size_t row, size_t col);

  /**
   * Updates the player's health within the room.
   *
   * @param max the player's maximum health
   * @param current the player's current health
   * @param player_vit the player's vit
   */
  void UpdatePlayerHealth(size_t max, size_t current, size_t player_vit);


  /**
   * Gets the height of this room.
   *
   * @return the height
   */
  size_t GetHeight() const;


  /**
   * Gets the width of this room.
   *
   * @return the width
   */
  size_t GetWidth() const;


  /**
   * Gets the player's max hp.
   *
   * @return maximum health
   */
  size_t GetMax() const;

  /**
   * Gets the player's current hp.
   *
   * @return current health
   */
  size_t GetCurrent() const;

  /**
   * Marks a location occupied within the room.
   *
   * @param row the row to be occupied
   * @param col the col to be occupied
   */
  void MarkOccupied(size_t row, size_t col);

  /**
   * Marks a location unoccupied within the room.
   *
   * @param row the row to be vacant
   * @param col the col to be vacant
   */
  void MarkVacant(size_t row, size_t col);

 private:
  /**
  * Checks and resizes vector of projectile pointers.
  */
  void CleanProjectiles();

  /**
   * Checks projectile collisions.
   */
  void CheckProjectileCollisions();

  //The obstacles within this room
  std::vector<std::vector<Obstacle*>> obstacles_;

  //The items within this room
  std::vector<std::vector<Item*>> items_;

  //The enemies within this room
  std::vector<std::vector<Enemy*>> enemies_;

  //The projectiles within the room
  std::vector<Projectile*> projectiles_;

  //The occupied squares in the room, used to prevent assignment of multiple entities to same location
  std::vector<std::vector<bool>> occupied_;

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

  //Keeps track of the player's row within the room (for projectiles)
  size_t player_row_ = 0;

  //Keeps track of the player's col within the room (for projectiles)
  size_t player_col_ = 0;

  //Keeps track of the player's maximum health within the room (for projectiles)
  size_t player_max_hp_;

  //Keeps track of the player's current health within the room (for projectiles
  size_t player_curr_hp_;

  //Tracks player's vitality
  size_t player_vit_;

  //The height of the game window
  double window_height_;

  //The width of the game window
  double window_width_;
};

} // namespace finalproject