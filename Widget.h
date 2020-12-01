#pragma once
#include "RenderInterface.h"
#include "WidgetComponent.h"
#include "WidgetComponent.h"
#include "TextField.h"
#include "TextBox.h"
#include "Button.h"

class Widget :
  public RenderInterface {
public:
  Widget(vec2<unsigned int> size, std::string name_window, std::vector<WidgetComponent*> *components, GLFWwindow* main_window = nullptr);
  void render() override;
  void wclicked(int button, int action, int mods);
private:
  std::string _name_window = "";
  vec2<unsigned int> _size = { 800, 600 };
  std::vector<WidgetComponent*> *_components = {};
  GLFWwindow* _window = nullptr;
  //void _processInput();
  void _error(std::string error);
};  

