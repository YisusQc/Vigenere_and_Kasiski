#pragma once

#include <string>
#include <unordered_map>

void kasiski(
  const std::string& text,
  int sequence_length
);

std::string kasiski_attack(
  const std::string& text,
  int sequence_length,
  const std::string* alphabet,
  const std::unordered_map<std::string,int>& alphabet_pos
);

