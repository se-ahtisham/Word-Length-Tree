#pragma once

#include<iostream>
#include<string>
#include <cstring>
#include <cmath>

using namespace std;

class Node {
public:
	Node();
	string name;
	Node* left;
	Node* right;
};