//
// Created by Larry Peng on 4/29/21.
//

#pragma once
#include "cinder/gl/gl.h"

namespace finalproject {

class Enemy {
 public:
  /**
   * Default constructor for an enemy
   */
  Enemy();

  /**
   * Displays an enemy.
   *
   * @param row the row to display
   * @param col the column to display
   * @param grid_size the size of the grid square occupied by the enemy
   */
  void Display(size_t row, size_t col, size_t grid_size) const;

  /**
   * Draws an enemy's health bar
   * @param row the row to display
   * @param col the column to display
   * @param grid_size the size of the grid square occupied by the enemy
   */
  void DrawHealthBar(size_t row, size_t col, size_t grid_size) const;

  /**
   * Makes this enemy take damage, returning the amount of health it has left
   *
   * @param damage the amount of damage this enemy takes
   * @return the new current health of this enemy
   */
  double TakeDamage(double damage);

 private:
  std::string name_ = "default";

  double max_health_;

  double current_health_;
};





}
