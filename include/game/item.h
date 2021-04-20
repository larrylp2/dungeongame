//
// Created by Larry Peng on 4/19/21.
//

#pragma once

namespace finalproject {

class Item {

 public:
  /**
   * Default constructor for item
   */
  Item();

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
