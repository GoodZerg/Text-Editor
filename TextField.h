#pragma once
#include "WidgetComponent.h"
class TextField : 
   public WidgetComponent
{
public:
  TextField(vec2<float> pos, vec2<float> size, std::string& str, WidgetComponent* Decorator = nullptr);
  void render();
private:
  std::string _text = "";
};

