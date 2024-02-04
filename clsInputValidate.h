#pragma once
#include "clsPeriod.h"
#include <typeinfo>

class clsInputValidate
{
public:
    static bool isNumberBetween(short Number, short From, short To)
    {
        return (Number >= From) && (Number <= To);
    }

    static bool isNumberBetween(int Number, int From, int To)
    {
        return (Number >= From) && (Number <= To);
    }

    static bool isNumberBetween(float number, float From, float To)
    {
        return (number >= From) && (number <= To);
    }

    static bool isNumberBetween(double number, double From, double To)
    {
        return (number >= From) && (number <= To);
    }

    static bool isDateBetween(clsDate Date, clsDate From, clsDate To)
    {
        clsPeriod Period(From, To);

        return clsPeriod::IsDateWithinPeriod(Period, Date);
    }

    static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again\n")
    {
        int Number;
        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }
        return Number;
    }

    static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        int Number = ReadIntNumber();

        while (!isNumberBetween(Number, From, To))
        {
            cout << ErrorMessage;
            Number = ReadIntNumber();
        }
        return Number;
    }

    static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again\n")
    {
        double Number;
        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }
        return Number;
    }

    static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        double Number = ReadDblNumber();

        while (!isNumberBetween(Number, From, To))
        {
            cout << ErrorMessage;
            Number = ReadDblNumber();
        }
        return Number;
    }

    static bool IsValideDate(clsDate Date)
    {
        return clsDate::IsValid(Date);
    }
};
