//
// Created by Larry Peng on 4/18/21.
//

#pragma once

#include <vector>
#include "entity/entity.h"
#include "entity/portal.h"

namespace finalproject {

class Room {
 public:
  /**
   * Default constructor for a room
   */
  Room();

  /**
   * Constructor for a room of a certain size
   * @param width the width of the room
   * @param height the height of the room
   * @param margin the margin between room edges and the window edges
   */
  Room(double width, double height, double margin);

  /**
   * Displays the room within the game
   */
  void Display() const;

  /**
   * Adds an entity to this room
   *
   * @param entity the entity to add to this room
   */
  void AddEntity(Entity& entity);

  /**
   * Adds a portal to this room
   *
   * @param portal the portal to add to this room
   */
  void AddPortal(Portal& portal);

  /**
   * Gets the entities within the room
   */
  std::vector<Entity> GetEntities() const;

  /**
   * Gets the portals within the room
   */
  std::vector<Portal> GetPortals() const;

 private:

  std::vector<Entity> entities_;

  std::vector<Portal> portals_;

  double width_;
  double height_;
  double margin_;
};


}