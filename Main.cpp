#include "Header.h"
#include "Widget.h"
#include "WidgetComponent.h"
#include "TextField.h"
#include "TextBox.h"

int main()
{
  vec2<unsigned int> size = { 800, 600 };
  vec2<float> vec1 = { 0.5, 0.5};
  vec2<float> vec3 = { 0.5, 0.5 };
  vec2<float> vec4 = { 0.0, 0.0 };
  std::vector<WidgetComponent*> a;
  Widget test(size, &a);
  a.push_back(new WidgetComponent(vec1, vec3));
  a.push_back(new WidgetComponent(vec4, vec3));
  test.render();
  return 0;
}