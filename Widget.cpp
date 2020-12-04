#include "Widget.h"

InputStruct Widget::GLBoxInput = { nullptr, 0 };

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
  glViewport(0, 0, width, height);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  auto wd = static_cast<Widget*>(glfwGetWindowUserPointer(window));
  if (key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE) {
    glfwSetWindowShouldClose(window, true);
    glfwDestroyWindow(window);
  }
  if (key >= 32 && key <= 126 && wd->getInput().IsInputing) {
    wd->getInput().Input->_text[0]->push_back(key);
  }
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
  if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE) {
    static_cast<Widget*>(glfwGetWindowUserPointer(window))->wclicked(button, action, mods);
  }
}


Widget::Widget(vec2<unsigned int> size, std::string name_window, std::vector<WidgetComponent*> *components, GLFWwindow* main_window)
{
  this->_name_window = name_window;
  this->_components = components;
  this->_size.x = size.x;
  this->_size.y = size.y;

  static int isinit = 0;
  if (isinit == 0) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    ++isinit;
  }

  _window = glfwCreateWindow(_size.x, _size.y, &_name_window[0], NULL, main_window);
  glfwSetWindowUserPointer(_window, this);
  // glfw: создание окна  
  if (_window == NULL) {
    _error("Failed to create GLFW window\n");
  }
  glfwMakeContextCurrent(_window);
  glfwSetFramebufferSizeCallback(_window, framebuffer_size_callback);
  // glad: загрузка всех указателей на OpenGL-функции
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    _error("Failed to initialize GLAD");
  }

  glfwSetInputMode(_window, GLFW_LOCK_KEY_MODS, GLFW_TRUE);
  glfwSetMouseButtonCallback(_window, mouse_button_callback);
  glfwSetKeyCallback(_window, key_callback);

}


void Widget::render(GLFWwindow* window)
{
  while (!glfwWindowShouldClose(_window))
  {
    // Обработка ввода
    // optimization++               glfwWaitEvents();


    // Рендеринг
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    for (auto& a : *_components) {
      a->render(_window);
    }


    // glfw: обмен содержимым front- и back- буферов. Отслеживание событий Ввода\Вывода (была ли нажата/отпущена кнопка, перемещен курсор мыши и т.п.)
    glfwSwapBuffers(_window);
    glfwPollEvents();
  }
}

vec2<unsigned int> Widget::getSize()
{
  return _size;
}

InputStruct Widget::getInput()
{
  return GLBoxInput;
}

void Widget::_error(std::string error)
{
  std::cout << error;
  system("pause");
  exit(1);
}

void Widget::wclicked(int button, int action, int mods)
{

  GLBoxInput.IsInputing = false;

  double xpos, ypos;
  glfwGetCursorPos(_window, &xpos, &ypos);

  /**         normalize cursor position         **/
  double _xpos = xpos, _ypos = ypos;
  _xpos /= _size.x / 2;
  _xpos -= 1;
  _ypos /= _size.y / 2;
  _ypos -= 1;
  _ypos = -_ypos;
  //std::cout << "x: " << _xpos << " y: " << _ypos << "\n";

  /**         check click components             **/
  for (size_t i = 0; i < _components->size(); i++) {
    if (_xpos >= (*_components)[i]->_pos.x && _xpos <= static_cast<double>((*_components)[i]->_pos.x) + (*_components)[i]->_size.x &&
        _ypos >= (*_components)[i]->_pos.y && _ypos <= static_cast<double>((*_components)[i]->_pos.y) + (*_components)[i]->_size.y) {
      try {
        try {
          GLBoxInput.IsInputing = false;
          GLBoxInput.Input = dynamic_cast<TextBox*>((*_components)[i]);
          TextBox* tmp = dynamic_cast<TextBox*>((*_components)[i]);
        } catch (const std::bad_cast& ee) {
          GLBoxInput.IsInputing = false;
          std::cout << ee.what();
        }  
        auto tmp = dynamic_cast<Button*>((*_components)[i]);
        auto tmp2 = dynamic_cast<TextBox*>((*_components)[i]);
        if (tmp !=  nullptr) {
          tmp->OnClicked(_window);
        }  
        if (tmp2 != nullptr) {
          GLBoxInput.Input = tmp2;
          GLBoxInput.IsInputing = true;
          tmp2->OnClicked(_window);
        }
      } catch (const std::bad_cast& e) {
        std::cout << e.what();
      }
    }
  }
}

std::vector<WidgetComponent*>* Widget::getWidgetComponent()
{
  return _components;
}
