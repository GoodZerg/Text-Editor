#include "Button.h"

Button::Button(vec2<float> pos, vec2<float> size, std::function<void(GLFWwindow*)> func, WidgetComponent* Decorator)
  : WidgetComponent(pos, size, Decorator)
{
  this->addOnClikedDynamic(func);
}

void Button::OnClicked(GLFWwindow* w)
{
  std::cout << "ButtonCliked\n";
  _ClikedDynamic(w);
}

void Button::addOnClikedDynamic(std::function<void(GLFWwindow*)> function)
{
  this->_ClikedDynamic = function;
}
