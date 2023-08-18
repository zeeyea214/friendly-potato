/*给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *a,*b;
    int size1=1,size2=1;
    if(!headA||!headB)return NULL;
    for(a=headA;a->next!=NULL;a=a->next,size1++);
    for(b=headB;b->next!=NULL;b=b->next,size2++);
    a = headA;
    b = headB;
    for(int i = 0;i<size1-size2;i++,a=a->next);
    for(int i = 0;i<size2-size1;i++,b=b->next);
    for(;a&&b&&a!=b;a=a->next,b = b->next);
    return b;
}/*方案一前面栈的解法中提到，从后向前很容易查找，那么能不能从前向后呢？若是两链表等长，那自然是可以的，指针同步后移，当遇到公共结点时两指针就会相遇，但若链表不等长那就不行了，两个指针可能会指向不同的公共结点，也就无法确定一个结点是否是公共结点。

由此，我们可以想到，能不能把两个链表变成等长的链表呢？显然若两链表不等长，那么长的链表的前 n 个结点（n 是长链表比短链表多的结点数）显然不可能是公共结点。而剩余部分两链表是等长的，自然就可以按照顺序同步后移的方法查找公共结点。

不过，为确定两链表长度差，得先遍历两链表确定长度*/


/*方案二除了计算链表长度外，我们还可以利用 两链表长度和相等 的性质来使得两个遍历指针同步

具体做法是：先遍历其中一个链表，当到底末端后跳到另一链表，最后

若两链表没有公共结点，那么两个链表指针都会走过 s1+s2s_1 + s_2s 
1
​
 +s 
2
​
  个结点，同时到达两链表末尾
若有公共结点，由于最后会同时走到两链表终点，所以倒退回去，两个指针一定会在第一个公共结点处相遇
当然，若两链表等长，那确实不会跳到另一链表，不过链表等长本身指针就是同步的，同样也能找到公共结点
*/

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
        struct ListNode *p, *q;

        for (p = headA, q = headB; p != q; ){
            if (p != NULL)
                p = p->next;
            else p = headB;
            if (q != NULL)
                q = q->next;
            else q = headA;
        }

        return p;
}

