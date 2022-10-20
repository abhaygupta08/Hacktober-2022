class Node
{
    int data;
    Node next;
    
    Node(int x){
        data = x;
        next = null;
    }
}

class Solution {
    public static Node moveToFront(Node head) {
        
        if(head == null){
            return null;
        }
        
        if(head.next == null){
            return head;
        }
        
        Node tmp= head;
        while(tmp.next.next != null){
            tmp= tmp.next;
        }
        
        Node newHead = tmp.next;
        tmp.next.next = head;
        tmp.next = null;
        
        return newHead;       
    }
}