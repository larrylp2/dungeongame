//
// Created by Larry Peng on 4/18/21.
//

#include "game/game_engine.h"
#include "entity/portal.h"
#include "entity/obstacle.h"

namespace finalproject {

GameEngine::GameEngine() {
  // Placeholder/test to see if cinder app visualization works from cmake configuration
  ci::app::setWindowSize(kWindowWidth, kWindowHeight);

  current_room_ = Room(10, 10, kRoomMargin); //ten by ten grid
  player_ = Player();
  player_.UpdateRoom(current_room_);

  //Adds two portals to the current room
  Portal portal_one = Portal(3, 3);
  Portal portal_two = Portal(7, 7);
  portal_one.LinkPortal(portal_two);
  portal_two.LinkPortal(portal_one);

  current_room_.AddPortal(portal_one);
  current_room_.AddPortal(portal_two);

  std::vector<std::tuple<size_t, size_t>> terrain = {std::make_tuple(1, 2),
                                                     std::make_tuple(2, 3),
                                                     std::make_tuple(3, 4),
                                                     std::make_tuple(4, 5)};
  current_room_.DesignateObstacles(terrain);

  //level_.AddRoom(current_room_);
  //level_.AddRoom(room_two);
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
    player_.UpdateLocation(-1, 0);
  } else if (event_code == ci::app::KeyEvent::KEY_a) {
    player_.UpdateLocation(0, -1);
  } else if (event_code == ci::app::KeyEvent::KEY_s) {
    player_.UpdateLocation(1, 0);
  } else if (event_code == ci::app::KeyEvent::KEY_d) {
    player_.UpdateLocation(0, 1);
  } else if (event_code == ci::app::KeyEvent::KEY_SPACE) {
    Portal current_portal = current_room_.GetPortals().at(player_.GetRow()).at(player_.GetCol());
    if (current_portal.IsValid())
    player_.Interact(current_portal);
  }
}







}