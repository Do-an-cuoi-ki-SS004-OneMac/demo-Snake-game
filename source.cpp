#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<vector>
#include<ctime>
#include<cstring>
#include<windows.h>
using namespace std;


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
