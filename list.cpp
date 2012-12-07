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

int main(int argc, char** argv) {
  map<string, int> list;
  string name;
  map<string, int>::iterator it;
  ifstream file(argv[1]);

  if(argc != 3) {
    cout << "Usage: ./list [filename] [threshold]" << endl;
  }
  else {
    cout << "filename: " << argv[1] << endl;
    cout << "threshold: " << argv[2] << endl;

    if(file.is_open()) {
      while(file.good()) {
	getline(file, name);
	if(list.count(name)) {
	  list[name]++;
	}
	else {
	  list.insert(pair<string, int>(name, 1));
	}
      }
    }
  

    cout << endl;
    cout << endl;
    cout << "----NICE----" << endl;
    for(it=list.begin(); it != list.end(); it++) {
      if(it->second >= atoi(argv[2])) {
	cout << it->first << endl;
      }
    }

    cout << endl;
    cout << endl;
    cout << "----NAUGHTY----" << endl;
    for(it=list.begin(); it != list.end(); it++) {
      if(it->second < atoi(argv[2])) {
	cout << it->first << endl;
      }
    }
  }
  return 0;
}
