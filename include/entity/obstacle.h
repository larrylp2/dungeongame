//
// Created by Larry Peng on 4/22/21.
//

#pragma once
#include "cinder/gl/gl.h"

namespace finalproject {

class Obstacle {
 public:
  Obstacle();

  Obstacle(glm::vec2 location, double width, double height, double margin);

  glm::vec2 GetLocation() const;

  std::string GetName() const;

  void Display() const;

 private:
  double width_;

  double height_;

  glm::vec2 location_;

  double margin_;


};



}
