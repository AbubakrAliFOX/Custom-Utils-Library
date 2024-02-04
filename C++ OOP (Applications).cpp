#include <iostream>
#include "clsUtils.h"
using namespace std;

int main()
{
    clsUtils::Srand();
    // cout << clsUtils::GenerateKey(clsUtils::MixChars); 
    clsUtils::GenerateKeys(10);
}
