
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not (l1 or l2):
            return None
        if not l1:
            return l2
        if not l2:
            return l1
        if l1.val > l2.val:
            curr = l2
            l2 = l2.next
        else:
            curr = l1
            l1 = l1.next
        head = curr
        while l1 and l2:
            if l1.val > l2.val:
                curr.next = l2
                l2 = l2.next
            else:
                curr.next = l1
                l1 = l1.next
            curr = curr.next
        if l1:
            curr.next = l1
        elif l2:
            curr.next = l2
        return head
