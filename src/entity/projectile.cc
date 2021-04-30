//
// Created by Larry Peng on 4/30/21.
//
#include "entity/projectile.h"

namespace finalproject {

Projectile::Projectile(float x, float y, size_t row, size_t col, size_t direction, float range, double strength, bool player_proj, size_t grid, float speed) {
  x_ = x;
  y_ = y;
  row_ = row;
  col_ = col;
  direction_ = direction;
  range_ = range;
  strength_ = strength;
  player_proj_ = player_proj;
  grid_ = grid;
  speed_ = speed;
}

size_t Projectile::Display() {
  UpdateLocation();
  glm::vec2 center_point(x_, y_);
  ci::gl::drawSolidCircle(center_point, strength_ / 2);
  return range_;
}

void Projectile::UpdateLocation() {
  range_ -= speed_;
  if (direction_ == 0) { //North
    y_ -= speed_;
  } else if (direction_ == 1) { //South
    y_ += speed_;
  } else if (direction_ == 2) { //East
    x_ += speed_;
  } else if (direction_ == 3) { //West
    x_ -= speed_;
  }
  row_ = y_ / grid_;
  col_ = x_ / grid_;
}

size_t Projectile::GetRow() const {
  return row_;
}

size_t Projectile::GetCol() const {
  return col_;
}

double Projectile::GetStrength() const {
  return strength_;
}





}