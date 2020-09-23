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
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    DoublyLinkedListNode* newnode= new DoublyLinkedListNode(data);
    newnode->next=NULL;
    newnode->prev=NULL;
    newnode->data=data;
    
    DoublyLinkedListNode* current=head;

    //to handle the null link list case
    if(head==NULL){
        head=newnode;
        return head;
    }

    //to handle the insertion in the begining case if data>current
    if(data<head->data){
        newnode->prev=NULL;
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
        return head;
    
    }

    while(data>current->data && current->next!=NULL){
        current=current->next;
    }
    //to handle the inserion in the last position id data>current

    if(current->next==NULL && data>current->data){
        newnode->prev=current;
        newnode->next=NULL;
        current->next=newnode;
        return head;
    }
    //to handle the usual case when data>current and insertion!=(begin or end)

        newnode->next=current;
        newnode->prev=current->prev;
            
        current=current->prev;
        current->next=newnode;

        current=current->next;
        current->prev=newnode;


    
    return head;

}
