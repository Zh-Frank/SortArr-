/**********************************************
�Զ�ά�������ð������
��ά�������ڴ������������е�
���Կ��Խ���ά���鿴��һ�����һά����
һά���鵽��ά�����±��Ӧ��ϵΪ
b[pos] ------> a[i][j]
pos / col = i	; 	pos % col = j
**********************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
void sort(int a[][5], int n = 4)
{
	//ֱ�ӶԶ�ά�����������
	for (int i = 0; i < n * 5 - 1; ++i)
	{
		for (int j = 0; j < n * 5 - i - 1; ++j)
		{
			if (a[j / 5][j % 5] > a[(j + 1) / 5][(j + 1) % 5])
			{
				swap(a[j / 5][j % 5], a[(j + 1) / 5][(j + 1) % 5]);
			}
		}
	}
	/*************************************************
	//�ڶ��ַ����Ƚ���ά����ת����һ��һά������
	//���ַ����Ƚ�ֱ�ۣ����Ƕ���һ������
	int *b = new int[5 * n];
	//����ע�͵Ĵ�pos������Ƕ�ά������һά����֮�䲻��Ҫ���������ת����ʽ
	//int pos = 0;
	for(int i = 0; i != n; ++i)
		for(int j = 0; j != 5; ++j)
			b[i * 5 + j] = a[i][j];
			//b[pos++] = a[i][j];
	//��һά��������
	for(int i = 0; i != 5 * n - 1; ++i)
		for(int j = 0; j != 5 * n - 1 - i; ++j)
			if(b[j] > b[j + 1])
				swap(b[j], b[j + 1]);
	//��һά�������ݻش浽��ά����
	//pos = 0;
	//for(int i = 0; i != n; ++i)
	//	for(int j = 0; j != 5; ++j)
	//		a[i][j] = b[pos++];
	for(int i = 0; i != 5 * n; ++i)
		a[i / 5][i % 5] = b[i];
	delete []b;		//�ͷ��ڴ�
	*********************************************/
}
void print(int a[][5], int n = 4)
{
	for (int i = 0; i != n; ++i)
	{
		for (int j = 0; j != 5; ++j)
			cout << a[i][j] << '\t';
		cout << endl;
	}
}

int main()
{
	cout << "��ά��������" << endl;
	int a[4][5];
	srand(static_cast<unsigned int>(time(0)));
	for (int i = 0; i != 4; ++i)
		for (int j = 0; j != 5; ++j)
			a[i][j] = rand() % 100;
	sort(a);
	print(a);
	system("pause");
	return 0;
}
