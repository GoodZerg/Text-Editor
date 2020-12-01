#include "WidgetComponent.h"

const char* WidgetComponent::__vertexShaderSource =
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* WidgetComponent::__fragmentShaderSource = 
"#version 330 core\n"
"out vec4 FragColor;\n"
"uniform vec4 Color;\n"
"void main()\n"
"{\n"
"   FragColor = Color;\n"
"}\n\0";



WidgetComponent::WidgetComponent(vec2<float> pos, vec2<float> size, WidgetComponent* Decorator)
{
  this->_pos = pos;
  this->_size = size;
  this->_Decorator = Decorator;


  /***         Shaders             ***/
  _compileShaderProgram();

  /***         Buffers             ***/
  _makeBuffers();
}

void WidgetComponent::_makeBuffers()
{

  float vertices[] = {
      _pos.x + _size.x, _pos.y + _size.y, 0.0f,
      _pos.x + _size.x, _pos.y          , 0.0f,
      _pos.x          , _pos.y          , 0.0f,
      _pos.x          , _pos.y + _size.y, 0.0f
  };

  unsigned int indices[] = {
    0, 1, 3,   
    1, 2, 3   
  };

  unsigned int EBO, VBO;
  glGenBuffers(1, &EBO);
  glGenBuffers(1, &VBO);

  glGenVertexArrays(1, &_VAO);
  glBindVertexArray(_VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}


void WidgetComponent::render()
{
  int vertexColorLocation = glGetUniformLocation(__shaderProgram, "Color");
  glUseProgram(__shaderProgram);
  glUniform4f(vertexColorLocation, 0, 0, 0, 1.0f);
  glBindVertexArray(_VAO);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
  if(_Decorator != nullptr)
    _Decorator->render();
}

void WidgetComponent::_error(std::string error, char infoLog[512])
{
  std::cout << error << infoLog;
  system("pause");
  exit(1);
}



void WidgetComponent::_compileShaderProgram()
{
  int success;
  char infoLog[512];
  
  // Вершинный шейдер
  int vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &__vertexShaderSource, NULL);
  glCompileShader(vertexShader);

  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    _error("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n", infoLog);
  }
  
  // Фрагментный шейдер
  int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &__fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);

  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    _error("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n", infoLog);
  }


  // Связывание шейдеров
  __shaderProgram = glCreateProgram();
  glAttachShader(__shaderProgram, vertexShader);
  glAttachShader(__shaderProgram, fragmentShader);
  glLinkProgram(__shaderProgram);

  glGetProgramiv(__shaderProgram, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(__shaderProgram, 512, NULL, infoLog);
    _error("ERROR::SHADER::PROGRAM::LINKING_FAILED\n", infoLog);
  }

  //чистка
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

}

