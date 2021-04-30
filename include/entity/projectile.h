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
   * @param x the starting x location of the projectile
   * @param y the starting y location of the projectile
   * @param row the row of the projectile
   * @param col the col of the projectile
   * @param direction the direction the projectile is travelling
   * @param range_ how far the projectile has to travel
   * @param strength_ the strength of the projectile
   * @param player_proj_ if the projectile was fired by the player or not
   * @param grid the size of grids
   * @param speed the speed of projectiles
   */
  Projectile(float x, float y, size_t row, size_t col, size_t direction, float range, double strength, bool player_proj, size_t grid, float speed);

  /**
   * Displays the projectile, updating and returning the remaining range it can travel
   *
   * @return the remaining travel range of the projectile
   */
  size_t Display();

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