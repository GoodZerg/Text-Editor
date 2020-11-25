#include "WidgetComponent.h"

WidgetComponent::WidgetComponent(vec2<int> pos, vec2<int> size, WidgetComponent* Decorator)
{
  this->pos = pos;
  this->size = size;
  this->Decorator = Decorator;
}
void WidgetComponent::render()
{
  
}
