//
// Created by Larry Peng on 4/18/21.
//

#include "game/game_engine.h"
#include "entity/portal.h"
#include "entity/obstacle.h"

namespace finalproject {

GameEngine::GameEngine() {
  ci::app::setWindowSize(kWindowWidth, kWindowHeight);
  GenerateLevels();
}

void GameEngine::GenerateLevels() {
  Room* room_one = new Room(10, 10, kRoomMargin, 0); //ten by ten grid
  current_room_ = room_one;
  player_ = Player();
  player_.UpdateRoom(current_room_);

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
  Portal* portal_three = new Portal(9, 9, *current_room_);
  Portal* portal_four = new Portal(0, 1, *room_two);
  portal_three->LinkPortal(*portal_four);
  portal_four->LinkPortal(*portal_three);
  level_.AddPortal(portal_three);
  level_.AddPortal(portal_four);

  Item* empty_item = new Item("Space Laser", 0, 10, 0, 50, 5, 0);
  room_one->AddItem(empty_item, 4, 9);

  Enemy* default_enemy = new Enemy(50, 10, 150, 2, 200);
  room_one->AddEnemy(default_enemy, 9, 1);

  level_.AddRoom(current_room_);
  level_.AddRoom(room_two);
  //Later replace with class that helps with random level generation
}


void GameEngine::draw() {
  ci::Color background_color("black");
  ci::gl::clear(background_color);

  if (!inventory_mode_) {
    level_.Display(current_room_->GetOrder());
    player_.Display();
  } else {
    DisplayInventory();
  }

}

void GameEngine::keyDown(ci::app::KeyEvent event) {
  int event_code = event.getCode();
  if (!inventory_mode_) { //If the player is not looking at their inventory
    if (event_code == ci::app::KeyEvent::KEY_w) {
      player_.UpdateLocation(-1, 0);
    } else if (event_code == ci::app::KeyEvent::KEY_a) {
      player_.UpdateLocation(0, -1);
    } else if (event_code == ci::app::KeyEvent::KEY_s) {
      player_.UpdateLocation(1, 0);
    } else if (event_code == ci::app::KeyEvent::KEY_d) {
      player_.UpdateLocation(0, 1);
    } else if (event_code == ci::app::KeyEvent::KEY_SPACE) { //Handles portal interaction
      std::vector<Portal*> portals = level_.GetPortals().at(current_room_->GetOrder());
      for (size_t index = 0; index < portals.size(); index++) {
        Portal* current_portal = portals.at(index);
        if (current_portal->GetRoom()->GetOrder() == current_room_->GetOrder()) {
          if (player_.GetCol() == current_portal->GetCol() && player_.GetRow() == current_portal->GetRow()) {
            std::cout << "Portal" << std::endl;
            current_room_ = current_portal->Interact(&player_);
            break;
          }
        }
      }
    } else if (event_code == ci::app::KeyEvent::KEY_e) { //Handles inventory
      OpenInventory();
      std::cout << "Open Inventory" << std::endl;
    } else if (event_code == ci::app::KeyEvent::KEY_f) { //Handles item pickup
      Item* current_item = current_room_->GetItems().at(player_.GetRow()).at(player_.GetCol());
      if (current_item != nullptr) {
        current_room_->RemoveItem(player_.GetRow(), player_.GetCol());
        player_.AddItem(current_item);
        std::cout << "Picked Up Item" << std::endl;
      }
    } else if (event_code == ci::app::KeyEvent::KEY_UP) {
      std::cout << "Attack" << std::endl;
      player_.FireProjectile(0);
    } else if (event_code == ci::app::KeyEvent::KEY_DOWN) {
      std::cout << "Attack" << std::endl;
      player_.FireProjectile(1);
    } else if (event_code == ci::app::KeyEvent::KEY_RIGHT) {
      std::cout << "Attack" << std::endl;
      player_.FireProjectile(2);
    } else if (event_code == ci::app::KeyEvent::KEY_LEFT) {
      std::cout << "Attack" << std::endl;
      player_.FireProjectile(3);
    }
  } else { //if the player is looking at their inventory
    if (event_code == ci::app::KeyEvent::KEY_e) {
      CloseInventory();
      std::cout << "Close Inventory" << std::endl;
    }
  }

}

void GameEngine::OpenInventory() {
  inventory_mode_ = true;
}

void GameEngine::CloseInventory() {
  inventory_mode_ = false;
}

void GameEngine::DisplayInventory() const {
  ci::gl::color(ci::Color("white"));
  ci::gl::drawStrokedRect(ci::Rectf(
          glm::vec2(kRoomMargin, kRoomMargin),
          glm::vec2(kWindowWidth - kRoomMargin, kWindowHeight - kRoomMargin)));

  ci::gl::drawStringCentered("inventory", glm::vec2(kWindowWidth / 2, kRoomMargin / 2));
  std::vector<Item*> inventory_items = player_.GetInventory();
  for (size_t index = 0; index < inventory_items.size(); index++) {
    ci::gl::drawStrokedRect(ci::Rectf(
            glm::vec2(kRoomMargin, kRoomMargin * (index + 1)),
            glm::vec2(kWindowWidth - kRoomMargin,kRoomMargin + kRoomMargin * (index + 1))));
    ci::gl::drawString(inventory_items.at(index)->GetSummary(), glm::vec2(kRoomMargin + 5, kRoomMargin * (index + 1) + kRoomMargin / 2));
  }
}









} // namespace finalproject