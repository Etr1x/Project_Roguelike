﻿#pragma once
#include "../items/items.h"
#include "../items/damage_up.h"
#include "../items/hp_up.h"
#include "../items/armor_up.h"
#include "../Player/Player.h"
#include "../inventory/inventory.h"
#include <iostream>
#include <map>
#include <string>


enum ItemsName {
    MedKit = 4,
    armorUp = 3,
    damageUp = 1,
    hpUp = 2,
};

class Store {
public:
    Store() : damageBoosts(5), healthBoosts(5), armorBoosts(5), healthPotions(10) {}

    void showItems() const {
        std::cout << "Available items:" << std::endl;
        std::cout << "- Damage boost x1 (ID: 1, price: 100, remaining: " << damageBoosts << ")" << std::endl;
        std::cout << "- Health boost x1 (ID: 2, price: 50, remaining: " << healthBoosts << ")" << std::endl;
        std::cout << "- Armor boost x1 (ID: 3, price: 75, remaining: " << armorBoosts << ")" << std::endl;
        std::cout << "- Health potion x1 (ID: 4, price: 25, remaining: " << healthPotions << ")" << std::endl;
    }

    bool buyItem(ItemsName id, Inventory& inventory, Player& player) {
        switch (id) {
        case 1:
            if (damageBoosts > 0) {
                //inventory.AddItem(DamageUp);
                inventory.removeCoins(100);
                damageBoosts--;
                return true;
            }
            return false;

        case 2:
            if (healthBoosts > 0) {
                //inventory.AddItem(HpUp);
                inventory.removeCoins(100);
                healthBoosts--;
                return true;
            }
            return false;

        case 3:
            if (armorBoosts > 0) {
                //inventory.AddItem(armorUp);
                inventory.removeCoins(100);
                armorBoosts--;
                return true;
            }
            return false;

        case 4:
            if (healthPotions > 0) {
                player.addHP(25);
                inventory.removeCoins(100);;
                healthPotions--;
                return true;
            }
            return false;

        default:
            return false;  // Товар не найден
        }
    }

    bool sellItem(ItemsName id, Inventory& inventory) {
        switch (id) {
        case 1:
            if (damageBoosts < 5) {
                //inventory.removeItem(DamageUp);
                inventory.addCoins(50);
                damageBoosts++;
                return true;
            }
            return false;

        case 2:
            if (healthBoosts < 5) {
                //inventory.removeItem(DamageUp);
                inventory.addCoins(50);
                healthBoosts++;
                return true;
            }
            return false;

        case 3:
            if (armorBoosts < 5) {
                //inventory.removeItem(DamageUp);
                inventory.addCoins(50);
                armorBoosts++;
                return true;
            }
            return false;

        case 4:
            return false;  // Зелья нельзя продавать

        default:
            return false;  // Товар не найден
        }
    }

private:
    int damageBoosts;
    int healthBoosts;
    int armorBoosts;
    int healthPotions;

};