#include <iostream>
#include <string>

using namespace std;

int main () {

  string a;

  // hard delimit on commas
  // we can reomve leading and trailing whitespaces

  // getline
  // ask for more input at beginning
  // (otherwise press enter without any input, or whitespace only) which starts the program

  while (true) {
    if (cin >> a) {
      cout << a << endl;
    } else {
      break;
    }
  }




}