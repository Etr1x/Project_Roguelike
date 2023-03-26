﻿class Enemy {
protected:
    int m_health;
    int m_attack;
    int m_defense;

public:
    Enemy(int health, int attack, int defense)
        : m_health(health), m_attack(attack), m_defense(defense) {}

    virtual ~Enemy() {}

    virtual void update() {}

    virtual void render() {}

    virtual void takeDamage(int damage) {
        // Вычисляем получаемый урон, учитывая защиту врага
        int actualDamage = damage - m_defense;
        if (actualDamage > 0) {
            m_health -= actualDamage;
        }
    }

    virtual int getHealth() const {
        return m_health;
    }

    virtual int getAttack() const {
        return m_attack;
    }

    virtual int getDefense() const {
        return m_defense;
    }
};