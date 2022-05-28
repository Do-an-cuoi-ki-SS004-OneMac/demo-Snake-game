#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<vector>
#include<ctime>
#include<cstring>
#include<windows.h>
using namespace std;
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