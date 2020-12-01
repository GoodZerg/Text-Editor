#include "TextField.h"

TextField::TextField(vec2<float> pos, vec2<float> size, std::string& str, WidgetComponent* Decorator)
  : WidgetComponent(pos, size, Decorator)
{
  this->_text = str;
}

void TextField::render() {
  int vertexColorLocation = glGetUniformLocation(__shaderProgram, "Color");
  glUseProgram(__shaderProgram);
  glUniform4f(vertexColorLocation, 0, 0, 0, 1.0f);
  glBindVertexArray(_VAO);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
  if (_Decorator != nullptr)
    _Decorator->render();
}
