#include "Writer.h"

#include <iostream>

Writer* Writer::s_instance = nullptr;

Writer* Writer::get_instance()
{
    if (s_instance == nullptr) {
        s_instance = new Writer(&std::cout);
    }
    return s_instance;
}

void Writer::remove_instance()
{
    delete s_instance;
    s_instance = nullptr;
}

void Writer::write_message(const std::string& message)
{
    if (m_out_stream != nullptr) {
        *m_out_stream << message;
    }
}

void Writer::set_writer(std::ostream* out_stream)
{
    m_out_stream = out_stream;
}

Writer::Writer(std::ostream* out_stream /*= nullptr*/)
    : m_out_stream(out_stream)
{
}

Writer::~Writer()
{
}
