#pragma once
#include "Header.h"
#include "Widget.h"
#include "Strings.h"
void FuncOne(GLFWwindow* window);
void FuncTwo(GLFWwindow* window);
void FuncThree(GLFWwindow* window);
void FuncFour(GLFWwindow* window);
void FuncFive(GLFWwindow* window);
void FuncSix(GLFWwindow* window);
void FuncSeven(GLFWwindow* window);
void FuncEight(GLFWwindow* window);
void FuncNine(GLFWwindow* window);
void FuncTen(GLFWwindow* window);
void CloseWindow(GLFWwindow* window);

void CloseWindow(GLFWwindow* window) {
  glfwSetWindowShouldClose(window, true);
  glfwDestroyWindow(window);
}

void FuncOne(GLFWwindow* window) {
  auto main_array = dynamic_cast<TextField*>((*static_cast<Widget*>(glfwGetWindowUserPointer(window))->getWidgetComponent())[0])->_text;
  vec2<unsigned int> size = { 400, 300 };
  vec2<float> vec1 = { 2, 0.5 };
  vec2<float> vec3 = { -1, 0.5 };
  vec2<float> vec4 = { -1, 0 };
  vec2<float> vec5 = { -0.2, -0.5 };
  vec2<float> vec6 = { 0.4, 0.4 };
  std::vector<WidgetComponent*> a;
  Widget test(size, "1", &a, window);
  std::string s = "0";
  std::string s1 = "0";
  a.push_back(new TextBox(vec3, vec1, *(new std::vector <std::string*>{ &s })));
  a.push_back(new TextBox(vec4, vec1, *(new std::vector <std::string*>{ &s1 })));
  std::string str1 = "Accept";
  a.push_back(new Button(vec5, vec6, CloseWindow, new TextField(vec5, vec6, *(new std::vector <std::string*>{ &str1 }))));
  test.render();

  std::vector<std::string> strings;
  strings.push_back(*(dynamic_cast<TextBox*>(a[0])->_text[0]));
  strings.push_back(*(dynamic_cast<TextBox*>(a[1])->_text[0]));
  std::string::size_type sz;
  int pos = std::stoi(strings[1], &sz);
  func::Insert(strings[0], pos, main_array);
  dynamic_cast<TextField*>((*static_cast<Widget*>(glfwGetWindowUserPointer(window))->getWidgetComponent())[0])->_text = main_array;
}

void FuncTwo(GLFWwindow* window) {
  auto main_array = dynamic_cast<TextField*>((*static_cast<Widget*>(glfwGetWindowUserPointer(window))->getWidgetComponent())[0])->_text;

  vec2<unsigned int> size = { 400, 300 };

  std::vector<WidgetComponent*> a;
  vec2<float> vec1 = { 2, 0.5 };
  vec2<float> vec3 = { -1, 0.5 };
  vec2<float> vec4 = { -1, 0 };
  vec2<float> vec5 = { -0.2, -0.5 };
  vec2<float> vec6 = { 0.4, 0.4 };
  Widget test(size, "1", &a, window);
  std::string s = "0";
  std::string s1 = "0";
  std::string str1 = "Accept";
  a.push_back(new TextBox(vec3, vec1, *(new std::vector <std::string*>{ &s })));
  a.push_back(new TextBox(vec4, vec1, *(new std::vector <std::string*>{ &s1 })));
  a.push_back(new Button(vec5, vec6, CloseWindow, new TextField(vec5, vec6, *(new std::vector <std::string*>{ &str1 }))));

  test.render();
  glfwTerminate();
  std::vector<std::string> strings;
  strings.push_back(*(dynamic_cast<TextBox*>(a[0])->_text[0]));
  std::string::size_type sz;
  int pos = std::stoi(strings[strings.size() - 1], &sz);
  strings.erase(strings.end() - 1);
  func::InsertMany(strings, pos, main_array);
}

void FuncThree(GLFWwindow* window) {
  auto main_array = dynamic_cast<TextField*>((*static_cast<Widget*>(glfwGetWindowUserPointer(window))->getWidgetComponent())[0])->_text;
  vec2<float> vec1 = { 2, 0.5 };
  vec2<float> vec3 = { -1, 0.5 };
  vec2<float> vec4 = { -1, 0 };
  vec2<float> vec5 = { -0.2, -0.9 };
  vec2<float> vec6 = { 0.4, 0.4 };
  vec2<unsigned int> size = { 400, 300 };
  std::vector<WidgetComponent*> a;

  Widget test(size, "1", &a, window);
  std::string s = "0";
  a.push_back(new TextBox(vec3, vec1, *(new std::vector <std::string*>{ &s })));
  std::string str1 = "Accept";
  a.push_back(new Button(vec5, vec6, CloseWindow, new TextField(vec5, vec6, *(new std::vector <std::string*>{ &str1 }))));
  test.render();
  glfwTerminate();
  std::vector<std::string> strings;

  std::string::size_type sz;
  int pos = std::stoi(strings[0], &sz);
  func::Delete(pos, main_array);
}

