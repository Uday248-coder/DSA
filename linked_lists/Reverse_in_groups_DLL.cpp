// https://www.geeksforgeeks.org/reverse-doubly-linked-list-groups-given-size/


// my tried implementation its wrong.
int size(Node* head){
	int c=0;
	while(head){
		c++;
		head=head->next;
	}
	return c;
}
Node* reverse(Node* head){
	Node* curr=head;
	Node* p=NULL;
	while(curr!=NULL){
		Node* next = curr->next;
		curr->next = curr->prev;
		curr->prev = next;
		p=curr;
		curr=next;
	}
	return p;
}
Node* Group_Reverse(Node* head, int k){
		if(size(head)<k){
			return reverse(head);
		}
  	Node* Grp_next=head;
		Node* end= head;
		int t = k;
		while(t-->0){
			Grp_next=Grp_next->next;
			end=end->next;
		}
		Grp_next = Group_Reverse(Grp_next->next,k);
		end->next = NULL;
		Node* Grp_prev = head->prev;
		head->prev = NULL:
		head = reverse(head);
		Grp_prev->next = head;
		head->prev = Grp_prev;
		end = head;
		while(end->next){
			end=end->next;
		}
		end->next = Grp_next;
		Grp_next->prev = end;
		return head;
}
