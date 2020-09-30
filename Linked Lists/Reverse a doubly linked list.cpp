/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
    DoublyLinkedListNode* temp=head;
    DoublyLinkedListNode* new_head=head;
    DoublyLinkedListNode* previous_pointer=NULL;
    while(temp!=NULL){
        previous_pointer=temp->prev;
        temp->prev=temp->next;
        temp->next=previous_pointer;
        new_head=temp;
        temp=temp->prev;
    }
    return new_head;
}
