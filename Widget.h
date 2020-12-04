#pragma once
#include "RenderInterface.h"
#include "WidgetComponent.h"
#include "WidgetComponent.h"
#include "TextField.h"
#include "TextBox.h"
#include "Button.h"

struct InputStruct;

class Widget :
  public RenderInterface {
public:
  Widget(vec2<unsigned int> size, std::string name_window, std::vector<WidgetComponent*> *components, GLFWwindow* main_window = nullptr);
  void render(GLFWwindow* window = nullptr) override;
  vec2<unsigned int> getSize();
  InputStruct getInput();
  void wclicked(int button, int action, int mods);
  std::vector<WidgetComponent*>* getWidgetComponent();
  GLFWwindow* _window = nullptr;
private:
  static InputStruct GLBoxInput;
  std::string _name_window = "";
  vec2<unsigned int> _size = { 800, 600 };
  std::vector<WidgetComponent*> *_components = {};

  void _error(std::string error);
};  

struct InputStruct {
  TextBox* Input;
  bool IsInputing;
};