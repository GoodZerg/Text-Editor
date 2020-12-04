#include "TextBox.h"

TextBox::TextBox(vec2<float> pos, vec2<float> size, std::vector<std::string*>& str, WidgetComponent* Decorator)
  :TextField(pos,size,str,Decorator)
{
}

void TextBox::OnClicked(GLFWwindow* w)
{
  std::cout << "TextBoxCliked\n";
}
void TextBox::render(GLFWwindow* window)
{
  int vertexColorLocation = glGetUniformLocation(__shaderProgram, "Color");
  glUseProgram(__shaderProgram);
  glUniform4f(vertexColorLocation, 0.317f, 0.176f, 0.658f, 1.0f);
  glBindVertexArray(_VAO);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

  dec(window);
}
