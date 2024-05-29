#include "Libraries.h"
#include "Functions.h"

void Settings_() {
	srand(time(NULL));
	Console::Title = "TITLE";
	Console::CursorVisible = false;
	Console::SetWindowSize(70, 30);
}

int IntRandom_(int _min, int _max) {
	return _min + rand() % (_max - _min + 1);
}

char CharRandom_(char _min, char _max) {
	return _min + rand() % (_max - _min + 1);
}

void FontColor_(int _color) {
	Console::ForegroundColor = (ConsoleColor)_color;
}

void CharColor_(char _c, int _color) {
	FontColor_(_color); cout << _c;
}

void StringColor_(string _s, int _color) {
	FontColor_(_color); cout << _s;
}

void Show_(int _x, int _y) {
	Console::SetCursorPosition(_x, _y);
}

void ShowColor_(int _x, int _y, int _color) {
	Show_(_x, _y);
	FontColor_(_color);
}

void ShowChar_(int _x, int _y, char _c) {
	Show_(_x, _y); cout << _c;
}

void ShowString_(int _x, int _y, string _s) {
	Show_(_x, _y);  cout << _s;
}

void ShowCharColor_(int _x, int _y, char _c, int _color) {
	ShowColor_(_x, _y, _color); cout << _c;
}

void ShowStringColor_(int _x, int _y, string _s, int _color) {
	ShowColor_(_x, _y, _color); cout << _s;
}

void ClearScreen_() {
	Console::Clear();
}

bool PrimeNumber_(int _n) {
	if (_n > 1) {
		int v{ 0 };
		for (int i = 1; i <= _n; i++)
			if (_n % i == 0) v++;

		if (v > 2) return false;
		else return true;
	}
	else return false;
}

void ShowBubble_(int* _arr, int _n) {
	for (int i = 0; i < _n; i++) {
		if (i != _n - 1) cout << _arr[i] << " ";
		else cout << _arr[i];
	}
}

void BubbleSort_(int* _arr, int _n, bool _order) {
	switch (_order) {
	case 0:
		for (int i = 0; i < _n - 1; i++) {
			int min = i;
			for (int j = i + 1; j < _n; j++)
				if (_arr[j] <= _arr[min])
					min = j;

			int tempArr = _arr[i];
			_arr[i] = _arr[min];
			_arr[min] = tempArr;
		}
		break;

	case 1:
		for (int i = 0; i < _n - 1; i++) {
			int max = i;
			for (int j = i + 1; j < _n; j++)
				if (_arr[j] >= _arr[max])
					max = j;

			int tempArr = _arr[i];
			_arr[i] = _arr[max];
			_arr[max] = tempArr;
		}
		break;

	default: break;
	}
}

void WaitKey_() {
	char c = _getch();
}

//void ShowQueue(queue<string> _q) {
//	while (!_q.empty()) {
//		cout << _q.front() << " ";
//		_q.pop();
//	}
//
//	cout << endl;
//}