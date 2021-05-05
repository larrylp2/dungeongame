//
// Created by Larry Peng on 4/30/21.
//

#pragma once
#include "cinder/gl/gl.h"

namespace finalproject {

class Projectile {
 public:

  /**
   * Constructs a projectile.
   *
   * @param row the row of the projectile
   * @param col the col of the projectile
   * @param direction the direction the projectile is travelling
   * @param range_ how far the projectile has to travel
   * @param strength_ the strength of the projectile
   * @param player_proj_ if the projectile was fired by the player or not
   * @param grid the size of grids
   * @param speed the speed of projectiles
   */
  Projectile(size_t row, size_t col, size_t direction, float range, double strength, bool player_proj, size_t grid, float speed);

  /**
   * Displays the projectile, updating and returning the remaining range it can travel.
   *
   * @param room_width the width of the room grid
   * @param room_height the height of the room grid
   * @return the remaining travel range of the projectile
   */
  size_t Display(size_t room_width, size_t room_height);

  /**
   * Update location.
   */
  void UpdateLocation();

  /**
   * Returns the row.
   *
   * @return the row
   */
  size_t GetRow() const;

  /**
   * Returns the col.
   *
   * @return the col
   */
  size_t GetCol() const;

  /**
   * Returns the strength of the projectile.
   *
   * @return the strength
   */
  double GetStrength() const;

  /**
   * Returns if this is a player generated projectile.
   */
  bool IsPlayer() const;

 private:
  //The x location in the cinder window
  float x_;

  //The y location in the cinder window
  float y_;

  //The row location in the game grid
  size_t row_;

  //The column location in the game grid
  size_t col_;

  //The direction the projectile is traveling
  size_t direction_;

  //The remaining range of the projectile
  float range_;

  //The strength of the projectile that determines size and damage
  double strength_;

  //A boolean representing if this projectile was one fired by the player
  bool player_proj_;

  //The length of a grid in the game
  size_t grid_;

  //The speed of the projectile
  float speed_;
};

} // namespace finalproject