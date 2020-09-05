#include <iostream>
#include <array>
#include <conio.h>

class data
{
private:
    short day;
    short month;
    short year;
public:
    data();
    data( short new_day,  short new_month,  short new_year);

    void set_day (const short new_data);
    void set_month (const short new_month);
    void set_year (const short new_year);

    const short get_day() const;
    const short get_month() const;
    const short get_year() const;

    void show1(std::ostream& os = std::cout) const;
    void show2(std::ostream& os = std::cout) const;
};

std::istream& operator>>(std::istream& is, data &d);

int main()
{
    setlocale(LC_ALL, "Rus");
    data d;
    do
    {
        std::cout << "Хотите вписать дату?(y/n)" << std:: endl;
        if (_getch() == 'y')
        {
            try
            {
                std::cin >> d;
                d.show1();
                std::cout << std::endl;
                d.show2();
                std::cout << std::endl;
            }
            catch (const std::exception& ex)
            {
                std::cout << ex.what() << std::endl;
            }
        }
        else
        {
            break;
        }
        std::cout << std::string(40, '_') << std::endl;
    } while (true);
    system("pause");
    return 0;
}

data::data()
{
}

data::data(short new_day,  short new_month,  short new_year)
{
    set_day(new_day);
    set_month(new_month);
    set_year(new_year);
}

void data::set_day(const  short new_data)
{
    if (new_data <= 31 && new_data >= 1)
        day = new_data;
    else        
        throw std::exception("Неправиьно введена день");
}

void data::set_month(const  short new_month)
{
    if (new_month <= 12 && new_month >= 1)
        month = new_month;
    else
        throw std::exception("Неправиьно введена месяц");
}

void data::set_year(const  short new_year)
{
    if (new_year >= 1)
        year = new_year;
    else
        throw std::exception("Неправиьно введена год");
}

const  short data::get_day() const
{
    return day;
}

const  short data::get_month() const
{
    return month;
}

const  short data::get_year() const
{
    return year;
}

void data::show1(std::ostream& os) const
{
    os << day << '.' << month << '.' << year;
}

void data::show2(std::ostream& os) const
{
    static std::array<std::string, 12> nameOfMonth = { "января", "февраля","марта", "апреля", "мая", "июня", "июля", "августа", "сентября", "октября", "ноября", "декабря" };
    os << day << ' ' << nameOfMonth[month + 1] << ' ' << year << " года";
}

std::istream& operator>>(std::istream& is, data& d)
{
    short temp_day;
    short temp_month;
    short temp_year;
    is >> temp_day >> temp_month >> temp_year;
    d.set_day(temp_day);
    d.set_month(temp_month);
    d.set_year(temp_year);
    return is;
}
