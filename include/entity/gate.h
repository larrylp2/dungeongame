//
// Created by Larry Peng on 5/4/21.
//

#pragma once
#include "game/level.h"
#include "game/room.h"
#include "entity/player.h"

namespace finalproject {

/**
 * Handles travel between levels
 */
class Gate {
public:
  /**
   * Constructor for a gate
   */
  Gate(Level* current_level, size_t order, size_t row, size_t col);

  /**
   * Displays the gate
   */
  void Display() const;

private:
  // The current level this gate is in
  Level* current_level_;

  // The index of the room this gate is in within the level
  size_t order_;

  // The row of the gate
  size_t row_;

  // The column of the gate
  size_t col_;


};


}
