# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if not head:
            return False
        
        stack = []
        pointer = head

        while pointer:
            stack.append(pointer.val)
            pointer = pointer.next
        
        pointer = head

        while pointer:
            if not stack:
                return False
            
            if pointer.val != stack[-1]:
                return False
            else:
                stack.pop()
                pointer = pointer.next
            
        return not stack



            