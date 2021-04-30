//
// Created by Larry Peng on 4/18/21.
//

#include "game/room.h"

namespace finalproject {

Room::Room() {
  width_ = 0;
  height_ = 0;
  margin_ = 0;
  obstacles_ = std::vector<std::vector<Obstacle*>>(height_, std::vector<Obstacle*>(width_));
  items_ = std::vector<std::vector<Item*>>(height_, std::vector<Item*>(width_));
  enemies_ = std::vector<std::vector<Enemy*>>(height_, std::vector<Enemy*>(width_));
  order_ = 0;
}


Room::Room(double height, double width, double margin, size_t order) {
  height_ = height;
  width_ = width;
  margin_ = margin;
  obstacles_ = std::vector<std::vector<Obstacle*>>(height_, std::vector<Obstacle*>(width_));
  items_ = std::vector<std::vector<Item*>>(height_, std::vector<Item*>(width_));
  enemies_ = std::vector<std::vector<Enemy*>>(height_, std::vector<Enemy*>(width_));
  order_ = order;
}

void Room::Display() {
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
      size_t remaining_range = current_proj->Display();
      if (remaining_range <= 0) {
        RemoveProj(index);
      }
    }
  }
  CleanProjectiles();

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

      Enemy* current_enemy = enemies_.at(row).at(col);
      if (current_enemy != nullptr) {
        double remaining_hp = current_enemy->TakeDamage(strength);
        std::cout << "Hit!" << std::endl;
        if (remaining_hp <= 0) {
          std::cout << "Killed" << std::endl;
          delete current_enemy;
          enemies_.at(row).at(col) = nullptr;
        }
        RemoveProj(index);
      }
      Obstacle* current_obstacle = obstacles_.at(row).at(col);
      if (current_obstacle != nullptr) {
        std::cout << "Blocked" << std::endl;
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

size_t Room::GetOrder() const {
  return order_;
}

size_t Room::GetHeight() const {
  return height_;
}

size_t Room::GetWidth() const {
  return width_;
}


} // namespace finalproject