//
// Created by Larry Peng on 4/18/21.
//
#include <catch2/catch.hpp>
#include "entity/enemy.h"
#include "entity/player.h"
#include "entity/portal.h"
#include "entity/projectile.h"
#include "game/item.h"
#include "game/room.h"

using finalproject::Enemy;
using finalproject::Player;
using finalproject::Portal;
using finalproject::Projectile;
using finalproject::Item;
using finalproject::Room;

TEST_CASE("Player") {
  //Create player
  Player* player = new Player();

  Room* room = new Room(5, 5, 1, 0, 10, 10);

  player->UpdateRoom(room);

  SECTION("Destructor") {
    delete player;
  }

  SECTION("Update Valid Location") {
    player->UpdateLocation(0, 1);
    REQUIRE(player->GetRow() == 0);
    REQUIRE(player->GetCol() == 1);


    player->UpdateLocation(3, -1);
    REQUIRE(player->GetRow() == 3);
    REQUIRE(player->GetCol() == 0);
  }

  SECTION("Update Invald Location") {
    //out of bounds
    player->UpdateLocation(100, 100);
    REQUIRE(player->GetRow() == 0);
    REQUIRE(player->GetCol() == 0);

    player->UpdateLocation(-100, -100);
    REQUIRE(player->GetRow() == 0);
    REQUIRE(player->GetCol() == 0);

    player->UpdateLocation(-100, 100);
    REQUIRE(player->GetRow() == 0);
    REQUIRE(player->GetCol() == 0);

    player->UpdateLocation(100, -100);
    REQUIRE(player->GetRow() == 0);
    REQUIRE(player->GetCol() == 0);
  }

  SECTION("Item Pickup") {
    Item* item = new Item("name", 100, 0, 0 ,0 ,0);
    player->AddItem(item);

    std::vector<Item*> inv = player->GetInventory();
    REQUIRE(inv.size() == 1);
    REQUIRE(inv.at(0) == item);

    REQUIRE(player->GetMaxHp() == 300); //item increases hp from 200 to 100
  }
}

TEST_CASE("Enemy") {
  Enemy enemy = Enemy(10, 10, 10, 10, 10);
  SECTION("Fire Projectile") {
    Projectile* proj = enemy.FireProjectile(0, 0, 0, 0);

    REQUIRE(proj->GetStrength() == 10);
    REQUIRE(proj->GetRow() == 0);
    REQUIRE(proj->GetCol() == 0);
  }
}

TEST_CASE("Portal") {
  Room* room = new Room(5, 5, 1, 0, 10, 10);
  Player* player = new Player();

  SECTION("Linking Portals within a Room") {
    Portal* portal = new Portal(0, 0, *room, false);
    Portal* portal_two = new Portal(0, 0, *room, false);
    portal->LinkPortal(*portal_two);

    REQUIRE(portal->Interact(player) == room);
  }

  SECTION("Linking Portals between Rooms") {
    Room* room_two = new Room(10, 10, 1, 0, 10, 10);
    Portal* portal = new Portal(0, 0, *room, true);
    Portal* portal_two = new Portal(0, 0, *room_two, true);
    portal->LinkPortal(*portal_two);

    REQUIRE(portal->Interact(player) == room_two);
  }
}
