//
// Created by Larry Peng on 4/19/21.
//
#include "entity/portal.h"

namespace finalproject {

Portal::Portal() {
  row_ = 0;
  col_ = 0;
  valid_ = false;
}

Portal::Portal(size_t row, size_t col) {
  row_ = row;
  col_ = col;
  valid_ = true;
}

void Portal::LinkPortal(Portal& destination) {
  destination_ = &destination;
}

void Portal::Display(size_t grid_size) const {
  //Temporarily an purple rectangle to represent the portal
  ci::gl::color(ci::Color("purple"));
  glm::vec2 left_point(col_ * grid_size + 5, row_ * grid_size + 5);
  glm::vec2 right_point(col_ * grid_size + grid_size - 5, row_ * grid_size + grid_size - 5);
  ci::gl::drawSolidRect(ci::Rectf(left_point, right_point));
}

Portal Portal::GetDestination() const {
  return *destination_;
}

size_t Portal::GetRow() const {
  return row_;
}


size_t Portal::GetCol() const {
  return col_;
}

bool Portal::IsValid() const {
  return valid_;
}

}

