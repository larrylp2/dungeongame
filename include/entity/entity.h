//
// Created by Larry Peng on 4/19/21.
//

#pragma once

#include "cinder/gl/gl.h"

namespace finalproject {

/**
 * Class that handles entities within a game (may remove later)
 */
class Entity {
 public:
  Entity();
  /**
   * Returns the pixel location of this entity
   * @return the pixel location
   */
  glm::vec2 GetLocation() const;

  /**
   * Returns the name of this entity
   * @return the name
   */
  std::string GetName() const;

  /**
   * Displays the current entity
   */
  void Display() const;

  //Need to fix OOP to allow for an Interact(Player) method here
  //Does not work because of circular dependency with header files

 private:

  //Location of the entity
  //Need to figure out how to use this with child classes in C++ OOP
  //glm::vec2 pixel_loc_;

  //glm::vec2 grid_loc_;

  //std::string name_;

};

}