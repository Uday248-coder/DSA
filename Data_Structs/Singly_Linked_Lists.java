// singly linked list in java!
class LL{
    Node head;
    Node tail;
    int size;

    LL(){
        this.size=0;
    }
    
    private class Node{
        int data;
        Node next;
    
        Node(int val){
            this.data=val;
        }
        Node(int val,Node x){
            this.data=val;
            this.next=x;
        }
    }

    Node find(int val){ // to return the Node holding a certain value
        Node temp=head;
        while(temp!=null){
            if(temp.data == val)
                return temp;
            temp=temp.next;
        }
        return null; // if that valu doesnt exist in the list itself .. 
    }
    Node get(int index){ // to return the pointer to a certain node at index 
        if(index>=size)
            return null;
        Node temp=head;
        for(int i=0;i<index;i++)
            temp=temp.next;
        return temp;

    }

    void display(){
        Node temp = head;
        while(temp!=null){
            System.out.print(temp.data+" -> ");
            temp=temp.next;
        }
        System.out.println("End");
    }

    void insertionFirst(int val){
        Node curr=new Node(val);
        curr.next = head;
        if(tail==null)
            tail=curr;
        head = curr;
        size++;
    }
    void deletionFirst(){
        if(head==null)
            return;
        head = head.next;
        size--;
    }
    /*
    void insertion(Node curr, int data){
        Node n=new Node(data);
        Node temp=curr.next;
        curr.next=n;
        n.next=temp;
        if(curr == tail)
            tail=curr.next;
        size++;
    }
    void deletion(Node prev, Node curr){
        if(tail==curr)
            tail=prev;
        prev.next = curr.next;
        size--;
    }
    */
    void insertion(int val, int ind){
        if(ind==0){
            insertionFirst(val);
            return;
        }
        else if(ind == size-1){
            insertionlast(val);
            return;
        }
        Node prev = get(ind-1);
        Node x=new Node(val);
        x.next=prev.next;
        prev.next=x;
        size++;
    }
    void deletion(int ind){
        if(ind==0){
            deletionFirst();
            return;
        }
        else if(ind==size-1){
            deletionLast();
            return;
        }
        
        Node prev=get(ind-1);
        // prev.next=get(ind+1); // can be done but calls that function again
        prev.next=prev.next.next;
        size--;
    }
    void insertionlast(int val){
        if(tail==null)
            insertionFirst(val);
        else{
            Node curr=new Node(val);
            tail.next = curr;
            tail = curr;
            size++;
        }
    }
    void deletionLast(){
        if(size<=1){
            deletionFirst();
            return;
        }
        Node secondLast = get(size -2);
        tail=secondLast;
        tail.next=null;
        size--;
    }
}
