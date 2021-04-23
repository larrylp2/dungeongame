//
// Created by Larry Peng on 4/18/21.
//

#include "entity/player.h"

namespace finalproject {

Player::Player() {
  current_room_ = Room();
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
  row_ += row;
  col_ += col;
}

void Player::UpdateRoom(Room room) {
  current_room_ = room;
}

void Player::Interact(const Portal& portal) {
  //location_ = portal.GetDestination().GetLocation();
  std::cout << "Interact" << std::endl;
}



}