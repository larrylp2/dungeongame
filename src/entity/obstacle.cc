//
// Created by Larry Peng on 4/22/21.
//

#include "entity/obstacle.h"

namespace finalproject {

Obstacle::Obstacle(glm::vec2 location, double width, double height, double margin) {
  location_ = location;
  width_ = width;
  height_ = height;
  margin_ = margin;
}

glm::vec2 Obstacle::GetLocation() const {
  return location_;
}

std::string Obstacle::GetName() const {
  return "Obstacle";
}

void Obstacle::Display() const {
  ci::gl::color(ci::Color("blue"));
  glm::vec2 left_point(location_.x - width_ / 2, location_.y - height_ / 2 + margin_);
  glm::vec2 right_point(location_.x + width_ / 2, location_.y + height_ / 2 + margin_);
  ci::gl::drawSolidRect(ci::Rectf(left_point, right_point));
}



}