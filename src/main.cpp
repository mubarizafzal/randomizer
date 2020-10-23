#include <iostream>
#include <random>
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
  vector<string> formatted;

  cout << "Enter nothing to begin randomized outputting:" << endl;

  while (true) {
    getline(cin, temp);
    cout << "this: " << temp << " fin" << endl;
    
    if (temp == "") {
      cin.clear();
      //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\0');
      cin >> temp;
      getline(cin, temp);
      cout << "this: " << temp << " fin" << endl;
    
      break;
    }

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
    }

    formatted.reserve(formatted.size() + values.size());
    for (const auto& s : values) {
      formatted.emplace_back(s);
    }

    temp = "";
  }
  
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> distribution(0, formatted.size() - 1);
  
  cout << "Randomized output now beginning!" << endl;
  cout << "Enter anything to quit:" << endl;

  while (!true) {

    cout << formatted[distribution(gen)] << endl;
    getline(cin, temp);
    if (temp != "") {
      break;
    }

  }
  
}