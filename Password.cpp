#include "Password.h"
#include <string>
#include <cctype>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 0;
  int index = 0;
  if (phrase.size() > 0) repetition = 1;
  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}

bool Password::has_mixed_case(string word){
  
  bool lowerCase = false;
  bool upperCase = false;
  for (int i = 0; i < word.length(); i++){
    if (isupper(word[i])) upperCase = true;
    if (islower(word[i])) lowerCase = true;
    if (lowerCase && upperCase) return true;
  }
  if (lowerCase == false || upperCase == false) return false;
  return true;
}
