//
// Created by Larry Peng on 5/4/21.
//

#include "game/level_generator.h"
#include <time.h>
#include <random>

namespace finalproject {

LevelGenerator::LevelGenerator(double window_width, double window_height, double grid_margin) {
  window_width_ = window_width;
  window_height_ = window_height;
  grid_margin_ = grid_margin;

  //create random seed
  std::srand(std::time(nullptr));
}

Level* LevelGenerator::GenerateLevel() const {

  Level* level = new Level(kLevelSize);
  std::cout << "Level Created" << std::endl;
  //First create all of the rooms within the level
  GenerateRooms(level);

  //Then create the inter-portals linking the rooms together
  GeneratePortals(level);

  //Create enemies within each room
  GenerateEnemies(level);

  //Create items within the room
  GenerateItems(level);

  //Create obstacles within the room
  GenerateObstacles(level);

  return level;
}

void LevelGenerator::GenerateRooms(Level* level) const {
  for (size_t order = 0; order < kLevelSize; order++) {
    std::srand(std::time(nullptr) + order); //Need to add this else all rooms are generated with same dimensions
    int room_height = rand() % 5 + 5; //Generate random number from 5 to 10
    int room_width =  rand() % 5 + 10; //Generate random number from 5 to 15

    level->AddRoom(new Room(room_height, room_width, grid_margin_, order, window_height_, window_width_));
    std::cout << room_height << " by " << room_width << " room added at order " << order << std::endl;
  }
}

void LevelGenerator::GeneratePortals(Level* level) const {
  //Every room will have two inter-portals except the first and last
  //Last room will have a gate
  std::vector<Room*> rooms = level->GetRooms();
  for(size_t order = 0; order < kLevelSize; order++) {
    Room* current_room = rooms.at(order);
    size_t current_room_height = current_room->GetHeight();
    size_t current_room_width = current_room->GetWidth();

    //Generate a random location within the current room
    int row = rand() % current_room_height;
    int col = rand() % current_room_width;
    if (order < kLevelSize - 1) {
      Portal* start = new Portal(row, col, *current_room, true);

      Room* next_room = rooms.at(order + 1);
      size_t next_room_height = next_room->GetHeight();
      size_t next_room_width = next_room->GetWidth();

      //Generate a random location within the current room
      int row2 = rand() % next_room_height;
      int col2 = rand() % next_room_width;

      Portal* end = new Portal(row2, col2, *next_room, true);

      //Link the two portals together
      start->LinkPortal(*end);
      end->LinkPortal(*start);
      level->AddPortal(start);
      level->AddPortal(end);
    } else {
      current_room->MarkOccupied(row, col);
      Gate* gate = new Gate(row, col);
      level->SetGate(gate);
    }
  }
}

void LevelGenerator::GenerateEnemies(Level *level) const {
  //Every room will have some number of enemies, but the last will have stronger enemies
  std::vector<Room*> rooms = level->GetRooms();
  for(size_t order = 0; order < kLevelSize; order++) {
    Room* current_room = rooms.at(order);
    size_t current_room_height = current_room->GetHeight();
    size_t current_room_width = current_room->GetWidth();

    // Find the total number of possible grid squares there are
    size_t total_squares = current_room_height * current_room_width;

    size_t enemy_max;
    int num_enemies;
    if (order == kLevelSize - 1) {
      enemy_max = .05 * total_squares; //half as many enemies as normal room
      num_enemies = rand() % enemy_max + 5;
    } else {
      enemy_max = .1 * total_squares; //In normal room, no more than 1/10th of squares
      num_enemies = rand() % enemy_max;
    }

    std::cout << num_enemies << " enemies generated in room " << order << std::endl;

    for (size_t enemy = 0; enemy < num_enemies; enemy++) {
      int health = rand() % 120 + 50; // 50 to 170 health
      int attack = rand() % 5 + 5; // 5 to 10 attack
      int range = rand() % 200 + 100; // 100 to 300 range
      int shot = rand() % 4 + 1; // 1 to 5 shot speed
      int freq = rand() % 150 + 50; // 70 to 220 fire frequency
      if (order == kLevelSize - 1) { //last room enemies have better stats
        health += 50;
        attack += 10;
        range += 50;
        shot += 2;
        freq -= 20;
      }

      Enemy* foe = new Enemy(health, attack, range, shot, freq);

      //Generate a random location within the current room
      int row = rand() % current_room_height;
      int col = rand() % current_room_width;
      current_room->AddEnemy(foe, row, col);
    }
  }
}

void LevelGenerator::GenerateObstacles(Level* level) const {
  //Every room will have a low number of obstacles (do not want portals to be unreachable)
  std::vector<Room*> rooms = level->GetRooms();
  for(size_t order = 0; order < kLevelSize; order++) {
    Room* current_room = rooms.at(order);
    size_t current_room_height = current_room->GetHeight();
    size_t current_room_width = current_room->GetWidth();

    // Find the total number of possible grid squares there are
    size_t total_squares = current_room_height * current_room_width;

    // No more than 1/5th of the room should be filled with obstacles
    size_t enemy_max = .2 * total_squares;

    int obstacles = rand() % enemy_max;

    for (size_t obs = 0; obs < obstacles; obs++) {
      //Generate a random location within the current room
      int row = rand() % current_room_height;
      int col = rand() % current_room_width;
      current_room->DesignateObstacle(row, col);
    }
  }
}

void LevelGenerator::GenerateItems(Level* level) const {
  //Every room will have 1 item, with the last room having a stronger item
  std::vector<Room*> rooms = level->GetRooms();
  for(size_t order = 0; order < kLevelSize; order++) {
    Room* current_room = rooms.at(order);
    size_t current_room_height = current_room->GetHeight();
    size_t current_room_width = current_room->GetWidth();

    int health = rand() % 50 + 50; // 50 to 100 health
    int attack = rand() % 5 + 5; // 5 to 10 attack
    int defense = rand() % 1; // 0 to 1 defense
    int range = rand() % 20 + 10; // 10 to 30 range
    int shot = rand() % 1; // 0 to 1 shot speed
    int vit = rand() % 8; // 0 to 8 vitality
    if (order == kLevelSize - 1) { //last room items have better stats
      health += 50;
      attack += 10;
      range += 50;
      shot += 1;
    }

    //Generate a random location within the current room
    int row = rand() % current_room_height;
    int col = rand() % current_room_width;
    Item* item = new Item("item", health, attack, defense, range, shot, vit);
    current_room->AddItem(item, row, col);
  }
}



}

