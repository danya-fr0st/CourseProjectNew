#include "dword.h"
#define number_of_dword 32
#define number_of_word 16
#define number_of_bytes 8

dword::dword()
{
    array_of_bytes[0] = 0;
    array_of_bytes[1] = 0;
}

dword::dword(int value)
{
    int tmp = value;
    for (int i = 0; i < number_of_dword; ++i)
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
            for (int i = number_of_dword-1; !getbit((number_of_dword-1) - i); --i)
            {
                flip(32 - i);
            }
    }
}

void dword::reset()
{
    for (size_t i = 0; i < number_of_dword; ++i)
    {
        setbit(i, 0);
    }
}

void dword::flip()
{
    for (size_t i = 0; i < number_of_dword; i++)
    {
        setbit(i, !getbit(i));
    }
}

bool dword::operator== (const dword& rhs) const
{
    for (int i = 0; i < number_of_dword; ++i)
    {
        if (getbit(i) != rhs.getbit(i))
            return false;
    }
    return true;
}

dword& dword::operator += (int rhs)
{
    int value = convert_to_int() + rhs;
    int tmp = value;
    for (int i = 0; i < number_of_dword; ++i)
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
            for (int i = number_of_dword-1; !getbit((number_of_dword-1) - i); --i)
            {
                flip(number_of_dword - i);
            }
    }
    return *this;
}

dword& dword::operator -= (const dword& rhs)
{
    for (int i = number_of_dword-1; i >= 0; --i)
        setbit(i, (rhs.getbit(i) != getbit(i)));
    return *this;
}

dword& dword::operator -= (int rhs)
{
    int value = convert_to_int() - rhs;
    int tmp = value;
    for (int i = 0; i < number_of_dword; ++i){
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
            for (int i = number_of_dword-1; !getbit((number_of_dword-1) - i); --i)
            {
                flip(number_of_dword - i);
            }
    }
    return *this;
}

dword& dword::operator =(int value)
{
    reset();
    int tmp = value;
    for (int i = 0; i < number_of_dword; ++i)
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
            for (int i = number_of_dword-1; !getbit((number_of_dword-1) - i); --i)
            {
                flip(number_of_dword - i);
            }
    }
    return *this;
}

dword& dword::operator += (const dword& rhs)
{
    for (int i = number_of_dword-1; i >= 0; --i)
        setbit(i, (rhs.getbit(i) != getbit(i)));
    return *this;
}

dword& dword::operator =(const dword& rhs)
{
    for (size_t i = 0; i <= number_of_dword-1; ++i)
        setbit(i, rhs.getbit(i));
    return *this;
}

void dword::flip(size_t index)
{
    setbit(index, !getbit(index));
}

bool dword::getbit(int index) const
{
    if (index < number_of_bytes)
        return array_of_bytes[0].return_array() >> index & 1;
    else if (index > number_of_bytes-1 && index < number_of_word)
        return array_of_bytes[1].return_array() >> (index - number_of_bytes) & 1;
    else if (index > number_of_bytes-1 && index < 24)
        return array_of_bytes[2].return_array() >> (index - number_of_word) & 1;
    else
        return array_of_bytes[3].return_array() >> (index - 24) & 1;
}

void dword::setbit(int index, bool newvalue)
{
    if (newvalue)
    {
        if (index < number_of_bytes)
            array_of_bytes[0].return_array() |= 1 << index;
        else if (index > number_of_bytes-1 && index < number_of_word)
            array_of_bytes[1].return_array() |= 1 << (index - number_of_bytes);
        else if (index > number_of_word-1 && index < 24)
            array_of_bytes[2].return_array() |= 1 << (index - number_of_word);
        else
            array_of_bytes[3].return_array() |= 1 << (index - 24);
    }
    else
    {
        if (index < number_of_bytes)
            array_of_bytes[0].return_array() &= ~(1 << index);
        else if (index > number_of_bytes-1 && index < number_of_word)
            array_of_bytes[1].return_array() &= ~(1 << (index - number_of_bytes));
        else if (index > number_of_word-1 && index < 24)
            array_of_bytes[2].return_array() &= ~(1 << (index - number_of_bytes));
        else
            array_of_bytes[3].return_array() &= ~(1 << (index - 24));
    }
}

byte dword::return_byte(size_t number) const
{
    return array_of_bytes[number];
}

byte & dword::return_byte(size_t number)
{
    return array_of_bytes[number];
}

dword::dword(const byte& first, const byte& second, const byte& third, const byte& fourth)
{
    array_of_bytes[0] = first;
    array_of_bytes[1] = second;
    array_of_bytes[2] = third;
    array_of_bytes[3] = fourth;
}

dword& dword::operator^=(const dword& in)
{
    for (int i = number_of_dword-1; i >= 0; --i)
    {
        if (in.getbit(i) == getbit(i))
        {
            setbit(i, 0);
        }
        else
            setbit(i, 1);
    }
    return *this;
}

dword& dword::operator&=(const dword& in)
{
    for (int i = number_of_dword-1; i >= 0; --i) {
        if (in.getbit(i) == 1 && getbit(i) == 1)
        {
            setbit(i, 1);
        }
        else
            setbit(i, 0);
    }
    return *this;
}

int dword::convert_to_int() const
{
    int result = 0;
    dword temp = *this;
    if (getbit(number_of_dword-1))
    {
        if (getbit(0))
            for (int i = number_of_dword-1; !getbit((number_of_dword-1) - i); --i)
            {
                temp.flip(number_of_dword - i);
            }
        temp.flip(0);
        temp.flip();
        for (int i = 0; i <= number_of_dword-1; ++i)
        {
            if (temp.getbit(i))
                result += (int)pow(2, i);
        }
        return -result;
    }

    else
    {
        for (int i = 0; i <= number_of_dword-1; ++i)
        {
            if (getbit(i))
                result += (int)pow(2, i);
        }
    }
    return result;
}

bool dword::parity()
{
    int temp = 0;
    for (int i = 0; i < 32; ++i)
        if (getbit(i)) ++temp;
    if (temp % 2)
        return false;
    else
        return true;
}

std::ostream & operator<<(std::ostream &out, dword &rhs)
{
    for (int i = 3; i >= 0; --i)
        out << rhs.return_byte(i) << " : ";
    return out;
}

std::string to_bin_str (dword& rhs){
    std::string out;
    for (int i = 31; i >= 0; --i)
        out = static_cast<char>(rhs.getbit(i) + '0') + out;
    return out;
}