void FuncFour(GLFWwindow* window) {
  auto main_array = dynamic_cast<TextField*>((*static_cast<Widget*>(glfwGetWindowUserPointer(window))->getWidgetComponent())[0])->_text;
  vec2<float> vec1 = { 2, 0.5 };
  vec2<float> vec3 = { -1, 0.5 };
  vec2<float> vec4 = { -1, 0 };
  vec2<float> vec5 = { -0.2, -0.95 };
  vec2<float> vec6 = { 0.4, 0.4 };
  vec2<float> vec7 = { -1, -0.5 };
  vec2<unsigned int> size = { 400, 300 };

  std::vector<WidgetComponent*> a;

  Widget test(size, "1", &a, window);
  std::string s = "0";
  std::string s1 = "0";
  std::string s2 = "0";
  a.push_back(new TextBox(vec3, vec1, *(new std::vector <std::string*>{ &s })));
  a.push_back(new TextBox(vec4, vec1, *(new std::vector <std::string*>{ &s1 })));
  a.push_back(new TextBox(vec7, vec1, *(new std::vector <std::string*>{ &s2 })));
  std::string str1 = "Accept";
  a.push_back(new Button(vec5, vec6, CloseWindow, new TextField(vec5, vec6, *(new std::vector <std::string*>{ &str1 }))));
  test.render();
  glfwTerminate();
  std::vector<std::string> strings;
  strings.push_back(*(dynamic_cast<TextBox*>(a[0])->_text[0]));
  strings.push_back(*(dynamic_cast<TextBox*>(a[1])->_text[0]));
  strings.push_back(*(dynamic_cast<TextBox*>(a[2])->_text[0]));
  std::string::size_type sz;
  int pos = std::stoi(strings[strings.size() - 1], &sz);
  strings.erase(strings.end() - 1);
  int num_str = std::stoi(strings[strings.size() - 1], &sz);
  strings.erase(strings.end() - 1);
  func::InsertSubstring(strings[0], num_str, pos, main_array);

}

void FuncFive(GLFWwindow* window) {
  auto main_array = dynamic_cast<TextField*>((*static_cast<Widget*>(glfwGetWindowUserPointer(window))->getWidgetComponent())[0])->_text;
  vec2<float> vec1 = { 2, 0.5 };
  vec2<float> vec3 = { -1, 0.5 };
  vec2<float> vec4 = { -1, 0 };
  vec2<float> vec5 = { -0.2, -0.95 };
  vec2<float> vec6 = { 0.4, 0.4 };
  vec2<float> vec7 = { -1, -0.5 };
  vec2<unsigned int> size = { 400, 300 };

  std::vector<WidgetComponent*> a;

  Widget test(size, "1", &a, window);
  std::string s = "0";
  std::string s1 = "0";
  std::string s2 = "0";
  a.push_back(new TextBox(vec3, vec1, *(new std::vector <std::string*>{ &s })));
  a.push_back(new TextBox(vec4, vec1, *(new std::vector <std::string*>{ &s1 })));
  a.push_back(new TextBox(vec7, vec1, *(new std::vector <std::string*>{ &s2 })));
  std::string str1 = "Accept";
  a.push_back(new Button(vec5, vec6, CloseWindow, new TextField(vec5, vec6, *(new std::vector <std::string*>{ &str1 }))));
  test.render();
  glfwTerminate();
  std::vector<std::string> strings;
  std::string::size_type sz;
  strings.push_back(*(dynamic_cast<TextBox*>(a[0])->_text[0]));
  strings.push_back(*(dynamic_cast<TextBox*>(a[1])->_text[0]));
  strings.push_back(*(dynamic_cast<TextBox*>(a[2])->_text[0]));
  int pos = std::stoi(strings[strings.size() - 1], &sz);
  strings.erase(strings.end() - 1);
  int num_str = std::stoi(strings[strings.size() - 1], &sz);
  strings.erase(strings.end() - 1);
  func::SymbolReplace(strings[0][0], pos, num_str, main_array);

}

