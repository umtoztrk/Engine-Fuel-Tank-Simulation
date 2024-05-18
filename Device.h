#pragma once
#include <string>
using namespace std;

class Device {
public:
	virtual string printInfo(int i) { return ""; }
};