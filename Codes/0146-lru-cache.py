'''
Author: LetMeFly
Date: 2023-09-24 13:04:45
LastEditors: LetMeFly
LastEditTime: 2023-09-24 15:20:51
'''
class LRU_Node:
    
    def __init__(self, previous, next, key, value):
        self.previous = previous
        self.next = next
        self.key = key
        self.value = value


class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.head = LRU_Node(None, None, 0, 0)
        self.tail = LRU_Node(self.head, None, 0, 0)
        self.head.next = self.tail
        self.ma = dict()
    

    def move2first(self, thisNode: LRU_Node):
        thisNode.previous.next = thisNode.next
        thisNode.next.previous = thisNode.previous
        
        thisNode.previous = self.head
        thisNode.next = self.head.next
        self.head.next = thisNode
        thisNode.next.previous = thisNode


    def get(self, key: int) -> int:
        if key in self.ma:
            self.move2first(self.ma[key])
            return self.ma[key].value
        return -1


    def put(self, key: int, value: int) -> None:
        if key in self.ma:
            thisNode = self.ma[key]
            thisNode.value = value
            self.move2first(thisNode)
        else:
            thisNode = LRU_Node(self.head, self.head.next, key, value)
            self.ma[key] = thisNode
            self.head.next = thisNode
            thisNode.next.previous = thisNode
            if len(self.ma) > self.capacity:
                toRemove = self.tail.previous
                del self.ma[toRemove.key]
                toRemove.previous.next = self.tail
                self.tail.previous = toRemove.previous


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)

def test(op, val):
    lru = LRUCache(val[0][0])
    for i in range(1, len(op)):
        if op[i] == "get":
            print(lru.get(val[i][0]))
        else:
            lru.put(val[i][0], val[i][1])
        print(lru.ma)


def test1():
    op = ["LRUCache","put","put","get","put","get","put","get","get","get"]
    val = [[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
    test(op, val)


if __name__ == '__main__':
    test1()
