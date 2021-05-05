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

  //Width of the game window
  double kWindowWidth = 800;

  //Height of the game window
  double kWindowHeight = 800;

  //Margin of the game window
  double kRoomMargin = 40;

private:
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

  /**
   * Displays a win
   */
  void DisplayWin();

  /**
   * Displays a loss
   */
  void DisplayLoss();

    /**
     * Interacts with the gate of the current level
     */
  void InteractGate();

  //Helps generate levels for the game
  LevelGenerator level_gen_ = LevelGenerator(kWindowWidth, kWindowHeight, kRoomMargin);

  //The current room displayed on the screen
  Room* current_room_;

  //Current Level within the game
  Level* current_level_;

  //The number of the current level
  size_t level_num_ = 1;

  //The number of levels the player needs to complete to win (TBD)
  size_t levels_to_win = 3;

  //The player
  Player* player_ = new Player();

  //A boolean representing if the player is viewing the inventory
  bool inventory_mode_ = false;

  //A boolean representing if the player has won or lost and is on a results screen
  bool results_screen_ = false;

};

} // namespace finalproject