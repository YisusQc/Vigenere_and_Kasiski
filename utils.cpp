#include "utils.hpp"

void substitution(std::string& text, const std::unordered_map<std::string, std::string>& substitutions)
{
  for (const auto& [from, to] : substitutions)
  {
    std::size_t pos = 0;
    while ((pos = text.find(from, pos)) != std::string::npos)
    {
      text.replace(pos, from.size(), to);
      pos += to.size();
    }
  }
}
