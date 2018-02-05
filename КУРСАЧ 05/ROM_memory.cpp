#include "ROM_memory.h"
#include <cstdlib>
#include <fstream>
#include "word.h"
#include <QMessageBox>

byte& ROM_memory::return_by_string(const std::string &title)
{
    if (title == "AH") return EAX.return_byte(0);
    else if (title == "AL") return EAX.return_byte(1);
    else if (title == "BH") return EBX.return_byte(0);
    else if (title == "BL") return EBX.return_byte(1);
    else if (title == "CH") return ECX.return_byte(0);
    else if (title == "CL") return ECX.return_byte(1);
    else if (title == "DH") return EDX.return_byte(0);
    else if (title == "DL") return EDX.return_byte(1);
}

word& ROM_memory::return_reg_by_string(const std::string &title)
{
    if (title == "EAX") return EAX;
    else if (title == "EBX") return EBX;
    else if (title == "ECX") return ECX;
    else if (title == "EDX") return EDX;
}

dword& ROM_memory::return_spec_reg_by_string(const std::string &title)
{
    if (title == "CR0") return CR0;
    else if (title == "CR1") return CR1;
    else if (title == "CR2") return CR2;
    else if (title == "CR3") return CR3;
}

word& ROM_memory::return_flags_by_string(const std::string &title)
{
    if (title == "Flags") return flags;
}

void ROM_memory::mov(const std::string &in, const std::string &out) {
    int temp_out(0);
    if (validator_parts(out))
        temp_out = return_by_string(out).convert_to_int();
    else if (validator_reg(out))
        temp_out = return_reg_by_string(out).convert_to_int();
    else if (validator_title(out))
        temp_out = data.return_by_string(out).convert_to_int();
    else if (isint(out))
        temp_out = std::atoi(out.c_str());

    if (validator_parts(in))
    {
        return_by_string(in) = temp_out;
        if (temp_out > 127 || temp_out < -128)
            flags.setbit(0, 1);
        else
            flags.setbit(0, 0);
    }
    else if (validator_reg(in)) {
        return_reg_by_string(in) = temp_out;
        if (temp_out > 2147483647 || temp_out < -2147483647)
            flags.setbit(0, 1);
        else
            flags.setbit(0, 0);
    }
    else if (validator_title(in)) {
        data.return_by_string(in) = temp_out;
        if (temp_out > 2147483647 || temp_out < -2147483647)
            flags.setbit(12, 1);
        else
            flags.setbit(0, 0);
    }
    else {}
    flags_check(in);
}

void ROM_memory::add(const std::string &in, const std::string &out) {
    int temp_out(0);
    if (validator_parts(out))
        temp_out = return_by_string(out).convert_to_int();
    else if (validator_reg(out))
        temp_out = return_reg_by_string(out).convert_to_int();
    else if (validator_title(out))
        temp_out = data.return_by_string(out).convert_to_int();
    else if (isint(out))
        temp_out = std::atoi(out.c_str());

    if (validator_parts(in)) {
        return_by_string(in) += temp_out;
        int temp = return_by_string(in).convert_to_int();
        if ((temp + temp_out) > 127 || (temp + temp_out) < -128)
            flags.setbit(0, 1);
        else
            flags.setbit(0, 0);
    }
    else if (validator_reg(in)) {
        return_reg_by_string(in) += temp_out;
        int temp = return_reg_by_string(in).convert_to_int();
        if ((temp + temp_out) - temp_out != temp)
            flags.setbit(0, 1);
        else
            flags.setbit(0, 0);
    }
    else if (validator_title(in)) {
        data.return_by_string(in) += temp_out;
        int temp = data.return_by_string(in).convert_to_int();
        if ((temp + temp_out) - temp_out != temp)
            flags.setbit(0, 1);
        else
            flags.setbit(0, 0);
    }
    else {}

    flags_check(in);
}


