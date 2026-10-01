class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def mergeTwoLists(list1: ListNode | None, list2: ListNode | None) -> ListNode | None:
    dummy = ListNode(0)
    tail = dummy

    c1, c2 = list1, list2
    while c1 and c2:
        if c1.val <= c2.val:
            tail.next = c1
            c1 = c1.next
        else:
            tail.next = c2
            c2 = c2.next
        tail = tail.next

    tail.next = c1 if c1 else c2

    return dummy.next


def makeLinkedListFromArray(array: list[int]) -> ListNode | None:
    if not array:
        return None
    head = ListNode(array[0])
    curr = head
    for val in array[1:]:
        curr.next = ListNode(val)
        curr = curr.next

    return head


list1 = makeLinkedListFromArray([1, 2, 4])
list2 = makeLinkedListFromArray([1, 3, 4])

merged = mergeTwoLists(list1, list2)
while merged:
    print(merged.val, end=" -> ")
    merged = merged.next
print("None")
