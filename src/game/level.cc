//
// Created by Larry Peng on 4/19/21.
//

#include "game/level.h"

namespace finalproject {

Level::Level(size_t room_cap) {
  room_cap_ = room_cap;
  rooms_ = std::vector<Room*>(room_cap_);
  portals_ = std::vector<std::vector<Portal*>>(room_cap_, std::vector<Portal*>(0));
}

void Level::AddPortal(Portal* portal) {
  Room* portal_room = portal->GetRoom();
  size_t index = portal_room->GetOrder();
  portals_.at(index).push_back(portal);
}


std::vector<std::vector<Portal*>> Level::GetPortals() const {
  return portals_;
}


void Level::AddRoom(Room* room) {
  rooms_.at(room->GetOrder()) = room;
  room_num_++;
}

void Level::Display(size_t room_order) const {
  rooms_.at(room_order)->Display();
  for (size_t index = 0; index < portals_.at(room_order).size(); index++) {
    portals_.at(room_order).at(index)->Display(rooms_.at(room_order)->GetGridSize());
  }
}


}