//
// Created by Larry Peng on 4/22/21.
//

#include "entity/obstacle.h"

namespace finalproject {

Obstacle::Obstacle() {
  valid_ = false;
}

void Obstacle::Display(size_t row, size_t col, size_t grid_size) const {
  ci::gl::color(ci::Color("white"));
  glm::vec2 left_point(col * grid_size, row * grid_size);
  glm::vec2 right_point(col * grid_size + grid_size, row * grid_size + grid_size);
  ci::gl::drawSolidRect(ci::Rectf(left_point, right_point));
}

bool Obstacle::IsValid() const {
  return valid_;
}

void Obstacle::MakeValid() {
  valid_ = true;
}

void Obstacle::MakeInvalid() {
  valid_ = false;
}

}