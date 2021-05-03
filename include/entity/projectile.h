//
// Created by Larry Peng on 4/30/21.
//

#pragma once
#include "cinder/gl/gl.h"

namespace finalproject {

class Projectile {
 public:

  /**
   * Constructs a projectile
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
   * Displays the projectile, updating and returning the remaining range it can travel
   *
   * @param room_width the width of the room grid
   * @param room_height the height of the room grid
   * @return the remaining travel range of the projectile
   */
  size_t Display(size_t room_width, size_t room_height);

  /**
   * Update location
   */
  void UpdateLocation();

  /**
   * Returns the row
   *
   * @return the row
   */
  size_t GetRow() const;

  /**
   * Returns the col
   *
   * @return the col
   */
  size_t GetCol() const;

  /**
   * Returns the strength of the projectile
   *
   * @return the strength
   */
  double GetStrength() const;

  /**
   * Returns if this is a player generated projectile
   */
  bool IsPlayer() const;

 private:
  float x_;

  float y_;

  size_t row_;

  size_t col_;

  size_t direction_;

  float range_;

  double strength_;

  bool player_proj_;

  size_t grid_;

  float speed_;
};


}