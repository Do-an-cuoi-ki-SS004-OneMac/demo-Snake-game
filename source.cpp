#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<vector>
#include<ctime>
#include<cstring>
#include<windows.h>
using namespace std;
struct KHUNG {
	int chieudai, chieurong;
	RAN ran;
	MOI moi;
	string level;
	int tocdo;
	char doc = 219;
	char duoi = 220;
	char tren = 223;
	char moian = '$';
	char dau = 2;
	char than = 'o';
	COORD c;   //Luu tru toa do
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);   // Thao tac tren man hinh
	void Vekhung() {
		system("cls");
		SetConsoleTextAttribute(h, 12); //12 la ma mau.
		for (int i = 1; i < chieudai - 1; i++) {
			c = { (short)i,0 };
			SetConsoleCursorPosition(h, c);
			cout << tren;
		}
		for (int i = 0; i < chieurong; i++)
			for (int j = 0; j < chieudai; j += chieudai - 1) {
				c = { (short)j,(short)i };
				SetConsoleCursorPosition(h, c);
				cout << doc;
			}
		for (int i = 1; i < chieudai - 1; i++) {
			c = { (short)i,(short)(chieurong - 1) };
			SetConsoleCursorPosition(h, c);
			cout << duoi;
		}
	}
	void VeRan() {
		SetConsoleTextAttribute(h, 13);
		for (int i = 0; i < ran.ToaDo.size(); i++) {
			c = { (short)ran.ToaDo[i].y,(short)ran.ToaDo[i].x };
			SetConsoleCursorPosition(h, c);
			if (i == 0)
				cout << dau;
			else
				cout << than;
		}
	}
	void VeMoi() {
		SetConsoleTextAttribute(h, 14);
		c = { (short)moi.toado.y,(short)moi.toado.x };
		SetConsoleCursorPosition(h, c);
		cout << moian;
	}
	void XoaRan() {
		for (int i = 0; i < ran.ToaDo.size(); i++) {
			c = { (short)ran.ToaDo[i].y,(short)ran.ToaDo[i].x };
			SetConsoleCursorPosition(h, c);
			cout << " ";
		}
	}
	bool GameOver() {
		if (ran.ToaDo[0].x <= 0 || ran.ToaDo[0].x >= chieurong - 1 || ran.ToaDo[0].y <= 0 || ran.ToaDo[0].y >= chieudai - 1)
			return true;
		for (int i = 4; i < ran.ToaDo.size(); i++)
			if (ran.ToaDo[0] == ran.ToaDo[i])
				return true;
		return false;
	}
	void InDiemSo() {
		int a[4] = { 10,11,12,14 };
		c = { (short)(chieudai + 2), 3 };
		SetConsoleTextAttribute(h, a[rand() % 4]);
		SetConsoleCursorPosition(h, c);
		cout << "\t  Welcome to play!!";
		c = { (short)(chieudai + 2), 4 };
		SetConsoleTextAttribute(h, a[rand() % 4]);
		SetConsoleCursorPosition(h, c);
		cout << "19522223 & 21522600 & 21522662";
		c = { (short)(chieudai + 4), 5 };
		SetConsoleTextAttribute(h, a[rand() % 4]);
		SetConsoleCursorPosition(h, c);
		cout << "      Goodluck to you\n\n\n\n\n\n";
		c = { (short)(chieudai + 4), 8 };
		SetConsoleTextAttribute(h, a[rand() % 4]);
		SetConsoleCursorPosition(h, c);
		cout << "        LEVEL: " << level << endl;
		c = { (short)(chieudai + 4), 10 };
		SetConsoleTextAttribute(h, a[rand() % 4]);
		SetConsoleCursorPosition(h, c);
		cout << "        Score : " << ran.ToaDo.size() - 4 << endl;
	}
	void VeTroChoi() {
		ran.XuatHien();
		moi.TaoMoi(ran.ToaDo, chieudai, chieurong);
		VeMoi();
		do {
			InDiemSo();
			VeRan();
			Sleep(tocdo);
			XoaRan();
			ran.DiChuyen();
			if (moi.BiRanAn(ran.ToaDo)) {
				ran.DaAnMoi();
				//Beep(1000,10);
				moi.TaoMoi(ran.ToaDo, chieudai, chieurong);
				VeMoi();
			}
		} while (!GameOver());
		c = { (short)(chieudai + 4), 12 };
		SetConsoleCursorPosition(h, c);
		string thua = "        GAME OVER!!";
		for (int i = 0; i < thua.length(); i++) {
			SetConsoleTextAttribute(h, i < 6 ? i + 9 : (i % 6) + 9);
			cout << thua[i];
		}

	}
};