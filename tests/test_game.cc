//
// Created by Larry Peng on 4/18/21.
//
#include <catch2/catch.hpp>
#include "game/item.h"
#include "game/level.h"
#include "game/room.h"
#include "entity/enemy.h"
#include "entity/portal.h"

using finalproject::Item;
using finalproject::Level;
using finalproject::Room;
using finalproject::Portal;
using finalproject::Enemy;

TEST_CASE("Item") {
  Item* item = new Item("Name", 0, 0, 0, 10, 10);
  SECTION("Summary") {
    std::string summary = item->GetSummary();
    REQUIRE("Name  |  HP: 0  ATK: 0  RNG: 0  SHOT: 10  VIT: 10  " == summary);
  }
}

TEST_CASE("Level") {
  Level* level = new Level(10);
  SECTION("Adding Valid Rooms") {
    Room* room_one = new Room(0, 0, 0, 1, 0, 0);
    Room* room_four = new Room(0, 0, 0, 4, 0, 0);
    Room* room_seven = new Room(0, 0, 0, 7, 0, 0);

    level->AddRoom(room_one);
    level->AddRoom(room_four);
    level->AddRoom(room_seven);

    std::vector<Room*> rooms = level->GetRooms();

    REQUIRE(rooms.at(1) == room_one);
    REQUIRE(rooms.at(4) == room_four);
    REQUIRE(rooms.at(7) == room_seven);
  }

  SECTION("Adding Invalid Room") {
    Room* room_eleven = new Room(0, 0, 0, 11, 0, 0);

    REQUIRE_THROWS_AS(level->AddRoom(room_eleven), std::invalid_argument);
  }

  SECTION("Adding Valid Portals") {
    Room* room_one = new Room(10, 10, 0, 1, 10, 10);

    Portal* portal = new Portal(0, 0, *room_one, false);
    level->AddPortal(portal);

    REQUIRE(level->GetPortals().at(1).size() == 1);
    REQUIRE(level->GetPortals().at(1).at(0) == portal);
  }

  SECTION("Adding Invalid Portal") {
    Room* room_hundo = new Room(10, 10, 0, 100, 0, 10);

    Portal* portal = new Portal(0, 0, *room_hundo, false);
    REQUIRE_THROWS_AS(level->AddPortal(portal), std::invalid_argument);
  }

}

TEST_CASE("Room") {
  Room* room = new Room(5, 5, 1, 0, 10, 10);
  SECTION("Destructor") {
    delete room;
  }

  SECTION("Add Valid Enemy") {
    Enemy* enemy = new Enemy(10, 10, 10, 10, 10);
    room->AddEnemy(enemy, 0, 0);

    REQUIRE(room->GetEnemies().at(0).at(0) == enemy);
  }

  SECTION("Add Invalid Enemy") {
    Enemy* enemy = new Enemy(10, 10, 10, 10, 10);

    REQUIRE_THROWS_AS(room->AddEnemy(enemy, 100, -10), std::invalid_argument);
  }

  SECTION("Add Valid Item") {
    Item* item = new Item("Name", 0, 0, 0, 10, 10);
    room->AddItem(item, 0, 0);

    REQUIRE(room->GetItems().at(0).at(0) == item);
  }

  SECTION("Add Invalid Item") {
    Item* item = new Item("Name", 0, 0, 0, 10, 10);

    REQUIRE_THROWS_AS(room->AddItem(item, -1, 5), std::invalid_argument);
  }

  SECTION("Add Valid Obstacle") {
    room->DesignateObstacle(0, 0);

    REQUIRE(room->GetObstacles().at(0).at(0) != nullptr);
  }

  SECTION("Add Invalid Obstacle") {
    REQUIRE_THROWS_AS(room->DesignateObstacle(100, 100), std::invalid_argument);
  }

  SECTION("Add Invalid Obstacle From Overlap") {
    room->MarkOccupied(0, 0);
    room->DesignateObstacle(0, 0);
    //Does not allow obstacle to exist on a grid with another entity
    REQUIRE(room->GetObstacles().at(0).at(0) == nullptr);
  }
}

