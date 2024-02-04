#pragma once
#include <iostream>
using namespace std;

class clsUtils
{
public:
    static int RandomNumber(int From, int To)
    {
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }

    enum enCharType
    {
        SamallLetter = 1,
        CapitalLetter = 2,
        Digit = 3,
        MixChars = 4,
        SpecialCharacter = 5
    };

    static void Srand()
    {
        // Seeds the random number generator in C++, called only once
        srand((unsigned)time(NULL));
    }

    static char GetRandomCharacter(enCharType CharType)
    {

        // updated this method to accept mixchars
        if (CharType == MixChars)
        {
            // Capital/Samll/Digits only
            CharType = (enCharType)RandomNumber(1, 5);
        }

        switch (CharType)
        {

        case enCharType::SamallLetter:
        {
            return char(RandomNumber(97, 122));
            break;
        }
        case enCharType::CapitalLetter:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        case enCharType::SpecialCharacter:
        {
            return char(RandomNumber(33, 47));
            break;
        }
        case enCharType::Digit:
        {
            return char(RandomNumber(48, 57));
            break;
        }
        defualt:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        }
    }

    static string GenerateWord(enCharType CharType, int Length = 4)
    {
        string RandomWord = "";

        for (int i = 0; i < Length; i++)
        {

            RandomWord += GetRandomCharacter(CharType);
        }

        return RandomWord;
    }

    static string GenerateKey(enCharType CharType = CapitalLetter)

    {
        string RandomKey = "";

        RandomKey = GenerateWord(CharType, 4) + "-";
        RandomKey = RandomKey + GenerateWord(CharType, 4) + "-";
        RandomKey = RandomKey + GenerateWord(CharType, 4) + "-";
        RandomKey = RandomKey + GenerateWord(CharType, 4);

        return RandomKey;
    }

    static void GenerateKeys(int Times, enCharType CharType = CapitalLetter)
    {
        for (int i = 1; i <= Times; i++)
        {
            cout << "Key [" << i << "] : " << GenerateKey(CharType) << endl;
        }
    }
};
