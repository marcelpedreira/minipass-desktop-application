#ifndef WIEGAND_H
#define WIEGAND_H

void codeSplit(int code, int &facCode, int &userCode)
{
    facCode = code / 100000;
    userCode = code % 100000;
}

int codeConcat(int facCode, int userCode)
{
    return (facCode * 100000) + userCode;
}


long concat(int high, int low)
{
    return (high * 256) + low;
}

void split(long number, int &high, int &low)
{
    low = number & 255;
    long temp = number & 0b1111111100000000;
    high = temp / 256;
}

void year_split(int year, int &year_high, int &year_low)
{
		year_high = year / 100;
		year_low = year % 100;
}

#endif // WIEGAND_H
