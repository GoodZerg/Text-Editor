#pragma once
#include "Header.h"
namespace func {
  void Insert(std::string s, int pos, std::vector<std::string*>& main_array);
  void InsertMany(std::vector<std::string> s, int pos, std::vector<std::string*>& main_array);
  void Delete(int pos, std::vector<std::string*>& main_array);
  void InsertSubstring(std::string s, int num_str, int pos, std::vector<std::string*>& main_array);
  void SymbolReplace(char symbol, int pos, int num_str, std::vector<std::string*>& main_array);
  void ReplaceSubstring(std::string old_str, std::string new_str, int str_start, int str_stop, std::vector<std::string*>& main_array);
  void RemoveZeroes(int str_start, int str_stop, std::vector<std::string*>& main_array);
  void RemoveAsterisks(int begin_index, int end_index, std::vector<std::string*>& main_array);
  void RemoveBracketsContent(int begin_index, int end_index, std::vector<std::string*>& main_array);
  void RemoveDigitsWithIncreasingValues(int begin_index, int end_index, std::vector<std::string*>& main_array);
}