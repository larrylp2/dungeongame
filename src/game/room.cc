//
// Created by Larry Peng on 4/18/21.
//

#include "game/room.h"

namespace finalproject {

Room::Room() {
  width_ = 0;
  height_ = 0;
  margin_ = 0;
}


Room::Room(double width, double height, double margin) {
  width_ = width;
  height_ = height;
  margin_ = margin;
}

void Room::Display() const {
  // Currently only displays the borders of the room
  ci::gl::color(ci::Color("white"));
  ci::gl::drawStrokedRect(ci::Rectf(
          glm::vec2(margin_, margin_),
          glm::vec2(width_ + margin_, height_ + margin_)));

  for (size_t index = 0; index < obstacles_.size(); index++) {
    obstacles_.at(index).Display();
  }
  for (size_t index = 0; index < portals_.size(); index++) {
    portals_.at(index).Display();
  }

}

void Room::AddPortal(Portal& portal) {
  portals_.push_back(portal);
}

void Room::AddObstacle(const Obstacle &obstacle) {
  obstacles_.push_back(obstacle);
}

std::vector<Portal> Room::GetPortals() const {
  return(portals_);
}

bool Room::CheckObstacle(const glm::vec2& location) const {

}



}