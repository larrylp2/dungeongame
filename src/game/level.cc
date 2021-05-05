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

Level::~Level() {
  //delete the rooms within the floor
  for(size_t order = 0; order < rooms_.size(); order++) {
    if (rooms_.at(order) != nullptr) {
      delete rooms_.at(order);
    }
    //Deletes the portals within the floor
    for (size_t portal = 0; portal < portals_.at(order).size(); portal++) {
      if (portals_.at(order).at(portal) != nullptr) {
        delete portals_.at(order).at(portal);
      }
    }
  }
  //deletes the gate of the floor
  delete gate_;
}

void Level::AddPortal(Portal* portal) {
  Room* portal_room = portal->GetRoom();
  size_t index = portal_room->GetOrder();
  portals_.at(index).push_back(portal);
}


std::vector<std::vector<Portal*>> Level::GetPortals() const {
  return portals_;
}

std::vector<Room*> Level::GetRooms() const {
  return rooms_;
}

void Level::AddRoom(Room* room) {
  rooms_.at(room->GetOrder()) = room;
  room_num_++;
}

void Level::Display(size_t room_order) const {
  //Displays the room, then displays all the portals or gates within the room
  rooms_.at(room_order)->Display();
  for (size_t index = 0; index < portals_.at(room_order).size(); index++) {
    portals_.at(room_order).at(index)->Display( rooms_.at(room_order)->GetGridSize());
  }
  if (room_order == room_cap_ - 1) {
    gate_->Display();
  }
}

void Level::SetGate(Gate* gate) {
  gate_ = gate;
}

Gate* Level::GetGate() const {
  return gate_;
}

} // namespace finalproject