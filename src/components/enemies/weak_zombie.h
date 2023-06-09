﻿#include "enemies.h"

class Weak_Zombie : public Enemy {
public:
    Weak_Zombie(int x, int y) : Enemy(10, 3, 5, x, y) {}

    std::vector<std::wstring> GetSprite() override {
        return AssetsInstance->GetAsset(Assets::AssetsName::Zombie_Waek);
    }

    int GetFOV() override { return 6; }

    std::wstring GetName() {
        return L"Strongest fighter in Redan";
    }
 
    virtual void takeDamage(int damage) override {
        Enemy::takeDamage(damage);
    }

};
