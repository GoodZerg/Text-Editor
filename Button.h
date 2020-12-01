#pragma once
#include "WidgetComponent.h"
#include "ClikedInterface.h"
class Button :
  public WidgetComponent, ClikedInterface
{
public:
  Button(vec2<float> pos, vec2<float> size, std::function<void(GLFWwindow*)> func, WidgetComponent* Decorator = nullptr);
  void OnClicked(GLFWwindow*) override;
  void addOnClikedDynamic(std::function<void(GLFWwindow*)>);
private:
  std::function<void(GLFWwindow*)> _ClikedDynamic = nullptr;
};

