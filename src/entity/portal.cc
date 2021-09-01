//
// Created by Larry Peng on 4/19/21.
//
#include "entity/portal.h"

namespace finalproject {

Portal::Portal(size_t row, size_t col, Room &room, bool another) {
  row_ = row;
  col_ = col;
  current_room_ = &room;
  current_room_->MarkOccupied(row, col);
  another_ = another;
}

void Portal::LinkPortal(Portal &destination) {
  destination_ = &destination;
}

void Portal::Display(size_t grid_size) const {
  //Portals that stay within a room are purple, while those that lead outside are green
  if (!another_) {
    ci::gl::color(ci::Color("purple"));
  } else {
    ci::gl::color(ci::Color("green"));
  }
  glm::vec2 left_point(col_ * grid_size + 5, row_ * grid_size + 5);
  glm::vec2 right_point(col_ * grid_size + grid_size - 5,
                        row_ * grid_size + grid_size - 5);
  ci::gl::drawSolidRect(ci::Rectf(left_point, right_point));
}

Room *Portal::GetRoom() const {
  return current_room_;
}

size_t Portal::GetRow() const {
  return row_;
}


size_t Portal::GetCol() const {
  return col_;
}

Room *Portal::Interact(Player *player) {
  player->UpdateRoom(destination_->GetRoom());
  size_t current_row = player->GetRow();
  size_t current_col = player->GetCol();
  size_t new_row = destination_->GetRow();
  size_t new_col = destination_->GetCol();
  player->UpdateLocation(new_row - current_row, new_col - current_col);
  return destination_->GetRoom();
}

} // namespace finalproject

