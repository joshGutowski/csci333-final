#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::map;
using std::pair;
using std::ifstream;
using std::ofstream;

int main(int argc, char** argv) {
  map<string, int> list;
  map<int, string> sort;
  string word;
  map<string, int>::iterator it;
  map<int, string>::reverse_iterator rit;
  ifstream file(argv[1]);
  ofstream words("words");


  if(argc != 2) {
    cout << "Usage: ./wordList [filename]" << endl;
  }
  else {
    cout << "filename: " << argv[1] << endl;


    if(file.is_open()) {
      while(file.good()) {
	getline(file, word, ' ');

	if(list.count(word)) {
	  list[word]++;
	}
	else {
	  list.insert(pair<string, int>(word, 1));
	}
      }
    }
  

    for(it=list.begin(); it != list.end(); it++) {
      sort.insert(pair<int, string>(it->second, it->first));
    }

   
    if(words.is_open()) {
      while(words.good()) {
	for(rit=sort.rbegin(); rit != sort.rend(); rit++) {
	  words << rit->second << "-" << rit->first << endl;
	}
	words.close();
      }
    }
    cout << "output file: words" << endl;

    
  }
  return 0;
}
