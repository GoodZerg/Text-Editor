#include "Widget.h"

Widget::Widget(std::vector<WidgetComponent*> components)
{
  this->components = components;
}

void Widget::render()
{

}

void Widget::processInput()
{
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}
