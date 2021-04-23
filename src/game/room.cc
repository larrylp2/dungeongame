//
// Created by Larry Peng on 4/18/21.
//

#include "game/room.h"

namespace finalproject {

Room::Room() {
  width_ = 0;
  height_ = 0;
  margin_ = 0;
  portals_ = std::vector<std::vector<Portal>>(height_, std::vector<Portal>(width_));
  //obstacles_ = std::vector<std::vector<Obstacle>>(height_, std::vector<Obstacle>(width_));
}


Room::Room(double width, double height, double margin) {
  width_ = width;
  height_ = height;
  margin_ = margin;
  portals_ = std::vector<std::vector<Portal>>(height_, std::vector<Portal>(width_));
  //obstacles_ = std::vector<std::vector<Obstacle>>(height_, std::vector<Obstacle>(width_));
}

void Room::Display() const {
  for (size_t row = 0; row < height_; row++) {
    for(size_t column = 0; column < width_; column++) {
      //Draws a grid from many empty rectangles
      ci::gl::color(ci::Color("white"));
      ci::gl::drawStrokedRect(ci::Rectf(
              glm::vec2(row * kGridSide,  column * kGridSide),
              glm::vec2((row + 1) * kGridSide,  (column + 1) * kGridSide)));
      //obstacles_.at(row).at(column).Display();
      Portal current_portal = portals_.at(row).at(column);
      if (current_portal.IsValid()) {
        current_portal.Display(kGridSide);
      }
    }
  }
}

double Room::GetGridSize() const {
  return kGridSide;
}



void Room::AddPortal(Portal& portal) {
  size_t row = portal.GetRow();
  size_t col = portal.GetCol();
  portals_.at(row).at(col) = portal;
}


/*
void Room::AddObstacle(const Obstacle &obstacle, size_t column, size_t row) {
  //obstacles_.at(row).at(column) = obstacle;
}
 */


std::vector<std::vector<Portal>> Room::GetPortals() const {
  return(portals_);
}




}