void ROM_memory::sub(const std::string &in, const std::string &out)
{
    int temp_out(0);
    if (validator_parts(out))
        temp_out = return_by_string(out).convert_to_int();
    else if (validator_reg(out))
        temp_out = return_reg_by_string(out).convert_to_int();
    else if (validator_title(out))
        temp_out = data.return_by_string(out).convert_to_int();
    else if (isint(out))
        temp_out = std::atoi(out.c_str());

    if (validator_parts(in)) {
        return_by_string(in) -= temp_out;
        int temp = return_by_string(in).convert_to_int();
        if ((temp - temp_out) > 127 || (temp - temp_out) < -128)
            flags.setbit(0, 1);
        else
            flags.setbit(0, 0);
    }
    else if (validator_reg(in)) {
        return_reg_by_string(in) -= temp_out;
        int temp = return_reg_by_string(in).convert_to_int();
        if ((temp - temp_out) + temp_out != temp)
            flags.setbit(0, 1);
        else
            flags.setbit(0, 0);
    }
    else if (validator_title(in)) {
        data.return_by_string(in) -= temp_out;
        int temp = data.return_by_string(in).convert_to_int();
        if ((temp - temp_out) + temp_out != temp)
            flags.setbit(0, 1);
        else
            flags.setbit(0, 0);
    }
    else {}
    flags_check(in);
}


void ROM_memory::xor_(const std::string &in, const std::string &out)
{
    int temp_out;
    if (validator_parts(out))
        temp_out = return_by_string(out).convert_to_int();
    else if (validator_reg(out))
        temp_out = return_reg_by_string(out).convert_to_int();
    else if (validator_title(out))
        temp_out = data.return_by_string(out).convert_to_int();
    else if (isint(out))
        temp_out = std::atoi(out.c_str());

    if (validator_parts(in))
        return_by_string(in) ^= temp_out;
    else if (validator_reg(in))
        return_reg_by_string(in) ^= temp_out;
    else if (validator_title(in))
        data.return_by_string(in) ^= temp_out;
    else {}
    flags_check(in);
}


void ROM_memory::and_(const std::string &in, const std::string &out)
{
    int temp_out;
    if (validator_parts(out))
        temp_out = return_by_string(out).convert_to_int();
    else if (validator_reg(out))
        temp_out = return_reg_by_string(out).convert_to_int();
    else if (validator_title(out))
        temp_out = data.return_by_string(out).convert_to_int();
    else
        temp_out = std::atoi(out.c_str());

    if (validator_parts(in))
        return_by_string(in) &= temp_out;
    else if (validator_reg(in))
        return_reg_by_string(in) &= temp_out;
    else if (validator_title(in))
        data.return_by_string(in) &= temp_out;
    else {}
    flags_check(in);
}

bool ROM_memory::cmp(const std::string &in, const std::string &out)
{
    int temp_in, temp_out;
    if (validator_parts(in))
        temp_in = return_by_string(in).convert_to_int();
    else if (validator_reg(in))
        temp_in = return_reg_by_string(in).convert_to_int();
    else if (validator_title(in))
        temp_in = data.return_by_string(in).convert_to_int();
    else if (isint(out))
        temp_in = std::atoi(out.c_str());

    if (validator_parts(out))
        temp_out = return_by_string(out).convert_to_int();
    else if (validator_reg(out))
        temp_out = return_reg_by_string(out).convert_to_int();
    else if (validator_title(out))
        temp_out = data.return_by_string(out).convert_to_int();
    else
        temp_out = std::atoi(out.c_str());

    if (temp_in == temp_out)
        return true;
    else
        return false;
}

void ROM_memory::add_integer(int out, const std::string &in)
{
    dword temp(out);
    data.push(temp, in);
}

void ROM_memory::push(const std::string &in)
{
    if (validator_title(in))
        Stack.push(data.return_by_string(in));
    else if (validator_parts(in))
        Stack.push(return_by_string(in));
    else if (validator_reg(in))
        Stack.push(return_reg_by_string(in));
    else if (isint(in))
        dword i = std::atoi(in.c_str());
        else{}
        flags_check(in);
}

void ROM_memory::pop(const std::string &in)
{
    if (validator_parts(in))
        return_by_string(in) = Stack.pop();
    else if (validator_reg(in))
        return_reg_by_string(in) = Stack.pop();
    else if (validator_title(in))
        data.return_by_string(in) = Stack.pop();
    else{}
    flags_check(in);
}

void ROM_memory::call(int in)
{
    /*if (!f_CR0.getbit(7)) {*/
        CR0 = in;
        f_CR0.setbit(7, 1);
    /*}
    else if (!f_CR1.getbit(7)) {
        CR1 = in;
        f_CR1.setbit(7, 1);
    }
    else if (!f_CR2.getbit(7)) {
        CR2 = in;
        f_CR2.setbit(7, 1);
    }
    else if (!f_CR3.getbit(7)) {
        CR3 = in;
        f_CR3.setbit(7, 1);
    }*/
}

