#pragma once
#include <string>
#include <vector>
using namespace std;

class CommandOutputMessage {
    bool isInternal;
    string id;
    vector<string> parameters;
};