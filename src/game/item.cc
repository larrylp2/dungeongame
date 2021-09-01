//
// Created by Larry Peng on 4/19/21.
//
#include "game/item.h"
namespace finalproject {

Item::Item(std::string name, size_t health, size_t attack, size_t range, size_t shot, size_t vitality) {
  item_name_ = name;
  health_mod_ = health;
  attack_mod_ = attack;
  range_mod_ = range;
  shot_mod_ = shot;
  vitality_mod_ = vitality;
}

void Item::Display(size_t row, size_t col, size_t grid_size) const {
  ci::gl::color(ci::Color("yellow"));
  //Item represented by yellow plus
  glm::vec2 left_point(col * grid_size + 2 * grid_size / 5, row * grid_size + 5);
  glm::vec2 right_point(col * grid_size + 3 * grid_size / 5, row * grid_size + grid_size - 5);
  ci::gl::drawSolidRect(ci::Rectf(left_point, right_point));

  glm::vec2 left_point_two(col * grid_size + 5, row * grid_size + 2 * grid_size / 5);
  glm::vec2 right_point_two(col * grid_size + grid_size - 5, row * grid_size + 3 * grid_size / 5);
  ci::gl::drawSolidRect(ci::Rectf(left_point_two, right_point_two));
}

std::string Item::GetSummary() const {
  //Generates a summary of the stats this item offers
  std::string info;
  info.append(item_name_);
  info.append("  |  ");
  info.append("HP: ");
  info.append(std::to_string(health_mod_));
  info.append("  ");
  info.append("ATK: ");
  info.append(std::to_string(attack_mod_));
  info.append("  ");
  info.append("RNG: ");
  info.append(std::to_string(range_mod_));
  info.append("  ");
  info.append("SHOT: ");
  info.append(std::to_string(shot_mod_));
  info.append("  ");
  info.append("VIT: ");
  info.append(std::to_string(vitality_mod_));
  info.append("  ");
  return info;
}

size_t Item::GetHealth() const {
  return health_mod_;
}

size_t Item::GetAttack() const {
  return attack_mod_;
}

size_t Item::GetRange() const {
  return range_mod_;
}

size_t Item::GetShot() const {
  return shot_mod_;
}

size_t Item::GetVitality() const {
  return vitality_mod_;
}

} // namespace finalproject