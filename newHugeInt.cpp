#define _CRT_SECURE_NO_WARNINGS

// HugeIntExperiments.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <math.h>

#define KEY_LENGTH 16


class hugeInt
{

	//----------------------------------------------------------*Поля*------------------------------------------------------------//
private:
	int length;
	short* digits;
	bool minus;
	//----------------------------------------------------------*Поля*------------------------------------------------------------//
public:
	int getLength(){
		return length;
	}
	void setLength(int l){
		length = l;
	}
	bool getMinus(){
		return minus;
	}
	void setMinus(bool a){
		minus = a;
	}

	void setDigits(int position, int digit){
		digits[position] = digit;	
	}
	short getDigit(int pos){
		return digits[pos];
	}
	//-------------------------------------------------------*Конструктор пустого числа заданой длины----------------------------------------//

	hugeInt(int l)
	{
		length = l;
		digits = new short[100];
	/*	for (int i = 0; i < length; i++){
			digits[i] = 0;
		}*/
		minus = false;
	}
	//-------------------------------------------------------*Конструктор пустого числа заданой длины----------------------------------------//
	
	//-------------------------------------------------------*Деструктор----------------------------------------//
	~hugeInt(){
		//std::cout<<"FINISHED"<<std::endl;
	}
	//-------------------------------------------------------*Деструктор----------------------------------------//

	//-------------------------------------------------------*Конструктор пустого числа-----------------------------------------------//	
	hugeInt()
	{
		length = 100;
		digits = new short[length];
		for (int i = 0; i < length; i++){
			digits[i] = 0;
		}
		minus = false;
	}
	//-------------------------------------------------------*Конструктор пустого числа----------------------------------------//	
	
	 //-------------------------------------------------------*Конструктор числа с заданным значением----------------------------------------//
    hugeInt(std::string d)
    {
		minus = false;
        length = d.length();
		digits = new short[d.length()];
		
		for (int i = 0; i < length; i++){
			digits[i] = d[length - i - 1] - '0';
		}
    }
    //-------------------------------------------------------*Конструктор числа с заданным значением-----------------------------------//

	
	//-------------------------------------------------------*Рандом-------------------------------------------------------------------------//
	void random(int len){
		length = len;
		for (int i = 0; i < length; i++){
			digits[i] = rand() % 9 + 1;
		}
		
	}
	//-------------------------------------------------------*Рандом-------------------------------------------------------------------------//

	//-------------------------------------------------------*Перевод в int-------------------------------------------------------------------------//
	int toInt(){
		int result = 0;

		for (int i = length - 1; i >= 0; i--){
			result += digits[i] * pow(10, i);
		}

		return result;
	}
	//-------------------------------------------------------*Перевод в int-------------------------------------------------------------------------//
	
	//-------------------------------------------------------*Печать-------------------------------------------------------------------------//	
		void print(){
		for (int i = 0; i < length; i++){
			std::cout<<digits[length - i - 1];
		}
		std::cout<<std::endl;
	}
	//-------------------------------------------------------*Печать-------------------------------------------------------------------------//	
	
	//-------------------------------------------------------*Сравнение-------------------------------------------------------------------------//	
	
	int compareHuge(hugeInt a, hugeInt b){
		/*if (a.minus && !b.minus)
			return -1;
		if(!a.minus && b.minus)
			return 1;*/
		if(a.length > b.length) return 1;
		if(a.length < b.length) return -1;

	    for (int i = length - 1; i >= 0; i--  ){
			if(a.digits[i] < b.digits[i]) return -1;
			if(a.digits[i] > b.digits[i]) return 1;
		}
		return 0;
	}
	//-------------------------------------------------------*Сравнение-------------------------------------------------------------------------//	
	
	//-------------------------------------------------------*Оператор <= -------------------------------------------------------------------------//	
	bool operator  <= (hugeInt b){
		if (length < b.length)
			return true;
		if (length > b.length)
			return false;

		for (int i = length - 1; i >= 0; i--){
			if (digits[i] < b.digits[i])
				return true;
			else if(digits[i] > b.digits[i])
				return false;
		}
		return true;
	}
	//-------------------------------------------------------*Оператор <= -------------------------------------------------------------------------//	

