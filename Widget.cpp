#include "Widget.h"

void _framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
  glViewport(0, 0, width, height);
}

Widget::Widget(vec2<unsigned int> size, std::vector<WidgetComponent*> *�omponents)
{
  this->_components = �omponents;
  this->_size.x = size.x;
  this->_size.y = size.y;


  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // glfw: �������� ����
  _window = glfwCreateWindow(_size.x, _size.y, "Text Editor main page", NULL, NULL);
  if (_window == NULL) {
    _error("Failed to create GLFW window\n");
  }
  glfwMakeContextCurrent(_window);
  glfwSetFramebufferSizeCallback(_window, _framebuffer_size_callback);
  // glad: �������� ���� ���������� �� OpenGL-�������
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    _error("Failed to initialize GLAD");
  }

}


void Widget::render()
{
  while (!glfwWindowShouldClose(_window))
  {
    // ��������� �����
    _processInput();

    // ���������
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    for (auto& a : *_components) {
      a->render();
    }


    // glfw: ����� ���������� front- � back- �������. ������������ ������� �����\������ (���� �� ������/�������� ������, ��������� ������ ���� � �.�.)
    glfwSwapBuffers(_window);
    glfwPollEvents();
  }


}

void Widget::_processInput()
{
  if (glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(_window, true);
}

void Widget::_error(std::string error)
{
  std::cout << error;
  system("pause");
  exit(1);
}
