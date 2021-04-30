//
// Created by Larry Peng on 4/29/21.
//

#include "entity/enemy.h"

namespace finalproject {

Enemy::Enemy() {
   max_health_ = 100;
   current_health_ = 100;
   std::cout << current_health_ << std::endl;
   std::cout << max_health_ << std::endl;
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






}

