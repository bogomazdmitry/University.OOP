#include <iostream>
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
    o << n.getSurname() << " " << n.getName() << " " << n.getPatronymic() << " " n.getNumber();
    return o;
}

int main()
{
    name n;
    std::cout << "Imput your name: ";
    std::cin >> n;
    std::cout << "Hello, " << n << "!" << std::endl;
    system("pause");
    return 0;
}
