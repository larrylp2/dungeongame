//
// Created by Larry Peng on 4/18/21.
//

#include "entity/player.h"
#include "entity/projectile.h"

namespace finalproject {

Player::Player() {
  row_ = 0;
  col_ = 0;
  health_ = 100;
  attack_ = 20;
  defense_ = 0;
  range_ = 200;
  shot_ = 5;
  vitality_ = 1;
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
  if (new_row >= current_room_->GetHeight() || new_col >= current_room_->GetWidth() || new_row < 0 || new_col < 0) {
    std::cout << "Reached Edge of Room" << std::endl;
  } else if (current_room_->GetObstacles().at(new_row).at(new_col) != nullptr){
    std::cout << "Cannot Move There" << std::endl;
  } else {
    row_ = new_row;
    col_ = new_col;
  }
}

void Player::UpdateRoom(Room* room) {
  current_room_ = room;
}

void Player::AddItem(Item* item) {
  inventory_.push_back(item);
  health_ += item->GetHealth();
  attack_ += item->GetAttack();
  defense_ += item->GetDefense();
  range_ += item->GetRange();
  shot_ += item->GetShot();
  vitality_ += item->GetVitality();
}


size_t Player::GetCol() const {
  return col_;
}

size_t Player::GetRow() const {
  return row_;
}

std::vector<Item*> Player::GetInventory() const {
  return inventory_;
}

void Player::FireProjectile(size_t direction) const {
  size_t grid = 40;
  Projectile* proj = new Projectile(row_, col_, direction, range_, attack_, true, grid, shot_);
  current_room_->AddProjectile(proj);
}



} // namespace finalproject