#include "qh_vector.h"
int main(int argc, char* argv[])
{
    //TODO ��������ӵ�Ԫ���ԣ�Խ��Խ�ã�����·��������ԽȫԽ��
    //TODO ��Ԫ����д����ο�INIParser�Ǹ���Ŀ����Ҫдһ��printf��Ҫ��assert���ж����жϡ�

    qh::vector<int> num_vect;
	num_vect.push_back(1);
	num_vect.clear();
	std::cout<<num_vect.empty();
#ifdef WIN32
    system("pause");
#endif

	return 0;
}

