#include "Zombie.hpp"

int main(void)
{
    randomChump("Foo1");
    Zombie *zombie = newZombie("Foo2");
    delete(zombie);
    zombie->announce();
}