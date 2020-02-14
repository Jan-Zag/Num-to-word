#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

#define Zero 0
#define One 1
#define Milliard 1000000000

string sum2str(double x);
string soundThreeDigits(int x);

int main()
{
	while (true) {
		double x;
		cout << " x(0..1 000 000 000) = ";
		cin >> x;
		cout << sum2str(x) << endl;
	}
	return 0;
}

string soundThreeDigits(int x)
{
	string answer = "";
	int h = x / 100;
	switch (h) {
	case 1: answer = " one"; break;
	case 2: answer = " two"; break;
	case 3: answer = " three"; break;
	case 4: answer = " four"; break;
	case 5: answer = " five"; break;
	case 6: answer = " six"; break;
	case 7: answer = " seven"; break;
	case 8: answer = " eight"; break;
	case 9: answer = " nine"; break;
	}
	if (h != 0) answer += " hundred";

	int dd = x % 100;
	if (20 <= dd && dd <= 99) {//[20..99]
		int d = x / 10 % 10;
		int o = x % 10;

		switch (d) {
		case 2: answer += " twenty"; break;
		case 3: answer += " thirty"; break;
		case 4: answer += " fourty"; break;
		case 5: answer += " fifty"; break;
		case 6: answer += " sixty"; break;
		case 7: answer += " seventy"; break;
		case 8: answer += " eighty"; break;
		case 9: answer += " ninety"; break;
		}
		switch (o) {
		case 1: answer += "-one"; break;
		case 2: answer += "-two"; break;
		case 3: answer += "-three"; break;
		case 4: answer += "-four"; break;
		case 5: answer += "-five"; break;
		case 6: answer += "-six"; break;
		case 7: answer += "-seven"; break;
		case 8: answer += "-eight"; break;
		case 9: answer += "-nine"; break;
		}
	}
	else {//[0..19]
		switch (dd) {
		case  1: answer += " one"; break;
		case  2: answer += " two"; break;
		case  3: answer += " three"; break;
		case  4: answer += " four"; break;
		case  5: answer += " five"; break;
		case  6: answer += " six"; break;
		case  7: answer += " seven"; break;
		case  8: answer += " eight"; break;
		case  9: answer += " nine"; break;
		case 10: answer += " ten"; break;
		case 11: answer += " eleven"; break;
		case 12: answer += " twelve"; break;
		case 13: answer += " thirteen"; break;
		case 14: answer += " fourteen"; break;
		case 15: answer += " fifteen"; break;
		case 16: answer += " sixteen"; break;
		case 17: answer += " seventeen"; break;
		case 18: answer += " eighteen"; break;
		case 19: answer += " nineteen"; break;
		}
	}

	return answer;
}

string sum2str(double x) {
	if (x < 0 || x > 1000000000)
	{
		string answer = "Incorect number";
		return answer;
	}
	if (x == Zero) {
		return " No dollars";
	}
	if (x == One) {
		return " One dollar";
	}
	if (x == Milliard) {
		return " One billion dollars";
	}

	int dollars = x;
	int cents = round((x - dollars) * 100);

	int mills = dollars / 1000000;
	int thsds = dollars / 1000 % 1000;
	int dolrs = dollars % 1000;

	string m = soundThreeDigits(mills);
	string t = soundThreeDigits(thsds);
	string d = soundThreeDigits(dolrs);
	string c = soundThreeDigits(cents);

	string answer = "";
	if (mills != 0) answer += m + " million";
	if (thsds != 0) answer += t + " thousand";
	if (dolrs != 0 || thsds != 0 || mills != 0) answer += d + " dollars";
	if (cents != 0) answer += c + " cents";

	return answer;
}