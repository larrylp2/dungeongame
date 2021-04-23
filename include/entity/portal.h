//
// Created by Larry Peng on 4/19/21.
//

#pragma once
#include "cinder/gl/gl.h"

namespace finalproject {

/**
 * Handles a portal that teleports a player to a new location
 * (currently only within a room, not between rooms)
 */
class Portal {
 public:
  Portal();
  /**
   * Default constructor for a portal
   *
   * @param row the row of this portal
   * @param col the column of this portal
   */
  Portal(size_t row, size_t col);

  /**
   * Links this portal to another portal.
   *
   * @param destination a pointer to another portal
   */
  void LinkPortal(Portal& destination);

  /**
   * Displays a portal
   *
   * @param gird_size the size of one grid square
   */
  void Display(size_t grid_size) const;

  /**
   * Gets the destination of the portal.
   *
   * @return the portal
   */
  Portal GetDestination() const;

  /**
   * Gets the row of this portal
   *
   * @return the row
   */
  size_t GetRow() const;


  /**
   * Gets the column of this portal
   *
   * @return the portal
   */
  size_t GetCol() const;


  /**
   * Gets if this portal is valid or not.
   *
   * @return the validity as a boolean
   */
  bool IsValid() const;

 private:
  //destination portal this leads to
  Portal* destination_;

  size_t col_;

  size_t row_;

  bool valid_ = false;
};

}