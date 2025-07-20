#include <stdio.h>
#include <stdlib.h>

// !类型定义
/*
	1.自定义数据类型(typedef)
	  C语言提供了一个叫做typedef的功能来声明一个已有的数据类型的新名字。比如:
	  typedef int Length;
	  使得Length 成为int类型的别名。
	  这样，Length这个名字就可以代替int出现在变量定义和参数声明的地方了：
	  Length a, b, len;
	  Length numbers[10];
	2.Typedef
	  声明新的类型的名字
	  新的名字是某种类型的别名
	  改善了程序的可读性
	  typedef long int64_t;		//! 重载已有的类型名字新名字的含义更清晰具有可移植性
	  typedef struct ADate {
		  int month;
		  int day;
		  int year;
		  };Date;				//! Data->struct ADate,简化了复杂的名字
	  int64_t i = 100000000000;
	  Date d = [9, 1, 2005];
*/

#define LEN sizeof(struct Student)

// 定义链表节点结构体
struct Student
{
	long num;			  // 学号
	float score;		  // 成绩
	struct Student *next; // 指向下一个节点的指针
};

int n; // 记录节点个数，这里保持原代码全局变量的方式，也可优化为局部变量通过指针传递

// 创建动态链表的函数
struct Student *creat(void)
{
	struct Student *head = NULL; // 头指针，初始化为空
	struct Student *p1, *p2;	 // p1 用于指向新创建的节点，p2 用于指向当前链表的尾节点
	n = 0;						 // 初始化节点计数

	// 动态分配第一个节点的内存
	p1 = p2 = (struct Student *)malloc(LEN);
	if (p1 == NULL)
	{ // 检查内存分配是否成功
		printf("内存分配失败！\n");
		return NULL;
	}
	scanf("%ld,%f", &p1->num, &p1->score); // 输入第一个学生的学号和成绩

	// 循环创建节点，直到输入学号为 0 结束
	while (p1->num != 0)
	{
		n++; // 节点个数加 1
		if (n == 1)
		{
			head = p1; // 第一个节点，让头指针指向它
		}
		else
		{
			p2->next = p1; // 不是第一个节点，将新节点连接到链表尾部
		}
		p2 = p1; // 更新尾节点指针，使其指向当前最后一个节点

		// 动态分配下一个节点的内存
		p1 = (struct Student *)malloc(LEN);
		if (p1 == NULL)
		{ // 检查内存分配是否成功
			printf("内存分配失败！\n");
			// 若内存分配失败，处理已分配的节点，避免内存泄漏（简单示例中可简化处理）
			return head;
		}
		scanf("%ld,%f", &p1->num, &p1->score); // 输入下一个学生的信息
	}
	p2->next = NULL; // 将链表最后一个节点的 next 置为 NULL，标记链表结束
	return head;	 // 返回头指针，通过头指针可访问整个链表
}

// 遍历输出链表内容的函数（可选，用于验证链表创建结果）
void printList(struct Student *head)
{
	struct Student *p = head;
	while (p != NULL)
	{
		printf("学号：%ld，成绩：%.1f\n", p->num, p->score);
		p = p->next;
	}
}

int main()
{
	struct Student *head = creat(); // 调用创建链表函数
	printList(head);				// 输出链表内容

	// 注意：实际使用完链表后，应编写释放内存的函数来释放动态分配的节点，避免内存泄漏
	// 这里简单示例可省略，复杂场景务必添加内存释放逻辑
	return 0;
}