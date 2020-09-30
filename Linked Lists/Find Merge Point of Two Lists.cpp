/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* check1=head1;
    SinglyLinkedListNode* check2=head2;
    SinglyLinkedListNode* temp=head2;
    int length1=0, length2=0;
    while(check1!=NULL){
        length1++;
        check1=check1->next;
    }
    while(check2!=NULL){
        length2++;
        check2=check2->next;
    }
    for(int i=0; i<length1; i++){
        head2=temp;
        for(int j=0; j<length2; j++){
            if(head1==head2){
                return head1->data;
            }
            head2=head2->next;
        }
        head1=head1->next;
    }
    return -1;

}
