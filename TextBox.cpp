#include "TextBox.h"

TextBox::TextBox(vec2<float> pos, vec2<float> size, std::vector<std::string*>& str, WidgetComponent* Decorator)
  :TextField(pos,size,str,Decorator)
{
}

void TextBox::OnClicked(GLFWwindow* w)
{
  std::cout << "TextBoxCliked\n";
}
