//
// Created by Larry Peng on 4/18/21.
//

#include "game/room.h"

namespace finalproject {

Room::Room(double height, double width, double margin, size_t order, double window_height, double window_width) {
  height_ = height;
  width_ = width;
  margin_ = margin;
  obstacles_ = std::vector<std::vector<Obstacle*>>(height_, std::vector<Obstacle*>(width_));
  items_ = std::vector<std::vector<Item*>>(height_, std::vector<Item*>(width_));
  enemies_ = std::vector<std::vector<Enemy*>>(height_, std::vector<Enemy*>(width_));
  order_ = order;

  window_height_ = window_height;
  window_width_ = window_width;

  //create random seed
  std::srand(std::time(nullptr));
}

void Room::Display() {
  ExecuteEnemyActions();
  for (size_t row = 0; row < height_; row++) {
    for(size_t column = 0; column < width_; column++) {
      //Draws a grid from many empty rectangles
      ci::gl::color(ci::Color("white"));
      ci::gl::drawStrokedRect(ci::Rectf(
              glm::vec2(column * kGridSide,  row * kGridSide),
              glm::vec2((column + 1) * kGridSide,  (row + 1) * kGridSide)));
      Obstacle* current_obstacle = obstacles_.at(row).at(column);
      if (current_obstacle != nullptr) {
        current_obstacle->Display(row, column, kGridSide);
      }
      Item* current_item = items_.at(row).at(column);
      if (current_item != nullptr) {
        current_item->Display(row, column, kGridSide);
      }
      Enemy* current_enemy = enemies_.at(row).at(column);
      if (current_enemy != nullptr) {
        current_enemy->Display(row, column, kGridSide);
      }
    }
  }
  CheckProjectileCollisions();
  for (size_t index = 0; index < projectiles_.size(); index++) {
    Projectile* current_proj = projectiles_.at(index);
    if (current_proj != nullptr) {
      size_t remaining_range = current_proj->Display(width_, height_);
      if (remaining_range <= 0) {
        RemoveProj(index);
      }
    }
  }
  CleanProjectiles();
  DisplayHealth();
}

void Room::DisplayHealth() const {
  double health_ratio = (1.0 * player_curr_hp_) / player_max_hp_;
  if (health_ratio > .7) { //Color of health bar changes as health drops
    ci::gl::color(ci::Color("green"));
  } else if (health_ratio > .3) {
    ci::gl::color(ci::Color("yellow"));
  } else {
    ci::gl::color(ci::Color("red"));
  }

  ci::gl::drawSolidRect(ci::Rectf(
          glm::vec2(kGridSide,  window_height_ - 2 * kGridSide),
          glm::vec2(health_ratio * (window_width_ - 2 * kGridSide) + kGridSide,  window_height_ - kGridSide)));
}


void Room::AddItem(Item* item, size_t row, size_t col) {
  items_.at(row).at(col) = item;
}

void Room::AddEnemy(Enemy* enemy, size_t row, size_t col) {
  enemies_.at(row).at(col) = enemy;
}

void Room::AddProjectile(Projectile* proj) {
  projectiles_.push_back(proj);
}

void Room::RemoveProj(size_t index) {
  delete projectiles_.at(index);
  projectiles_.at(index) = nullptr;
}

void Room::CleanProjectiles() {
  bool all_null = true;
  for (size_t proj = 0; proj < projectiles_.size(); proj++) {
    if (projectiles_.at(proj) != nullptr) {
      all_null = false;
      break;
    }
  }
  if (all_null) {
    projectiles_ = std::vector<Projectile*>(0);
  }
}


void Room::CheckProjectileCollisions() {
  for (size_t index = 0; index < projectiles_.size(); index++) {
    Projectile* current_proj = projectiles_.at(index);
    if (current_proj != nullptr) {
      size_t row = current_proj->GetRow();
      size_t col = current_proj->GetCol();
      double strength = current_proj->GetStrength();
      if (current_proj->IsPlayer()) {
        Enemy* current_enemy = enemies_.at(row).at(col);
        if (current_enemy != nullptr) {
          double remaining_hp = current_enemy->TakeDamage(strength);
          std::cout << "Hit Enemy!" << std::endl;
          if (remaining_hp <= 0) {
            std::cout << "Killed" << std::endl;
            delete current_enemy;
            enemies_.at(row).at(col) = nullptr;
          }
          RemoveProj(index);
        }
      } else {
        if (row == player_row_ && col == player_col_) {
          std::cout << "Player Hit!" << std::endl;
          player_curr_hp_ -= strength;
          RemoveProj(index);
        }
      }
      Obstacle* current_obstacle = obstacles_.at(row).at(col);
      if (current_obstacle != nullptr) {
        std::cout << "Obstacle Hit!" << std::endl;
        RemoveProj(index);
      }
    }
  }
  CleanProjectiles();
}


void Room::RemoveItem(size_t row, size_t col) {
  items_.at(row).at(col) = nullptr;
}


double Room::GetGridSize() const {
  return kGridSide;
}

void Room::DesignateObstacles(const std::vector<std::tuple<size_t, size_t>>& coordinates) {
  Obstacle obstacle = Obstacle();
  for (size_t index = 0; index < coordinates.size(); index++) {
    std::tuple<size_t, size_t> pair = coordinates.at(index);
    obstacles_.at(std::get<0>(pair)).at(std::get<1>(pair)) = &obstacle;
  }
}

std::vector<std::vector<Obstacle*>> Room::GetObstacles() const {
  return obstacles_;
}

std::vector<std::vector<Item*>> Room::GetItems() const {
  return items_;
}

std::vector<std::vector<Enemy*>> Room::GetEnemies() const {
  return enemies_;
}

bool Room::AddEnemyTo2DVector(Enemy* enemy, std::vector<std::vector<Enemy*>>& enemy_loc, size_t row, size_t col) {
  if (row >= 0 && col >= 0 && row < height_ && col < width_) {
    if (enemy_loc.at(row).at(col) == nullptr) {
      enemy_loc.at(row).at(col) = enemy;
    } else {
      std::cout << "Enemy Collision" << std::endl;
      if (row + 1 < height_) {
        return AddEnemyTo2DVector(enemy, enemy_loc, row + 1, col);
      } else if (col + 1 < width_) {
        return AddEnemyTo2DVector(enemy, enemy_loc, row, col + 1);
      } else if (row - 1 >= 0) {
        return AddEnemyTo2DVector(enemy, enemy_loc, row - 1, col);
      } else if (col - 1 >= 0) {
        return AddEnemyTo2DVector(enemy, enemy_loc, row, col - 1);
      } else {
        std::cout << "Enemy has no valid square to occupy" << std::endl;
        delete enemy;
      }
    }
    return true;
  } else {
    return false;
  }
}

void Room::ExecuteEnemyActions() {
  //Create empty 2d vector with enemy locations
  std::vector<std::vector<Enemy*>> new_enemy_loc(height_, std::vector<Enemy*>(width_));
  for (size_t row = 0; row < enemies_.size(); row++) {
    for (size_t col = 0; col < enemies_.at(0).size(); col++) {
      Enemy* current_enemy = enemies_.at(row).at(col);
      if (current_enemy != nullptr) { //If this enemy exists, generate random number to determine its direction of movement
        //Generate random number from 0 to 250, only moving when that number falls between 0 to 4
        int number = rand() % 250;

        //Handles Movement
        bool move_successful = true;
        if (number <= 1) { //Move north
          move_successful = AddEnemyTo2DVector(current_enemy, new_enemy_loc, row - 1, col);
        } else if (number <= 2 ) { //Move south
          move_successful = AddEnemyTo2DVector(current_enemy, new_enemy_loc, row + 1, col);
        } else if (number <= 3) { //Move east
          move_successful = AddEnemyTo2DVector(current_enemy, new_enemy_loc, row, col + 1);
        } else if (number <= 4) { //Move west
          move_successful = AddEnemyTo2DVector(current_enemy, new_enemy_loc, row, col - 1);
        } else {
          move_successful = AddEnemyTo2DVector(current_enemy, new_enemy_loc, row, col);
        }
        if (!move_successful) { //Maintains the enemy's current position if it tried to be moved out of bounds
          AddEnemyTo2DVector(current_enemy, new_enemy_loc, row, col);
        }

        //Handles Projectiles
        size_t fire_freq = current_enemy->GetFireFrequency();
        //Generate random number from 0 to firing frequency, only firing a projectile when number is between 0 and 4
        number = rand() % fire_freq;
        if (number <= 1) { //Fires north
          AddProjectile(current_enemy->FireProjectile(row, col, 0, kGridSide));
        } else if (number <= 2) { //Fires south
          AddProjectile(current_enemy->FireProjectile(row, col, 1, kGridSide));
        } else if (number <= 3) { //Fires east
          AddProjectile(current_enemy->FireProjectile(row, col, 2, kGridSide));
        } else if (number <= 4) { //Fires west
          AddProjectile(current_enemy->FireProjectile(row, col, 3, kGridSide));
        }
      }
    }
  }
  enemies_ = new_enemy_loc;
}

size_t Room::GetOrder() const {
  return order_;
}

void Room::UpdatePlayerLocation(size_t row, size_t col) {
  player_row_ = row;
  player_col_ = col;
}

void Room::UpdatePlayerHealth(size_t max, size_t current) {
  player_max_hp_ = max;
  player_curr_hp_ = current;
}


size_t Room::GetHeight() const {
  return height_;
}

size_t Room::GetWidth() const {
  return width_;
}

size_t Room::GetMax() const {
  return player_max_hp_;
}

size_t Room::GetCurrent() const {
  return player_curr_hp_;
}


} // namespace finalproject