	//-------------------------------------------------------*Оператор >= -------------------------------------------------------------------------//	
	bool operator  >= (hugeInt b){
		if (length < b.length)
			return false;
		if (length > b.length)
			return true;
		
		for (int i = length - 1; i >= 0; i--){
			if (digits[i] < b.digits[i])
				return false;
			else if(digits[i] > b.digits[i])
				return true;
		}
		return true;
	}
	//-------------------------------------------------------*Оператор >= -------------------------------------------------------------------------//	

	//-------------------------------------------------------*Оператор < -------------------------------------------------------------------------//	
	bool operator  < (hugeInt b){
		if (length < b.length)
			return true;
		if (length > b.length)
			return false;
		for (int i = length -1; i >= 0; i--){
			if (digits[i] > b.digits[i])
				return false;
			else if (digits[i] < b.digits[i])
				return true;
		}
		return false;
	}
	//-------------------------------------------------------*Оператор < -------------------------------------------------------------------------//	

		//-------------------------------------------------------*Оператор > -------------------------------------------------------------------------//	
	bool operator  > (hugeInt b){
		if (length < b.length)
			return false;
		if (length > b.length)
			return true;
		for (int i = length -1; i >= 0; i--){
			if (digits[i] > b.digits[i])
				return true;
			else if (digits[i] < b.digits[i])
				return false;
		}
		return false;
	}
	//-------------------------------------------------------*Оператор > -------------------------------------------------------------------------//	
		
	//-------------------------------------------------------*Оператор == -------------------------------------------------------------------------//	
	bool operator == (hugeInt b){
		if (minus != b.minus)
			return false;
		if (length != b.length)
			return false;
		for (int i = length - 1; i >= 0; i--)
			if (digits[i] != b.digits[i])
				return false;
		return true;
	}
	//-------------------------------------------------------*Оператор == -------------------------------------------------------------------------//	

	//-------------------------------------------------------*Оператор != -------------------------------------------------------------------------//	
	bool operator != (hugeInt b){
		if (length != b.length)
			return true;
		for (int i = length - 1; i >= 0; i--)
			if (digits[i] != b.digits[i])
				return true;
		return false;
	}
	//-------------------------------------------------------*Оператор != -------------------------------------------------------------------------//	

	//-------------------------------------------------------*Оператор != int -------------------------------------------------------------------------//	
	bool operator != (int b){
		if (length == 0)
			return true;
		int bLength = 0;
		int temp = b;
		do{
			b /= 10;
			bLength++;
		}while (b != 0);
		int* intDigits = new int[bLength];
		if (length != bLength)
			return true;

		int divisor = pow(10, bLength - 1);
		for (int i = 0; i < bLength; i++){
			intDigits[length - i - 1] = temp / divisor;
			if (digits[length - i - 1] != intDigits[length - i - 1])
				return true;
			temp -= intDigits[length - i - 1] * divisor;
			divisor /= 10;
		}
		return false;
	}
	//-------------------------------------------------------*Оператор != int -------------------------------------------------------------------------//	
	
	//-------------------------------------------------------*Оператор == int -------------------------------------------------------------------------//	
	bool operator == (int b){
		int bLength = 0;
		int temp = b;
		do{
			b /= 10;
			bLength++;
		}while (b != 0);
		int* intDigits = new int[bLength];
		if (length != bLength)
			return false;

		int divisor = pow(10, bLength - 1);
		for (int i = 0; i < bLength; i++){
			intDigits[length - i - 1] = temp / divisor;
			if (digits[length - i - 1] != intDigits[length - i - 1])
				return false;
			temp -= intDigits[length - i - 1] * divisor;
			divisor /= 10;
		}
		return true;
	}
	//-------------------------------------------------------*Оператор == int -------------------------------------------------------------------------//	

	//-------------------------------------------------------*Оператор = HugeInt -------------------------------------------------------------------------//	
	hugeInt operator = (hugeInt b){
		length = b.length;
		minus = b.minus;
		for (int i = 0; i < b.length; i++){
			digits[i] = 0;
			digits[i] = b.digits[i];
		}
		return *this;
	}
	//-------------------------------------------------------*Оператор = HugeInt-------------------------------------------------------------------------//

