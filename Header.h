#pragma once

#include <functional>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<vector>
#include<string>

constexpr int zero_int = 0;


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
