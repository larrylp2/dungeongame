//
// Created by Larry Peng on 4/19/21.
//
#include "entity/portal.h"

namespace finalproject {

Portal::Portal() {
  row_ = 0;
  col_ = 0;
  //valid_ = false;
}

Portal::Portal(size_t row, size_t col, Room& room) {
  row_ = row;
  col_ = col;
  current_room_ = &room;
  //valid_ = true;
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

Room* Portal::GetRoom() const {
  return current_room_;
}

size_t Portal::GetRow() const {
  return row_;
}


size_t Portal::GetCol() const {
  return col_;
}

Room* Portal::Interact(Player* player) {
  size_t current_row = player->GetRow();
  size_t current_col = player->GetCol();
  size_t new_row = destination_->GetRow();
  size_t new_col = destination_->GetCol();
  player->UpdateLocation(new_row - current_row, new_col - current_col);
  return destination_->GetRoom();
}

/*
bool Portal::IsValid() const {
  return valid_;
} */

}

