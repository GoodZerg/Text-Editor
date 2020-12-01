#pragma once
#include "WidgetComponent.h"
#include "ClikedInterface.h"
class Button :
  public WidgetComponent, ClikedInterface
{
public:
  Button(vec2<float> pos, vec2<float> size, std::function<void()> func, WidgetComponent* Decorator = nullptr);
  void OnClicked() override;
  void addOnClikedDynamic(std::function<void()>);
private:
  std::function<void()> _ClikedDynamic = nullptr;
};

