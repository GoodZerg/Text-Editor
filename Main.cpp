#include "Header.h"
#include "Widget.h"
#include "ButtonsDynamic.h"



int main() {
  std::string tmp = "1224";
  vec2<unsigned int> size = { 1200, 800 };
  vec2<float> vec1 = { -1, -1 };
  vec2<float> textfield_size = { 1.5, 2.0 };
  vec2<float> vec4 = { 0.5, 0.8 };
  vec2<float> vec5 = { 0.5, 0.2 };
  vec2<float> vec6 = { 0.5, 0.6 };
  vec2<float> vec7 = { 0.5, 0.4 };
  vec2<float> vec8 = { 0.5, 0.2 };
  vec2<float> vec9 = { 0.5, 0 };
  vec2<float> vec10 = { 0.5, -0.2 };
  vec2<float> vec11 = { 0.5, -0.4 };
  vec2<float> vec12 = { 0.5, -0.6 };
  vec2<float> vec13 = { 0.5, -0.8 };
  vec2<float> vec14 = { 0.5, -1 };
  std::string str = "ia sdelal tokgggo wiwod$$$";
  std::string strr = "ia sdeasdasdlal tokgggo wiwod";
  std::vector<WidgetComponent*> a;
  Widget test(size, "123", &a);
  std::string str1 = "Insert";
  std::string str2 = "InsertMany";
  std::string str3 = "Delete";
  std::string str4 = "InsertSubstring";
  std::string str5 = "SymbolReplace";
  std::string str6 = "ReplaceSubstring";
  std::string str7 = "RemoveZeroes";
  std::string str8 = "RemoveAsterisks";
  std::string str9 = "RemoveBracketsContent";
  std::string str10 = "RemoveDigitsWithIncreas";
  a.push_back(new TextField(vec1, textfield_size, *(new std::vector <std::string*>{ &str, &strr })));
  a.push_back(new Button(vec4, vec5, FuncOne, new TextField(vec4, vec5, *(new std::vector <std::string*>{ &str1 }))));
  a.push_back(new Button(vec6, vec5, FuncTwo, new TextField(vec6, vec5, *(new std::vector <std::string*>{ &str2 }))));
  a.push_back(new Button(vec7, vec5, FuncThree, new TextField(vec7, vec5, *(new std::vector <std::string*>{ &str3 }))));
  a.push_back(new Button(vec8, vec5, FuncFour, new TextField(vec8, vec5, *(new std::vector <std::string*>{ &str4 }))));
  a.push_back(new Button(vec9, vec5, FuncFive, new TextField(vec9, vec5, *(new std::vector <std::string*>{ &str5 }))));
  a.push_back(new Button(vec10, vec5, FuncSix, new TextField(vec10, vec5, *(new std::vector <std::string*>{ &str6 }))));
  a.push_back(new Button(vec11, vec5, FuncSeven, new TextField(vec11, vec5, *(new std::vector <std::string*>{ &str7 }))));
  a.push_back(new Button(vec12, vec5, FuncEight, new TextField(vec12, vec5, *(new std::vector <std::string*>{ &str8 }))));
  a.push_back(new Button(vec13, vec5, FuncNine, new TextField(vec13, vec5, *(new std::vector <std::string*>{ &str9 }))));
  a.push_back(new Button(vec14, vec5, FuncTen, new TextField(vec14, vec5, *(new std::vector <std::string*>{ &str10 }))));
  test.render();
  glfwTerminate();
  return 0;
}
void Rec(std::vector<std::string*>& array) {
  for (int i = 0; i < array.size(); ++i) {
    if (array.size() > 60) {
      if (i + 1 < array.size()) {
        array[i + 1]->insert(0, array[i]->substr(60));
        array[i]->erase(60);
      }
      else {
        array.push_back(new std::string(array[i]->substr(60)));
        array[i]->erase(60);
      }
    }
  }
}