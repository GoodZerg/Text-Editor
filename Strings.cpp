#include "Strings.h"

// inserts
void func::Insert(std::string s, int pos, std::vector<std::string*>& main_array) {
  if (pos == -1) pos = 0;
  if (pos >= main_array.size()) main_array.resize(pos, new std::string("*"));
  main_array.insert(main_array.begin() + pos, new std::string(s));
  return;
}
void func::InsertMany(std::vector<std::string> strs, int pos, std::vector<std::string*>& main_array) {
  if (pos >= main_array.size()) {
    main_array.resize(pos, new std::string("$"));
    for (int i = 0; i < strs.size(); ++i)
      main_array.push_back(new std::string(strs[i]));
  }
  else {
    for (int i = 0; i < strs.size(); ++i)
      main_array.insert(main_array.begin() + pos + i, new std::string(strs[i]));
  }
  return;
}
void func::Delete(int pos, std::vector<std::string*>& main_array) {
  --pos;
  main_array.erase(main_array.begin() + pos);
  return;
}

// modify
void func::InsertSubstring(std::string s, int str_pos, int char_pos, std::vector<std::string*>& main_array) {
  --str_pos;
  --char_pos;
  main_array[str_pos]->insert(char_pos, s);
  return;
}
void func::SymbolReplace(char ch, int str_pos, int char_pos, std::vector<std::string*>& main_array) {
  --str_pos;
  --char_pos;
  (*main_array[str_pos])[char_pos] = ch;
  return;
}
void func::ReplaceSubstring(std::string old_str, std::string new_str, int begin_index, int end_index, std::vector<std::string*>& main_array) {
  if (end_index == -1) {
    begin_index = 0;
    end_index = main_array.size();
  }
  else {
    --end_index;
    --begin_index;
  }
  for (int i = begin_index; i < end_index; ++i) {
    size_t pos = main_array[i]->find(old_str);
    while (pos != std::string::npos) {
      main_array[i]->replace(pos, old_str.size(), new_str);
      pos = main_array[i]->find(old_str, pos + new_str.size());
    }
  }
  return;
}

// algorithmic
void func::RemoveZeroes(int begin_index, int end_index, std::vector<std::string*>& main_array) {
  if (end_index == -1) {
    begin_index = 0;
    end_index = main_array.size();
  }
  else {
    --end_index;
    --begin_index;
  }
  for (int i = begin_index; i <= end_index; ++i) {
    for (int index = 0; index < main_array[i]->size() - 1; ++index) {
      if ((*main_array[i])[index] == '0') {
        if (std::string("0123456789").find((*main_array[i])[index + 1]) != -1) {
          if (index == 0) {
            main_array[i]->erase(main_array[i]->begin() + index);
            --index;
          }
          else if (std::string("0123456789").find((*main_array[i])[index - 1]) == -1) {
            main_array[i]->erase(main_array[i]->begin() + index);
            --index;
          }
        }
      }
    }
  }
  return;
}
void func::RemoveAsterisks(int begin_index, int end_index, std::vector<std::string*>& main_array) {
  if (end_index == -1) {
    begin_index = 0;
    end_index = main_array.size();
  }
  else {
    --end_index;
    --begin_index;
  }
  for (int i = begin_index; i <= end_index; ++i) {
    *main_array[i] += "6";
    for (int j = 0; j < main_array[i]->size(); ++j) {
      if (main_array[i]->at(j) == '*') {
        int k = j;
        for (; main_array[i]->at(j) == '*' && j < main_array[i]->size() - 1; ++j) continue;
        if (j == k + 1) continue;

        std::string tmp;
        for (int h = 0; h < (j - k) / 2; ++h) tmp += "+";
        main_array[i]->replace(main_array[i]->begin() + k,
          main_array[i]->begin() + j, tmp);
        j = 0;
      }
    }
    main_array[i]->erase(--main_array[i]->end());
  }
  return;
}
void func::RemoveBracketsContent(int begin_index, int end_index, std::vector<std::string*>& main_array) {
  if (end_index == -1) {
    begin_index = 0;
    end_index = main_array.size();
  }
  else {
    --end_index;
    --begin_index;
  }
  for (auto i = main_array.begin() + begin_index;
    i <= main_array.begin() + end_index; ++i) {
    *(*i) += "6";
    for (auto j = (*i)->begin(); j < (*i)->end(); ++j) {
      if (*j == '{') {
        for (; *j != '}'; (*i)->erase(j)) continue;
        (*i)->erase(j);
      }
    }
    (*i)->erase(--(*i)->end());
  }
  return;
}
void func::RemoveDigitsWithIncreasingValues(int begin_index, int end_index, std::vector<std::string*>& main_array) {
  if (end_index == -1) {
    begin_index = 0;
    end_index = main_array.size();
  }
  else {
    --end_index;
    --begin_index;
  }
  for (auto i = main_array.begin() + begin_index; i < main_array.begin() + end_index;
    ++i) {
    *(*i) += "f";
    for (auto j = (*i)->begin(); j < (*i)->end() - 1; ++j) {
      auto IsDigit = [](char ch) -> bool {
        return std::string("0123456789").find(ch) != -1;
      };
      if (IsDigit(*j)) {
        auto k = j + 1;
        for (; IsDigit(*k) && k < (*i)->end() - 1; ++k) continue;
        if (k - j > 1) {
          for (auto t = j; t < k - 1; ++t) {
            if (*t >= *(t + 1)) {
              (*i)->erase(j, k);
              break;
            }
          }
        }
      }
    }
    (*i)->erase(--(*i)->end());
  }
  return;
}
