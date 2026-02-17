#include <iostream>
// using namespace std;

#define LENGTH 10

int g = 10; // globális 

int main() {

	// kiiratás
	std::cout << "Hello World";
	std::cout << "a" << " " <<"b" << "c" << std::endl;

	// változók típusai
	char a = 'c';
	int i = 0;
	short int si = 1;
	long int li = 50;
	float f = 10.2;
 	double d = 10.2;
	bool b = false;
	
	// változók mérete
	std::string s = "abc";
	std::cout << s.size();
	std::cout << "char: " << sizeof(char) << std::endl;
	std::cout << "int: " << sizeof(int) << std::endl;
	std::cout << "short int: " << sizeof(short int) << std::endl;
	std::cout << "long int: " << sizeof(long int) << std::endl;
	std::cout << "float: " << sizeof(float) << std::endl;
	std::cout << "double: " << sizeof(double) << std::endl;
	std::cout << "bool: " << sizeof(bool) << std::endl;

	// változó létrehozása
	int z1 = 1, z2 = 2;
	char x, y;
	int n;
	std::cout << x << " " << y << " " << n << std::endl;

	// komment
	/*
		test
	*/

	typedef int egesz;
	egesz e = 0; 
	std::cout << g << std::endl;

	// globális és lokális változók (3. sor)	
	{
		std::cout <<g <<std::endl;
		int g = 5;
		std::cout <<g <<std::endl;
		
	}

	std::cout << g << std::endl;

	const int width = 11;

	// operatáorok +, -, *, /, %, ++, --
	// 3 féle operátor: - unáris: ++ --
	// 					- dináris: + - * / %
	// 					- ternáris: ?:
	
	// ++ increment, -- decrease
	int mod = 10 % 3;
	std::cout << mod <<std::endl;
	std::cout << ++mod << std::endl;
	std::cout << mod++ << std::endl;
	std::cout << mod << std::endl;	
}
