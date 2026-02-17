#pragma once

#include <string>
#include <iostream>

class ClapTrap {
    private:
        std::string name;
        unsigned int hit_points;
        unsigned int energy_points;
        unsigned int attack_damage;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        std::string getName();
        unsigned int getHitPoint();
        unsigned int getEnergyPoint();
        unsigned int getAttackDamage();
        void subHitPoint(int val);
        void subEnergyPoint(int val);
        void subAttackDamage(int val);
        void addHitPoint(int val);
        void addEnergyPoint(int val);
        void addAttackDamage(int val);
        ~ClapTrap();
};
