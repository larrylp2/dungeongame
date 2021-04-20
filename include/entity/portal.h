//
// Created by Larry Peng on 4/19/21.
//

#pragma once
#include "cinder/gl/gl.h"

namespace finalproject {

class Portal {
 public:
  Portal();
  /**
   * Default constructor for a portal
   *
   * @param location the location of this portal
   */
  Portal(const glm::vec2& location);


  /**
   * Destructor for a portal
   */

  /**
   * Copy Constructor
   */

  /**
   * Copy Operator
   */

  /**
   * Move Constructor
   */

  /**
   * Move Operator
   */


  /**
   * Links this portal to another portal.
   *
   * @param destination a pointer to another portal
   */
  void LinkPortal(Portal& destination);

  /**
   * Displays a portal
   */
  void Display() const;

  /**
   * Gets the location of the portal.
   *
   * @return the location
   */
  glm::vec2 GetLocation() const;

  /**
   * Gets the destination of the portal.
   *
   * @return the portal
   */
  Portal GetDestination() const;

 private:
  //destination portal this leads to
  Portal* destination_;

  //The location of this portal
  glm::vec2 location_;
};

}