#ifndef CHECK_H
#define CHECK_H
#include <iostream>
#include <string>
using namespace std;

void checkName(string& str);
void checkDate(int* D, string& str);
void checkSign(string& str);
int checkIndex(int minInd, int maxInd);
void changeDateSign(int* D, string& str);

#endif 