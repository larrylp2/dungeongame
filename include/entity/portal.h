//
// Created by Larry Peng on 4/19/21.
//

#pragma once
#include "cinder/gl/gl.h"
#include "game/room.h"
#include "entity/player.h"

namespace finalproject {

/**
 * Handles a portal that teleports a player to a new location.
 */
class Portal {
 public:
  /**
   * Constructor for a portal.
   *
   * @param row the row of this portal
   * @param col the column of this portal
   * @param room the room this portal is in
   * @param another if this portal leads to another oom
   */
  Portal(size_t row, size_t col, Room& room, bool another);

  /**
   * Links this portal to another portal.
   *
   * @param destination a pointer to another portal
   */
  void LinkPortal(Portal& destination);

  /**
   * Displays a portal.
   *
   * @param gird_size the size of one grid square
   */
  void Display(size_t grid_size) const;

  /**
   * Gets the row of this portal.
   *
   * @return the row
   */
  size_t GetRow() const;

  /**
   * Gets the column of this portal.
   *
   * @return the portal
   */
  size_t GetCol() const;

  /**
   * Gets the current room of this portal
   *
   * @return the room
   */
  Room* GetRoom() const;

  /**
   * Handles portal interaction by a player.
   *
   * @param player the player who entered the portal
   * @return the room the destination portal is in
   */
  Room* Interact(Player* player);

 private:
  //destination portal this leads to
  Portal* destination_;

  //The current room that this portal is in
  Room* current_room_;

  //If this portal leads to another room, or remains in the same room
  bool another_;

  //The column location of the portal
  size_t col_;

  //The row location of the portal
  size_t row_;
};

} // namespace finalproject