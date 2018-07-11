#include <iostream>
#include <string>
#include <conio.h>
#include <list>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

class Elem
{
	public:
		
		Elem()
		{
			maxId++;
			id = maxId;
		}
		
		void deleteElem(int n); // Удаляет элемент номер N из списка
		void clear(); // Очищает элемент
		
		Elem copy(Elem elem) // Создает копию элемента
		{
			Elem newElem;
			newElem = elem;
			newElem.txt = txt;
			newElem.value = value;
			newElem.type = type;
			newElem.count = count;
			newElem.func = func;
			for (list <Elem>::iterator i = elements.begin(); i < elements.end(); i++) {
				newElem.elements[i] = elements[i].copy(newElem);
			}
			return newElem;
			////////////////////////////////////////////////////// ТУТ ЗАКОНЧИЛ
		}
		
		Elem add(Elem elem) // Добавляет элемент в конец списка
		{
			count++;
			elements.push_back(elem);
			list <Elem>::iterator i = elements.begin();
			(*i).parent = this;
			return (*i);
		}
		
		Elem CreateAndAdd(string s, int t) // Создает и добавляет элемент в конец списка
		{
			Elem elem;
			elem.txt = s;
			elem.value = s;
			elem.type = t;
			add(elem);
			return elem;
		}
		
		void deleteElem() // Удаляет последний элемент
		{
			count--;
			elements.erase(elements.end());
		}
		
	private:
		Elem* parent; // Родитель элемента
		int id; // ID элемента
		int static maxId;
		string err; // Ошибка
		string txt; // Слово
		string value; // Значение
		int type; // Тип элемента
		bool func; // Проверяет это функция или нет
		int count; // счетчик элементов
		list<Elem> elements; // Список слов
};

//Проверка вхождения символа в диапозон значений
bool predel(char c, string str)
{
	if(str.length() % 2 != 0) {
		cout << "Ошибка. Параметр должны быть четными.";
	}
	int i = 0;
	while(i < str.length()) {
		if(c >= str[i] && c <= str[i + 1]) {
			return true;
		}
		else {
			i += 2;
		}
	}
}
//Чтение оператора из строки
string readOperator(int& k, int len, string str)
{
	string result = "";
	if (k < len && predel(str[k], "AZaz")) {
		while(k < len && predel(str[k], "AZaz09__")) {
			result += str[k];
			k++;
		}
	}
	return result;
}
//Проверяет является строка оператором или нет
bool checkOperator(int k, int len, string str)
{
	if(readOperator(k, len, str) != "") {
		return true;
	}
	else {
		return false;
	} 
}
//Чтение одинарных знаков из строки
string readSing(int& k, int len, string str)
{
	int i = 0;
	string StrSigns = "+-/\*()[]<>=;:,";
	if (k <= len) {
		while (StrSigns.length() >= i) {
			if (StrSigns[i] == str[k]) {
				string result = "";
				result = str[k];
				k++;
				return result;
			}
			else {
				i++;
			}
		}
	}
}
//Проверяет является строка одинарным символом или нет
bool checkSign(int k, int len, string str)
{
	if(readSing(k, len, str) != "") {
		return true;
	}
	else {
		return false;
	} 
}
//Чтение двойных знаков из строки
string readDoubleSing(int& k, int len, string str)
{
	int i = 0;
	string StrSigns = "==<=>=!=<<>>";
	if (k <= len) {
		while (StrSigns.length() >= i + 1) {
			if (StrSigns[i] == str[k] && StrSigns[i + 1] == str[k + 1]) {
				string result = "";
				result += str[k];
				result += str[k + 1];
				k += 2;
				return result;
			}
			else {
				i++;
			}
		}
	}
}
//Проверяет является строка двойным символом или нет
bool checkDoubleSing(int k, int len, string str)
{
	if(readDoubleSing(k, len, str) != "") {
		return true;
	}
	else {
		return false;
	} 
}


////Чтение однострочного комментария из строки
//string readSingleLineComments(int& k, int len, string str)
//{
//	return "";
//}

////Чтение многострочного комментария из строки
//string readMultiLineСomments(int& k, int len, string str)
//{
//}


int main(int argc, char** argv) {
	string s = "Sum(a,b); Minus(r,d);";
	int k = 0;
	while (k < s.length()) {
		if(checkOperator(k, s.length(), s)){
			cout << readOperator(k, s.length(), s) << endl;
		}
		else {
			if(checkSign(k, s.length(), s)) {
				cout << readSing(k, s.length(), s) << endl;
			}
		}
		if (s[k] == ' ') k++;
	}
	return 0;
}
