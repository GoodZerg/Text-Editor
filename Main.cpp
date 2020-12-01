#include "Header.h"
#include "Widget.h"
#include "ButtonsDynamic.h"

int main() {
  std::string tmp = "1224";
  main_array.push_back(&tmp);
  vec2<unsigned int> size = { 800, 600 };
  vec2<float> vec1 = { 0.5, 0.5 };
  vec2<float> vec3 = { 0.5, 0.5 };
  vec2<float> vec4 = { -0.5, -0.5 };
  std::string str = "123";
  std::vector<WidgetComponent*> a;
  Widget test(size, "123", &a);
  a.push_back(new TextBox(vec1, vec3, str));
  a.push_back(new Button(vec4, vec3, FuncOne));
  test.render();
  glfwTerminate();
  return 0;
}