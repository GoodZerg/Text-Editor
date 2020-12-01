#include "Widget.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
  glViewport(0, 0, width, height);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  if (key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE)
    glfwSetWindowShouldClose(window, true);
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


void Widget::render()
{
  while (!glfwWindowShouldClose(_window))
  {
    // Обработка ввода
    // optimization++               glfwWaitEvents();


    // Рендеринг
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    for (auto& a : *_components) {
      a->render();
    }


    // glfw: обмен содержимым front- и back- буферов. Отслеживание событий Ввода\Вывода (была ли нажата/отпущена кнопка, перемещен курсор мыши и т.п.)
    glfwSwapBuffers(_window);
    glfwPollEvents();
  }
}


/*
void Widget::_processInput()
{
  if (glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(_window, true);
  if (false)
    glfwSetWindowShouldClose(_window, true);
}
*/


void Widget::_error(std::string error)
{
  std::cout << error;
  system("pause");
  exit(1);
}

void Widget::wclicked(int button, int action, int mods)
{
}
