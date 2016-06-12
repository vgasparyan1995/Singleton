#include <string>

class Writer
{
public:
    void write_message(const std::string& message);
    void set_writer(std::ostream* out_stream);

private:
    std::ostream* m_out_stream;

public:
    static Writer* get_instance();
    static void remove_instance();

private:
    static Writer* s_instance;

    Writer(std::ostream* out_stream = nullptr);
    ~Writer();
    Writer(const Writer&) = delete;
    Writer& operator=(const Writer&) = delete;
};
