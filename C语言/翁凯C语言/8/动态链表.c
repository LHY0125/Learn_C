#include <stdio.h>
#include <stdlib.h>

// !���Ͷ���
/*
	1.�Զ�����������(typedef)
	  C�����ṩ��һ������typedef�Ĺ���������һ�����е��������͵������֡�����:
	  typedef int Length;
	  ʹ��Length ��Ϊint���͵ı�����
	  ������Length������־Ϳ��Դ���int�����ڱ�������Ͳ��������ĵط��ˣ�
	  Length a, b, len;
	  Length numbers[10];
	2.Typedef
	  �����µ����͵�����
	  �µ�������ĳ�����͵ı���
	  �����˳���Ŀɶ���
	  typedef long int64_t;		//! �������е��������������ֵĺ�����������п���ֲ��
	  typedef struct ADate {
		  int month;
		  int day;
		  int year;
		  };Date;				//! Data->struct ADate,���˸��ӵ�����
	  int64_t i = 100000000000;
	  Date d = [9, 1, 2005];
*/

#define LEN sizeof(struct Student)

// ��������ڵ�ṹ��
struct Student
{
	long num;			  // ѧ��
	float score;		  // �ɼ�
	struct Student *next; // ָ����һ���ڵ��ָ��
};

int n; // ��¼�ڵ���������ﱣ��ԭ����ȫ�ֱ����ķ�ʽ��Ҳ���Ż�Ϊ�ֲ�����ͨ��ָ�봫��

// ������̬����ĺ���
struct Student *creat(void)
{
	struct Student *head = NULL; // ͷָ�룬��ʼ��Ϊ��
	struct Student *p1, *p2;	 // p1 ����ָ���´����Ľڵ㣬p2 ����ָ��ǰ�����β�ڵ�
	n = 0;						 // ��ʼ���ڵ����

	// ��̬�����һ���ڵ���ڴ�
	p1 = p2 = (struct Student *)malloc(LEN);
	if (p1 == NULL)
	{ // ����ڴ�����Ƿ�ɹ�
		printf("�ڴ����ʧ�ܣ�\n");
		return NULL;
	}
	scanf("%ld,%f", &p1->num, &p1->score); // �����һ��ѧ����ѧ�źͳɼ�

	// ѭ�������ڵ㣬ֱ������ѧ��Ϊ 0 ����
	while (p1->num != 0)
	{
		n++; // �ڵ������ 1
		if (n == 1)
		{
			head = p1; // ��һ���ڵ㣬��ͷָ��ָ����
		}
		else
		{
			p2->next = p1; // ���ǵ�һ���ڵ㣬���½ڵ����ӵ�����β��
		}
		p2 = p1; // ����β�ڵ�ָ�룬ʹ��ָ��ǰ���һ���ڵ�

		// ��̬������һ���ڵ���ڴ�
		p1 = (struct Student *)malloc(LEN);
		if (p1 == NULL)
		{ // ����ڴ�����Ƿ�ɹ�
			printf("�ڴ����ʧ�ܣ�\n");
			// ���ڴ����ʧ�ܣ������ѷ���Ľڵ㣬�����ڴ�й©����ʾ���пɼ򻯴���
			return head;
		}
		scanf("%ld,%f", &p1->num, &p1->score); // ������һ��ѧ������Ϣ
	}
	p2->next = NULL; // ���������һ���ڵ�� next ��Ϊ NULL������������
	return head;	 // ����ͷָ�룬ͨ��ͷָ��ɷ�����������
}

// ��������������ݵĺ�������ѡ��������֤�����������
void printList(struct Student *head)
{
	struct Student *p = head;
	while (p != NULL)
	{
		printf("ѧ�ţ�%ld���ɼ���%.1f\n", p->num, p->score);
		p = p->next;
	}
}

int main()
{
	struct Student *head = creat(); // ���ô���������
	printList(head);				// �����������

	// ע�⣺ʵ��ʹ���������Ӧ��д�ͷ��ڴ�ĺ������ͷŶ�̬����Ľڵ㣬�����ڴ�й©
	// �����ʾ����ʡ�ԣ����ӳ����������ڴ��ͷ��߼�
	return 0;
}