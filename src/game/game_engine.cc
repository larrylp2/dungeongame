//
// Created by Larry Peng on 4/18/21.
//

#include "game/game_engine.h"
#include "entity/portal.h"
#include "entity/obstacle.h"

namespace finalproject {

GameEngine::GameEngine() {
  ci::app::setWindowSize(kWindowWidth, kWindowHeight);
  current_level_ = level_gen_.GenerateLevel();
  std::cout << "Level Generated" << std::endl;
  current_room_ = current_level_->GetRooms().at(0);
  std::cout << "Current Room Located" << std::endl;
  player_->UpdateRoom(current_room_);
  std::cout << "Player Created" << std::endl;
}


void GameEngine::draw() {
  ci::Color background_color("black");
  ci::gl::clear(background_color);

  //Displays loss if the player has no hp, otherwise either displays inventory or game
  if (player_->GetCurrHp() <= 0) {
    DisplayLoss();
  } else if (level_num_ > levels_to_win) {
    DisplayWin();
  } else {
    if (!inventory_mode_) {
      current_level_->Display(current_room_->GetOrder());
      player_->Display();
    } else {
      DisplayInventory();
    }

    //Writes out the current level and room in the bottom left
    std::string summary;
    summary.append("Level: ");
    summary.append(std::to_string(level_num_));
    summary.append(" | Room: ");
    summary.append(std::to_string(current_room_->GetOrder()));
    ci::gl::drawString(summary, glm::vec2(5, kWindowHeight - 10));
  }
}

void GameEngine::keyDown(ci::app::KeyEvent event) {
  int event_code = event.getCode();
  if (event_code == ci::app::KeyEvent::KEY_r) { //restarts the game
    level_num_ = 1; //resets level num
    if (player_ != nullptr) {
      //delete player_;
    }
    player_ = new Player(); //resets player
    if (current_level_ != nullptr) {
      delete current_level_;
    }
    current_level_ = level_gen_.GenerateLevel();
    current_room_ = current_level_->GetRooms().at(0);
    player_->UpdateRoom(current_room_);
  }

  if (!inventory_mode_ && !results_screen_) { //If the player is not looking at their inventory
    if (event_code == ci::app::KeyEvent::KEY_w) {
      player_->UpdateLocation(-1, 0);
    } else if (event_code == ci::app::KeyEvent::KEY_a) {
      player_->UpdateLocation(0, -1);
    } else if (event_code == ci::app::KeyEvent::KEY_s) {
      player_->UpdateLocation(1, 0);
    } else if (event_code == ci::app::KeyEvent::KEY_d) {
      player_->UpdateLocation(0, 1);
    } else if (event_code == ci::app::KeyEvent::KEY_SPACE) { //Handles tile interactions in general
      // First checks for items, then portals, then gates
      //Checks if player location has an item
      Item* current_item = current_room_->GetItems().at(player_->GetRow()).at(player_->GetCol());
      if (current_item != nullptr) {
        current_room_->RemoveItem(player_->GetRow(), player_->GetCol());
        player_->AddItem(current_item);
        current_room_->UpdatePlayerHealth(player_->GetMaxHp(), player_->GetCurrHp(), player_->GetPlayerVit());
      } else {
        //Checks through all portals in the room to see if one is at the player location
        std::vector<Portal*> portals = current_level_->GetPortals().at(current_room_->GetOrder());
        bool portal_found = false;
        for (size_t index = 0; index < portals.size(); index++) {
          Portal* current_portal = portals.at(index);
          if (current_portal->GetRoom()->GetOrder() == current_room_->GetOrder()) {
            if (player_->GetCol() == current_portal->GetCol() && player_->GetRow() == current_portal->GetRow()) {
              portal_found = true;
              current_room_ = current_portal->Interact(player_);
              break;
            }
          }
        }
        //checks if the player is interacting with a gate
        if (!portal_found) {
          if (current_room_->GetOrder() == current_level_->GetRooms().size() - 1) {
            Gate* gate = current_level_->GetGate();
            if (player_->GetRow() == gate->GetRow() && player_->GetCol() == gate->GetCol()) {
              InteractGate();
            }
          }
        }
      }
    } else if (event_code == ci::app::KeyEvent::KEY_e) { //Handles inventory
      OpenInventory();
    } else if (event_code == ci::app::KeyEvent::KEY_UP) { //Fires projectiles in different directions
        player_->FireProjectile(0);
    } else if (event_code == ci::app::KeyEvent::KEY_DOWN) {
      player_->FireProjectile(1);
    } else if (event_code == ci::app::KeyEvent::KEY_RIGHT) {
      player_->FireProjectile(2);
    } else if (event_code == ci::app::KeyEvent::KEY_LEFT) {
      player_->FireProjectile(3);
    }
  } else { //if the player is looking at their inventory
    if (event_code == ci::app::KeyEvent::KEY_e) {
      CloseInventory();
    }
  }

}

void GameEngine::InteractGate() {
  //Updates the level number
  level_num_++;
  //Deletes the current level, generating a new one and updating the player's room
  delete current_level_;
  current_level_ = level_gen_.GenerateLevel();
  current_room_ = current_level_->GetRooms().at(0);
  player_->UpdateRoom(current_room_);
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

  //Displays each item in the player's inventory
  ci::gl::drawStringCentered("inventory", glm::vec2(kWindowWidth / 2, kRoomMargin / 2));
  std::vector<Item*> inventory_items = player_->GetInventory();
  for (size_t index = 0; index < inventory_items.size(); index++) {
    ci::gl::drawStrokedRect(ci::Rectf(
            glm::vec2(kRoomMargin, kRoomMargin * (index + 1)),
            glm::vec2(kWindowWidth - kRoomMargin,kRoomMargin + kRoomMargin * (index + 1))));
    ci::gl::drawString(inventory_items.at(index)->GetSummary(),
                       glm::vec2(kRoomMargin + 5, kRoomMargin * (index + 1) + kRoomMargin / 2));
  }
}

void GameEngine::DisplayWin() {
  ci::gl::drawStringCentered("You Win!!! press R to restart", glm::vec2(kWindowWidth / 2, kWindowHeight / 2));
  results_screen_ = true;
}

void GameEngine::DisplayLoss() {
  ci::gl::drawStringCentered("You Lose... press R to restart", glm::vec2(kWindowWidth / 2, kWindowHeight / 2));
  results_screen_ = true;
}

} // namespace finalproject