void FuncSix(GLFWwindow* window) {
  auto main_array = dynamic_cast<TextField*>((*static_cast<Widget*>(glfwGetWindowUserPointer(window))->getWidgetComponent())[0])->_text;
  vec2<float> vec1 = { 2, 0.4 };
  vec2<float> vec3 = { -1, 0.6 };
  vec2<float> vec4 = { -1, 0.2 };
  vec2<float> vec5 = { -0.2, -0.975 };
  vec2<float> vec6 = { 0.4, 0.35 };
  vec2<float> vec7 = { -1, -0.2 };
  vec2<float> vec8 = { -1, -0.6 };
  vec2<unsigned int> size = { 400, 350 };

  std::vector<WidgetComponent*> a;

  Widget test(size, "1", &a, window);
  std::string s = "0";
  std::string s1 = "0";
  std::string s2 = "0";
  std::string s3 = "0";
  a.push_back(new TextBox(vec3, vec1, *(new std::vector <std::string*>{ &s })));
  a.push_back(new TextBox(vec4, vec1, *(new std::vector <std::string*>{ &s1 })));
  a.push_back(new TextBox(vec7, vec1, *(new std::vector <std::string*>{ &s2 })));
  a.push_back(new TextBox(vec8, vec1, *(new std::vector <std::string*>{ &s3 })));

  std::string str1 = "Accept";
  a.push_back(new Button(vec5, vec6, CloseWindow, new TextField(vec5, vec6, *(new std::vector <std::string*>{ &str1 }))));
  test.render();
  glfwTerminate();
  std::vector<std::string> strings;
  strings.push_back(*(dynamic_cast<TextBox*>(a[0])->_text[0]));
  strings.push_back(*(dynamic_cast<TextBox*>(a[1])->_text[0]));
  strings.push_back(*(dynamic_cast<TextBox*>(a[2])->_text[0]));
  strings.push_back(*(dynamic_cast<TextBox*>(a[3])->_text[0]));
  std::string::size_type sz;
  int stop = std::stoi(strings[strings.size() - 1], &sz);
  strings.erase(strings.end() - 1);
  int start = std::stoi(strings[strings.size() - 1], &sz);
  strings.erase(strings.end() - 1);
  func::ReplaceSubstring(strings[0], strings[1], start, stop, main_array);
}

void FuncSeven(GLFWwindow* window) {
  auto main_array = dynamic_cast<TextField*>((*static_cast<Widget*>(glfwGetWindowUserPointer(window))->getWidgetComponent())[0])->_text;
  vec2<float> vec1 = { 2, 0.5 };
  vec2<float> vec3 = { -1, 0.5 };
  vec2<float> vec4 = { -1, 0 };
  vec2<float> vec5 = { -0.2, -0.5 };
  vec2<float> vec6 = { 0.4, 0.4 };
  vec2<unsigned int> size = { 400, 300 };

  std::vector<WidgetComponent*> a;

  Widget test(size, "1", &a, window);
  std::string s = "0";
  std::string s1 = "0";
  a.push_back(new TextBox(vec3, vec1, *(new std::vector <std::string*>{ &s })));
  a.push_back(new TextBox(vec4, vec1, *(new std::vector <std::string*>{ &s1 })));
  std::string str1 = "Accept";
  a.push_back(new Button(vec5, vec6, CloseWindow, new TextField(vec5, vec6, *(new std::vector <std::string*>{ &str1 }))));
  test.render();
  glfwTerminate();
  std::vector<std::string> strings;
  strings.push_back(*(dynamic_cast<TextBox*>(a[0])->_text[0]));
  strings.push_back(*(dynamic_cast<TextBox*>(a[1])->_text[0]));
  std::string::size_type sz;
  int stop = std::stoi(strings[strings.size() - 1], &sz);
  strings.erase(strings.end() - 1);
  int start = std::stoi(strings[strings.size() - 1], &sz);
  strings.erase(strings.end() - 1);
  func::RemoveZeroes(start, stop, main_array);
}

