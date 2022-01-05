//
//  day8_2~5_LinkedList.c
//  day8_2~5_LinkedList
//
//  Created by 雨轩 on 2022/1/5.
//

#include "LinkedList.h"

int main(int argc, const char * argv[]) {
    node *head = (node*)malloc(sizeof(node));
    head->next = NULL;
    head->val = 0;
    LinkedList(head);
    return 0;
}
