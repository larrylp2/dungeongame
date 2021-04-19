//
// Created by Larry Peng on 4/18/21.
//

#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include <vector>
#include "game/room.h"
#include "entity/player.h"

// Need to decide on a name for the game
namespace finalproject {

namespace game {


/**
 * Launches the visual game
 */
class GameEngine : public ci::app::App {
 public:
  /**
   * Default constructor for a GameEngine
   */
  GameEngine();

  // Override methods of cinder app
  void draw() override;

  void keyDown(ci::app::KeyEvent event) override;

  double kWindowWidth = 800;

  double kWindowHeight = 800;

  double kRoomMargin = 50;


 private:
  //The current room displayed on the screen
  game::Room current_room_;

  //All of the rooms within the game
  std::vector<game::Room> rooms_;

  //The player
  entity::Player player_;

};


}


}