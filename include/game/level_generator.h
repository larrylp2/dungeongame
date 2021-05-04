//
// Created by Larry Peng on 5/4/21.
//

#pragma once
#include "game/level.h"

namespace finalproject {

class LevelGenerator {
public:
  LevelGenerator(double window_width, double window_height, double grid_margin);

  Level* GenerateLevel() const;

private:

  size_t kLevelSize = 10;

  double window_width_;

  double window_height_;

  double grid_margin_;

};


}