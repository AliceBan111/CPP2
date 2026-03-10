#pragma once

struct OptionData {
  double strike;
  double spot;
  double r;
  double vol;
  double expiry;
  bool isCall;
};

void printOptionByValue(OptionData opt);
void printOptionByPointer(const OptionData* opt);
void printOptionByReference(const OptionData& opt);
