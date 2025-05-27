class ListNode {
    var val: Int
    var next: ListNode?
    init(_ val: Int) { self.val = val; self.next = nil }
}

func reverse(_ head: ListNode?) -> ListNode? {
    var prev: ListNode? = nil
    var current = head
    while current != nil {
        let next = current?.next
        current?.next = prev
        prev = current
        current = next
    }
    return prev
}

func isPalindrome(_ head: ListNode?) -> Bool {
    var slow = head, fast = head
    while fast?.next != nil && fast?.next?.next != nil {
        slow = slow?.next
        fast = fast?.next?.next
    }
    var second = reverse(slow?.next)
    var first = head
    while second != nil {
        if first?.val != second?.val { return false }
        first = first?.next
        second = second?.next
    }
    return true
}
