#include "control.h"
#include <string.h>

Control::Control()
{
}

Control::~Control()
{
}

void Control::start()
{
    this->state = true;
}

void Control::stop()
{
    this->state = false;
}

bool Control::is_started()
{
    return this->state;
}

char Control::get_input()
{
    return this->inp_char;
}

void Control::sink(const char input)
{
    this->inp_char = input;
}

const char * Control::source()
{
    return this->converter.read(this->inp_char);
}
