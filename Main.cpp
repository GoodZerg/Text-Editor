
#include "Header.h"
#include "Widget.h"
#include "WidgetComponent.h"
#include "TextField.h"
#include "TextBox.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// ���������
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
  vec2<int> pos(0,0);
  pos.x = 0;
  pos.y = 0;
  std::string str("srt");
  TextField* a = new TextField(pos,pos,str);
  a->render();
  // glfw: ������������� � ����������������
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    // glfw: �������� ����
  GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGL for Ravesli.com", NULL, NULL);
  if (window == NULL)
  {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  // glad: �������� ���� ���������� �� OpenGL-�������
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  // ���� ����������
  while (!glfwWindowShouldClose(window))
  {
    // ��������� �����
    processInput(window);

    // ���������� ����������
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // glfw: ����� ���������� front- � back- �������. ������������ ������� �����/������� (���� �� ������/�������� ������, ��������� ������ ���� � �.�.)
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  // glfw: ����������, ������������ ���� ����� ��������������� GLFW-��������
  glfwTerminate();
  return 0;
}

// ��������� ���� ������� �����: ������ GLFW � �������/���������� ������ �� ���������� � ������ ����� � ��������������� ��������� ������ �������
void processInput(GLFWwindow* window)
{
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}

// glfw: ������ ���, ����� ���������� ������� ���� (������������� ��� ���������� ��������), ���������� ������ callback-�������
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
  // ����������, ��� ���� ��������� ������������� ����� �������� ���� 
// �������� ��������, ��� ������ � ������ ����� ����������� ������, ��� ������� �� Retina-��������
  glViewport(0, 0, width, height);
}
