#pragma once
#include "TextField.h"
#include "ClikedInterface.h"

struct InputStruct {
  TextBox* Input;
  bool IsInputing;
};

extern InputStruct GLBoxInput = { nullptr, 0 };

class TextBox :
  public TextField, ClikedInterface
{
public:
  void OnClicked() override;
};

