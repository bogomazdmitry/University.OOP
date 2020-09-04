#include <iostream>

class String
{
private:
    size_t size;
    char* str;

public:
    String(const char* str1 = "");

    String(size_t n, char c);

    String(size_t n);

    String(const String& other);

    String& operator=(const String& other);

    String operator+(const String& other) const;

    String& operator+=(const String& other);

    size_t _size() const;

    const char* c_str() const;

    friend std::istream& operator>>(std::istream& is, String& s);
    friend std::ostream& operator<<(std::ostream& os, const String &s);

    ~String();
};

int main()
{
    setlocale(LC_ALL, "Rus");
    std::cout << "Введите строку" << std::endl;
    String s;
    std::cin >> s;
    String g(20, '5');
    std::cout << s << " + " << g << " + " << s << " = " << s + g + String(s) << std::endl;
    system("pause");
    return 0;
}

String::String(const char* str1)
{
    size = strlen(str1);
    str = new char[size + 1];
    for (int i = 0; i < size; i++)
    {
        str[i] = str1[i];
    }
    str[size] = '\0';
}

String::String(size_t n, char c) :
    size(n),
    str(new char[n + 1])
{
    for (int i = 0; i < size; i++)
    {
        str[i] = c;
    }
    str[size] = '\0';
}

String::String(size_t n) :
    size(n),
    str(new char[n + 1])
{
    str[size] = '\0';
}

String::String(const String& other)
{
    size = other.size;
    str = new char[size + 1];
    for (int i = 0; i <= size; ++i)
    {
        str[i] = other.str[i];
    }
}

String& String::operator=(const String& other)
{
    if (this == &other)
        return *this;
    delete[]str;
    size = other.size;
    str = new char[size + 1];
    for (int i = 0; i <= size; ++i)
    {
        str[i] = other.str[i];
    }
    return *this;
}

String String::operator+(const String& other) const
{
    String result(other.size + size);
    for (size_t i = 0; i < size; ++i)
    {
        result.str[i] = str[i];
    }
    for (size_t i = 0; i < other.size; ++i)
    {
        result.str[size + i] = other.str[i];
    }
    return result;
}

String& String::operator+=(const String& other)
{
    return *this = *this + other;
}

size_t String::_size() const
{
    return size;
}

const char* String::c_str() const
{
    return str;
}

std::istream& operator>>(std::istream& is, String& s)
{
    is >> s.str;
    s.size = strlen(s.str);
    return is;
}

std::ostream& operator<<(std::ostream& os, const String& s)
{
    os << s.str;
    return os;
}


String::~String()
{
    delete[]str;
    str = nullptr;
}