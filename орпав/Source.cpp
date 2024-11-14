#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Kurs { I = 1, II, III, IV, V, VI };
enum Spec { MATH_ECONOMICS, PHISICS_INFORMATICS, LABOR_TRANING };


struct student {
	string prizv;
	unsigned kurs;
	Spec spec;
	double Phisics_mark;
	double Math_mark;
	double Inform_mark;
};

void Create(student*& s, int n);
int Ast_Phisics(student* arr, int n);
void Print_head(student* arr, int n);
void Print_body(student* arr, int n);
void Print_avr_sub(student* arr, int n);//Print averange mark for subject all students
double avr_sub_math(student* arr, int n);
double avr_sub_phis(student* arr, int n);
double avr_sub_inf(student* arr, int n);

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n;
	cout << "amount of students = ? ";cin >> n;
	student* s = new student[n];
	int menuItem;
	do {
		cout << "\n\n"
			<< "������� ��\n\n"
			<< "[1] - �������� ����� � ���������\n"
			<< "[2] - ���� ����� �� �����\n"
			<< "[3] - ���� ���������� ���� �� ������� ��� ����\n"
			<< "[4] - ���� ������� �������� � ���� � ������ � ��� 4 ��� 5\n"
			<< "[5] - ����� � ��������\n\n"
			<< "������ ��������: "; cin >> menuItem;
		cout << "\n\n\n";
		switch (menuItem) {
		case 1:
			Create(s, n);

			break;
		case 2:
			Print_head(s, n);
			break;
		case 3:
			Print_avr_sub(s, n);
			break;
		case 4:
			cout << Ast_Phisics(s, n);
			break;
		case 5:
			return 0;
		default:
			cout << "�� ����� ��������� ��������! "
				"��� ������ ����� - ����� ��������� ������ ����\n";
		}
	} while (menuItem != 0);
}
void Create(student*& s, int n) {
	int spec;
	for (int i = 0; i < n;i++) {
		cout << "������� No" << i + 1 << ":\n";

		cin.get();
		cin.sync();

		cout << "�������: "; getline(cin, s[i].prizv);
		cout << "����: "; cin >> s[i].kurs;
		cout << "������������(0 - ���������� � ��������, 1 - ������ � �����������, 2 - ������� ��������) \n";
		cin >> spec;
		switch (spec) {
		case 0:
			s[i].spec = MATH_ECONOMICS;
			break;
		case 1:
			s[i].spec = PHISICS_INFORMATICS;
			break;
		case 2:
			s[i].spec = LABOR_TRANING;
			break;
		default:
			cout << "������� ������ �����";
		}

		cout << "������ ������ � ����������\n";
		cin >> s[i].Math_mark;
		cout << endl;

		cout << "������ ������ � ������ \n";
		cin >> s[i].Phisics_mark;
		cout << endl;

		cout << "������ ������ � �����������\n";
		cin >> s[i].Inform_mark;
		cout << endl;

	}

}

int Ast_Phisics(student* arr, int n) {//amount of students that have 5 or 4 Phisics
	int k = 0;
	for (int i = 0;i < n;i++) {
		if (arr[i].Phisics_mark == 4 || arr[i].Phisics_mark == 5)
			k++;
	}
	return k;
}

void Print_head(student* arr, int n) {
	cout << "===================================================================================\n"
		<< "|N" << setw(10) << "|SURNAME " << setw(10) << "|Kurs " << setw(10) << "|SPECIALITY" << setw(8) << "|PHISICS" << setw(12) << "|MATH " << setw(28) << " |INFORMATICS   " << setw(4) << " | \n";
	Print_body(arr, n);
	cout << "===================================================================================\n\n";
}

void Print_body(student* arr, int n) {
	int pos = 1;
	string spec;
	cout << "-----------------------------------------------------------------------------------\n";
	for (int i = 0; i < n;i++) {

		if (arr[i].spec == 0)
			spec = "ME";
		if (arr[i].spec == 1)
			spec = "PHI";
		if (arr[i].spec == 2)
			spec = "LT";

		cout << "|" << pos << " |" << setw(10)
			<< arr[i].prizv << "  |" << setw(5)
			<< arr[i].kurs << "|" << setw(10)
			<< spec << "|" << setw(13)
			<< arr[i].Phisics_mark << "|" << setw(18)
			<< arr[i].Math_mark << "|" << setw(15)
			<< arr[i].Inform_mark << "|" << endl;
		pos++;
	}
}
void Print_avr_sub(student* arr, int n) {
		cout << "������� ��� �� �������(������ ������ � ��� ��������)\n"
			<< "����������: \n" << avr_sub_math(arr, n) << endl;

		cout << "������: \n" << avr_sub_phis(arr, n) << endl;

		cout << "�����������: \n" << avr_sub_inf(arr, n) << endl;

}
double avr_sub_math(student* arr, int n) {
	double avr = 0;
	for (int i = 0; i < n;i++) {
		avr += arr[i].Math_mark;
	}
	return avr / n;
}
double avr_sub_phis(student* arr, int n) {
	double avr = 0;
	for (int i = 0; i < n;i++) {
		avr += arr[i].Phisics_mark;
	}
	return avr / n;
}
double avr_sub_inf(student* arr, int n) {
	double avr = 0;
	for (int i = 0; i < n;i++) {
		avr += arr[i].Inform_mark;
	}
	return avr / n;
}