int ROM_memory::comp(const std::string &input)
{
    std::cout << "Compilation begins." << std::endl;
    std::ifstream file(input.c_str());
    int count = 0;
    std::string in;
    for (file >> in; !file.eof(); file >> in)
    {
        ++count;
        if (in == "dword")
        {
            file >> in;
            dword temp(0);
            data.push(temp, in);
        }
        else if (validator_command_double(in))
        {
            file >> in;
            if (!validator_title(in) && !validator_parts(in) && !validator_reg(in) && !isint(in))
            {
                std::cout << "Unknown <in>: <" << in << "> in string " << count << std::endl;
                return false;
            }
            file >> in;
            if (!validator_title(in) && !validator_parts(in) && !validator_reg(in) && !isint(in))
            {
                std::cout << "Unknown <out>: <" << in << "> in string " << count << std::endl;
                return false;
            }
        }
        else if (validator_command(in))
        {
            file >> in;
            if (!validator_title(in) && !validator_parts(in) && !validator_reg(in) && !isint(in))
            {
                std::cout << "Unknown <in>: <" << in << "> in string " << count << std::endl;
                return false;
            }
        }
        else if (in == "out" || in == "jmp" || in == "jne" || in == "label") {}
        else
        {
            std::cout << "Unknown command: <" << in << "> in string " << count << std::endl;
            return false;
        }
    }
    while (data.return_size() != 0)
    {
        data.pop();
        data.~memory();
    }
    std::cout << "The compilation is finished. Number of strings in file: " << count << std::endl;
    return count;
}

bool ROM_memory::parser(const std::string &command)
{
    int first = command.find_first_of(' ');
    int last = command.find_last_of(' ');
    std::string in = command.substr(first + 1, last - first - 1);
    std::string out = command.substr(last + 1);
    std::string input = command.substr(0, first);

    if (validator_command_double(input))
    {
        if (input == "mov") mov(in, out);
        else if (input == "add") add(in, out);
        else if (input == "sub") sub(in, out);
        else if (input == "cmp") cmp(in, out);
        else if (input == "xor") xor_ (in, out);
        else if (input == "and") and_ (in, out);
    }
    else if (validator_command(input))
    {
        if (input == "push") push(in);
        else if (input == "pop") pop(in);
        else if (input == "dword") add_integer(0, in);
        else if (input == "dec") sub(in, "1");
        else if (input == "inc") add(in, "1");
    }/*
    else if (input == "out")
    {
        std::cout <<
            "EAX: " << EAX << std::endl <<
            "EBX: " << EBX << std::endl <<
            "ECX: " << ECX << std::endl <<
            "EDX: " << EDX << std::endl <<
            "\nCR0: " << CR0 << std::endl <<
            "CR1: " << CR1 << std::endl <<
            "CR2: " << CR2 << std::endl <<
            "CR3: " << CR3 << std::endl <<
            "\nFlags: " << flags << std::endl;
        return true;
    }*/
    else if (input == "exit") return false;
    //
    // refresh registers' values
    //
    return true;

}

