//
// Created by Larry Peng on 4/18/21.
//

#pragma once

#include <vector>
#include "entity/entity.h"

namespace finalproject {

namespace game {

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

 private:
  //std::vector<std::vector<entity::Entity>>entities_;
  double width_;
  double height_;
  double margin_;
};







}


}