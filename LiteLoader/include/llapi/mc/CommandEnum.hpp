#pragma once
#include <string>
#include <vector>
using namespace std;

class CommandEnum {
    string name;
    vector<string> values;
    bool isSoft;
public:
    CommandEnum(string nm, vector<string> vls, bool soft) : name(nm), values(vls), isSoft(soft) {}
    inline string getName() {
        return name;
    }
    inline vector<string> getValues() {
        return values;
    }
    inline bool isSoft() {
        return isSoft;
    }
};