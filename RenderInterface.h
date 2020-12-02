#pragma once

#include "Header.h"

class RenderInterface {
public:
  virtual void render(GLFWwindow* window) = 0;
};

