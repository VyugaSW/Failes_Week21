
#include <Windows.h>
#include <iostream>

using namespace std;
//Задание 1. Дано два текстовых файла.Выяснить, совпа -
//дают ли их строки.Если нет, то вывести несовпадающую
//строку из каждого файла.
void Task1();

//Задание 2. Дан текстовый файл. Необходимо создать
//новый файл и записать в него следующую статистику по
//исходному файлу :
//■■Количество символов;
//■■Количество строк;
//■■Количество гласных букв;
//■■Количество согласных букв;
//■■Количество цифр.
void Task2();
//Массив согласных букв
const char lettersCons[42] = { 'B','C','D','F','G','H','J','K','L','M','N','P','Q','R','S','T','V','W','X','Y','Z',
							   'b','c','d','f','g','h','j','k','l','m','n','p','q' ,'r','s','t','v','w','x','y','z'};
//Массив гласных букв
const char lettersVowel[12] = { 'A','E','I','O' ,'U','Y',
								'a','e','i','o','u','y'};

//Задание 3. Шифр Цезаря — один из древнейших шифров.
//При шифровании каждый символ заменяется другим,
//отстоящим от него в алфавите на фиксированное число
//позиций.
//Дан текст. Зашифровать его, используя
//шифр Цезаря.Результат записать в другой файл.
void Task3();

int main()
{
	//Task1();
	//Task2();
	Task3();
}

void Task1() {
	FILE* out1;
	FILE* out2;
	const char* path1 = "C:\\Test\\test.txt";
	const char* path2 = "C:\\Test\\test2.txt";
	char* s1 = new char[125]; //Буфер строк первого файла
	char* s2 = new char[125]; //Буфер строк второго файла
	bool flag = true; //Проверка на наличие отличий
	if (!fopen_s(&out1, path1, "r")) {
		if (!fopen_s(&out2, path2, "r")) {
			int i = 0; //Какая строка по счету с начала
			while (!feof(out1)) {
				i++;
				fgets(s1, 125, out1);
				fgets(s2, 125, out2);
				if (strcmp(s1, s2) == 0)
					continue;
				else
				{
					cout << "Strings Rows numbered " << i << " do not match\n";
					cout << "String of file \"test.txt\":\n ";
					cout << s1 << endl;
					cout << "String of file \"test2.txt\":\n ";
					cout << s2 << endl;
					flag = false;
				}
			}
			fclose(out2);
		}
		fclose(out1);
	}
	if (flag)
		cout << "File lines are identical\n";
	delete[] s1;
	delete[] s2;
}
void Task2(){
	FILE* out;
	const char* path = "C:\\Test\\test.txt";
	char s; //Буфер символа
	char* str = new char[125]; //Буфер для строки
	int strings = 0, letters = 0, lettersC = 0, lettersV = 0, numbers = 0;
	if (!fopen_s(&out, path, "r")) {
		while (!feof(out)) {
			s = getc(out);
			letters++;
			if (isdigit(s))
				numbers++;

			else if (isalpha(s)) {
				for (int i = 0; i < 42; i++) {
					if (s == lettersCons[i]) {
						lettersC++;
						break;
					}
				}
				for (int i = 0; i < 12; i++) {
					if (s == lettersVowel[i]) {
						lettersV++;
						break;
					}
				}
			}
		}
		fclose(out);
	}
	if (!fopen_s(&out, path, "r")) {
		while (!feof(out)) {
			fgets(str, 125, out);
			strings++;
		}
		fclose(out);
	} //Не придумал как более верно сделать подсчёт строк

	cout << "Strings - " << strings << endl;
	cout << "Letters Cons. - " << lettersC << endl;
	cout << "Letter Vowel - " << lettersV << endl;
	cout << "Letters - " << letters << endl;
	cout << "Numbers - " << numbers << endl;
}
void Task3() {
	FILE* in;
	const char* path = "C:\\Test\\test3.txt"; //путь
	char* string = new char[70]{"Eat those French rolls and have some tea"};
	char s;
	if (!fopen_s(&in, path, "w")) {
			for (int i = 0; i < 50; i++) {
				s = string[i];
				if (s >= 'a' && s <= 'w')
					fputc((s + 3), in);
				//Не озарило меня наитие как вернее сделать последние три буквы,
				//посему было мною решено добавить их как исключения (аналогично с прописными)
				else if (s == 'x')
					fputc('a', in);
				else if (s == 'y')
					fputc('b', in);
				else if (s == 'z')
					fputc('c', in);
				else if (s >= 'A' && s <= 'W')
					fputc((s+3), in);

				else if (s == 'X')
					fputc('A', in);
				else if (s == 'Y')
					fputc('B', in);
				else if (s == 'Z')
					fputc('C', in);

				else
					fputc(s, in);
		}
		fclose(in);
		cout << "Text encrypted successfully\n";
	}
	else
		cout << "File wasn't opened\n";
	

}