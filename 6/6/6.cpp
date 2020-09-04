#include <iostream>
#include <string>
#include <vector>

using std::string;
typedef std::vector<string> text;

class Human
{
private:
    string name;
    string surname;
    string patronymic;
    unsigned short year;
    
public:
    void set_name(string new_name);
    void set_surname(string new_surnme);
    void set_patronymic(string new_patronymic);
    void set_year(unsigned short new_year);

    string get_name() const;
    string get_surname() const;
    string get_patronymic() const;
    unsigned short get_year() const;
};

class UniversityTeacher : public Human
{
private:
    string position; 
    string academicDegree;
    string specialty;
    text   listOfScientificPapers;

public:
    void set_position(string new_position);
    void set_academicDegree(string new_academicDegree);
    void set_specialty(string new_specialty);
    void set_listOfScientificPapers(text new_listOfScientificPapers);

    string get_position() const;
    string get_academicDegree() const;
    string get_specialty() const;
    text get_listOfScientificPapers() const;
};

class CommissionMember : public Human
{
private:
    string nameOfTheCommission;
    string yearOfAppointmentToTheCommission; 
    string certificateNumber; 
    text autobiography;

public:
    void set_nameOfTheCommission(string new_nameOfTheCommission);
    void set_yearOfAppointmentToTheCommission(string new_yearOfAppointmentToTheCommission);
    void set_certificateNumber(string new_certificateNumber);
    void set_autobiography(text new_autobiography);

    string get_nameOfTheCommission() const;
    string get_yearOfAppointmentToTheCommission() const;
    string get_certificateNumber() const;
    text get_autobiography() const;
};

class UniversityTeacher_CommissionMember : virtual public UniversityTeacher, virtual public CommissionMember
{
private:
    text listOfWorksPerformedInTheCommission;

public:
    text get_listOfWorksPerformedInTheCommission() const;
    void set_listOfWorksPerformedInTheCommission(text new_listOfWorksPerformedInTheCommission);
};

int main()
{}

void Human::set_name(string new_name)
{
    name = new_name;
}

void Human::set_surname(string new_surnme)
{
    surname = new_surnme;
}

void Human::set_patronymic(string new_patronymic)
{
    patronymic = new_patronymic;
}

void Human::set_year(unsigned short new_year)
{
    year = new_year;
}

string Human::get_name() const
{
    return name;
}

string Human::get_surname() const
{
    return surname;
}

string Human::get_patronymic() const
{
    return patronymic;
}

unsigned short Human::get_year() const
{
    return year;
}

void UniversityTeacher::set_position(string new_position)
{
    position = new_position;
}

void UniversityTeacher::set_academicDegree(string new_academicDegree)
{
    academicDegree = new_academicDegree;
}

void UniversityTeacher::set_specialty(string new_specialty)
{
    specialty = new_specialty;
}

void UniversityTeacher::set_listOfScientificPapers(text new_listOfScientificPapers)
{
    listOfScientificPapers = new_listOfScientificPapers;
}

string UniversityTeacher::get_position() const
{
    return position;
}

string UniversityTeacher::get_academicDegree() const
{
    return academicDegree;
}

string UniversityTeacher::get_specialty() const
{
    return specialty;
}

text UniversityTeacher::get_listOfScientificPapers() const
{
    return listOfScientificPapers;
}

void CommissionMember::set_nameOfTheCommission(string new_nameOfTheCommission)
{
    nameOfTheCommission = new_nameOfTheCommission;
}

void CommissionMember::set_yearOfAppointmentToTheCommission(string new_yearOfAppointmentToTheCommission)
{
    new_yearOfAppointmentToTheCommission = new_yearOfAppointmentToTheCommission;
}

void CommissionMember::set_certificateNumber(string new_certificateNumber)
{
    certificateNumber = new_certificateNumber;
}

void CommissionMember::set_autobiography(text new_autobiography)
{
    autobiography = new_autobiography;
}

string CommissionMember::get_nameOfTheCommission() const
{
    return nameOfTheCommission;
}

string CommissionMember::get_yearOfAppointmentToTheCommission() const
{
    return yearOfAppointmentToTheCommission;
}

string CommissionMember::get_certificateNumber() const
{
    return certificateNumber;
}

text CommissionMember::get_autobiography() const
{
    return autobiography;
}

text UniversityTeacher_CommissionMember::get_listOfWorksPerformedInTheCommission() const
{
    return listOfWorksPerformedInTheCommission;
}

void UniversityTeacher_CommissionMember::set_listOfWorksPerformedInTheCommission(text new_listOfWorksPerformedInTheCommission)
{
    listOfWorksPerformedInTheCommission = new_listOfWorksPerformedInTheCommission;
}
