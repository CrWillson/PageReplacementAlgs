//*******************************************************************
// OPT.cpp
// 
// By: Caleb Willson
// Date: 10/26/22
//
// Summary: Implementation for the optimal page replacement alg
//*******************************************************************

#include "OPT.h"

OPT::OPT(int numPageFrames, vector<int> reference) : ReplacementAlgorithm(numPageFrames) {
    pageFaultCount = 0;
    currIndex = 0;
    refString = reference;
}

void OPT::insert(int pageNumber) {
    // check if the page is already loaded
    for (int i = 0; i < frameList.size(); i++) {
        if (frameList.at(i) == pageNumber) {
            currIndex++;
            return;
        }
    }

    // load the new page
    if (frameList.size() >= pageFrameCount) {

        // Find the next index in which each currently loaded page is referenced
        // and store it in the nextRef vector.
        // If the page is never used again, assign it a nextRef greater than 
        // the size of the reference string vector.
        for (int i = 0; i < frameList.size(); i++) {
            for (int j = currIndex; j < refString.size(); j++) {
                if (frameList.at(i) == refString.at(j)) {
                    nextRef.at(i) = j;
                    break;
                }
            }
            if (nextRef.at(i) < currIndex) {
                nextRef.at(i) = refString.size() + 1;
            }
        }
        // Get the index of the page not used for the longest time
        int optIndex = 0;
        for (int i = 0; i < nextRef.size(); i++) {
            if (nextRef.at(i) >= nextRef.at(optIndex)) {
                optIndex = i;
            }
        }

        // replace that page
        frameList.at(optIndex) = pageNumber;
    }
    // load the new page if there are empty page frames
    else {
        frameList.push_back(pageNumber);
        nextRef.push_back(-1);
    }
    // incrememnt the page faults and the current index
    pageFaultCount++;
    currIndex++;
}

