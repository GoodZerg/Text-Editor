#pragma once
#include "RenderInterface.h"
#include "WidgetComponent.h"
class Widget :
  public RenderInterface {
public:
  Widget(std::vector<WidgetComponent*> components);
  void render() override;
  void processInput();
private:
  std::vector<WidgetComponent*> components = {};
  GLFWwindow* window = nullptr;
};