bool ROM_memory::file_parser(std::string in)
{
    std::string out, label, input;
    std::ifstream file(in.c_str());
    if (!file.is_open()) {
//        QMessageBox::information(w, QString("Error"), QString("File cannot be opened!"), QMessageBox::Ok);
        return false;
    }
    file.seekg(0, std::ios_base::beg);
    if (comp(in))
    {
        for (file >> input; !file.eof(); file >> input)
        {
            if (validator_command_double(input))
            {
                file >> in >> out;
                if (input == "mov")
                    mov(in, out);
                else if (input == "add")
                    add(in, out);
                else if (input == "sub")
                    sub(in, out);
                else if (input == "xor")
                    xor_ (in, out);
                else if (input == "and")
                    and_ (in, out);
                else if (input == "dec")
                    add(in, "1");
                else if (input == "inc")
                    sub(in, "1");
                else if (input == "cmp") {
                    int temp = (int)file.tellg();
                    file >> label;
                    if (label == "jne")
                    {
                        if (cmp(in, out))
                        {
                            file >> label;
                            file.seekg(-((int)file.tellg() - labels.return_by_string(label).convert_to_int()), std::ios_base::cur);
                        }
                    }
                    else
                    {
                        file.seekg(-((int)file.tellg() - temp), std::ios_base::cur);
                    }
                }
            }
            else if (validator_command(input))
            {
                file >> in;
                if (input == "push")
                    push(in);
                else if (input == "pop")
                    pop(in);
                else if (input == "call")
                {
                    call((int)file.tellg());
                    file.seekg(callret.return_by_string(in).convert_to_int(), std::ios_base::beg);
                }
                else if (input == "dword")
                {
                    if (!validator_title(in))
                    {
                        add_integer(0, in);
                    }
                }
                else if (input == "jmp")
                {
                    file.seekg(-((int)file.tellg() - labels.return_by_string(label).convert_to_int()), std::ios_base::cur);
                }
            }
            else if (input == "label") {}
            else if (input == "ret")
            {
                if (f_CR0.getbit(7))
                {
                    f_CR0.setbit(7, 0);
                    file.seekg(CR0.convert_to_int(), std::ios_base::beg);
                }
            }

            else if (input == "out")
            {
                std::cout << "EAX: " << EAX << std::endl <<
                    "EBX: " << EBX << std::endl <<
                    "ECX: " << ECX << std::endl <<
                    "EDX: " << EDX << std::endl << std::endl;
            }
            else if (input == "open")
            {
           //     file_parser();
            }
            else if (validator_callret_title(input))
            {
                for(file >> input; input != "ret"; file >> input) { }
            }
        }
//        QMessageBox::information(w, "Success", "File processed successfully", QMessageBox::Ok);
        data.~memory();
        labels.~memory();
        callret.~memory();
        //
        // refresh registers
        //
        return true;
    }
    //
    // refresh registers
    //
    return false;
}

bool ROM_memory::validator_parts(const std::string &in)
{
    if (in == "AH" || in == "BH" || in == "AL" || in == "BL" || in == "CL" || in == "DL" || in == "CH" || in == "DH")
        return true;
    else return false;
}

bool ROM_memory::validator_reg(const std::string &in)
{
    if (in == "EAX" || in == "EBX" || in == "ECX" || in == "EDX")
        return true;
    else return false;
}

bool ROM_memory::validator_cr_reg(const std::string &in)
{
    if (in == "CR0" || in == "CR1" || in == "CR2" || in == "CR3")
        return true;
    else return false;
}

bool ROM_memory::validator_command_double(const std::string &in)
{
    if (in == "mov" || in == "add" || in == "sub" || in == "cmp" || in == "xor" ||
        in == "and")
        return true;
    else return false;
}

bool ROM_memory::validator_command(const std::string &in)
{
    if (in == "push" || in == "pop" || in == "dec" || in == "inc" || in == "dword" ||
        in == "label" || in == "jne" || in == "jmp" || in == "call")
        return true;
    else return false;
}

bool ROM_memory::validator_title(const std::string &in)
{
    return data.validator(in);
}

bool ROM_memory::validator_callret_title(const std::string &in)
{
    return callret.validator(in);
}

bool ROM_memory::validator_labels(const std::string &in)
{
    return labels.validator(in);
}

bool ROM_memory::isint(const std::string &in)
{
    int i = 0;
    if (in[0] == '-') ++i;
    for (i; i < in.size(); ++i) {
        if (!isdigit(in[i]))
            return false;
    }
    return true;
}

void ROM_memory::parity(const std::string &in)
{
    if (validator_parts(in))
    {
        if (return_by_string(in).parity())
        flags.setbit(2, 1);
        else
        flags.setbit(2, 0);
    }
    else if (validator_reg(in))
    {
        if (return_reg_by_string(in).parity())
            flags.setbit(2, 1);
        else
            flags.setbit(2, 0);
    }
        else if (validator_title(in))
    {
        if (data.return_by_string(in).parity())
            flags.setbit(2, 1);
        else
            flags.setbit(2, 0);
    }
        else {}
}

void ROM_memory::zero(const std::string &in)
{
    if (validator_parts(in))
    {
        if (!return_by_string(in).convert_to_int())
            flags.setbit(6, 1);
        else
            flags.setbit(6, 0);
    }
    else if (validator_reg(in))
    {
        if (!return_reg_by_string(in).convert_to_int())
            flags.setbit(6, 1);
        else
            flags.setbit(6, 0);
    }
    else if (validator_title(in))
    {
        if (!data.return_by_string(in).convert_to_int())
            flags.setbit(6, 1);
        else
            flags.setbit(6, 0);
    }
    else {}
}

void ROM_memory::flags_check(const std::string &in)
{
    parity(in);
    zero(in);
}
