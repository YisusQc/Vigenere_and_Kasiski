#include "kasiski.hpp"

#include <vector>
#include <iostream>
#include <limits>

void kasiski(const std::string& text, int sequence_length)
{
	std::unordered_map<std::string, std::vector<std::size_t>> sequences;

	for (std::size_t i = 0; i + sequence_length <= text.size(); ++i)
		sequences[text.substr(i, sequence_length)].push_back(i);

	for (const auto& [sequence, positions] : sequences)
	{
		if (positions.size() < 2)
			continue;

		std::cout << sequence << " -> posiciones: ";

		for (auto position : positions)
			std::cout << position << ' ';

		std::cout << "| distancias: ";

		for (std::size_t i = 1; i < positions.size(); ++i)
			std::cout << positions[i] - positions[i - 1] << ' ';

		std::cout << '\n';
	}
}

namespace
{
	const std::unordered_map<std::string, double> spanish_frequency = {
		{"A", 12.53}, {"B", 1.42}, {"C", 4.68}, {"D", 5.86},
		{"E", 13.68}, {"F", 0.69}, {"G", 1.01}, {"H", 0.70},
		{"I", 6.25}, {"J", 0.44}, {"K", 0.02}, {"L", 4.97},
		{"M", 3.15}, {"N", 6.71}, {"Ñ", 0.31}, {"O", 8.68},
		{"P", 2.51}, {"Q", 0.88}, {"R", 6.87}, {"S", 7.98},
		{"T", 4.63}, {"U", 3.93}, {"V", 0.90}, {"W", 0.01},
		{"X", 0.22}, {"Y", 0.90}, {"Z", 0.52}
	};

	std::vector<int> factorize(int number)
	{
		std::vector<int> factors;

		for (int i = 2; i <= number; ++i)
		{
			if (number % i == 0)
				factors.push_back(i);
		}

		return factors;
	}

	std::vector<std::string> split_subcryptograms(const std::string& text, int key_length)
	{
		std::vector<std::string> subcryptograms(key_length);

		for (std::size_t i = 0; i < text.size(); ++i)
			subcryptograms[i % key_length] += text[i];

		return subcryptograms;
	}

	int find_key_length(const std::string& text, int sequence_length)
	{
		std::unordered_map<std::string, std::vector<std::size_t>> sequences;
		std::unordered_map<int, int> factor_count;

		for (std::size_t i = 0; i + 1 < text.size(); ++i)
			sequences[text.substr(i, sequence_length)].push_back(i);

		for (const auto& [sequence, positions] : sequences)
		{
			if (positions.size() < 2)
				continue;

			for (std::size_t i = 1; i < positions.size(); ++i)
			{
				int distance = positions[i] - positions[i - 1];

				for (int factor : factorize(distance))
					++factor_count[factor];
			}
		}

		int key_length = 0;
		int max_count = 0;

		for (const auto& [factor, count] : factor_count)
		{
			if (count > max_count)
			{
				max_count = count;
				key_length = factor;
			}
		}

		std::cout << "Longitud probable de la clave: " << key_length << '\n';

		return key_length;
	}

	double frequency_score(const std::string& subcryptogram, int shift, const std::string* alphabet, const std::unordered_map<std::string, int>& alphabet_pos)
	{
		std::unordered_map<std::string, int> frequencies;

		for (std::size_t i = 0; i < subcryptogram.size();)
		{
			std::string letter;

			for (int j = 0; j < 27; ++j)
			{
				if (subcryptogram.compare(i, alphabet[j].size(), alphabet[j]) == 0)
				{
					letter = alphabet[j];
					break;
				}
			}

			if (!letter.empty())
			{
				++frequencies[letter];
				i += letter.size();
			}
			else
			{
				++i;
			}
		}

		double score = 0;
		double size = 0;

		for (const auto& [letter, count] : frequencies)
			size += count;

		for (const auto& [letter, expected] : spanish_frequency)
		{
			int position = alphabet_pos.at(letter);
			int encrypted_position = (position + shift) % 27;

			const std::string& encrypted_letter = alphabet[encrypted_position];

			double observed = frequencies[encrypted_letter];
			double expected_count = size * expected / 100.0;

			if (expected_count > 0)
			{
				score += (observed - expected_count) * (observed - expected_count) / expected_count;
			}
		}

		return score;
	}

	int best_shift(const std::string& subcryptogram, const std::string* alphabet, const std::unordered_map<std::string, int>& alphabet_pos)
  {
    std::unordered_map<std::string, int> frequencies;

    for (std::size_t i = 0; i < subcryptogram.size();)
    {
      std::string letter;

      for (int j = 0; j < 27; ++j)
      {
        if (subcryptogram.compare(i, alphabet[j].size(), alphabet[j]) == 0)
        {
          letter = alphabet[j];
          break;
        }
      }

      if (!letter.empty())
      {
        ++frequencies[letter];
        i += letter.size();
      }
      else
      {
        ++i;
      }
    }

    const int aeos[] = {0, 4, 15, 19};

    int best = 0;
    int best_aeos_score = -1;
    double best_frequency_score = std::numeric_limits<double>::max();

    for (int shift = 0; shift < 27; ++shift)
    {
      int aeos_score = 0;

      for (int position : aeos)
      {
        const std::string& letter = alphabet[(position + shift) % 27];
        aeos_score += frequencies[letter];
      }

      double score = frequency_score(subcryptogram, shift, alphabet, alphabet_pos);

      if (aeos_score > best_aeos_score || (aeos_score == best_aeos_score && score < best_frequency_score))
      {
        best = shift;
        best_aeos_score = aeos_score;
        best_frequency_score = score;
      }
    }

    return best;
  }
}

std::string kasiski_attack(const std::string& text, int sequence_length, const std::string* alphabet, const std::unordered_map<std::string, int>& alphabet_pos)
{
	int key_length = find_key_length(text, sequence_length);
	std::cout << "Longitud de clave: " << key_length << '\n';

	auto subcryptograms = split_subcryptograms(text, key_length);

	std::string key;

	for (int i = 0; i < key_length; ++i)
	{
		int shift = best_shift(subcryptograms[i], alphabet, alphabet_pos);
		key += alphabet[shift];
		std::cout << "Subcriptograma " << i << " -> " << alphabet[shift] << " (" << shift << ")\n";
	}

	std::cout << "Clave encontrada: " << key << '\n';

	return key;
}