	//-------------------------------------------------------*Оператор = int -------------------------------------------------------------------------//	
	hugeInt operator = (int b){
		int bLength = 0;
		int temp = b;
		do{
			b /= 10;
			bLength++;
		}while (b != 0);
		int divisor = pow(10, bLength - 1);
		length = bLength;
		for (int i = 0; i < length; i++){
			digits[length - i - 1] = temp / divisor;
			temp -= digits[length - i - 1] * divisor;
			divisor /= 10;
		}
		return *this;
	}
	//-------------------------------------------------------*Оператор = int -------------------------------------------------------------------------//	
	
	
	//-------------------------------------------------------*Оператор +  -------------------------------------------------------------------------//	
	hugeInt operator + (hugeInt b){
		if (minus == b.minus){
		int newLength;
		if (compareHuge(*this, b) == 1)
			newLength = length + 1;
		else
			newLength = b.length + 1;

		hugeInt temp(newLength);
		
		hugeInt tempA(newLength);
		hugeInt tempB(newLength);

		for(int i = 0; i < newLength; i++){
			tempA.digits[i] = 0;
			tempB.digits[i] = 0;
		}
		for(int i = 0; i < b.length; i++)
			tempB.digits[i] = b.digits[i]; 
		for (int i = 0; i < length; i++)
			tempA.digits[i] = digits[i];

		for (int ix = 0; ix < newLength; ix++)
		{
			tempB.digits[ix] += tempA.digits[ix]; // суммируем последние разряды чисел
			tempB.digits[ix + 1] += (tempB.digits[ix] / 10); // если есть разряд для переноса, переносим его в следующий разряд
			tempB.digits[ix] %= 10; // если есть разряд для переноса он отсекается
		}
		tempB.length = newLength;
		if (tempB.digits[newLength - 1] == 0)
			tempB.length -= 1;
		tempB.minus = minus;
		return tempB;
		} else {
			if (compareHuge(*this, b) == 1){
				hugeInt result(length);
				hugeInt tempA(length);
				hugeInt tempB(length);
				bool min = minus;
				tempA = *this;
				tempB = b;
				tempA.minus = false;
				tempB.minus = false;
				result = tempA - tempB;
				result.minus = minus;
				return result;
			} else {
				hugeInt result(b.length);
				hugeInt tempA(b.length);
				hugeInt tempB(b.length);
				bool min = b.minus;
				tempA = *this;
				tempB = b;
				tempA.minus = false;
				tempB.minus = false;
				result = tempB - tempA;
				result.minus = min;
				return result;
			}
		}
	}
	//-------------------------------------------------------*Оператор + -------------------------------------------------------------------------//	

	//-------------------------------------------------------*Оператор - -------------------------------------------------------------------------//	
	hugeInt operator - (hugeInt b){
		int newLength;
		bool m = false;
		/*if (minus != b.minus){
			if(compareHuge(*this, b) == 1)
		}*/

		if (compareHuge(*this, b) == 1){
			newLength = length ;
		}else{
			newLength = b.length;
		}
		
		hugeInt result(newLength);
		hugeInt newA(length);
		hugeInt newB(newLength);

		for(int i = 0; i < newA.length; i++)
				newA.digits[i] = digits[i];
		for (int i = 0; i < newLength; i++){
			result.digits[i] = 0;
			newB.digits[i] = 0;
		}
		for (int i = 0; i < b.length; i++){
			newB.digits[i] = b.digits[i];
		}
		for (int ix = 0; ix < (newLength); ix++) // проход по всем разрядам числа, начиная с последнего, не доходя до первого
		{
			if (ix < (newLength - 1)) // если текущий разряд чисел не первый
			{
				newA.digits[ix + 1]--; // в следующуем разряде большего числа занимаем 1.
				result.digits[ix] += 10 + newA.digits[ix]; // в ответ записываем сумму значения текущего разряда большего числа и 10-ти
 
			} else	// если текущий разряд чисел - первый
				result.digits[ix] += newA.digits[ix]; // в ответ суммируем значение текущего разряда большего числа
 
			result.digits[ix] -= newB.digits[ix]; // вычитаем значение текущего разряда меньшего числа
 
			if (result.digits[ix] / 10 > 0) // если значение в текущем разряде двухразрядное
			{
				result.digits[ix + 1]++; // переносим единицу в старший разряд
				result.digits[ix] %= 10; // в текущем разряде отсекаем ее
			}
		}
			
		while (result.digits[result.length - 1] == 0)
			--result.length;
		if (result.length == 0){
			result.length = 1;
			result.digits[0] = 0;
		}
		return result;
	}
	//-------------------------------------------------------*Оператор - -------------------------------------------------------------------------//	

