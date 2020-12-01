#include "TextBox.h"

TextBox::TextBox(vec2<float> pos, vec2<float> size, std::string& str, WidgetComponent* Decorator)
  :TextField(pos,size,str,Decorator)
{
}

void TextBox::OnClicked()
{
  std::cout << "TextBoxCliked\n";
}
