#pragma once

#include "WidgetComponent.h"
#include <ft2build.h>
#include FT_FREETYPE_H  

struct Character;

class TextField : 
   public WidgetComponent
{
public:
  TextField(vec2<float> pos, vec2<float> size, std::vector<std::string*>& str, WidgetComponent* Decorator = nullptr);
  void render(GLFWwindow* window);
  std::vector<std::string*> _text;
  void rec();
  void dec(GLFWwindow* window);
  int shaderProgramText;
private:
  std::map<char, Character> _Characters;
  unsigned int VAO_, VBO_;
  void _renderText(float scale, vec3<float> color, GLFWwindow* window);
};


struct Character {
  unsigned int TextureID; // ID текстуры глифа
  vec2<int> Size; // размер глифа
  vec2<int> Bearing; // смещение от линии шрифта до верхнего/левого угла глифа
  unsigned int Advance; // смещение до следующего глифа
};