void FuncEight(GLFWwindow* window) {
  auto main_array = dynamic_cast<TextField*>((*static_cast<Widget*>(glfwGetWindowUserPointer(window))->getWidgetComponent())[0])->_text;
  vec2<float> vec1 = { 2, 0.5 };
  vec2<float> vec3 = { -1, 0.5 };
  vec2<float> vec4 = { -1, 0 };
  vec2<float> vec5 = { -0.2, -0.5 };
  vec2<float> vec6 = { 0.4, 0.4 };
  vec2<unsigned int> size = { 400, 300 };

  std::vector<WidgetComponent*> a;

  Widget test(size, "1", &a, window);
  std::string s = "0";
  std::string s1 = "0";
  a.push_back(new TextBox(vec1, vec3, *(new std::vector <std::string*>{ &s })));
  a.push_back(new TextBox(vec1, vec3, *(new std::vector <std::string*>{ &s1 }))); a.push_back(new TextBox(vec3, vec1, *(new std::vector <std::string*>{ &s })));
  a.push_back(new TextBox(vec4, vec1, *(new std::vector <std::string*>{ &s1 })));
  std::string str1 = "Accept";
  a.push_back(new Button(vec5, vec6, CloseWindow, new TextField(vec5, vec6, *(new std::vector <std::string*>{ &str1 }))));
  test.render();
  glfwTerminate();
  std::vector<std::string> strings;
  strings.push_back(*(dynamic_cast<TextBox*>(a[0])->_text[0]));
  strings.push_back(*(dynamic_cast<TextBox*>(a[1])->_text[0]));
  std::string::size_type sz;
  int stop = std::stoi(strings[strings.size() - 1], &sz);
  strings.erase(strings.end() - 1);
  int start = std::stoi(strings[strings.size() - 1], &sz);
  strings.erase(strings.end() - 1);
  func::RemoveAsterisks(start, stop, main_array);
}

void FuncNine(GLFWwindow* window) {
  auto main_array = dynamic_cast<TextField*>((*static_cast<Widget*>(glfwGetWindowUserPointer(window))->getWidgetComponent())[0])->_text;
  vec2<float> vec1 = { 2, 0.5 };
  vec2<float> vec3 = { -1, 0.5 };
  vec2<float> vec4 = { -1, 0 };
  vec2<float> vec5 = { -0.2, -0.5 };
  vec2<float> vec6 = { 0.4, 0.4 };
  vec2<unsigned int> size = { 400, 300 };

  std::vector<WidgetComponent*> a;

  Widget test(size, "1", &a, window);
  std::string s = "0";
  std::string s1 = "0";

  a.push_back(new TextBox(vec3, vec1, *(new std::vector <std::string*>{ &s })));
  a.push_back(new TextBox(vec4, vec1, *(new std::vector <std::string*>{ &s1 })));

  std::string str1 = "Accept";
  a.push_back(new Button(vec5, vec6, CloseWindow, new TextField(vec5, vec6, *(new std::vector <std::string*>{ &str1 }))));
  test.render();
  glfwTerminate();
  std::vector<std::string> strings;
  strings.push_back(*(dynamic_cast<TextBox*>(a[0])->_text[0]));
  strings.push_back(*(dynamic_cast<TextBox*>(a[1])->_text[0]));
  std::string::size_type sz;
  int stop = std::stoi(strings[strings.size() - 1], &sz);
  strings.erase(strings.end() - 1);
  int start = std::stoi(strings[strings.size() - 1], &sz);
  strings.erase(strings.end() - 1);
  func::RemoveBracketsContent(start, stop, main_array);
}

void FuncTen(GLFWwindow* window) {
  auto main_array = dynamic_cast<TextField*>((*static_cast<Widget*>(glfwGetWindowUserPointer(window))->getWidgetComponent())[0])->_text;
  vec2<float> vec1 = { 2, 0.5 };
  vec2<float> vec3 = { -1, 0.5 };
  vec2<float> vec4 = { -1, 0 };
  vec2<float> vec5 = { -0.2, -0.5 };
  vec2<float> vec6 = { 0.4, 0.4 };
  vec2<unsigned int> size = { 400, 300 };

  std::vector<WidgetComponent*> a;

  Widget test(size, "1", &a, window);
  std::string s = "0";
  std::string s1 = "0";
  a.push_back(new TextBox(vec3, vec1, *(new std::vector <std::string*>{ &s })));
  a.push_back(new TextBox(vec4, vec1, *(new std::vector <std::string*>{ &s1 })));
  std::string str1 = "Accept";
  a.push_back(new Button(vec5, vec6, CloseWindow, new TextField(vec5, vec6, *(new std::vector <std::string*>{ &str1 }))));

  test.render();
  glfwTerminate();
  std::vector<std::string> strings;
  strings.push_back(*(dynamic_cast<TextBox*>(a[0])->_text[0]));
  strings.push_back(*(dynamic_cast<TextBox*>(a[1])->_text[0]));
  std::string::size_type sz;
  int stop = std::stoi(strings[strings.size() - 1], &sz);
  strings.erase(strings.end() - 1);
  int start = std::stoi(strings[strings.size() - 1], &sz);
  strings.erase(strings.end() - 1);
  func::RemoveDigitsWithIncreasingValues(start, stop, main_array);
}