	//-------------------------------------------------------*Оператор * -------------------------------------------------------------------------//
	hugeInt operator*(hugeInt b){
	
		int newLength = length + b.length + 1;
		hugeInt result(newLength);
		hugeInt newB(newLength);
		if (minus && b.minus)
			result.minus = !minus;
		else if (!minus && !b.minus)
			result.minus = minus;
		else
			result.minus = true;

		for (int i = 0; i < newLength; i++){
			result.digits[i] = 0;
			newB.digits[i] = 0;
		}
		for (int i = 0; i < b.length; i++)
			newB.digits[i] = b.digits[i];


		for (int i=0;i<length;i++)
		{
			int r = 0;
			for (int j=0;j<b.length | r;j++)
			{
				result.digits[i+j] += digits[i] * newB.digits[j] + r;
				r = result.digits[i+j] / 10;
				result.digits[i+j] -= r * 10;
			}
		}
		while (result.digits[result.length - 1] == 0){
			--result.length;
			if (result.length == 0){
				result.length = 1;
				result.digits[0] = 0;
				break;
			}
		}

		return result;
	}
	//-------------------------------------------------------*Оператор * -------------------------------------------------------------------------//
	
	//-------------------------------------------------------*Оператор / -------------------------------------------------------------------------//	
	hugeInt operator / (hugeInt b)
	{
		hugeInt a(length);
		a = *this;
		hugeInt res(length);
		hugeInt curValue(length);
		hugeInt cur(length);

		hugeInt mm(1);
		hugeInt xx (1);
		hugeInt ten("10");

		for (int i = 0; i < res.length; i++){
			res.digits[i] = 0;
			curValue.digits[i] = 0;
			cur.digits[i] = 0;	
		}
		for (int i = a.length-1; i>=0; i--)
		 {
			curValue = curValue * ten;
			curValue.digits[0] = a.digits[i];
			// подбираем максимальное число x, такое что b * x <= curValue
			int x = 0;
			int l = 0, r = 10;
			while (l <= r)
			{
				int m = (l + r) >> 1;
				mm = m;
				/*for (int i = 0; i < cur.length; i++)
					cur.digits[i] = 0;*/
				cur = b * mm;
				if (cur <= curValue)
				{
					x = m;
					l = m+1;
				}
				else
					r = m-1;
			}
			res.digits[i] = x;
			xx = x;
			curValue = curValue - b * xx;
		}
		// избавляемся от лидирующих нулей
		int pos = a.length;
/*		while (pos>=0 && !res.digits[pos])
		pos--;
		res.length = pos+1;*/

		while (res.length != 0 && res.digits[res.length - 1] == 0)
			res.length --;
		if(res.length == 0){
			res.length = 1;
			res.digits[0] = 0;
		}
		
		if (minus && b.minus)
			res.minus = !minus;
		else if (!minus && !b.minus)
			res.minus = minus;
		else
			res.minus = true;

		return res;
	}
	//-------------------------------------------------------*Оператор / -------------------------------------------------------------------------//	
	
	//-------------------------------------------------------*Оператор % -------------------------------------------------------------------------//	
	hugeInt operator % (hugeInt b)
	{
		hugeInt a(length);
		a = *this;
		hugeInt res(length);
		hugeInt curValue(length);
		hugeInt cur(length);

		hugeInt mm(1);
		hugeInt xx (1);
		hugeInt ten("10");

		for (int i = 0; i < res.length; i++){
			res.digits[i] = 0;
			curValue.digits[i] = 0;
			cur.digits[i] = 0;	
		}
		for (int i = a.length-1; i>=0; i--)
		 {
			curValue = curValue * ten;
			curValue.digits[0] = a.digits[i];
			// подбираем максимальное число x, такое что b * x <= curValue
			int x = 0;
			int l = 0, r = 10;
			while (l <= r)
			{
				int m = (l + r) >> 1;
				mm = m;
				/*for (int i = 0; i < cur.length; i++)
					cur.digits[i] = 0;*/
				cur = b * mm;
				if (cur <= curValue)
				{
					x = m;
					l = m+1;
				}
				else
					r = m-1;
			}
			res.digits[i] = x;
			xx = x;
			curValue = curValue - b * xx;
		}

		curValue.minus = a.minus;
		return curValue;
	}
	//-------------------------------------------------------*Оператор % -------------------------------------------------------------------------//	
	

