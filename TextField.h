#pragma once
#include "WidgetComponent.h"
class TextField : public WidgetComponent
{
public:
  TextField(vec2<int> pos, vec2<int> size, std::string& str, WidgetComponent* Decorator = nullptr);
  void render();
private:
  std::string text = "";
};

