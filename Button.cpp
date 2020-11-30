#include "Button.h"

void Button::OnClicked()
{
  _ClikedDynamic();
}

void Button::addOnClikedDynamic(std::function<void()> function)
{
  this->_ClikedDynamic = function;
}
