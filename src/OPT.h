#pragma once

//*******************************************************************
// OPT.h
// 
// By: Caleb Willson
// Date: 10/26/22
//
// Summary: Header file for OPT class
//*******************************************************************

#include <iostream>
#include <vector>
#include "ReplacementAlgorithm.h"

using namespace std;

class OPT : public ReplacementAlgorithm {
public:
	OPT(int numPageFrames, vector<int> reference);
	void insert(int pageNumber) override;

private:
	vector<int> frameList;
	vector<int> refString;
	vector<int> nextRef;
	int currIndex;
};

