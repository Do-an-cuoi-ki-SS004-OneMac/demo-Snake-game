struct RAN {
    int ChieuDai;
	vector<DIEM> ToaDo;
	DIEM duoitruoc;
	char XacDinhPhuongHuong(DIEM a, DIEM b) {
		DIEM huong = a - b;
		if (huong.x == 0 && huong.y == 2)
			return 'E';
		else if (huong.x == 0 && huong.y == -2)
			return 'W';
		else if (huong.x == 1 && huong.y == 0)
			return 'S';
		else
			return 'N';
	}
	void DiThang(DIEM& dau, char huong) {
		if (huong == 'N')
			dau.x--;
		else if (huong == 'S')
			dau.x++;
		else if (huong == 'E')
			dau.y += 2;
		else
			dau.y -= 2;
	}
	void DoiHuong(int lenh, char& huong) {
		if ((huong == 'N' || huong == 'S') && (lenh != 72 && lenh != 80)) {
			if (lenh == 77)
				huong = 'E';
			if (lenh == 75)
				huong = 'W';
		}
		else if ((huong == 'E' || huong == 'W') && (lenh != 77 && lenh != 75)) {
			if (lenh == 72)
				huong = 'N';
			if (lenh == 80)
				huong = 'S';
		}
	}
	void DiChuyenThan() {
	duoitruoc = ToaDo[ChieuDai - 1];
		for (int i = ChieuDai - 1; i >= 1; --i)
			ToaDo[i] = ToaDo[i - 1];
	}
	void DiChuyenDau(){
	char huong = XacDinhPhuongHuong(ToaDo[1], ToaDo[2]);
		if (_kbhit()) {
			int c = _getch();
			c = _getch();
			DoiHuong(c, huong);
			DiThang(ToaDo[0], huong);
		}
		else
			DiThang(ToaDo[0], huong);
	}
	void DiChuyen() {
		DiChuyenThan();
		DiChuyenDau();
		//cout<<"\a";
	}
	void XuatHien() {
		for (int i(ToaDo.size() - 1), j(1); i >= 0; i--, j += 2) {
			ToaDo[i].x = 1;
			ToaDo[i].y = j;
		}
	}
	void DaAnMoi() {
		ChieuDai++;
		ToaDo.resize(ChieuDai);
		ToaDo[ChieuDai - 1] = duoitruoc;
	}
};
