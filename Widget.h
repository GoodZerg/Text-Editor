#pragma once
#include "RenderInterface.h"
#include "WidgetComponent.h"
class Widget :
  public RenderInterface {
public:
  Widget(vec2<unsigned int> size, std::vector<WidgetComponent*> *components);
  void render() override;
private:
  vec2<unsigned int> _size = { 800, 600 };
  std::vector<WidgetComponent*> *_components = {};
  GLFWwindow* _window = nullptr;
  void _processInput();
  void _error(std::string error);
};  

