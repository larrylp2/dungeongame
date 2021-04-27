//
// Created by Larry Peng on 4/19/21.
//

#pragma once
#include <vector>
#include "game/room.h"
#include "entity/portal.h"

namespace finalproject {

/**
 * Class that represents a level within the game, containing multiple rooms.
 */
class Level {

 public:

  /**
   * Default constructor.
   */
  Level();

  /**
   * Displays important objects within a room of the level
   *
   * @param room_order the index of the room to display information about
   */
  void Display(size_t room_order) const;

  /**
   * Constructor for a level.
   *
   * @param room_cap the max number of rooms
   */
  Level(size_t room_cap);

  /**
   * Adds a room to a level
   *
   * @param room the room to add
   */
  void AddRoom(Room* room);

  /**
   * Ads a portal to the level
   *
   * @param portal the portal to add
   */
  void AddPortal(Portal* portal);

  /**
   * Gets the portals within the level
   *
   * @return the portals within th level
   */
  std::vector<std::vector<Portal*>> GetPortals() const;

 private:
  //The maximum number of rooms within this floor
  size_t room_cap_;

  //The number of rooms currently within this floor
  size_t room_num_;

  //The rooms within the floor
  std::vector<Room*> rooms_;

  //The portals within the floor
  std::vector<std::vector<Portal*>> portals_;

};

}