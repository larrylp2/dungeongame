//
// Created by Larry Peng on 4/19/21.
//

#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

namespace finalproject {

/**
 * Class that represents an item a player can pick up to get stronger.
 */
class Item {

 public:
  /**
   * Default constructor for item.
   */
  Item();

  /**
   * Displays the item.
   *
   * @param row the row to display
   * @param col the column to display
   * @param grid_size the size of the grid square occupied by the item
   */
  void Display(size_t row, size_t col, size_t grid_size) const;

 private:
  //How much this item alters the health of the player
  double health_mod_;

  //How much this item alters the attack of the player
  double attack_mod_;

  //How much this item alters the defense of the player
  double defense_mod_;

  //How much this item alters the speed of the player
  double speed_mod_;

  //How much this item alters the dexterity of the player
  double dexterity_mod_;

  //How much this item alters the vitality of the player
  double vitality_mod_;



};


}
