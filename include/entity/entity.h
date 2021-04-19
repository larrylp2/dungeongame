//
// Created by Larry Peng on 4/19/21.
//

#pragma once

#include "cinder/gl/gl.h"

namespace finalproject {

namespace entity {

class Entity {
 public:
  /**
   * Returns the pixel location of this entity
   * @return the pixel location
   */
  glm::vec2 GetPixelLoc() const;

  /**
   * Returns the grid location of this entity within a room
   * @return the grid location
   */
  glm::vec2 GetGridLoc() const;

  /**
   * Returns the name of this entity
   * @return the name
   */
  std::string GetName() const;

  /**
   * Displays the current entity
   */
  void Display() const;

 private:

  //Location of the entity
  //Need to figure out how to use this with child classes in C++ OOP
  glm::vec2 pixel_loc_;

  //glm::vec2 grid_loc_;

  std::string name_;

};



}


}