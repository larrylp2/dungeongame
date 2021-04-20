//
// Created by Larry Peng on 4/19/21.
//
#include "entity/portal.h"

namespace finalproject {

Portal::Portal(const glm::vec2& location) {
  location_ = location;
}

void Portal::LinkPortal(Portal& destination) {
  destination_ = &destination;
}

void Portal::Display() const {
  //Temporarily an purple rectangle to represent the portal
  ci::gl::color(ci::Color("purple"));
  glm::vec2 left_point(location_.x - 5, location_.y - 5);
  glm::vec2 right_point(location_.x + 5, location_.y + 5);
  ci::gl::drawSolidRect(ci::Rectf(left_point, right_point));
}

glm::vec2 Portal::GetLocation() const {
  return location_;
}

Portal Portal::GetDestination() const {
  return *destination_;
}

}

