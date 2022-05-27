#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<vector>
#include<ctime>
#include<cstring>
#include<windows.h>
using namespace std;

struct DIEM {
  int x, y;
	DIEM() {
		x = 0;
		y = 0;
	}
	DIEM(int a, int b) {
		x = a;
		y = b;
	}
	DIEM operator - (DIEM d2) {
		DIEM d;
		d.x = x - d2.x;
		d.y = y - d2.y;
		return d;
	}
	bool operator == (DIEM d2) {
		return (x == d2.x && y == d2.y);
	}
};
struct RAN {};
struct MOI {
	DIEM toado;
	bool BiRanAn(vector<DIEM> toadoran) {
		return (toadoran[0] == toado);
	}
	bool MoiTrenRanHoacKhongHopLi(vector<DIEM> toadoran) {
		for (int i = 0; i < toadoran.size(); i++) {
			if (toado == toadoran[i])
				return true;
			if (i != 0) {
				int xtrong = (toadoran[i].x + toadoran[i - 1].x) / 2;
				int ytrong = (toadoran[i].y + toadoran[i - 1].y) / 2;
				if (toado.x == xtrong && toado.y == ytrong)
					return true;
			}
		}
		return false;
	}
	void TaoMoi(vector<DIEM> toadoran, int chieudai, int chieurong) {
		srand((unsigned)time(NULL));
		do {
			toado.x = rand() % (chieurong - 2) + 1;
			toado.y = rand() % (chieudai - 2) + 1;
		} while (MoiTrenRanHoacKhongHopLi(toadoran));
	}
};
struct KHUNG {};

int main(){


}
