//
// Created by Larry Peng on 5/4/21.
//

#pragma once
#include "game/level.h"
#include "entity/enemy.h"
#include "entity/gate.h"

namespace finalproject {

class LevelGenerator {
public:
  LevelGenerator(double window_width, double window_height, double grid_margin);

  Level* GenerateLevel() const;

private:
  size_t kLevelSize = 10;

  void GenerateRooms(Level* level) const;

  void GeneratePortals(Level* level) const;

  void GenerateEnemies(Level* level) const;

  void GenerateObstacles(Level* level) const;

  void GenerateItems(Level* level) const;

  double window_width_;

  double window_height_;

  double grid_margin_;

};


}