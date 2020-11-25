#pragma once
#include "WidgetComponent.h"
#include "ClikedInterface.h"
class Button :
  public WidgetComponent, ClikedInterface
{
public:
  void OnClicked() override;
  void addOnClikedDynamic(std::function<void()>);
private:
  std::function<void()> ClikedDynamic = nullptr;
};

