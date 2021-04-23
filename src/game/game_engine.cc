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

  current_room_ = Room(kWindowWidth - 2 * kRoomMargin, kWindowHeight - 2 * kRoomMargin, kRoomMargin);
  player_ = Player();

  //Adds two portals to the current room
  Portal portal_one = Portal(glm::vec2(300,300));
  Portal portal_two = Portal(glm::vec2(400,400));
  portal_one.LinkPortal(portal_two);
  portal_two.LinkPortal(portal_one);

  current_room_.AddPortal(portal_one);
  current_room_.AddPortal(portal_two);

  Obstacle obstacle = Obstacle(glm::vec2(350, 350), 5, kWindowHeight - 2 * kRoomMargin, kRoomMargin);
  current_room_.AddObstacle(obstacle);

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
    player_.MoveUp();
  } else if (event_code == ci::app::KeyEvent::KEY_a) {
    player_.MoveLeft();
  } else if (event_code == ci::app::KeyEvent::KEY_s) {
    player_.MoveDown();
  } else if (event_code == ci::app::KeyEvent::KEY_d) {
    player_.MoveRight();
  } else if (event_code == ci::app::KeyEvent::KEY_SPACE) {
    /*for (size_t index = 0; index < current_room_.GetEntities().size(); index++) {
      if (glm::distance(player_.GetLocation(), current_room_.GetEntities().at(index).GetLocation()) <= 40) {
        Room current_room = current_room_.GetEntities().at(index).Interact(current_player_);
      }
    }*/
    for (size_t index = 0; index < current_room_.GetPortals().size(); index++) {
      if (glm::distance(player_.GetLocation(), current_room_.GetPortals().at(index).GetLocation()) <= 10) {
        player_.Interact(current_room_.GetPortals().at(index));
        break;
      }
    }
  }
}







}