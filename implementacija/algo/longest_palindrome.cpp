#include "longest_palindrome.h"

pair<int, int> find_longest_palindrome(const string& str) {  // returns [start, end)
    int n = str.length();
    if (n == 0) return {0, 0};
    if (n == 1) return {0, 1};
    n = 2*n + 1;  // Position count
    int L[n];   // LPS Length Array
    L[0] = 0;
    L[1] = 1;
    int C = 1;    // centerPosition
    int R = 2;    // centerRightPosition
    int i = 0;    // currentRightPosition
    int iMirror;  // currentLeftPosition
    int maxLPSLength = 0, maxLPSCenterPosition = 0;
    int start = -1, end = -1, diff = -1;

    for (i = 2; i < n; i++) {
        iMirror  = 2*C-i;  // get currentLeftPosition iMirror for currentRightPosition i
        L[i] = 0;
        diff = R - i;  // If currentRightPosition i is within centerRightPosition R
        if (diff > 0) L[i] = min(L[iMirror], diff);
                                                                      // Attempt to expand
        while ( ((i + L[i]) < n && (i - L[i]) > 0) && (               // palindrome centered at
                ((i + L[i] + 1) % 2 == 0) ||                          // currentRightPosition i Here
                (str[(i + L[i] + 1)/2] == str[(i - L[i] - 1)/2]))) {  // for odd positions, we
            L[i]++;                                                   // compare characters and if
        }                                                             // match then increment LPS
                                                                      // Length by ONE If even
        if (L[i] > maxLPSLength) {  // Track maxLPSLength             // position, we just increment
            maxLPSLength = L[i];                                      // LPS by ONE without any
            maxLPSCenterPosition = i;                                 // character comparison
        }

        if (i + L[i] > R) {  // If palindrome centered at currentRightPosition i
            C = i;           // expand beyond centerRightPosition R,
            R = i + L[i];    // adjust centerPosition C based on expanded palindrome.
        }
    }
    start = (maxLPSCenterPosition - maxLPSLength)/2;
    end = start + maxLPSLength;
    return {start, end};
}
