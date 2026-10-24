#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

class Character {
protected:
    string name;
    int health = 100;
    int shield = 50;
public:
    Character(string n) {
        name = n;
    }
    void takeDamage(int amount)
    {
        cout << name << " получил " << amount << " урон" << '\n';
        //  снимаем броню
        if (shield >= amount)
        {
            shield -= amount;
            cout << "Броня приняла урон" << '\n';
        }
        else
        {
            int damageToHealth = amount - shield;
            shield = 0;
            health -= damageToHealth;

            cout << "Броня сломанаю Здоровье уменьшилось на "
                << damageToHealth << "." << '\n';
        }

        cout << "Здоровье: " << health << '\n';
        cout << "Броня: " << shield << '\n';
    }
};
class Recon : public Character {
public:
    Recon(string n) : Character(n)
    {
    }
    void scanArea()
    {
        cout << "[" << name << "] скан местности: "
            << "2 врага" << '\n';
    }
};
class Support : public Character {
public:
    Support(string n) : Character(n)
    {
    }
    void dropHeal()
    {
        cout << "[" << name << "]  востанавливает жизнь союзникам" << '\n';
        cout << "Союзники получили лечение" << '\n';
    }
};

int main()
{
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);
    // два разных персонажа
    Recon recon("Розвідник");
    Support support("Сапорт");

    cout << "== Розвідник ==" << '\n';
    recon.takeDamage(70);

    cout << '\n';

    cout << "=== Сапорт ===" << '\n';
    support.takeDamage(120);
    cout << '\n';
    recon.scanArea();
    cout << '\n';
    support.dropHeal();

}