	//-------------------------------------------------------*Быстрое возведение в степень -------------------------------------------------------------------------//
	hugeInt power(hugeInt x, hugeInt n)
	{
		hugeInt result("1");
		hugeInt tempX(x.length * n.length);
		hugeInt tempN(n.length * x.length);

		hugeInt one("1");
		hugeInt two("2");

		tempX = x;
		tempN = n;

		while (tempN != 0)
		{
			if (tempN % two != 0)
			{
				result = result * tempX;
				tempN = tempN - one;
			}
		tempX = tempX * tempX;
		tempN = tempN / two;
    }
    return result;
}

	//-------------------------------------------------------*Быстрое возведение в степень -------------------------------------------------------------------------//

	
	//-------------------------------------------------------*Ввод-------------------------------------------------------------------------------//	
	void input(){
		std::string s;
		std::cin>>s;
		length = s.length();
		digits = new short[length];
		for (int i = 0; i < s.length(); i++){
			digits[i] = s[length - i - 1] - '0';
		}
	}
	//-------------------------------------------------------*Ввод-------------------------------------------------------------------------------//

	//-------------------------------------------------------*Возведение в степень по модулю----------------------------------------------------//	
	hugeInt powerMod(hugeInt b, hugeInt e, hugeInt m){
		hugeInt c(m.length * m.length);
		hugeInt tempB(m.length * m.length);
		hugeInt tempM(m.length);
		hugeInt tempE(e.length);
		hugeInt one("1");
		hugeInt two("2");

		c = 1;
		tempB = b;
		tempM = m;
		tempE = e;
		while (tempE != 0) {
			if (tempE % two == 0) {
				tempE = tempE / two;
				tempB = (tempB * tempB) % tempM; 
			}
			else {
				tempE = tempE - one;
				c = (c * tempB) % tempM; // [ b = (b*a)%n; ]
			}
		while (tempB.digits[tempB.length - 1] == 0)
			tempB.length--;
		}

		return c;
	}
	//-------------------------------------------------------*Возведение в степень по модулю-----------------------------------------------------//	

	//-------------------------------------------------------*Поиск простых чисел----------------------------------------------------//
	bool getPrimeNumber(int l){
		hugeInt n(l);
		//hugeInt s(l);
		hugeInt t(l);
		hugeInt a(l);
		hugeInt k(l);
		hugeInt x(l);
		hugeInt counter(l);
		hugeInt two("2");
		hugeInt one("1");
	    /*do{
			n.random(n.length);
		}while (n.prime());*/
		n = *this;
		t = n - one;
		int s = 0;

		while(t % two == 0)
		{
			t = t / two;
			s = s + 1;
		}

		for (int i = 0; i < l; i++)
		{
			do{
				a.random(rand() % l + 1);
			}while(a < two || a > n - two);
			
			x = powerMod(a, t, n);
			if (x == one || x == n - one)
				continue;

			for (int r = 1; r < s; r++)
			{
				x = powerMod(x, two, n);
				if (x == one)
					return false;
				if(x == n - one)
					break;
			}
			if (x != n - one)
				return false;
		}
		return true;
	}
	//-------------------------------------------------------*Поиск простых чисел----------------------------------------------------//	
		
	//-------------------------------------------------------*Проверка на четность----------------------------------------------------//	
	bool prime(){
		if (digits[0] % 2 == 0)
			return true;
		return false;
	}
	//-------------------------------------------------------*Проверка на четность----------------------------------------------------//	
};
	
class Key{
private:
	hugeInt n;
	hugeInt e;
	hugeInt d;
public:
	hugeInt getN(){
		return n;
	}
	hugeInt getE(){
		return e;
	}
	
