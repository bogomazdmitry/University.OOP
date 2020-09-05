#include <iostream>

class Deckan;

class Group
{
private:
    static int numberOfLastCreatedGroup;
    int numberOfGroup;
    Group(int numberOfCreatedGroup);
public:
    friend class Deckan;
    int get_numberOfGroup() const;
};

int Group::numberOfLastCreatedGroup = 0;

class Deckan
{
public:
    Group create_group(int numberOfGroup);
    void set_numberOfGroup(Group& gr, int newNumberOfGroup);
    int get_numberOfLastCreatedGroup() const;
};

int main()
{
    setlocale(LC_ALL, "Russian");
    Deckan D;
    Group gr = D.create_group(914301);
    Group gr1 = D.create_group(914302);
    std::cout << "Ноер группы: " << gr.get_numberOfGroup() << std::endl;
    std::cout << "Ноер последней созданной группы: " << D.get_numberOfLastCreatedGroup() << std::endl;
    system("pause");
    return 0;
}

Group::Group(int numberOfCreatedGroup):
    numberOfGroup(numberOfCreatedGroup)
{
    numberOfLastCreatedGroup = numberOfCreatedGroup;
}

int Group::get_numberOfGroup() const
{
    return numberOfGroup;
}

Group Deckan::create_group(int numberOfGroup)
{
    return Group(numberOfGroup);
}

void Deckan::set_numberOfGroup(Group& gr, int newNumberOfGroup)
{

    if (Group::numberOfLastCreatedGroup == gr.numberOfGroup)
    {
    Group::numberOfLastCreatedGroup = newNumberOfGroup;
    }
    gr.numberOfGroup = newNumberOfGroup;
}

int Deckan::get_numberOfLastCreatedGroup() const
{
    return Group::numberOfLastCreatedGroup;
}
