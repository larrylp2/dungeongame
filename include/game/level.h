//
// Created by Larry Peng on 4/19/21.
//

#pragma once
#include <vector>
#include "game/room.h"

namespace finalproject {

class Level {

 public:
  /**
   * Default constructor for a level.
   */
  Level();

  /**
   * Adds a room to a level
   */
  void AddRoom(Room room);



 private:
  //The rooms within the floor
  std::vector<Room> rooms_;

};

}