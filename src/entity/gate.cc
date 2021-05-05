//
// Created by Larry Peng on 5/4/21.
//

#include "entity/gate.h"

namespace finalproject {

Gate::Gate(size_t row, size_t col) {
  row_ = row;
  col_ = col;
  grid_size_ = 40;
}

void Gate::Display() const {
  ci::gl::color(ci::Color("purple"));
  glm::vec2 left_point(col_ * grid_size_ + 5, row_ * grid_size_ + 5);
  glm::vec2 right_point(col_ * grid_size_ + grid_size_ - 5,
                        row_ * grid_size_ + grid_size_ - 5);
  ci::gl::drawSolidRect(ci::Rectf(left_point, right_point));
}

}