#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<vector>
#include<ctime>
#include<cstring>
#include<windows.h>
using namespace std;


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
		if (toado.y % 2 == 0)
			return true;
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

void NhapCacYeuCau(KHUNG& khung)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 14);
	khung.chieudai = 80;
	khung.chieurong = 30;
	SetConsoleTextAttribute(h, 10);
	khung.ran.ChieuDai = 4;
	SetConsoleTextAttribute(h, 11);
	cout << "\n\n\n\n\n\n\n                                                 Choose level:";
	cout << "\n                                                     1.Hard.";
	cout << "\n                                                     2.Medium.";
	cout << "\n                                                     3.Easy\n";
	cout << "                                                        ";
	int n;
	cin >> n;
	if (n == 1)
	{
		khung.level = "Hard";
		khung.tocdo = 70;
	}
	else if (n == 2)
	{
		khung.level = "Medium";
		khung.tocdo = 150;
	}
	else if (n == 3)
	{
		khung.level = "Easy";
		khung.tocdo = 300;
	}
	SetConsoleTextAttribute(h, 12);
	cout << "                                            Press any key to play...";
	_getch();
	system("cls");
}



int main() {
	hear: KHUNG khung;
	NhapCacYeuCau(khung);
	khung.Vekhung();
	khung.ran.ToaDo.resize(khung.ran.ChieuDai);
	khung.VeTroChoi();
	_getch();
	system("cls");
	string a = "\n\n\n\n\n\n\n\n                                              Do you want to play again? \n                                                       yes/no";
	cout << a << endl;
	cout << "                                                Your answer: ";
	string m;
	cin >> m;
	if (m == "yes")
	{
		system("cls");
		goto hear;
	}

	string s = "\n                                                     Thank you";
	for (int a[8] = { 10,11,12,14,11,10,14,12 }, i = 0; i < s.length(); i++) {
		SetConsoleTextAttribute(khung.h, a[i % 8]);
		cout << s[i];
	}
}