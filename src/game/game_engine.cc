//
// Created by Larry Peng on 4/18/21.
//

#include "game/game_engine.h"

namespace finalproject {

namespace game {

GameEngine::GameEngine() {
  // Placeholder/test to see if cinder app visualization works from cmake configuration
  ci::app::setWindowSize(kWindowWidth, kWindowHeight);

  current_room_ = game::Room(kWindowWidth - 2 * kRoomMargin, kWindowHeight - 2 * kRoomMargin, kRoomMargin);
  player_ = entity::Player();
}

void GameEngine::draw() {
  ci::Color background_color("black");
  ci::gl::clear(background_color);

  current_room_.Display();
  player_.Display();
}

void GameEngine::keyDown(ci::app::KeyEvent event) {
  int event_code = event.getCode();
  if (event_code == ci::app::KeyEvent::KEY_w) {
    player_.MoveUp();
  } else if (event_code == ci::app::KeyEvent::KEY_a) {
    player_.MoveLeft();
  } else if (event_code == ci::app::KeyEvent::KEY_s) {
    player_.MoveDown();
  } else if (event_code == ci::app::KeyEvent::KEY_d) {
    player_.MoveRight();
  }
}

}

}