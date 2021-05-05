//
// Created by Larry Peng on 4/18/21.
//

#pragma once

#include "cinder/gl/gl.h"
#include "game/item.h"
#include "game/room.h"

namespace finalproject {

/**
 * Class that represents the player.
 */
class Player {
 public:
  /**
   * Default Constructor for a player class.
   */
  Player();

  /**
   * Destructor for a player
   */
  ~Player();

  /**
   * Displays a player.
   */
  void Display();

  /**
   * Updates the player's location.
   *
   * @param row how much to change the row by
   * @param col how much to change the col by
   */
  void UpdateLocation(size_t row, size_t col);

  /**
   * Updates the player's current room.
   *
   * @param room the current room of the player
   */
  void UpdateRoom(Room* room);

  /**
   * Adds an item to the player's inventory, updating stats (need to implement)
   *
   * @param item the item the player gains
   */
  void AddItem(Item* item);

  /**
   * Get player column.
   *
   * @return the player's column location
   */
  size_t GetCol() const;

  /**
   * Get player row.
   *
   * @return the player's row location
   */
  size_t GetRow() const;

  /**
   * Gets the player's inventory
   *
   * @return the player's inventory
   */
  std::vector<Item*> GetInventory() const;

  /**
   * Fires a projectile.
   *
   * @param direction the direction to do the attack
   */
  void FireProjectile(size_t direction) const;

  /**
   * Gets the player's max health
   *
   * @return the max hp
   */
  size_t GetMaxHp() const;

  /**
   * Gets the player's current health
   *
   * @return the current h[
   */
  size_t GetCurrHp() const;

  /**
   * Gets the player's vitality
   *
   * @return the vit
   */
  size_t GetPlayerVit() const;

 private:
  //The current room of the player
  Room* current_room_;

  //The row of the player
  size_t row_;

  //The col of the player
  size_t col_;

  //The inventory of the player
  std::vector<Item*> inventory_;

  //The player's maximum health
  size_t max_health_;

  //The player's current health
  size_t current_health_;

  //The player's attack damage
  size_t attack_;

  //The player's range
  size_t range_;

  //The player's shot speed
  size_t shot_;

  //The players vitality (how much is healed from defeating enemies)
  size_t vitality_;

};

} // namespace finalproject