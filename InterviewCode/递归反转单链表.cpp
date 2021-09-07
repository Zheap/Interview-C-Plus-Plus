#include <iostream>
#include "common.h"

using namespace std;


//递归反转整个链表
ListNode* reverse(ListNode* head) {
	if (head == nullptr || head->next == nullptr)
		return head;
	ListNode* last = reverse(head->next);
	head->next->next = head;
	head->next = nullptr;
	return last;
}

//递归反转链表中前n个

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

//递归反转链表中[m,n]部分，索引从1开始

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