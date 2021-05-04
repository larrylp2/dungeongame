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
#include "entity/portal.h"
#include "game/level_generator.h"
#include "entity/gate.h"

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

  void InteractGate(Gate* gate);

  //Width of the game window
  double kWindowWidth = 800;

  //Height of the game window
  double kWindowHeight = 800;

  //Margin of the game window
  double kRoomMargin = 50;

  // Generates levels for the game
  // Idea is to make this method call a separate level generator class that creates room randomly
  // void GenerateLevels();

private:

  LevelGenerator level_gen_ = LevelGenerator(kWindowWidth, kWindowHeight, kRoomMargin);

  //The current room displayed on the screen
  Room* current_room_;

  //Current Level within the game
  Level* current_level_;

  //The player
  Player player_ = Player();

  bool inventory_mode_ = false;

  /**
   * Toggles the game to display the player's inventory.
   */
  void OpenInventory();

  /**
   * Toggles the game to no longer display the player's inventory.
   */
  void CloseInventory();

  /**
   * Displays the player inventory
   */
  void DisplayInventory() const;

};

}