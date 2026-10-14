#include <string>
#include <unordered_map>

#include "vignere.hpp"

void vignere(std::string& word, std::string key, const std::string* alphabet, const std::unordered_map<std::string, int>& alphabet_pos, int mod)
{
  std::size_t pos = 0;
  std::size_t key_byte_pos = 0;

  while (pos < word.size())
  {
    std::string letter;
    for (int i = 0; i < mod; ++i)
    {
      if (word.compare(pos, alphabet[i].size(), alphabet[i]) == 0)
      {
        letter = alphabet[i];
        break;
      }
    }

    int word_index = alphabet_pos.at(letter);

    std::string key_letter;
    for (int i = 0; i < mod; ++i)
    {
      if (key.compare(key_byte_pos, alphabet[i].size(), alphabet[i]) == 0)
      {
        key_letter = alphabet[i];
        break;
      }
    }
    int key_index = alphabet_pos.at(key_letter);

    int result_index = (word_index + key_index) % mod;

    word.replace(pos, letter.size(), alphabet[result_index]);
    pos += alphabet[result_index].size();
    key_byte_pos += key_letter.size();
    if (key_byte_pos >= key.size()) key_byte_pos = 0;
  }
}

void vignere_decrypt(std::string& word, std::string key, const std::string* alphabet, const std::unordered_map<std::string, int>& alphabet_pos, int mod)
{
  std::size_t pos = 0;
  std::size_t key_byte_pos = 0;

  while (pos < word.size())
  {
    std::string letter;
    for (int i = 0; i < mod; ++i)
    {
      if (word.compare(pos, alphabet[i].size(), alphabet[i]) == 0)
      {
        letter = alphabet[i];
        break;
      }
    }

    int word_index = alphabet_pos.at(letter);

    std::string key_letter;
    for (int i = 0; i < mod; ++i)
    {
      if (key.compare(key_byte_pos, alphabet[i].size(), alphabet[i]) == 0)
      {
        key_letter = alphabet[i];
        break;
      }
    }
    int key_index = alphabet_pos.at(key_letter);

    int result_index = (word_index - key_index + mod) % mod;

    word.replace(pos, letter.size(), alphabet[result_index]);
    pos += alphabet[result_index].size();
    key_byte_pos += key_letter.size();
    if (key_byte_pos >= key.size()) key_byte_pos = 0;
  }
}

void vignere_autokey(std::string& word, std::string key, const std::string* alphabet, const std::unordered_map<std::string, int>& alphabet_pos, int mod)
{
	std::size_t pos = 0;
	std::size_t key_byte_pos = 0;
	std::size_t key_index = 0;

	while (pos < word.size())
	{
		std::string letter;
		for (int i = 0; i < mod; ++i)
		{
			if (word.compare(pos, alphabet[i].size(), alphabet[i]) == 0)
			{
				letter = alphabet[i];
				break;
			}
		}

		int word_index = alphabet_pos.at(letter);

		std::string key_letter;
		for (int i = 0; i < mod; ++i)
		{
			if (key.compare(key_byte_pos, alphabet[i].size(), alphabet[i]) == 0)
			{
				key_letter = alphabet[i];
				break;
			}
		}

		int key_index_value = alphabet_pos.at(key_letter);

		int result_index = (word_index + key_index_value) % mod;

		word.replace(pos, letter.size(), alphabet[result_index]);
		pos += alphabet[result_index].size();
		key_byte_pos += key_letter.size();
		if (key_byte_pos >= key.size()) key_byte_pos = 0;
		if (key_index + key_letter.size() >= key.size()) key += letter;
		key_index += key_letter.size();
	}
}

void vignere_autokey_decrypt(std::string& word, std::string key, const std::string* alphabet, const std::unordered_map<std::string, int>& alphabet_pos, int mod)
{
	std::size_t pos = 0;
	std::size_t key_byte_pos = 0;
	std::size_t key_index = 0;

	while (pos < word.size())
	{
		std::string letter;
		for (int i = 0; i < mod; ++i)
		{
			if (word.compare(pos, alphabet[i].size(), alphabet[i]) == 0)
			{
				letter = alphabet[i];
				break;
			}
		}

		int word_index = alphabet_pos.at(letter);

		std::string key_letter;
		for (int i = 0; i < mod; ++i)
		{
			if (key.compare(key_byte_pos, alphabet[i].size(), alphabet[i]) == 0)
			{
				key_letter = alphabet[i];
				break;
			}
		}

		int key_index_value = alphabet_pos.at(key_letter);

		int result_index = (word_index - key_index_value + mod) % mod;

		std::string decrypted_letter = alphabet[result_index];
		word.replace(pos, letter.size(), decrypted_letter);
		pos += decrypted_letter.size();
		key_byte_pos += key_letter.size();
		if (key_byte_pos >= key.size()) key_byte_pos = 0;
		if (key_index + key_letter.size() >= key.size()) key += decrypted_letter;
		key_index += key_letter.size();
	}
}

