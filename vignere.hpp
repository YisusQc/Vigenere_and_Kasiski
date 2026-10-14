#pragma once

#include <string>
#include <unordered_map>

void vignere(
  std::string& word,
  std::string key,
  const std::string *alphabet,
  const std::unordered_map<std::string,int>& alphabet_pos,
  int mod
);

void vignere_decrypt(
  std::string& word,
  std::string key,
  const std::string *alphabet,
  const std::unordered_map<std::string,int>& alphabet_pos,
  int mod
);

void vignere_autokey(
  std::string& word,
  std::string key,
  const std::string* alphabet,
  const std::unordered_map<std::string,int>& alphabet_pos,
  int mod
);

void vignere_autokey_decrypt(
  std::string& word,
  std::string key,
  const std::string* alphabet,
  const std::unordered_map<std::string,int>& alphabet_pos,
  int mod
);

