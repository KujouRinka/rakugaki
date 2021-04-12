#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

map<string, string> buildMap(istream &mapFile) {
    map<string, string> tranMap;
    string key, value;
    while (mapFile >> key && getline(mapFile, value)) {
        if (value.size() > 1)
            tranMap[key] = value.substr(1);
        else
            throw runtime_error("no rule for " + key);
    }
    return tranMap;
}

string transWord(map<string, string> &transMap, const string &transWord) {
    if (transMap.count(transWord))
        return transMap[transWord];
    return transWord;
}

void wordTransform(istream &mapFile, istream &input, ostream &output = cout) {
    auto transMap = buildMap(mapFile);
    string text;
    while (getline(input, text)) {
        istringstream iss(text);
        string word;
        bool firstWord = true;
        while (iss >> word) {
            if (firstWord)
                firstWord = false;
            else
                output << " ";
            output << transWord(transMap, word);
        }
        output << endl;
    }
}

int main() {
    ifstream dic("dic.in"), r("read.in");
    ofstream o("write.out");
    wordTransform(dic, r, o);
    o.close();
    return 0;
}
