#pragma once
#include "RenderInterface.h"
class WidgetComponent :
  public RenderInterface
{
public:
  WidgetComponent(vec2<int> pos, vec2<int> size, WidgetComponent* Decorator = nullptr);
  void render() override;
private:
  vec2<int> pos;
  vec2<int> size;
  WidgetComponent* Decorator = nullptr;
};

