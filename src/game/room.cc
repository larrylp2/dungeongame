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

void Room::Display() const {
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
}

void Room::AddItem(Item* item, size_t row, size_t col) {
  items_.at(row).at(col) = item;
}

void Room::AddEnemy(Enemy* enemy, size_t row, size_t col) {
  enemies_.at(row).at(col) = enemy;
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