//
// Created by Larry Peng on 4/18/21.
//

#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include <vector>
#include "game/room.h"
#include "game/level.h"
#include "entity/player.h"

// Need to decide on a name for the game
namespace finalproject {

/**
 * Launches the visual game.
 */
class GameEngine : public ci::app::App {
 public:
  /**
   * Default constructor for a GameEngine.
   */
  GameEngine();

  // Override methods of cinder app
  void draw() override;
  void keyDown(ci::app::KeyEvent event) override;

  //Width of the game window
  double kWindowWidth = 800;

  //Height of the game window
  double kWindowHeight = 800;

  //Margin of the game window
  double kRoomMargin = 50;


 private:
  //The current room displayed on the screen
  Room current_room_;

  //All of the levels within the game (need to improve level class before adding)
  //std::vector<game::Level> levels_;

  //The current level
  //Level level_;

  //The player
  Player player_;

};

}