#include "byte.h"
#define number_of_bytes 8

byte::byte()
{
    for (int i = 0; i < number_of_bytes; ++i)
    {
        setbit(i, 0);
    }
}

byte::~byte() {}

byte::byte(int value)
{
    int tmp = value;
    for (int i = 0; i < number_of_bytes; ++i)
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
            for (int i = number_of_bytes-1; !getbit((number_of_bytes-1) - i); --i)
            {
                    flip(number_of_bytes - i);
            }
    }
}
byte& byte::operator += (const byte& input)
{
    for (int i = number_of_bytes-1; i >= 0; --i)
        setbit(i, (input.getbit(i) != getbit(i)));
    return *this;
}

byte& byte::operator += (int input)
{
    int value = convert_to_int() + input;
    int tmp = value;
    for (int i = 0; i < number_of_bytes; ++i)
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
            for (int i = number_of_bytes-1; !getbit((number_of_bytes-1) - i); --i)
            {
                flip(number_of_bytes - i);
            }
    }
    return *this;
}

byte& byte::operator -= (const byte& input)
{
    for (int i = number_of_bytes-1; i >= 0; --i)
        setbit(i, (input.getbit(i) != getbit(i)));
    return *this;
}

byte& byte::operator -= (int input)
{
    int value = convert_to_int() - input;
    int tmp = value;
    for (int i = 0; i < number_of_bytes; ++i)
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
            for (int i = number_of_bytes-1; !getbit((number_of_bytes-1) - i) ; --i)
            {
                flip(number_of_bytes-1 - i);
            }
    }
    return *this;
}

byte& byte::operator =(const byte& input)
{
    for (size_t i = 0; i <= number_of_bytes-1; ++i)
        setbit(i, input.getbit(i));
    return *this;
}

byte& byte::operator =(int input)
{
    reset();
    int tmp = input;
    for (int i = 0; i < number_of_bytes; ++i)
    {
        if (input % 2)
            setbit(i, 1);
        else
            setbit(i, 0);
        input = input / 2;
    }
    if (tmp < 0)
    {
        flip();
        flip(0);
        if (!getbit(0))
            for (int i = number_of_bytes-1; !getbit((number_of_bytes-1) - i); --i)
            {
                flip(number_of_bytes - i);
            }
    }
    return *this;
}

byte& byte::operator^=(const byte& input)
{
    for (int i = number_of_bytes-1; i >= 0; --i)
    {
        if (input.getbit(i) == getbit(i))
        {
            setbit(i, 0);
        }
        else
            setbit(i, 1);
    }
    return *this;
}

byte& byte::operator&=(const byte& input)
{
    for (int i = number_of_bytes-1; i >= 0; --i)
    {
        if (input.getbit(i) == 1 && getbit(i) == 1)
        {
            setbit(i, 1);
        }
        else
            setbit(i, 0);
    }
    return *this;
}

int byte::convert_to_int() const
{
    int result = 0;
    byte temp = *this;
    if (getbit(number_of_bytes-1))
    {
        if (getbit(0))
            for (int i = number_of_bytes-1; !getbit((number_of_bytes-1) - i); --i)
            {
                temp.flip(number_of_bytes - i);
            }
        temp.flip(0);
        temp.flip();
        for (int i = 0; i <= number_of_bytes-1; ++i)
        {
            if (temp.getbit(i))
                result += (int)pow(2, i);
        }
        return -result;
    }
    else
    {
        for (int i = 0; i <= number_of_bytes-1 ; ++i)
        {
            if (getbit(i))
                result += (int)pow(2, i);
        }
    }
    return result;
}

void byte::reset()
{
    for (size_t i = 0; i < number_of_bytes; ++i)
    {
        setbit(i, 0);
    }
}

void byte::flip(size_t index)
{
    setbit(index, !getbit(index));
}

void byte::flip()
{
    for (size_t i = 0; i < number_of_bytes; i++)
    {
        setbit(i, !getbit(i));
    }
}

void byte::setbit(int index, bool newvalue)
{
    if (newvalue)
        array_of_bytes |= 1 << index;
    else
        array_of_bytes &= ~(1 << index);
}

bool byte::getbit(int index) const
{
    return array_of_bytes >> index & 1;
}

bool byte::operator== (const byte& input) const
{
    for (int i = 0; i < number_of_bytes; ++i)
    {
        if (getbit(i) != input.getbit(i))
            return false;
    }
    return true;
}

unsigned char byte::return_array() const
{
    return array_of_bytes;
}

unsigned char & byte::return_array()
{
    return array_of_bytes;
}

bool byte::parity()
{
    int temp = 0;
    for (int i = 0; i < 8; ++i)
        if (getbit(i)) ++temp;
    if (temp % 2)
        return false;
    else
        return true;
}

std::ostream & operator<<(std::ostream &output, byte &input)
{
    for (int i = number_of_bytes-1; i >= 0; --i)
        output << input.getbit(i);
    return output;
}
