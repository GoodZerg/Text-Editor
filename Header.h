#pragma once

#include <functional>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <string>
#include <map>
#include <stdexcept>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

static std::vector<std::string*> main_array;


template <typename T>
struct vec2 {
  T x;
  T y;
  vec2(T x, T y) {
    this->x = x;
    this->y = y;
  }
  vec2() {};
};

template <typename T>
struct vec3 {
  T x;
  T y;
  T z;
  vec3(T x, T y, T z) {
    this->x = x;
    this->y = y;
    this->z = z;
  }
  vec3() {};
};