	hugeInt getD(){
		return d;
	}
	//-------------------------------------------------------*Конструктор----------------------------------------------------//	
	Key(){

	}
	//-------------------------------------------------------*Конструктор----------------------------------------------------//	
	
	
	//-------------------------------------------------------*НОД по евклиду----------------------------------------------------//	
	 hugeInt nod(hugeInt a, hugeInt b){
		hugeInt tempA(a.getLength());
		hugeInt tempB(b.getLength());
		
		tempA = a;
		tempB = b;

		int newLength;
		if(tempA == 0 && tempB == 0){
			tempA = 1;
			return tempA;
		}

		if (tempA > tempB)
			newLength = tempB.getLength();
		else
			newLength = tempA.getLength();

		hugeInt r(newLength);
		do{
			r= tempA % tempB;
			tempA = tempB;
			tempB = r;
		}while (r != 0);
		return tempA;
	}
	
	//-------------------------------------------------------*НОД по евклиду----------------------------------------------------//	

	//-------------------------------------------------------*Финальное уравнение----------------------------------------------------//	
	hugeInt getE(hugeInt a, hugeInt b){
	hugeInt r(a.getLength());
  hugeInt q(a.getLength());
  hugeInt a11(a.getLength());
  hugeInt a12(a.getLength());  
  hugeInt a21(a.getLength());
  hugeInt a22(a.getLength());
  hugeInt y(a.getLength());
  

  hugeInt A11(a.getLength());
  hugeInt A12(a.getLength());
  hugeInt A21(a.getLength());
  hugeInt A22(a.getLength());
  
  hugeInt tempA(a.getLength());
  hugeInt tempB(b.getLength());

  tempA = a;
  tempB = b;

  a11 = 1;
  a12 = 0;
  a21 = 0;
  a22 = 1;


  while ( tempB > 0)
  {
    r = tempA % tempB;
    q = tempA / tempB;
    if (r == 0)
      break;

	q.setMinus(!q.getMinus());
    A11 = a12;
    A12 = a11+a12*q;
    A21 = a22;
    A22 = a21+a22*q;
	q.setMinus(!q.getMinus());

    a11 = A11, a12 = A12, a21 = A21, a22 = A22;


    tempA = tempB;
    tempB = r;
  }
  y = a22;
	return y;
	}

	//-------------------------------------------------------*Финальное уравнение----------------------------------------------------//	

	//-------------------------------------------------------*Кейген----------------------------------------------------//	
	void keyGen(char* publicPath, char* privatePath){
		hugeInt p(KEY_LENGTH / 2);
		hugeInt q(KEY_LENGTH / 2);
		hugeInt m(KEY_LENGTH);
		
		hugeInt one("1");
		std::cout<<"Generating private and public keys...\n";
		do{
			p.random(p.getLength());
		}while (!p.getPrimeNumber(p.getLength()));
		p.print();
		do{
			q.random(q.getLength());
		}while (!q.getPrimeNumber(q.getLength()));
		n = p * q;
		n.print();
		m = (p - one) * (q - one);
	
		do{
			d.random(KEY_LENGTH - 3);//разобраться с длиной!
		}while(d >= m || nod(m, d) != 1);
		e = getE(m,d);
		savePrivate(privatePath);
		savePublic(publicPath);
	}
	//-------------------------------------------------------*Кейген----------------------------------------------------//	
	void savePrivate(char* path){
		std::ofstream f(path, std::ofstream::binary);
		f<<'d';
		for (int i = 0; i < d.getLength(); i++){
			f<<d.getDigit(i);
		}
		f<<'n';
		for (int i = 0; i < n.getLength(); i++){
			f<<n.getDigit(i);
		}
		f<<"\0";
	}
	void savePublic(char* path){
		std::ofstream f(path, std::ofstream::binary);
		f<<'e';
		for (int i = 0; i < e.getLength(); i++){
			f<<e.getDigit(i);
		}
		f<<'n';
		for (int i = 0; i < n.getLength(); i++){
			f<<n.getDigit(i);
		}
		f<<"\0";
	}

