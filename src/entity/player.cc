//
// Created by Larry Peng on 4/18/21.
//

#include "entity/player.h"

namespace finalproject {

Player::Player() {
  row_ = 0;
  col_ = 0;
}

void Player::Display() const {
  //Temporarily an orange triangle to represent the player
  ci::gl::color(ci::Color("orange"));
  size_t grid = 40;
  glm::vec2 top_point(grid / 2.0 + col_ * grid, row_ * grid + 5);
  glm::vec2 left_point(col_ * grid + 5, row_ * grid + grid - 5);
  glm::vec2 right_point(col_ * grid + grid - 5, row_ * grid + grid - 5);
  ci::gl::drawSolidTriangle(top_point, left_point, right_point);
}

void Player::UpdateLocation(size_t row, size_t col) {
  size_t new_row = row_ + row;
  size_t new_col = col_ + col;
  if (current_room_->GetObstacles().at(new_row).at(new_col).IsValid()) {
    std::cout << "Cannot Move There" << std::endl;
  } else {
    row_ = new_row;
    col_ = new_col;
  }
}

void Player::UpdateRoom(Room& room) {
  current_room_ = &room;
}

void Player::Interact(const Portal& portal) {
  col_ = portal.GetDestination().GetCol();
  row_ = portal.GetDestination().GetRow();
  std::cout << "Interact" << std::endl;
}

size_t Player::GetCol() const {
  return col_;
}

size_t Player::GetRow() const {
  return row_;
}


}