bool has_cycle(Node* head) {
    //Here I am using Floyd's cycle finding algorithm
    Node* slow=head;
    Node* fast=head;
    Node* temp=head;
    while(slow!=NULL && fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
        fast=fast->next;
         if(slow==fast){
            return true;
        }
    }
    return false;
}
