//
// Created by Larry Peng on 4/18/21.
//

#include "game/room.h"

namespace finalproject {

namespace game {

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

}




}


}