#include <iostream>
#include "common.h"

using namespace std;


//�ݹ鷴ת��������
ListNode* reverse(ListNode* head) {
	if (head == nullptr || head->next == nullptr)
		return head;
	ListNode* last = reverse(head->next);
	head->next->next = head;
	head->next = nullptr;
	return last;
}

//�ݹ鷴ת������ǰn��

ListNode* splitNode = nullptr;
ListNode* reverse(ListNode* head, int n)
{
	if (n == 1) {
		splitNode = head->next;
		return head;
	}
	ListNode* last = reverse(head->next, n - 1);
	head->next->next = head;
	head->next = splitNode;
	return last;
}

//�ݹ鷴ת������[m,n]���֣�������1��ʼ

ListNode* splitNode = nullptr;
ListNode* reverseN(ListNode* head, int n)
{
	if (n == 1) {
		splitNode = head->next;
		return head;
	}
	ListNode* last = reverseN(head->next, n - 1);
	head->next->next = head;
	head->next = splitNode;
	return last;
}

ListNode* reverseBetween(ListNode* head, int m, int n)
{
	if (m == 1) {
		return reverseN(head, n);
	}
	head->next = reverseBetween(head->next, m - 1, n - 1);
	return head;
}