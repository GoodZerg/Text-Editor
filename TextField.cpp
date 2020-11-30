#include "TextField.h"

TextField::TextField(vec2<float> pos, vec2<float> size, std::string& str, WidgetComponent* Decorator)
  : WidgetComponent(pos, size, Decorator)
{
  this->_text = str;
}

void TextField::render()
{

}
