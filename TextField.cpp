#include "TextField.h"

TextField::TextField(vec2<int> pos, vec2<int> size, std::string& str, WidgetComponent* Decorator)
  : WidgetComponent(pos, size, Decorator)
{
  this->text = str;
}

void TextField::render()
{
  
}
