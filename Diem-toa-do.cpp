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
