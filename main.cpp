#include <unordered_map>
#include <string>
#include <iostream>

#include "vignere.hpp"
#include "kasiski.hpp"
#include "utils.hpp"

int main()
{
  std::string alphabet_191[191] = {
    "!", "\"", "#", "$", "%", "&", "'", "(", ")", "*",
    "+", ",", "-", ".", "/", "0", "1", "2", "3", "4",
    "5", "6", "7", "8", "9", ":", ";", "<", "=", ">",
    "?", "@", "A", "B", "C", "D", "E", "F", "G", "H",
    "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R",
    "S", "T", "U", "V", "W", "X", "Y", "Z", "[", "\\",
    "]", "^", "_", "`", "a", "b", "c", "d", "e", "f",
    "g", "h", "i", "j", "k", "l", "m", "n", "o", "p",
    "q", "r", "s", "t", "u", "v", "w", "x", "y", "z",
    "{", "|", "}", "~", "‘", "’", "¡", "¢", "£", "¤",
    "¥", "¦", "§", "¨", "©", "ª", "«", "¬", "­", "®",
    "¯", "°", "±", "²", "³", "´", "µ", "¶", "·", "¸",
    "¹", "º", "»", "¼", "½", "¾", "¿", "À", "Á", "Â",
    "Ã", "Ä", "Å", "Æ", "Ç", "È", "É", "Ê", "Ë", "Ì",
    "Í", "Î", "Ï", "Ð", "Ñ", "Ò", "Ó", "Ô", "Õ", "Ö",
    "×", "Ø", "Ù", "Ú", "Û", "Ü", "Ý", "Þ", "ß", "à",
    "á", "â", "ã", "ä", "å", "æ", "ç", "è", "é", "ê",
    "ë", "ì", "í", "î", "ï", "ð", "ñ", "ò", "ó", "ô",
    "õ", "ö", "÷", "ø", "ù", "ú", "û", "ü", "ý", "þ",
    "ÿ"
  };

  std::unordered_map<std::string, int> alphabet_pos_191 = {
    {"!", 0}, {"\"", 1}, {"#", 2}, {"$", 3}, {"%", 4},
    {"&", 5}, {"'", 6}, {"(", 7}, {")", 8}, {"*", 9},
    {"+", 10}, {",", 11}, {"-", 12}, {".", 13}, {"/", 14},
    {"0", 15}, {"1", 16}, {"2", 17}, {"3", 18}, {"4", 19},
    {"5", 20}, {"6", 21}, {"7", 22}, {"8", 23}, {"9", 24},
    {":", 25}, {";", 26}, {"<", 27}, {"=", 28}, {">", 29},
    {"?", 30}, {"@", 31}, {"A", 32}, {"B", 33}, {"C", 34},
    {"D", 35}, {"E", 36}, {"F", 37}, {"G", 38}, {"H", 39},
    {"I", 40}, {"J", 41}, {"K", 42}, {"L", 43}, {"M", 44},
    {"N", 45}, {"O", 46}, {"P", 47}, {"Q", 48}, {"R", 49},
    {"S", 50}, {"T", 51}, {"U", 52}, {"V", 53}, {"W", 54},
    {"X", 55}, {"Y", 56}, {"Z", 57}, {"[", 58}, {"\\", 59},
    {"]", 60}, {"^", 61}, {"_", 62}, {"`", 63}, {"a", 64},
    {"b", 65}, {"c", 66}, {"d", 67}, {"e", 68}, {"f", 69},
    {"g", 70}, {"h", 71}, {"i", 72}, {"j", 73}, {"k", 74},
    {"l", 75}, {"m", 76}, {"n", 77}, {"o", 78}, {"p", 79},
    {"q", 80}, {"r", 81}, {"s", 82}, {"t", 83}, {"u", 84},
    {"v", 85}, {"w", 86}, {"x", 87}, {"y", 88}, {"z", 89},
    {"{", 90}, {"|", 91}, {"}", 92}, {"~", 93}, {"‘", 94},
    {"’", 95}, {"¡", 96}, {"¢", 97}, {"£", 98}, {"¤", 99},
    {"¥", 100}, {"¦", 101}, {"§", 102}, {"¨", 103}, {"©", 104},
    {"ª", 105}, {"«", 106}, {"¬", 107}, {"­", 108}, {"®", 109},
    {"¯", 110}, {"°", 111}, {"±", 112}, {"²", 113}, {"³", 114},
    {"´", 115}, {"µ", 116}, {"¶", 117}, {"·", 118}, {"¸", 119},
    {"¹", 120}, {"º", 121}, {"»", 122}, {"¼", 123}, {"½", 124},
    {"¾", 125}, {"¿", 126}, {"À", 127}, {"Á", 128}, {"Â", 129},
    {"Ã", 130}, {"Ä", 131}, {"Å", 132}, {"Æ", 133}, {"Ç", 134},
    {"È", 135}, {"É", 136}, {"Ê", 137}, {"Ë", 138}, {"Ì", 139},
    {"Í", 140}, {"Î", 141}, {"Ï", 142}, {"Ð", 143}, {"Ñ", 144},
    {"Ò", 145}, {"Ó", 146}, {"Ô", 147}, {"Õ", 148}, {"Ö", 149},
    {"×", 150}, {"Ø", 151}, {"Ù", 152}, {"Ú", 153}, {"Û", 154},
    {"Ü", 155}, {"Ý", 156}, {"Þ", 157}, {"ß", 158}, {"à", 159},
    {"á", 160}, {"â", 161}, {"ã", 162}, {"ä", 163}, {"å", 164},
    {"æ", 165}, {"ç", 166}, {"è", 167}, {"é", 168}, {"ê", 169},
    {"ë", 170}, {"ì", 171}, {"í", 172}, {"î", 173}, {"ï", 174},
    {"ð", 175}, {"ñ", 176}, {"ò", 177}, {"ó", 178}, {"ô", 179},
    {"õ", 180}, {"ö", 181}, {"÷", 182}, {"ø", 183}, {"ù", 184},
    {"ú", 185}, {"û", 186}, {"ü", 187}, {"ý", 188}, {"þ", 189},
    {"ÿ", 190}
  };

  std::string alphabet_27[27] = {
    "A","B","C","D","E","F","G","H","I","J","K","L","M",
    "N","Ñ","O","P","Q","R","S","T","U","V","W","X","Y","Z"
  };

  std::unordered_map<std::string, int> alphabet_pos_27 = {
    {"A",0},{"B",1},{"C",2},{"D",3},{"E",4},{"F",5},{"G",6},
    {"H",7},{"I",8},{"J",9},{"K",10},{"L",11},{"M",12},{"N",13},
    {"Ñ",14},{"O",15},{"P",16},{"Q",17},{"R",18},{"S",19},{"T",20},
    {"U",21},{"V",22},{"W",23},{"X",24},{"Y",25},{"Z",26}
  };

  std::unordered_map<std::string, int> alphabet_freq = {
    {"A",0},{"B",0},{"C",0},{"D",0},{"E",0},{"F",0},{"G",0},{"H",0},{"I",0},{"J",0},{"K",0},{"L",0},{"M",0},
    {"N",0},{"Ñ",0},{"O",0},{"P",0},{"Q",0},{"R",0},{"S",0},{"T",0},{"U",0},{"V",0},{"W",0},{"X",0},{"Y",0},{"Z",0}
  };

  std::unordered_map<std::string, std::string> accents = {{"Á","A"},{"É","E"},{"Í","I"},{"Ó","O"},{"Ú","U"},{"á","a"},{"é","e"},{"í","i"},{"ó","o"},{"ú","u"}};
  std::unordered_map<std::string, std::string> to_uppercase = {{"a","A"},{"b","B"},{"c","C"},{"d","D"},{"e","E"},{"f","F"},{"g","G"},{"h","H"},{"i","I"},{"j","J"},{"k","K"},{"l","L"},{"m","M"},{"n","N"},{"ñ","Ñ"},{"o","O"},{"p","P"},{"q","Q"},{"r","R"},{"s","S"},{"t","T"},{"u","U"},{"v","V"},{"w","W"},{"x","X"},{"y","Y"},{"z","Z"}};
  std::unordered_map<std::string, std::string> remove_symbols = {{"¿",""},{"?",""},{"!",""},{"¡",""},{",",""},{";",""},{".",""},{":",""},{"'",""}};
  std::unordered_map<std::string, std::string> remove_spaces = {{" ",""}};

  std::string text = "Creer que es posible es el paso número uno hacia el  éxito. Despertarse y pensar en algo positivo puede cambiar el transcurso de todo el día. No eres lo suficientemente viejo como para no iniciar un nuevo camino hacia tus sueños. Levántate cada mañana creyendo que vas a vivir el mejor día de tu vida";
  std::string key = "POSITIVO";

  //-----------------------------------------------------------------------------------------------
  // Dado que estoy trabajando sobre el 'text' original, solo puedo aplicar uno de
  // los cifrados a la vez, si aplico los 4 consecutivos, solo el primero trabajará
  // sobre el 'text' original, los demás lo harán sobre el primer cifrado resultante.

  // std::cout << "\n" << text << "\n\n";
  // substitution(text, accents);
  // substitution(text, to_uppercase);
  // substitution(text, remove_symbols);
  // substitution(text, remove_spaces);
  // vignere(text, key, alphabet_27, alphabet_pos_27, 27);
  // std::cout << text << "\n\n";
  // vignere_decrypt(text, key, alphabet_27, alphabet_pos_27, 27);
  // std::cout << text << "\n\n";

  // std::cout << "\n" << text << "\n\n";
  // substitution(text, remove_spaces);
  // vignere(text, key, alphabet_191, alphabet_pos_191, 191);
  // std::cout << text << "\n\n";
  // vignere_decrypt(text, key, alphabet_191, alphabet_pos_191, 191);
  // std::cout << text << "\n\n";

  // std::cout << "\n" << text << "\n\n";
  // substitution(text, accents);
  // substitution(text, to_uppercase);
  // substitution(text, remove_symbols);
  // substitution(text, remove_spaces);
  // vignere_autokey(text, key, alphabet_27, alphabet_pos_27, 27);
  // std::cout << text << "\n\n";
  // vignere_autokey_decrypt(text, key, alphabet_27, alphabet_pos_27, 27);
  // std::cout << text << "\n\n";

  std::cout << "\n" << text << "\n\n";
  substitution(text, remove_spaces);
  vignere_autokey(text, key, alphabet_191, alphabet_pos_191, 191);
  std::cout << text << "\n\n";
  vignere_autokey_decrypt(text, key, alphabet_191, alphabet_pos_191, 191);
  std::cout << text << "\n\n";

  //-----------------------------------------------------------------------------------------------

  std::string ciphertext = "WPIXHVYYOSRTECSZBEEGHUUFWRWTZGRWUFSRIWESSXVOHAIHOHWWHCWHUZOBOZEAOYBMCRLTEYOTI";

  std::cout << "\n" << ciphertext << "\n\n";
  kasiski(ciphertext, 2);

  std::string key_result = kasiski_attack(ciphertext, 2, alphabet_27, alphabet_pos_27);
  vignere_decrypt(ciphertext, key_result, alphabet_27, alphabet_pos_27, 27);
  std::cout << "\n" << ciphertext << "\n\n";

  std::string text2 = "PIENSO QUE EL MAR ESTA TRANQUILO POR LO QUE LAS TEMPRESTADES PODRIAN VENIR A PARTIR DE MAÑANA";
  std::string key2 = "HIELO";

  std::cout << "\n" << text2 << "\n\n";
  substitution(text2, remove_spaces);
  vignere(text2, key2, alphabet_27, alphabet_pos_27, 27);
  std::cout << text2 << "\n\n";

  std::string ciphertext2 = "XHGDQESDMPKÑDEEDKNGJZPFJSUIFZOLFCINFJCESVZTGBFXCIUDAYNUUDIZYWWZBEYNVQWIVUNKZEPHDODQUZZLBDNDRWTHQSERÑIVMLERCMGIFLSORZXTSDIGLOXQSDJHWVCIWQXQJCKMBPOKMPSKMUVIMNJDNBLCSZHXHNYYUIXDBSOXHZLXWVGDJGXHWLTDWKÑSAQIMZLNBVMLXHUOQQXIQGWGUFTWKZKMOKUDNINSIFJDUOZIJBSVVOWFAIEÑGYOWPSOAP";
  std::string key3 = "UNODELOSMASGRANDESCRIPTOGRAFOS";

  std::cout << "\n" << ciphertext2 << "\n\n";
  vignere_autokey_decrypt(ciphertext2, key3, alphabet_27, alphabet_pos_27, 27);
  std::cout << ciphertext2 << "\n\n";

  std::string ciphertext3 = "MAXYHGAVAPUUGZHEGZQOWOBNIPQKRNÑMEXIGONIICUCAWIGCTEAGMNOLRSZJNLWÑAWWIGLDDZSNIZDNBIXGZLAYMXÑCVEKIETMOEOPBEWPTNIXCXUIHMECXLNOCECYXEQPBWUFANIICÑJIKISCZUAILBGSOANKBFWUAYWNSCHLCWYDZHDZAQVMPTVGFGPVAJWFVPUOYMXCWERVLQCZWECIFVITUZSNCZUAIKBFMÑALIEGLBSZLQUXÑOHWOCGHNYWÑQKDANZUDIFOIMXNPHNUWQOKLMVBNNKRMKONDPDPNMIKAWOXMEEIVEKGBGSFHVADWPGOYMHOIUEEIPGOLENZBSCHAGKQTZDRÑMÑNWTUZIÑNCMÑNAXKQUWDLVANNIHLÑNCQNWGEHIPGZDTZTÑNNWÑNEEWFUMGIÑNXNTWXNVIXCZOAZSOQUVENDNFWUSZYHGLRACPGGUGIYWHOTRMZUGQQDDZIZFWHVVSHCUGOGIFKBXAXPBOBRDVDUCMVTKGIKDRSZLUQSDVPMXVIVEYMFGTEANIMQLHLGPQOHRYWCFEWFOISNÑPUAYINNÑXNÑPGKWGOILQGAFOILQTAHEIIDWMÑEÑXNEPRCVDQTURSK";
  std::cout << "\n" << ciphertext3 << "\n\n";

  std::string key_result2 = kasiski_attack(ciphertext3, 4, alphabet_27, alphabet_pos_27);
  // vignere_decrypt(ciphertext3, key_result2, alphabet_27, alphabet_pos_27, 27);
  vignere_autokey_decrypt(ciphertext3, key_result2, alphabet_27, alphabet_pos_27, 27);
  std::cout << "\n" << ciphertext3 << "\n\n";

  return 0;
}

