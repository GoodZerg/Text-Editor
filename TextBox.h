#pragma once
#include "TextField.h"
#include "ClikedInterface.h"

class TextBox :
  public TextField, ClikedInterface
{
public:
  TextBox(vec2<float> pos, vec2<float> size, std::vector<std::string*>& str, WidgetComponent* Decorator = nullptr);
  void OnClicked(GLFWwindow*) override;
  void render(GLFWwindow* window);
};