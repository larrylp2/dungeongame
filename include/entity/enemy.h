//
// Created by Larry Peng on 4/29/21.
//

#pragma once
#include "cinder/gl/gl.h"
#include "entity/projectile.h"

namespace finalproject {

class Enemy {
 public:
  /**
   * Constructor for an enemy
   *
   * @param max_health the enemy's max health
   * @param attack the enemy's attack
   * @param range the enemy's range
   * @param shot the enemy's shot speed
   * @param fire_freq a number that determines how frequently this enemy fires
   */
  Enemy(size_t max_health, size_t attack, size_t range, size_t shot, size_t fire_freq);

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

  /**
   * Generates and returns a projectile from this enemy
   *
   * @param row the row of the projectile
   * @param col the column of the projectile
   * @param direct the direction this projectile should travel
   * @param grid the width of the room grid
   */
  Projectile* FireProjectile(size_t row, size_t col, size_t direct, size_t grid) const;

  /*
   * Returns the fire frequency, a number that determines how often this enemy shoots
   */
  size_t GetFireFrequency() const;

 private:
  std::string name_ = "default";

  size_t fire_frequency_;

  double max_health_;

  double current_health_;

  size_t attack_;

  size_t range_;

  size_t shot_;

};





}
