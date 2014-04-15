#include <stdio.h>
#include <stdlib.h>
#include "ini_parser.h"
#include <iostream>
void test1()
{
	using namespace qh;
	const char* ini_text= "a=1\nb=2\n"; 
	INIParser parser;
	if (!parser.Parse(ini_text, strlen(ini_text), "\n", "=")) {
		assert(false);
	}

	const std::string& a = parser.Get("a", NULL);
	assert(a == "1");
	delete &a;

	const std::string& bvalue = parser.Get("b", NULL);
	std::string b = bvalue;
	assert(b == "2");
	delete &bvalue;

	const std::string& c = parser.Get("c", NULL);
	assert(c == "");
	delete &c;
}

void test2()
{
	using namespace qh;
	const char* ini_text= "a=1||b=2||c=3"; 
	INIParser parser;
	if (!parser.Parse(ini_text, strlen(ini_text), "||", "=")) {
		assert(false);
	}

	const std::string& a = parser.Get("a", NULL);
	assert(a == "1");
	delete &a;

	const std::string& bvalue = parser.Get("b", NULL);
	std::string b = bvalue;
	assert(b == "2");
	delete &bvalue;

	const std::string& c = parser.Get("c", NULL);
	assert(c == "3");
	delete &c;
}

void test3()
{
	using namespace qh;
	const char* ini_text= "||||a:1||b:2||||c:3||||||"; 
	INIParser parser;
	if (!parser.Parse(ini_text, strlen(ini_text), "||", ":")) {
		assert(false);
	}

	const std::string& a = parser.Get("a", NULL);
	assert(a == "1");
	delete &a;

	const std::string& bvalue = parser.Get("b", NULL);
	std::string b = bvalue;
	assert(b == "2");
	delete &bvalue;

	const std::string& c = parser.Get("c", NULL);
	assert(c == "3");
	delete &c;
}
void test4()//多空格情况
{
	using namespace qh;
	const char* ini_text= "a=1\n\nb=22\n\n"; 
	INIParser parser;
	if (!parser.Parse(ini_text, strlen(ini_text), "\n", "=")) {
		assert(false);
	}

	const std::string& a = parser.Get("a", NULL);
	assert(a == "1");
	delete &a;

	const std::string& bvalue = parser.Get("b", NULL);
	std::string b = bvalue;
	assert(b == "22");
	delete &bvalue;

	const std::string& c = parser.Get("c", NULL);
	assert(c == "");
	delete &c;
}
void test5()//value多位的情况
{
	using namespace qh;
	const char* ini_text= "||||a:1||b:2||||c:3333"; 
	INIParser parser;
	if (!parser.Parse(ini_text, strlen(ini_text), "||", ":")) {
		assert(false);
	}

	const std::string& a = parser.Get("a", NULL);
	assert(a == "1");
	delete &a;

	const std::string& bvalue = parser.Get("b", NULL);
	std::string b = bvalue;
	assert(b == "2");
	delete &bvalue;

	const std::string& c = parser.Get("c", NULL);
	assert(c == "3333");
	delete &c;
}
void test6()//value多位的情况
{
	using namespace qh;
	INIParser parser;
	if (!parser.Parse("test1.ini", "||", "=")) {
		assert(false);
	}

	const std::string& a = parser.Get("a", NULL);
	assert(a == "1");
	delete &a;

	const std::string& bvalue = parser.Get("b", NULL);
	std::string b = bvalue;
	assert(b == "2");
	delete &bvalue;

	const std::string& c = parser.Get("c", NULL);
	assert(c == "3");
	delete &c;
}
void test7()//value多位的情况
{
	using namespace qh;
	INIParser parser;
	if (!parser.Parse("test2.ini","||", ":")) {
		assert(false);
	}

	const std::string& a = parser.Get("a", NULL);
	assert(a == "1");
	delete &a;

	const std::string& bvalue = parser.Get("b", NULL);
	std::string b = bvalue;
	assert(b == "2");
	delete &bvalue;

	const std::string& c = parser.Get("c", NULL);
	assert(c == "322");
	delete &c;
}
int main(int argc, char* argv[])
{
    //TODO 在这里添加单元测试，越多越好，代码路径覆盖率越全越好

	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	std::cout<<"测试用例均通过O(∩_∩)O~"<<std::endl;
    return 0;
}


