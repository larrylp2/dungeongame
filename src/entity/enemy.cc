//
// Created by Larry Peng on 4/29/21.
//

#include "entity/enemy.h"

namespace finalproject {

Enemy::Enemy(size_t max_health, size_t attack, size_t range, size_t shot, size_t fire_freq) {
   max_health_ = max_health;
   current_health_ = max_health_;
   attack_ = attack;
   range_ = range;
   shot_ = shot;
   fire_frequency_ = fire_freq;
}

void Enemy::Display(size_t row, size_t col, size_t grid_size) const {
  ci::gl::color(ci::Color("red"));
  glm::vec2 left_point(col * grid_size + 2 * grid_size / 5, row * grid_size + 2 * grid_size / 5);
  glm::vec2 right_point(col * grid_size + 3 * grid_size / 5, row * grid_size + 6 * grid_size / 7);
  ci::gl::drawSolidRect(ci::Rectf(left_point, right_point));

  DrawHealthBar(row, col, grid_size);
}

void Enemy::DrawHealthBar(size_t row, size_t col, size_t grid_size) const {
  //Health Bar
  double health_percentage = current_health_ / max_health_;

  ci::gl::color(ci::Color("green"));
  glm::vec2 left_point(col * grid_size + 5, row * grid_size + (2 * grid_size / 15));
  glm::vec2 right_point(col * grid_size + 5 + health_percentage * (grid_size - 10), row * grid_size + (4 * grid_size / 15));
  ci::gl::drawSolidRect(ci::Rectf(left_point, right_point));
}

double Enemy::TakeDamage(double damage) {
  current_health_ -= damage;
  return current_health_;
}

Projectile* Enemy::FireProjectile(size_t row, size_t col, size_t direct, size_t grid) const {
  Projectile* proj = new Projectile(row, col, direct, range_, attack_, false, grid, shot_);
  return proj;
}

size_t Enemy::GetFireFrequency() const {
  return fire_frequency_;
}


}

