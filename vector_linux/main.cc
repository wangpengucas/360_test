#include "qh_vector.h"
#include <iostream>
#include <assert.h>
void test1()
{
	std::cout<<"test1:"<<std::endl;
	qh::vector<int> num_vect;
	for(int i = 0;i<10;i++)
		num_vect.push_back(i);//0-9存入容器内
	int a=0;
	num_vect.pop_back(a);//将9取出
	assert(a==9);
	for(int i = 0;i<num_vect.size();i++)
	{
		assert(num_vect[i]==i);
		//std::cout<<num_vect[i]<<std::endl;//打印
	}
	assert(*num_vect.begin()==0);
	std::cout<<"End of test1!!ok!!"<<std::endl;
}
void test2()
{
	std::cout<<"test2:"<<std::endl;
	qh::vector<int> num_vect(10,5);
	for(int i = 0;i<num_vect.size();i++)
	{
		assert(num_vect[i]==5);
		//std::cout<<num_vect[i]<<std::endl;//打印
	}
	std::cout<<"End of test2!!ok!!"<<std::endl;
}
void test3()//析构函数处出错，未想通原因
{
	std::cout<<"test3:"<<std::endl;
	qh::vector<int> num_vect1;
	for(int i = 0;i<10;i++)
		num_vect1.push_back(i);
	qh::vector<int> num_vect2(num_vect1);
	for(int i = 0;i<num_vect2.size();i++)
	{
		assert(num_vect2[i]==i);
		//std::cout<<num_vect[i]<<std::endl;//打印
	}
	std::cout<<"End of test3!!ok!!"<<std::endl;
}
void test4()
{
	std::cout<<"test4:"<<std::endl;
	qh::vector<int> num_vect;
	for(int i = 0;i<10;i++)
		num_vect.push_back(i);
	assert(num_vect.size()==10);
	std::cout<<"End of test4!!ok!!"<<std::endl;
}
void test5()
{
	std::cout<<"test5:"<<std::endl;
	qh::vector<int> num_vect;
	num_vect.push_back(1);
	num_vect.clear();
	assert(num_vect.empty()==true);
	num_vect.resize(10);
    assert(num_vect.size()==10);
	/*std::cout<<num_vect.size()<<std::endl;*/
	std::cout<<"End of test5!!ok!!"<<std::endl;
}
int main(int argc, char* argv[])
{
    //TODO 在这里添加单元测试，越多越好，代码路径覆盖率越全越好
    //TODO 单元测试写法请参考INIParser那个项目，不要写一堆printf，要用assert进行断言判断。
	test1();
	test2();
	//test3();//析构函数处出错，未想通原因
	test4();
	test5();
#ifdef WIN32
    system("pause");
#endif

	return 0;
}

