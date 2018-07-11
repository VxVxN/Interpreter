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
		
		void deleteElem(int n); // ������� ������� ����� N �� ������
		void clear(); // ������� �������
		
		Elem copy(Elem elem) // ������� ����� ��������
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
			////////////////////////////////////////////////////// ��� ��������
		}
		
		Elem add(Elem elem) // ��������� ������� � ����� ������
		{
			count++;
			elements.push_back(elem);
			list <Elem>::iterator i = elements.begin();
			(*i).parent = this;
			return (*i);
		}
		
		Elem CreateAndAdd(string s, int t) // ������� � ��������� ������� � ����� ������
		{
			Elem elem;
			elem.txt = s;
			elem.value = s;
			elem.type = t;
			add(elem);
			return elem;
		}
		
		void deleteElem() // ������� ��������� �������
		{
			count--;
			elements.erase(elements.end());
		}
		
	private:
		Elem* parent; // �������� ��������
		int id; // ID ��������
		int static maxId;
		string err; // ������
		string txt; // �����
		string value; // ��������
		int type; // ��� ��������
		bool func; // ��������� ��� ������� ��� ���
		int count; // ������� ���������
		list<Elem> elements; // ������ ����
};

//�������� ��������� ������� � �������� ��������
bool predel(char c, string str)
{
	if(str.length() % 2 != 0) {
		cout << "������. �������� ������ ���� �������.";
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
//������ ��������� �� ������
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
//��������� �������� ������ ���������� ��� ���
bool checkOperator(int k, int len, string str)
{
	if(readOperator(k, len, str) != "") {
		return true;
	}
	else {
		return false;
	} 
}
//������ ��������� ������ �� ������
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
//��������� �������� ������ ��������� �������� ��� ���
bool checkSign(int k, int len, string str)
{
	if(readSing(k, len, str) != "") {
		return true;
	}
	else {
		return false;
	} 
}
//������ ������� ������ �� ������
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
//��������� �������� ������ ������� �������� ��� ���
bool checkDoubleSing(int k, int len, string str)
{
	if(readDoubleSing(k, len, str) != "") {
		return true;
	}
	else {
		return false;
	} 
}


////������ ������������� ����������� �� ������
//string readSingleLineComments(int& k, int len, string str)
//{
//	return "";
//}

////������ �������������� ����������� �� ������
//string readMultiLine�omments(int& k, int len, string str)
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
