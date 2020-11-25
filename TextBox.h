#pragma once
#include "TextField.h"
#include "ClikedInterface.h"

struct InputStruct;

class TextBox :
  public TextField, ClikedInterface
{
public:
  void OnClicked() override;
  static InputStruct GLBoxInput;
};

struct InputStruct {
  TextBox* Input;
  bool IsInputing;
};