#pragma once
#include "Header.h"
namespace func {
  void Insert(std::string s, int pos = 0);
  void InsertMany(std::vector<std::string> s, int pos = 0);
  void Delete(int pos = 0);
  void InsertSubstring(std::string s, int num_str, int pos);
  void SymbolReplace(char symbol, int pos, int num_str);
  void ReplaceSubstring(std::string old_str, std::string new_str, int str_start = 0, int str_stop = -1);
  void RemoveZeroes(int str_start = 0, int str_stop = -1);
  void RemoveAsterisks(int begin_index = 0, int end_index = -1);
  void RemoveBracketsContent(int begin_index = 0, int end_index = -1);
  void RemoveDigitsWithIncreasingValues(int begin_index = 0, int end_index = -1);
}