	void readPrivate(char* path){
		std::ifstream f(path , std::ifstream::binary);
		f.seekg (0, f.end);
        int fileLength = f.tellg();
        f.seekg (0, f.beg);
		char* temp = new char[fileLength];		
		f.read(temp, fileLength);
		std::string buffer(temp,fileLength);

		int curPos = 1;
		int counter = 0;
		while (buffer[curPos] != 'n'){
			d.setDigits(counter, buffer[curPos] - '0'); 
			counter++;
			curPos++;
		}
		d.setLength(counter);
		curPos++;
		counter = 0;
		while (buffer[curPos]	 != '\0'){
			n.setDigits(counter, buffer[curPos] - '0');
			counter++;
			curPos++;
		}
		n.setLength(counter);
	}

	void readPublic(char* path){
		std::ifstream f(path, std::ifstream::binary);
		f.seekg (0, f.end);
        int fileLength = f.tellg();
        f.seekg (0, f.beg);
		char* temp = new char[fileLength];
		f.read(temp, fileLength);
		std::string buffer(temp,fileLength);
		int curPos = 1;
		int counter = 0;
		while (temp[curPos] != 'n'){
			e.setDigits(counter, buffer[curPos] - '0'); 
			counter++;
			curPos++;
		}
		e.setLength (counter);
		curPos++;
		counter = 0;
		while (buffer[curPos] != '\0'){
			n.setDigits(counter, buffer[curPos] - '0'); //здесь fstream считывает лишнее
			counter++;
			curPos++;
		}
		n.setLength(counter);
	}
	
};

void cryptFile(char* fileName, char* encFileName, char* pathToKey){
	std::ifstream toCrypt(fileName, std::ifstream::binary);
	std::ofstream crypted(encFileName, std::ifstream::binary);

	if (toCrypt.fail()){
		std::cout<<"Fail to open FIle"<<std::endl;
	} else {
	Key key;
	key.readPublic(pathToKey);
	hugeInt initialSymbol(50);
	hugeInt finishSymbol(50);
	
	toCrypt.seekg (0, toCrypt.end);
	int fileLength = toCrypt.tellg();
	toCrypt.seekg (0, toCrypt.beg);

	char* temp = new char[fileLength];
	toCrypt.read(temp, fileLength);
	
	std::string buffer(temp, fileLength);
	std::cout<<"Encrypting data...\n";
	for(int i = 0; i < fileLength; i++){
		initialSymbol = buffer[i]; 
		finishSymbol = initialSymbol.powerMod(initialSymbol, key.getE(), key.getN());
		for (int counter = 0; counter < finishSymbol.getLength(); counter++){
			crypted<<finishSymbol.getDigit(counter);
		}
		crypted<<'n';
	}
	}
}

void decryptFile(char* fileName, char* decFileName, char* pathToKey){
	std::ifstream toEncrypt(fileName, std::ifstream::binary);
	std::ofstream decrypted(decFileName, std::ifstream::binary);
	hugeInt initialSymbol(KEY_LENGTH);
	hugeInt decryptedSymbol(3);
	if(toEncrypt.fail()){
		std::cout<<"File opening error!\n";
	} else {
		Key key;
		key.readPrivate(pathToKey);

		char tempDigit;
		char stopper;
		char symbol;
		std::cout<<"Decrypting data...\n";
		for (;toEncrypt;){
			int counter = 0;
			toEncrypt.get(tempDigit);
			do {
				initialSymbol.setDigits(counter, tempDigit - '0');
				counter++;
				toEncrypt.get(tempDigit);
			}while(tempDigit != 'n');
			initialSymbol.setLength(counter);
			decryptedSymbol = initialSymbol.powerMod(initialSymbol, key.getD(), key.getN());
			symbol = decryptedSymbol.toInt();
			if (!toEncrypt.eof())
				decrypted<<symbol;
		}
	}

}



int main(int argc, char* argv[])
{
	if (argc == 3) {
		Key key;
		printf("%s",argv[1]);
		key.keyGen(argv[1], argv[2]);
	}
	
	if (argc == 5){
		if (argv[1][0] == 'e'){
			cryptFile(argv[2], argv[3], argv[4]);
		}
		if (argv[1][0] == 'd')
			decryptFile(argv[2], argv[3], argv[4]);

	}

	system("pause");
	return 0;
}

