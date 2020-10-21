#include <iostream>
#include <string>
#include <vector>

using namespace std;


vector<string> splitString (const string& s, const string& delimiters) {
  vector<string> ret;
  string current = "";
  bool hit = false;

  for (const char &c : s) {
    
    for (const char &d : delimiters) {
    
      if (c == d) {
        hit = true;
        break;
      }
    }

    if (hit) {
      if (current != "") {
        ret.push_back(current);
        current = "";
      }
    } else {
      current = current + c;
    }

    hit = false;
  }

  if (current != "") {
    ret.push_back(current);
  }
  
  return ret;
}

int main () {

  string temp;

  // hard delimit on commas
  // we can reomve leading and trailing whitespaces

  // getline
  // ask for more input at beginning
  // (otherwise press enter without any input, or whitespace only) which starts the program

  vector<string> values;

  while (true) {
    getline(cin, temp);
    values = splitString(temp, ",");
    for (auto&& s: values) {
      for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
          s = s.substr(i, s.size() - i);
          break;
        }
      }
      while (s.back() == ' ') {
        s.pop_back();
      }
      cout << s << endl;
    }
    cout << "---------" << endl;
  }




}