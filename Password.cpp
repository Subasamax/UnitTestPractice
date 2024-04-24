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


Password::Password(){
  pass_history.push_back("ChicoCA-95929");
}


  /*
  receives a password and sets the latest in pass_history to it if and only
  if it meets all criteria:
    1. The password is at least 8 letters long, but no longer than 20
    2. It has no more than 3 of the same leading characters
    3. It has mixed case (at least one upper case and at least one lower case)
    4. It was not a previous password in the history
  */
void Password::set(string s){
  if (s.size() > 8 && s.size() < 21){
    if (count_leading_characters(s) < 4){
      if (has_mixed_case(s)){
        bool found = false;
        for (int i = 0 ; i < pass_history.size(); i++){
          if (pass_history[i] == s) found = true;
        }
        if (!found) {
          pass_history.push_back(s);
          return;
        };
        return;
      }
    }
  }
}



  /*
  receives a string and authenticates it against the latest password in the
  pass_history, returning true for an exact match or false when it does not match
  or if a password has not been set.
  */
bool Password::authenticate(string s){
  if (pass_history.size() == 0) return false;
  if (pass_history[pass_history.size()-1] == s) {
    return true;
  }
  return false;
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
