//
// Created by Larry Peng on 5/4/21.
//

#pragma once
#include "game/room.h"
#include "entity/player.h"

namespace finalproject {

/**
 * Handles travel between levels.
 */
class Gate {
public:
  /**
   * Constructor for a gate.
   */
  Gate(size_t row, size_t col);

  /**
   * Displays the gate.
   */
  void Display() const;

  /**
   * Gets the row of the gate.
   *
   * @return the row
   */
  size_t GetRow() const;

  /**
   * Gets the column of the gate.
   *
   * @return the col
   */
  size_t GetCol() const;

private:
  // The row of the gate
  size_t row_;

  // The column of the gate
  size_t col_;

  // The length of one grid in the game
  size_t grid_size_;

};


} // namespace finalproject
