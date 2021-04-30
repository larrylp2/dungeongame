//
// Created by Larry Peng on 4/18/21.
//

#pragma once

#include <vector>
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
   * Displays a player.
   */
  void Display() const;

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


 private:
  // The current room of the player
  Room* current_room_;

  // The row of the player
  size_t row_;

  // The col of the player
  size_t col_;

  // The inventory of the player
  std::vector<Item*> inventory_;

};

}