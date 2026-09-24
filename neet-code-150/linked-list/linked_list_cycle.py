class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


def hasCycle(head: ListNode | None) -> bool:
    seen_nodes = set()
    current = head
    while current:
        if current in seen_nodes:
            return True

        seen_nodes.add(current)
        current = current.next

    return False
