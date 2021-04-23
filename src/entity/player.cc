//
// Created by Larry Peng on 4/18/21.
//

#include "entity/player.h"

namespace finalproject {

Player::Player() {
  current_room_ = Room();
  location_ = glm::vec2(100, 100);
}

void Player::Display() const {
  //Temporarily an orange triangle to represent the player
  ci::gl::color(ci::Color("orange"));
  glm::vec2 top_point(location_.x, location_.y - 10);
  glm::vec2 left_point(location_.x - 10, location_.y);
  glm::vec2 right_point(location_.x + 10, location_.y);
  ci::gl::drawSolidTriangle(top_point, left_point, right_point);
}

void Player::MoveUp() {
  location_.y -= speed_;
}

void Player::MoveDown() {
  location_.y += speed_;
}

void Player::MoveLeft() {
  location_.x -= speed_;
}

void Player::MoveRight() {
  location_.x += speed_;
}

glm::vec2 Player::GetLocation() const {
  return location_;
}

double Player::GetSpeed() const {
  return speed_;
}

void Player::Interact(const Portal& portal) {
  location_ = portal.GetDestination().GetLocation();
  std::cout << "Interact" << std::endl;
}


}