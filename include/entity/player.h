//
// Created by Larry Peng on 4/18/21.
//

#pragma once

#include <vector>
#include "game/item.h"
#include "game/room.h"
#include "entity/portal.h"

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
   * Moves the player up.
   */
  void MoveUp();

  /**
   * Moves the player down.
   */
  void MoveDown();

  /**
   * Moves the player left.
   */
  void MoveLeft();

  /**
   * Moves the player right.
   */
  void MoveRight();

  /**
   * Displays a player.
   */
  void Display() const;

  /**
   * Updates the player's location.
   *
   * @param location the player's new location
   */
  void UpdateLocation(glm::vec2 location);

  /**
   * Retrieves the player's location.
   *
   * @return the player's location
   */
  glm::vec2 GetLocation() const;

  /**
   * Retrieves the player's speed.
   *
   * @return the player's speed
   */
  double GetSpeed() const;

  /**
   * Handles player interaction with a portal, updating player location and returning new room.
   */
  void Interact(const Portal& portal);


 private:
  // The current room of the player
  Room current_room_;

  // The inventory of the player
  std::vector<Item> inventory_;

  // The current location of the player
  glm::vec2 location_;

  // The speed of the player (temporary default value 10)
  double speed_ = 10;

};

}