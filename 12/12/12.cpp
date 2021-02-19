#include <iostream>
#include <fstream>
#include <string>

class name
{
private:
    std::string surname;
    std::string name;
    std::string patronymic;
    int number;

public:
    void setSurname(const std::string& surname)
    {
        this->surname = surname;
    }

    void setName(const std::string& name)
    {
        this->name = name;
    }

    void setPatronymic(const std::string& patronymic)
    {
        this->patronymic = patronymic;
    }

    void setNumber(const int number)
    {
        this->number = number;
    }

    std::string getSurname() const
    {
        return surname;
    }

    std::string getName() const
    {
        return name;
    }

    std::string getPatronymic() const
    {
        return patronymic;
    }

    int getNumber() const
    {
        return number;
    }

    void readOfFile(std::ifstream& i)
    {
        std::string temp;
        i >> surname >> name >> patronymic >> temp;
        try
        {
            number = std::stoi(temp);
        }
        catch (...)
        {
            number = 0;
        }
    }

    void writeOfFile(std::ofstream& o)
    {
        o << surname << '\n' << name << '\n' << patronymic << '\n' << number << '\n';
    }
};

std::istream& operator>>(std::istream& i, name& n)
{
    std::string temp;
    i >> temp;
    n.setSurname(temp);
    i >> temp;
    n.setName(temp);
    i >> temp;
    n.setPatronymic(temp);
    i >> temp;
    try
    {
        n.setNumber(std::stoi(temp));
    }
    catch (...)
    {
        n.setNumber(0);
    }
    return i;
}

std::ostream& operator<<(std::ostream& o, const name& n)
{
    o << n.getSurname() << " " << n.getName() << " " << n.getPatronymic() << " " << n.getNumber();
    return o;
}

int main()
{
    name n;
    std::cout << "Imput your name: ";
    std::cin >> n;
    
    std::ofstream o("user.txt");
    n.writeOfFile(o);
    o.close();

    std::ifstream i("user.txt");
    n.readOfFile(i);
    i.close();

    std::cout << "Hello, " << n << "!" << std::endl;
    system("pause");
    return 0;
}
