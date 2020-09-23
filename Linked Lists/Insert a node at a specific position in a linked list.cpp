/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    SinglyLinkedListNode* newnode= new SinglyLinkedListNode(data);
    //newnode->data=data;
    SinglyLinkedListNode* current=head;
    int counter=0;
    if(position==0){
        newnode->next=head;
        return newnode;
    }
    while(counter<position-1){
        current=current->next;
        counter++;
    }
    newnode->next=current->next;
    current->next=newnode;
    return head;
}
