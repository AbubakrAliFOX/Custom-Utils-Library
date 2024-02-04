#include <iostream>
#include "clsUtils.h"
#include "clsInputValidate.h"

using namespace std;

int main()
{
    clsUtils::Srand();
    // cout << clsUtils::GenerateKey(clsUtils::MixChars);
    cout << clsInputValidate::isDateBetween(clsDate(1, 6, 2020), clsDate(31, 12, 2021), clsDate(1, 1, 2020));
}
