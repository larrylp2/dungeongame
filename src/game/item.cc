//
// Created by Larry Peng on 4/19/21.
//
#include "game/item.h"
namespace finalproject {

Item::Item() {
  health_mod_ = 0;
  attack_mod_ = 0;
  defense_mod_ = 0;
  speed_mod_ = 0;
  dexterity_mod_ = 0;
  vitality_mod_ = 0;
}

void Item::Display(size_t row, size_t col, size_t grid_size) const {
  ci::gl::color(ci::Color("yellow"));
  glm::vec2 left_point(col * grid_size + 2 * grid_size / 5, row * grid_size + 5);
  glm::vec2 right_point(col * grid_size + 3 * grid_size / 5, row * grid_size + grid_size - 5);
  ci::gl::drawSolidRect(ci::Rectf(left_point, right_point));

  glm::vec2 left_point_two(col * grid_size + 5, row * grid_size + 2 * grid_size / 5);
  glm::vec2 right_point_two(col * grid_size + grid_size - 5, row * grid_size + 3 * grid_size / 5);
  ci::gl::drawSolidRect(ci::Rectf(left_point_two, right_point_two));
}

std::string Item::GetName() const {
  return item_name_;
}




}