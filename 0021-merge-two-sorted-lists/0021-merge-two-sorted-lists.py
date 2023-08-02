# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution(object):
    def mergeTwoLists(self, list1, list2):
        """
        :type list1: Optional[ListNode]
        :type list2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        
        if not list1:
            return list2
        if not list2:
            return list1
        
        answer = dummy = ListNode()

        while list1 and list2:
            if list1.val <= list2.val:
                dummy.next = list1
                dummy = dummy.next
                list1 = list1.next
            else:
                dummy.next = list2
                dummy = dummy.next
                list2 = list2.next
        
        if list1 or list2:
            dummy.next = list1 if list1 else list2

        return answer.next