//
// Created by Larry Peng on 4/22/21.
//

#pragma once
#include "cinder/gl/gl.h"

namespace finalproject {

class Obstacle {
 public:
  /**
   * Default constructor for an obstacle.
   */
  Obstacle();

  /**
   * Displays an obstacle.
   *
   * @param row the row to display
   * @param col the column to display
   * @param grid_size the size of the grid square occupied by the obstacle
   */
  void Display(size_t row, size_t col, size_t grid_size) const;

};



}
