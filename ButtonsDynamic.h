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
  vec2<float> vec1 = { 0.5, 0.5 };
  vec2<float> vec3 = { 0.5, 0.5 };
  vec2<float> vec4 = { -0.5, -0.5 };
  std::vector<WidgetComponent*> a;
  Widget test(size, "1", &a, window);
  std::string s = "";
  std::string s1 = "";
  a.push_back(new TextBox(vec1, vec3, *(new std::vector <std::string*> { &s })));
  a.push_back(new TextBox(vec1, vec3, *(new std::vector <std::string*> { &s1 })));
  a.push_back(new Button(vec1, vec3, CloseWindow));
  test.render();

  std::vector<std::string> strings;
  strings.push_back(*dynamic_cast<TextBox*>(a[0])->_text[0]);
  strings.push_back(*dynamic_cast<TextBox*>(a[1])->_text[0]);
  std::cout << strings[0] << " " << strings[1] << std::endl;
  std::string::size_type sz;
  int pos = std::stoi(strings[1], &sz);

  func::Insert(strings[0], pos, main_array);
  std::cout << main_array.size();

  std::cout << main_array.size();
}
/*
void FuncTwo(GLFWwindow* window) {

  vec2<unsigned int> size = { 400, 300 };

  std::vector<WidgetComponent*> a;

  Widget test(size, "1", &a, window);

  test.render();
  glfwTerminate();
  std::vector<std::string> strings;
  std::string::size_type sz;
  int pos = std::stoi(strings[strings.size() - 1], &sz);
  strings.erase(strings.end() - 1);
  func::InsertMany(strings, pos - 1);
}

void FuncThree(GLFWwindow* window) {

  vec2<unsigned int> size = { 400, 300 };

  std::vector<WidgetComponent*> a;

  Widget test(size, "1", &a, window);

  test.render();
  glfwTerminate();
  std::vector<std::string> strings;
  std::string::size_type sz;
  int pos = std::stoi(strings[0], &sz);
  func::Delete(pos - 1);
}

void FuncFour(GLFWwindow* window) {

  vec2<unsigned int> size = { 400, 300 };

  std::vector<WidgetComponent*> a;

  Widget test(size, "1", &a, window);

  test.render();
  glfwTerminate();
  std::vector<std::string> strings;
  std::string::size_type sz;
  int pos = std::stoi(strings[strings.size() - 1], &sz);
  strings.erase(strings.end() - 1);
  int num_str = std::stoi(strings[strings.size() - 1], &sz);
  strings.erase(strings.end() - 1);
  func::InsertSubstring(strings[0], num_str - 1, pos - 1);

}

void FuncFive(GLFWwindow* window) {

  vec2<unsigned int> size = { 400, 300 };

  std::vector<WidgetComponent*> a;

  Widget test(size, "1", &a, window);

  test.render();
  glfwTerminate();
  std::vector<std::string> strings;
  std::string::size_type sz;
  int pos = std::stoi(strings[strings.size() - 1], &sz);
  strings.erase(strings.end() - 1);
  int num_str = std::stoi(strings[strings.size() - 1], &sz);
  strings.erase(strings.end() - 1);
  func::SymbolReplace(strings[0][0], pos - 1, num_str - 1);

}

void FuncSix(GLFWwindow* window) {

  vec2<unsigned int> size = { 400, 300 };

  std::vector<WidgetComponent*> a;

  Widget test(size, "1", &a, window);

  test.render();
  glfwTerminate();
  std::vector<std::string> strings;
  std::string::size_type sz;
  int stop = std::stoi(strings[strings.size() - 1], &sz);
  strings.erase(strings.end() - 1);
  int start = std::stoi(strings[strings.size() - 1], &sz);
  strings.erase(strings.end() - 1);
  func::ReplaceSubstring(strings[0], strings[1], start - 1, stop - 1);
}

void FuncSeven(GLFWwindow* window) {

  vec2<unsigned int> size = { 400, 300 };

  std::vector<WidgetComponent*> a;

  Widget test(size, "1", &a, window);

  test.render();
  glfwTerminate();
  std::vector<std::string> strings;
  std::string::size_type sz;
  int stop = std::stoi(strings[strings.size() - 1], &sz);
  strings.erase(strings.end() - 1);
  int start = std::stoi(strings[strings.size() - 1], &sz);
  strings.erase(strings.end() - 1);
  func::RemoveZeroes(start - 1, stop - 1);
}

void FuncEight(GLFWwindow* window) {

  vec2<unsigned int> size = { 400, 300 };

  std::vector<WidgetComponent*> a;

  Widget test(size, "1", &a, window);

  test.render();
  glfwTerminate();
  std::vector<std::string> strings;
  std::string::size_type sz;
  int stop = std::stoi(strings[strings.size() - 1], &sz);
  strings.erase(strings.end() - 1);
  int start = std::stoi(strings[strings.size() - 1], &sz);
  strings.erase(strings.end() - 1);
  func::RemoveAsterisks(start, stop);
}

void FuncNine(GLFWwindow* window) {

  vec2<unsigned int> size = { 400, 300 };

  std::vector<WidgetComponent*> a;

  Widget test(size, "1", &a, window);

  test.render();
  glfwTerminate();
  std::vector<std::string> strings;
  std::string::size_type sz;
  int stop = std::stoi(strings[strings.size() - 1], &sz);
  strings.erase(strings.end() - 1);
  int start = std::stoi(strings[strings.size() - 1], &sz);
  strings.erase(strings.end() - 1);
  func::RemoveBracketsContent(start, stop);
}

void FuncTen(GLFWwindow* window) {

  vec2<unsigned int> size = { 400, 300 };

  std::vector<WidgetComponent*> a;

  Widget test(size, "1", &a, window);

  test.render();
  glfwTerminate();
  std::vector<std::string> strings;
  std::string::size_type sz;
  int stop = std::stoi(strings[strings.size() - 1], &sz);
  strings.erase(strings.end() - 1);
  int start = std::stoi(strings[strings.size() - 1], &sz);
  strings.erase(strings.end() - 1);
  func::RemoveDigitsWithIncreasingValues(start, stop);
}
*/