#include<iostream>

class SmartArray {
private:
	int arr[10];
	int count;
	void wWhile() {
		std::cout << "������ ����������!" << std::endl;
		count = 0;
		reset();
	}
	void ifnot(int count) {
		if (count > 10 || count < 0)
			wWhile();
	}
	void create() {
		for (int i{}; i < 10; ++i)
			arr[i] = rand() % 10 + 1;
	}

public:
	SmartArray(int new_count, int new_arr = 0) :
		arr{ new_arr },
		count{ new_count }
	{ create(); }

	void reset() {
		for (int i{}; i < count; ++i)
			arr[i] = {};
		std::cout << "������ ������� ������." << std::endl;
	}

	void push() {
		count++;
		ifnot(count);
		arr[count] = rand() % 10 + 1;
		std::cout << "����� ������� ����������." << std::endl;
	}

	void pop() {
		std::cout << "�����: " << arr[count - 1] << std::endl;
		count--;
		ifnot(count);
		arr[count] = {};
	}

	void print() {
		for (int i{}; i < count; ++i)
			std::cout << arr[i] << ' ';
		std::cout << std::endl;
	}

};

int main() {
	srand(time(NULL));
	rand();
	setlocale(LC_ALL, "Russian");
	int countMain{};
	bool whileFirst{ true };
	bool whileSecond{ true };
	while (whileFirst) {
		std::cout << "������� ���-�� ���������� �������: ";
		std::cin >> countMain;
		if (countMain > 10 || countMain < 0) {
			std::cout << "������������� ���-�� ����������!" << std::endl;
			whileFirst = true;
		}
		whileFirst = false;
	}
	SmartArray a{ countMain };
	while (whileSecond) {
		std::cout << "�������� �������� � ������ - 1\n������� ��������� �������� ������� - 2\n�������� ������ - 3\n����������� ������ - 4\n";
		int switchNum{};
		std::cin >> switchNum;
		switch (switchNum) {
		case 1: a.push(); whileSecond = true; break;
		case 2: a.pop(); whileSecond = true; break;
		case 3: a.reset(); whileSecond = false; whileFirst = true; break;
		case 4: a.print(); whileSecond = true; break;
		default: whileSecond = true;
		}
	}

	return 0;
}