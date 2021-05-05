//
// Created by Larry Peng on 4/19/21.
//

#pragma once
#include <vector>
#include "game/room.h"
#include "entity/portal.h"
#include "entity/gate.h"

namespace finalproject {

/**
 * Class that represents a level within the game, containing multiple rooms.
 */
class Level {

 public:
  /**
   * Constructor for a level.
   *
   * @param room_cap the max number of rooms
   */
  Level(size_t room_cap);

  /**
   * Destructor for a level
   */
  ~Level();

  /**
   * Displays important objects within a room of the level
   *
   * @param room_order the index of the room to display information about
   */
  void Display(size_t room_order) const;

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
   * @return the portals within the level
   */
  std::vector<std::vector<Portal*>> GetPortals() const;

  /**
   * Gets the rooms within the level
   *
   * @return the rooms within the level
   */
  std::vector<Room*> GetRooms() const;

  /**
   * Sets the gate within the level
   *
   * @param gate the gate within the level
   */
  void SetGate(Gate* gate);

  /**
   * Gets the gate within the level
   *
   * @return the gate
   */
  Gate* GetGate() const;

 private:
  //The maximum number of rooms within this floor
  size_t room_cap_;

  //The number of rooms currently within this floor
  size_t room_num_;

  //The rooms within the floor
  std::vector<Room*> rooms_;

  //The portals within the floor
  std::vector<std::vector<Portal*>> portals_;

  //The gate of the floor
  Gate* gate_;

};

}