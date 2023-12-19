#pragma once
#include "TStack.h"
#include <string.h>

bool isDigit(char& in)
{
	return (in >= '0' && in <= '9');
}

int Prior(char c)
{
	if ((c == '*') || (c == '/'))
		return 3;
	else if ((c == '+') || (c == '-'))
		return 2;
	else if (c == '(')
		return 1;
	else
		throw "non-expect symbol";
}

char* Stroka(char* s)
{
	TStack<char> l;
	int count = strlen(s);
	char* s2 = new char[count + 1] {'\0'};
	int g = 0;
	for (int i = 0; i < count; i++)
	{
		if (isDigit(s[i]))
		{
			s2[g] = s[i];
			g++;
		}
		else if (s[i] == ')')
		{
			char m = l.Pull();
			while (m != '(')
			{
				s2[g] = m;
				g++;
				m = l.Pull();
			}
		}
		else
		{
			int p = Prior(s[i]);
			if (l.IsEmpty() == true)
				l.Push(s[i]);
			else
			{
				char n = l.Pull();
				int pn = Prior(n);
				if (pn < p)
				{
					l.Push(n);
					l.Push(s[i]);
				}
				else
				{
					while ((pn >= p) && (!l.IsEmpty()))
					{
						s2[g] = n;
						g++;
						n = l.Pull();
						pn = Prior(n);
					}
					l.Push(n);
					l.Push(s[i]);
				}
			}
		}
	}
	while (!l.IsEmpty())
	{
		s2[g] = l.Pull();
		g++;
	}
	return s2;
}

double calcul(char* in)
{
	double num1,num2;
	TStack<char> num,nun;
	char op,op2=']', op3,op4;
	for (int i = 0; i < strlen(in)+1; i++)
	{
			num.Push(in[i]);
	}
	while (!(num.IsEmpty()))
	{
		op = num.Pull();
		while (!isDigit(op2) && !isDigit(op3))
		{
			if (op2 != ']')
			{
				num.Push(nun.Pull());
				num.Push(nun.Pull());
			}
			op = num.Pull();
			op2 = num.Pull();
			op3 = num.Pull();
			nun.Push(op);
			nun.Push(op2); 
			nun.Push(op3);
		}
		num1 = nun.Pull(), num2 = nun.Pull(); op = nun.Pull();
		if (op == '+')
			num.Push(num1 + num2);
		else if (op == '-')
			num.Push(num1 - num2);
		else if (op == '/')
			num.Push(num2 / num1);
		else if (op == '*')
			num.Push(num1 * num2);
		while (!(nun.IsEmpty()))
			num.Push(nun.Pull());
		op2 = ']'; op3 = ']';
	}
	return num.Pull();
}