// https://www.geeksforgeeks.org/reverse-doubly-linked-list-groups-given-size/


Node* Group_Reverse(Node* head, int k){
	if(!head)
		return head;
	Node* curr = head;
	Node* newHead = NULL;
	Node* tail = NULL;
	int count=0;

	while(curr!= NULL){
		Node* grp_head = curr;
		Node* prev = NULL;
		Node* next = NULL;
		int count =0;
		while(curr!=NULL && count <k){
			next = curr->next;
			curr->next = prev;
			curr->prev = NULL;
			if(prev){
				prev->prev = curr;
			}
			prev = curr;
			curr=next;
			count++;
		}
		if(!newHead){
			newHead = prev;
		}
		if(tail){
			tail->next = prev;
			prev->prev = tail;
		}
		tail =grp_head;
	}
	return newHead;
}
