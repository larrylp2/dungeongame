//
// Created by Larry Peng on 4/22/21.
//

#pragma once
#include "cinder/gl/gl.h"

namespace finalproject {

class Obstacle {
 public:
  Obstacle();

  void Display(size_t row, size_t col, size_t grid_size) const;

  bool IsValid() const;

  void MakeValid();

  void MakeInvalid();

 private:

  bool valid_;

};



}
