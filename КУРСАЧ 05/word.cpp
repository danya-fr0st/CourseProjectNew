#include "word.h"
#define number_of_word 16
#define number_of_bytes 8

word::word()
{
    array_of_bytes[0] = 0;
    array_of_bytes[1] = 0;
}

word::~word() {}

short word::convert_to_int() const
{
    short result = 0;
    word temp = *this;
    if (getbit(number_of_word-1))
    {
        if (getbit(0))
            for (int i = number_of_word-1; !getbit(number_of_word-1 - i); --i)
            {
                temp.flip(number_of_word - i);
            }
        temp.flip(0);
        temp.flip();
        for (int i = 0; i <= number_of_word-1; ++i)
        {
            if (temp.getbit(i))
                result += (int)pow(2, i);
        }
        return -result;
    }

    else
    {
        for (int i = 0; i <= number_of_word-1; ++i)
        {
            if (getbit(i))
                result += (int)pow(2, i);
        }
    }
    return result;
}

word::word(int value)
{
    int tmp = value;

    for (int i = 0; i < number_of_word; ++i)
    {
        if (value % 2)
            setbit(i, 1);
        else
            setbit(i, 0);
        value = value / 2;
    }
    if (tmp < 0)
    {
        flip();
        flip(0);
        if (!getbit(0))
            for (int i = number_of_word-1; !getbit(number_of_word-1 - i); --i)
            {
                flip(number_of_word - i);
            }
    }
}

void word::reset()
{
    for (size_t i = 0; i < number_of_word; ++i)
    {
        setbit(i, 0);
    }
}

void word::flip()
{
    for (size_t i = 0; i < number_of_word; i++)
    {
        setbit(i, !getbit(i));
    }
}

bool word::operator== (const word& rhs) const
{
    for (int i = 0; i < number_of_word; ++i)
    {
        if (getbit(i) != rhs.getbit(i))
            return false;
    }
    return true;
}

bool word::operator!= (const word& rhs) const
{
    for (int i = 0; i < number_of_word; ++i)
    {
        if (getbit(i) != rhs.getbit(i))
            return true;
    }
    return false;
}

word& word::operator += (int rhs)
{
    int val = convert_to_int() + rhs;
    int tmp = val;
    for (int i = 0; i < number_of_word; ++i)
    {
        if (val % 2)
            setbit(i, 1);
        else
            setbit(i, 0);
        val = val / 2;
    }
    if (tmp < 0)
    {
        flip();
        flip(0);
        if (!getbit(0))
            for (int i = number_of_word-1; !getbit((number_of_word-1) - i); --i)
            {
                flip(16 - i);
            }
    }
    return *this;
}

word& word::operator -= (const word& rhs)
{
    for (int i = number_of_word-1; i >= 0; --i)
        setbit(i, (rhs.getbit(i) != getbit(i)));
    return *this;
}

word& word::operator -= (int rhs)
{
    int val = convert_to_int() - rhs;
    int tmp = val;
    for (int i = 0; i < number_of_word; ++i)
    {
        if (val % 2)
            setbit(i, 1);
        else
            setbit(i, 0);
        val = val / 2;
    }
    if (tmp < 0)
    {
        flip();
        flip(0);
        if (!getbit(0))
            for (int i = number_of_word-1; !getbit((number_of_word-1) - i); --i)
            {
                flip(number_of_word - i);
            }
    }
    return *this;
}

word& word::operator =(int value)
{
    reset();
    int tmp = value;
    for (int i = 0; i < number_of_word; ++i)
    {
        if (value % 2)
            setbit(i, 1);
        else
            setbit(i, 0);
        value = value / 2;
    }
    if (tmp < 0)
    {
        flip();
        flip(0);
        if (!getbit(0))
            for (int i = number_of_word-1; !getbit((number_of_word-1) - i); --i)
            {
                flip(number_of_word - i);
            }
    }
    return *this;
}

word& word::operator += (const word& rhs)
{
    for (int i = number_of_word-1; i >= 0; --i)
        setbit(i, (rhs.getbit(i) != getbit(i)));
    return *this;
}

word& word::operator =(const word& rhs)
{
    for (size_t i = 0; i <= number_of_word-1; ++i)
        setbit(i, rhs.getbit(i));
    return *this;
}

void word::flip(size_t index)
{
    setbit(index, !getbit(index));
}

bool word::getbit(int index) const
{
    if(index < 8)
        return array_of_bytes[0].return_array() >> index & 1;
    else
        return array_of_bytes[1].return_array() >> (index - number_of_bytes) & 1;
}

void word::setbit(int index, bool newvalue)
{
    if (newvalue && index < number_of_bytes)
    {
        array_of_bytes[0].return_array() |= 1 << index;
    }
    else if (newvalue && index > number_of_bytes-1)
    {
        array_of_bytes[1].return_array() |= 1 << index - number_of_bytes;
    }
    else if (!newvalue && index < number_of_bytes)
    {
        array_of_bytes[0].return_array() &= ~(1 << index);
    }
    else
    {
        array_of_bytes[1].return_array() &= ~(1 << (index - number_of_bytes));
    }
}

byte word::return_byte(size_t number) const
{
    return array_of_bytes[number];
}

byte & word::return_byte(size_t number)
{
    return array_of_bytes[number];
}

word::word(const byte& first, const byte& second)
{
    array_of_bytes[0] = first;
    array_of_bytes[1] = second;
}

word& word::operator^=(const word& in)
{
    for (int i = number_of_word-1; i >= 0; --i) {
        if (in.getbit(i) == getbit(i))
        {
            setbit(i, 0);
        }
        else
            setbit(i, 1);
    }
    return *this;
}

word& word::operator&=(const word& in)
{
    for (int i = number_of_word-1; i >= 0; --i) {
        if (in.getbit(i) == 1 && getbit(i) == 1)
        {
            setbit(i, 1);
        }
        else
            setbit(i, 0);
    }
    return *this;
}

std::ostream & operator<<(std::ostream &out, word &rhs)
{
    for (int i = 15; i >= 0; --i)
        out << rhs.getbit(i);
    return out;
}

std::string to_bin_str (word& rhs){
    std::string out;
    for (int i = 15; i >= 0; --i)
        out = static_cast<char>(rhs.getbit(i) + '0') + out;
    return out;
}

bool word::parity()
{
    int temp = 0;
    for (int i = 0; i < 16; ++i)
        if (getbit(i)) ++temp;
    if (temp % 2)
        return false;
    else
        return true;
}


