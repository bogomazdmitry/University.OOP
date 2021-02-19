#include <iostream>
#include <string>

class ActionsOfDecan
{
public:
    virtual void zaplanirovat() const = 0;
    virtual void rabotat() const = 0;
};

class Otcheeslet : public ActionsOfDecan
{
public:
    virtual void zaplanirovat() const 
    {
        std::cout << "Otchesly vseh zavtra!!!" << std::endl;
    }

    virtual void rabotat() const
    {
        std::cout << "Sha otchilu!!!" << std::endl;
    }
};

class Popit : public ActionsOfDecan
{
public:
    virtual void zaplanirovat() const = 0;
    virtual void rabotat() const = 0;
};

class PopetChai : public Popit
{
public:
    virtual void zaplanirovat() const
    {
        std::cout << "Budu pit chai vsegda!!!" << std::endl;
    }

    virtual void rabotat() const
    {
        std::cout << "Pu chai))" << std::endl;
    }
};

class PopitCofe : public Popit
{
public:
    virtual void zaplanirovat() const
    {
        std::cout << "Budu pit cofe vsegda!!!" << std::endl;
    }

    virtual void rabotat() const
    {
        std::cout << "Pu cofe(" << std::endl;
    }
};

class DatOsvebojdenie : public ActionsOfDecan
{
public:
    virtual void zaplanirovat() const
    {
        std::cout << "Ny, mojet dam osvobojdenie zavtra, esli pridesh)))" << std::endl;
    }

    virtual void rabotat() const
    {
        std::cout << "Ny davai posmotrim ocenki i dam..... A zachem tebe???" << std::endl;
    }
};

class Chillit : public ActionsOfDecan
{
public:
    virtual void zaplanirovat() const
    {
        std::cout << "Chillu zavtra!!!" << std::endl;
    }

    virtual void rabotat() const
    {
        std::cout << "Chillu!!!" << std::endl;
    }
};

class FactoryActionsOfDecan
{
public:
    static ActionsOfDecan* getWithString(std::string name)
    {
        if (name == "Otcheeslet")
        {
            return new Otcheeslet();
        }

        if (name == "PopetChai")
        {
            return new PopetChai();
        }

        if (name == "PopitCofe")
        {
            return new PopitCofe();
        }

        if (name == "DatOsvebojdenie")
        {
            return new DatOsvebojdenie();
        }

        return new Chillit();
    }

};

class Dekan
{
private:
    Dekan() {}
    Dekan(const Dekan& d) = delete;
    Dekan(Dekan&& d) = delete;
    static Dekan* dekan;

public:
    static Dekan* GetDekan()
    {
        if (dekan == NULL)
        {
            dekan = new Dekan();
        }
        return dekan;
    }

    void pochtiRabotat(const ActionsOfDecan& action) const
    {
        action.rabotat();
    }

    void planirovat(const ActionsOfDecan& action)
    {
        action.zaplanirovat();
    }
};
Dekan* Dekan::dekan = NULL;

int main()
{
    std::string working;
    std::cout << "Zanlanirovat: ";
    std::cin >> working;
    auto action1 = FactoryActionsOfDecan::getWithString(working);
    std::cout << "Sdelat: ";
    std::cin >> working;
    auto action2 = FactoryActionsOfDecan::getWithString(working);

    Dekan::GetDekan()->planirovat(*action1);
    Dekan::GetDekan()->pochtiRabotat(*action2);

    delete action1;
    delete action2;
    system("pause");
    return 0;
}
