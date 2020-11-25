#include "Button.h"

void Button::OnClicked()
{
  ClikedDynamic();
}

void Button::addOnClikedDynamic(std::function<void()> function)
{
  this->ClikedDynamic = function;
}
