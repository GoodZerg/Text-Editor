#pragma once
#include "TextField.h"
#include "ClikedInterface.h"

struct InputStruct;

class TextBox :
  public TextField, ClikedInterface
{
public:
  TextBox(vec2<float> pos, vec2<float> size, std::string& str, WidgetComponent* Decorator = nullptr);
  void OnClicked(GLFWwindow*) override;
};

struct InputStruct {
  TextBox* Input;
  bool IsInputing;
};