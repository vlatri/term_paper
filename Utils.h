#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>

using namespace std;

class Utils {
  public:
    static string enterPrompt;
    static string trim(const string&);
    static string replaceChar(string, char, char);
    static string slice(string, int, int);
    static bool isNumber(const string&);
    static bool contains(string, string);
    static bool contains(string, char);
    static int strToInt(string);
    static int askForInt(string, int, int);
    static vector<string> strSplitBySpace(string);
    static string askForStr(string);
};

#endif