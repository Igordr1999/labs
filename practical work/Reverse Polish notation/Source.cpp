#include<iostream>
#include<stack>
using namespace std;

int calc(int x, int y, char t) {
	switch (t) {
	case '+':
		return x + y;
	case '-':
		return x - y;
	case '*':
		return x * y;
	case '/':
		return x / y;
	default:
		break;
	}
}

int main() {
	stack <int> st;
	int n, q, a, b, value;
	char s;
	cout << "lenght: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;
		if ((s == '+') || (s == '-') || (s == '*') || (s == '/')) {
			//запоминаем и удаляем два верхних числа из стека
			b = st.top();
			st.pop();
			a = st.top();
			st.pop();

			//вычисляем результат и добавляем его в стек
			value = calc(a, b, s);
			st.push(value);
			cout << a << " " << s << " " << b << " = " << value << endl;
		}
		else {
			//добавляем число (цифру) в стек
			q = (int)s - 48;
			st.push(q);
		}
	}
	cout << endl << "Answer: " << value<<endl;
	system("pause");
	return 0;
}