#pragma once

#include "../Field/Field.h"
#include <time.h>
#include "../utills/utils.h"
#include "../enemies/enemies.h"
#include"../Player/Player.h"
#include "../enemies/common_zombie.h"
#include "../enemies/weak_zombie.h"
#include "../enemies/mutant_zombie.h"
#include "../shop/shop.h"

//void PrintField(Field* _field) {
//	for (int i = 0; i < _field->GetHeight(); i++) {
//		for (int j = 0; j < _field->GetWidth(); j++) {
//			std::cout << _field->GetCellChar(i, j);
//		}
//		std::cout << std::endl;
//	}
//}

class Map_gen {
private:
	vector<Enemy*>* enemies;
	Field* pole;
	Store* store_;
public:
	Store* GetStore() {
		return store_;
	}

	vector<Enemy*>* GetEnemies() {
		return enemies;
	}

	Map_gen() { }
	void Generate(const int num_rm, Player* igrok, int num_weaks, int num_normal, int num_giga_chads) {
		const int* arr_l = Massive_of_rand_l();
		const int* arr_h = Massive_of_rand_h();
		Field* ma = Make_border(arr_h, arr_l);
		int mid_l1 = arr_l[0] / 2;
		int mid_l2 = arr_l[1] / 2;
		int mid_l3 = arr_l[2] / 2;
		int mid_l4 = arr_l[3] / 2;
		int mid_h1 = arr_h[0] / 2;
		int mid_h2 = arr_h[1] / 2;
		int mid_h3 = arr_h[2] / 2;
		int* arr = new int[num_rm];
		int* arr_rm = rand_arr(num_rm);

		for (int i = 0; i < num_rm; i++) {
			if (arr_rm[i] == 1) {
				FillSquare(ma, 1, 1, arr_h[0] - 1, arr_l[0] - 1, wall);
				FillSquare(ma, 2, 2, arr_h[0] - 2, arr_l[0] - 2, pass);
			}
			else if (arr_rm[i] == 2) {
				FillSquare(ma, 1, 1 + arr_l[0], arr_h[0] - 1, (arr_l[1] + arr_l[0]) - 1, wall);
				FillSquare(ma, 2, 2 + arr_l[0], arr_h[0] - 2, (arr_l[1] + arr_l[0]) - 2, pass);
			}
			else if (arr_rm[i] == 3) {
				FillSquare(ma, 1, 1 + (arr_l[0] + arr_l[1]), arr_h[0] - 1, (arr_l[0] + arr_l[1] + arr_l[2]) - 1, wall);
				FillSquare(ma, 2, 2 + (arr_l[0] + arr_l[1]), arr_h[0] - 2, (arr_l[0] + arr_l[1] + arr_l[2]) - 2, pass);
			}
			else if (arr_rm[i] == 4) {
				FillSquare(ma, 1, 1 + (arr_l[0] + arr_l[1] + arr_l[2]), arr_h[0] - 1, (arr_l[0] + arr_l[1] + arr_l[2] + arr_l[3]) - 1, wall);
				FillSquare(ma, 2, 2 + (arr_l[0] + arr_l[1] + arr_l[2]), arr_h[0] - 2, (arr_l[0] + arr_l[1] + arr_l[2] + arr_l[3]) - 2, pass);
			}
			else if (arr_rm[i] == 5) {
				FillSquare(ma, arr_h[0] + 1, 1, (arr_h[0] + arr_h[1]) - 1, arr_l[0] - 1, wall);
				FillSquare(ma, arr_h[0] + 2, 2, (arr_h[0] + arr_h[1]) - 2, arr_l[0] - 2, pass);
			}
			else if (arr_rm[i] == 6) {
				FillSquare(ma, arr_h[0] + 1, 1 + arr_l[0], (arr_h[0] + arr_h[1]) - 1, (arr_l[1] + arr_l[0]) - 1, wall);
				FillSquare(ma, arr_h[0] + 2, 2 + arr_l[0], (arr_h[0] + arr_h[1]) - 2, (arr_l[1] + arr_l[0]) - 2, pass);
			}
			else if (arr_rm[i] == 7) {
				FillSquare(ma, arr_h[0] + 1, 1 + (arr_l[0] + arr_l[1]), (arr_h[0] + arr_h[1]) - 1, (arr_l[0] + arr_l[1] + arr_l[2]) - 1, wall);
				FillSquare(ma, arr_h[0] + 2, 2 + (arr_l[0] + arr_l[1]), (arr_h[0] + arr_h[1]) - 2, (arr_l[0] + arr_l[1] + arr_l[2]) - 2, pass);
			}
			else if (arr_rm[i] == 8) {
				FillSquare(ma, arr_h[0] + 1, 1 + (arr_l[0] + arr_l[1] + arr_l[2]), (arr_h[0] + arr_h[1]) - 1, (arr_l[0] + arr_l[1] + arr_l[2] + arr_l[3]) - 1, wall);
				FillSquare(ma, arr_h[0] + 2, 2 + (arr_l[0] + arr_l[1] + arr_l[2]), (arr_h[0] + arr_h[1]) - 2, (arr_l[0] + arr_l[1] + arr_l[2] + arr_l[3]) - 2, pass);
			}
			else if (arr_rm[i] == 9) {
				FillSquare(ma, (arr_h[0] + arr_h[1]) + 1, 1, (arr_h[0] + arr_h[1] + arr_h[2]) - 1, arr_l[0] - 1, wall);
				FillSquare(ma, (arr_h[0] + arr_h[1]) + 2, 2, (arr_h[0] + arr_h[1] + arr_h[2]) - 2, arr_l[0] - 2, pass);
			}
			else if (arr_rm[i] == 10) {
				FillSquare(ma, (arr_h[0] + arr_h[1]) + 1, 1 + arr_l[0], (arr_h[0] + arr_h[1] + arr_h[2]) - 1, (arr_l[1] + arr_l[0]) - 1, wall);
				FillSquare(ma, (arr_h[0] + arr_h[1]) + 2, 2 + arr_l[0], (arr_h[0] + arr_h[1] + arr_h[2]) - 2, (arr_l[1] + arr_l[0]) - 2, pass);
			}
			else if (arr_rm[i] == 11) {
				FillSquare(ma, (arr_h[0] + arr_h[1]) + 1, 1 + (arr_l[0] + arr_l[1]), (arr_h[0] + arr_h[1] + arr_h[2]) - 1, (arr_l[0] + arr_l[1] + arr_l[2]) - 1, wall);
				FillSquare(ma, (arr_h[0] + arr_h[1]) + 2, 2 + (arr_l[0] + arr_l[1]), (arr_h[0] + arr_h[1] + arr_h[2]) - 2, (arr_l[0] + arr_l[1] + arr_l[2]) - 2, pass);
			}
			else if (arr_rm[i] == 12) {
				FillSquare(ma, (arr_h[0] + arr_h[1]) + 1, 1 + (arr_l[0] + arr_l[1] + arr_l[2]), (arr_h[0] + arr_h[1] + arr_h[2]) - 1, (arr_l[0] + arr_l[1] + arr_l[2] + arr_l[3]) - 1, wall);
				FillSquare(ma, (arr_h[0] + arr_h[1]) + 2, 2 + (arr_l[0] + arr_l[1] + arr_l[2]), (arr_h[0] + arr_h[1] + arr_h[2]) - 2, (arr_l[0] + arr_l[1] + arr_l[2] + arr_l[3]) - 2, pass);
			}

		}
		for (int i = 0; i < 22; i++) {
			for (int j = 0; j < 134; j++) {

				if (i == mid_h1 && (j >= mid_l1) && (j <= (arr_l[0] + arr_l[1] + arr_l[2] + mid_l4))) {
					ma->SetCell(i, j, tunnel);
				}
				else if (i == mid_h2 + arr_h[0] && (j >= mid_l1) && (j <= (arr_l[0] + arr_l[1] + arr_l[2] + mid_l4))) {
					ma->SetCell(i, j, tunnel);
				}
				else if (i == mid_h3 + arr_h[1] + arr_h[0] && (j >= mid_l1) && (j <= (arr_l[0] + arr_l[1] + arr_l[2] + mid_l4))) {
					ma->SetCell(i, j, tunnel);
				}
				else if (j == mid_l1 && (i >= mid_h1) && (i <= (arr_h[0] + arr_h[1] + mid_h3))) {
					ma->SetCell(i, j, tunnel);
				}
				else if (j == (mid_l2 + arr_l[0]) && (i >= mid_h1) && (i <= (arr_h[0] + arr_h[1] + mid_h3))) {
					ma->SetCell(i, j, tunnel);
				}
				else if (j == mid_l3 + arr_l[1] + arr_l[0] && (i >= mid_h1) && (i <= (arr_h[0] + arr_h[1] + mid_h3))) {
					ma->SetCell(i, j, tunnel);
				}
				else if (j == mid_l4 + arr_l[0] + arr_l[1] + arr_l[2] && (i >= mid_h1) && (i <= (arr_h[0] + arr_h[1] + mid_h3))) {
					ma->SetCell(i, j, tunnel);

				}

			}
		}

		igrok->SetXY(mid_l1, mid_h1);

		int l = 0;
		int k = 0;
		enemies = new vector<Enemy*>();

		for (int i = 0; i < 22 * 134; i++) {
			l = 2 + rand() % 130;
			k = 2 + rand() % 20;
			if (ma->GetCellState(k, l) == pass) {
				if (num_weaks != 0) {
					enemies->push_back(new Weak_Zombie(l, k));
					num_weaks--;
				}
				else if (num_normal != 0) {
					enemies->push_back(new Common_Zombie(l, k));
					num_normal--;
				}
				else if (num_giga_chads != 0) {
					enemies->push_back(new MutantZombie(l, k));
					num_giga_chads--;
				}
				else {
					break;
				}
				ma->SetCell(k,l, enemy);
			}
		}
		store_ = new Store();
		store_->SetXY(igrok->GetX(), igrok->GetY() - 1);
		ma->SetCell(igrok->GetY() - 1, igrok->GetX(), shop);
		pole = ma;
	}

	Field* GetField() {
		return pole;
	}
};