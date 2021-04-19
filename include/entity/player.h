//
// Created by Larry Peng on 4/18/21.
//

#pragma once

#include <vector>
#include "entity/entity.h"
#include "game/item.h"
#include "game/room.h"

namespace finalproject {

namespace entity {

class Player: public entity::Entity {
 public:
  /**
   * Default Constructor for a player class.
   */
  Player();

  /**
   * Moves the player up
   */
  void MoveUp();

  /**
   * Moves the player down
   */
  void MoveDown();

  /**
   * Moves the player left
   */
  void MoveLeft();

  /**
   * Moves the player right
   */
  void MoveRight();

  /**
   * Displays a player
   */
  void Display() const;

 private:
  // The current room of the player
  game::Room current_room_;

  // The inventory of the player
  std::vector<game::Item> inventory_;

  // The current location of the player
  glm::vec2 location_;

  // The speed of the player (temporary default value 10)
  double speed_ = 10;

};


}


}