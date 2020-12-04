#include "TextField.h"

TextField::TextField(vec2<float> pos, vec2<float> size, std::vector<std::string*>& str, WidgetComponent* Decorator)
  : WidgetComponent(pos, size, Decorator)
{
  this->_text = str;

  // make Character to 

  FT_Library ft;
  if (FT_Init_FreeType(&ft)) {
    std::cout << "Could not init FreeType Library";
  }

  std::string fon = "fonts/Ubuntu-Bold.TTF";

  FT_Face face;
  if (FT_New_Face(ft, fon.c_str(), 0, &face)) {
    std::cout << "Failed to load font";
  }

  FT_Set_Pixel_Sizes(face, 0, 48);

  glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // отключаем ограничение выравнивания байтов

  for (unsigned int c = 0; c < 256; c++)
  {
    // Загружаем глифы символов 
    if (FT_Load_Char(face, c, FT_LOAD_RENDER))
    {
      std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
      continue;
    }

    // Генерируем текстуру
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(
      GL_TEXTURE_2D,
      0,
      GL_RED,
      face->glyph->bitmap.width,
      face->glyph->bitmap.rows,
      0,
      GL_RED,
      GL_UNSIGNED_BYTE,
      face->glyph->bitmap.buffer
    );

    // Задаем для текстуры необходимые опции
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Сохраняем символ для последующего использования
    Character character = {
        texture,
        vec2<int>(face->glyph->bitmap.width, face->glyph->bitmap.rows),
        vec2<int>(face->glyph->bitmap_left, face->glyph->bitmap_top),
        face->glyph->advance.x
    };
    _Characters.insert(std::pair<char, Character>(c, character));
  }
  
  FT_Done_Face(face);
  FT_Done_FreeType(ft);

  const char* vertexShaderText =
    "#version 330 core\n"
    "layout (location = 0) in vec4 vertex;\n"
    "out vec2 TexCoords;\n"
    "uniform mat4 projection;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = projection * vec4(vertex.xy, 0.0, 1.0);\n"
    "   TexCoords = vertex.zw;\n"  
    "}\0";

  const char* fragmentShaderText =
    "#version 330 core\n"
    "in vec2 TexCoords;"
    "out vec4 color;\n"
    "uniform sampler2D text;\n"
    "uniform vec3 textColor;\n"
    "void main()\n"
    "{\n"
    "   vec4 sampled = vec4(1.0, 1.0, 1.0, texture(text, TexCoords).r);\n"
    "   color = vec4(textColor, 1.0) * sampled;\n"
    "}\n\0";
    
  //// shaders ////
  int success;
  char infoLog[512];

  int vertexShader_ = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader_, 1, &vertexShaderText, NULL);
  glCompileShader(vertexShader_);

  glGetShaderiv(vertexShader_, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(vertexShader_, 512, NULL, infoLog);
    std::cout << "SHADER::VERTEX::COMPILATION_FAILED\n";
  }

  int fragmentShader_ = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader_, 1, &fragmentShaderText, NULL);
  glCompileShader(fragmentShader_);

  glGetShaderiv(fragmentShader_, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(fragmentShader_, 512, NULL, infoLog);
    std::cout << "SHADER::FRAGMENT::COMPILATION_FAILED\n";
  }

  // Связывание шейдеров
  shaderProgramText = glCreateProgram();
  glAttachShader(shaderProgramText, vertexShader_);
  glAttachShader(shaderProgramText, fragmentShader_);
  glLinkProgram(shaderProgramText);

  glGetProgramiv(shaderProgramText, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(shaderProgramText, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n";
  }

  //чистка
  glDeleteShader(vertexShader_);
  glDeleteShader(fragmentShader_);


  glGenVertexArrays(1, &VAO_);
  glGenBuffers(1, &VBO_);
  glBindVertexArray(VAO_);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_);
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);


  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}

void TextField::render(GLFWwindow* window) {

  int vertexColorLocation = glGetUniformLocation(__shaderProgram, "Color");
  glUseProgram(__shaderProgram);
  glUniform4f(vertexColorLocation, 0, 0, 0, 1.0f);
  glBindVertexArray(_VAO);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

  _renderText(0.4, vec3<float>(0.5, 0.8f, 0.2f), window);
  if (_Decorator != nullptr)
    _Decorator->render(window);
}

void TextField::rec() {
  for (int i = 0; i < _text.size(); ++i) {
    if (_text[i]->size() > 17) {
      if (i + 1 < _text.size()) {
        _text[i + 1]->insert(0, _text[i]->substr(17));
        _text[i]->erase(17);
      }
      else {
        _text.push_back(new std::string(_text[i]->substr(17)));
        _text[i]->erase(17);
      }
    }
  }
}

void TextField::_renderText(float scale, vec3<float> color, GLFWwindow* window)
{
  int w = 0, h = 0;
  glfwGetWindowSize(window, &w, &h);
  glUseProgram(shaderProgramText);
  glUniform3f(glGetUniformLocation(shaderProgramText, "textColor"), color.x, color.y, color.z);
  glUniformMatrix4fv(glGetUniformLocation(shaderProgramText, "projection"), 1, GL_FALSE,
    glm::value_ptr(glm::ortho(0.0f, static_cast<float>(w),
      0.0f, static_cast<float>(h))));
  glActiveTexture(GL_TEXTURE0);
  glBindVertexArray(VAO_);

  // Перебираем все символы
  for (int i = 0; i < _text.size(); ++i) {
    float x = (_pos.x + 1)* w/2, y = (_pos.y + 1)* h/2 + _size.y*h/2 - 20*(i+1);
    std::string::const_iterator c;
    for (c = (*_text[i]).begin(); c != (*_text[i]).end(); c++)
    {
      Character ch = _Characters[*c];

      float xpos = x + ch.Bearing.x * scale;
      float ypos = y - (ch.Size.y - ch.Bearing.y) * scale;

      float w = ch.Size.x * scale;
      float h = ch.Size.y * scale;

      // Обновляем VBO для каждого символа
      float vertices[6][4] = {
          { xpos, ypos + h, 0.0f, 0.0f },
          { xpos, ypos, 0.0f, 1.0f },
          { xpos + w, ypos, 1.0f, 1.0f },

          { xpos, ypos + h, 0.0f, 0.0f },
          { xpos + w, ypos, 1.0f, 1.0f },
          { xpos + w, ypos + h, 1.0f, 0.0f }
      };

      // Визуализируем текстуру глифа поверх прямоугольника
      glBindTexture(GL_TEXTURE_2D, ch.TextureID);

      // Обновляем содержимое памяти VBO
      glBindBuffer(GL_ARRAY_BUFFER, VBO_);
      glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
      glBindBuffer(GL_ARRAY_BUFFER, 0);

      // Рендерим прямоугольник
      glDrawArrays(GL_TRIANGLES, 0, 6);

      // Теперь производим смещение для отображения следующего глифа (обратите внимание, что данное смещение измеряется в единицах, составляющих 1/64 пикселя)
      x += (ch.Advance >> 6) * scale; // побитовый сдвиг на 6, чтобы получить значение в пикселях (2^6 = 64)
    }
  }
  glBindVertexArray(0);
  glBindTexture(GL_TEXTURE_2D, 0);
}
