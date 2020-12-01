#include "Button.h"

Button::Button(vec2<float> pos, vec2<float> size, std::function<void()> func, WidgetComponent* Decorator)
  : WidgetComponent(pos, size, Decorator)
{
  this->addOnClikedDynamic(func);
}

void Button::OnClicked()
{
  std::cout << "ButtonCliked\n";
  _ClikedDynamic();
}

void Button::addOnClikedDynamic(std::function<void()> function)
{
  this->_ClikedDynamic = function;
}
