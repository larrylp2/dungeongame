//
// Created by Larry Peng on 4/18/21.
//

#include "entity/player.h"
#include "entity/projectile.h"

namespace finalproject {

Player::Player() {
  row_ = 0;
  col_ = 0;
  max_health_ = 200;
  current_health_ = max_health_;
  attack_ = 20;
  range_ = 200;
  shot_ = 5;
  vitality_ = 1;
}

Player::~Player() {
  for (size_t item = 0; item < inventory_.size(); item++) {
    if (inventory_.at(item) != nullptr) {
      delete inventory_.at(item);
    }
  }
}


void Player::Display() {
  //Temporarily an orange triangle to represent the player
  ci::gl::color(ci::Color("orange"));
  size_t grid = 40;
  glm::vec2 top_point(grid / 2.0 + col_ * grid, row_ * grid + 5);
  glm::vec2 left_point(col_ * grid + 5, row_ * grid + grid - 5);
  glm::vec2 right_point(col_ * grid + grid - 5, row_ * grid + grid - 5);
  ci::gl::drawSolidTriangle(top_point, left_point, right_point);

  max_health_ = current_room_->GetMax();
  current_health_ = current_room_->GetCurrent();
}

void Player::UpdateLocation(size_t row, size_t col) {
  size_t new_row = row_ + row;
  size_t new_col = col_ + col;
  if (new_row >= current_room_->GetHeight() || new_col >= current_room_->GetWidth()
  || new_row < 0 || new_col < 0) {
  } else if (current_room_->GetObstacles().at(new_row).at(new_col) != nullptr){
  } else {
    row_ = new_row;
    col_ = new_col;
  }
  current_room_->UpdatePlayerLocation(row_, col_);
}

void Player::UpdateRoom(Room* room) {
  current_room_ = room;
  current_room_->UpdatePlayerLocation(row_, col_);
  current_room_->UpdatePlayerHealth(max_health_, current_health_, vitality_);
}

void Player::AddItem(Item* item) {
  inventory_.push_back(item);
  max_health_ += item->GetHealth();
  current_health_ += item->GetHealth();
  attack_ += item->GetAttack();
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

size_t Player::GetMaxHp() const {
  return max_health_;
}

size_t Player::GetCurrHp() const {
  return current_health_;
}

size_t Player::GetPlayerVit() const {
  return vitality_;
}

} // namespace finalproject