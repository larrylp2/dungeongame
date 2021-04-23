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
  Room* room_one = new Room(10, 10, kRoomMargin, 0); //ten by ten grid
  current_room_ = room_one;
  player_ = Player();
  player_.UpdateRoom(*current_room_);

  //Adds two portals to the current room
  Portal portal_one(3, 3, *current_room_);
  Portal portal_two(7, 7, *current_room_);
  portal_one.LinkPortal(portal_two);
  portal_two.LinkPortal(portal_one);

  level_.AddPortal(&portal_one);
  level_.AddPortal(&portal_two);

  std::vector<std::tuple<size_t, size_t>> terrain = {std::make_tuple(1, 2),
                                                     std::make_tuple(2, 3),
                                                     std::make_tuple(3, 4),
                                                     std::make_tuple(4, 5)};
  current_room_->DesignateObstacles(terrain);

  //Need to add constructors, destructors, etc
  Room* room_two = new Room(2, 8, kRoomMargin, 1);
  Portal portal_three = Portal(9, 9, *current_room_);
  Portal portal_four = Portal(0, 1, *room_two);
  portal_three.LinkPortal(portal_four);
  portal_four.LinkPortal(portal_three);
  level_.AddPortal(&portal_three);
  level_.AddPortal(&portal_four);

  level_.AddRoom(current_room_);
  level_.AddRoom(room_two);
}

void GameEngine::draw() {
  ci::Color background_color("black");
  ci::gl::clear(background_color);

  level_.Display(current_room_->GetOrder());
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
    /*
    Portal current_portal = current_room_.GetPortals().at(player_.GetRow()).at(player_.GetCol());
    if (current_portal.IsValid())
    player_.Interact(current_portal);
     */
    std::vector<Portal*> portals = level_.GetPortals().at(current_room_->GetOrder());
    for (size_t index = 0; index < portals.size(); index++) {
      Portal* current_portal = portals.at(index);
      if (current_portal->GetRoom()->GetOrder() == current_room_->GetOrder()) {
        std::cout << "Portals Found" << std::endl;
        if (player_.GetCol() == current_portal->GetCol() && player_.GetRow() == current_portal->GetRow()) {
          std::cout << "Portal Found" << std::endl;
          current_room_ = current_portal->Interact(&player_);
          break;
        }
      }
    }
  }
}







}