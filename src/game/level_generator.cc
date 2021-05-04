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

  //create random seeds
  std::srand(std::time(nullptr));
}

Level* LevelGenerator::GenerateLevel() const {

  Level* level = new Level(kLevelSize);
  std::cout << "Level Created" << std::endl;
  //First create all of the rooms within the level
  for (size_t order = 0; order < kLevelSize; order++) {
    int room_height = rand() % 5 + 5; //Generate random number from 5 to 10
    int room_width =  rand() % 5 + 10; //Generate random number from 5 to 15

    //Currently a glitch that all rooms are generated with the same dimensions
    level->AddRoom(new Room(room_height, room_width, grid_margin_, order, window_height_, window_width_));
    std::cout << room_height << " by " << room_width << " room added at order " << order << std::endl;
  }

  //Then create the inter-portals linking the rooms together
  //Every room will have two inter-portals except the first and last
  std::vector<Room*> rooms = level->GetRooms();
  for(size_t order = 0; order < kLevelSize; order++) {
    if (order < kLevelSize - 1) {
      Room* current_room = rooms.at(order);
      size_t current_room_height = current_room->GetHeight();
      size_t current_room_width = current_room->GetWidth();

      //Generate a random location within the current room
      int row = rand() % current_room_height;
      int col = rand() % current_room_width;

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
    }
  }
  return level;
}

}

