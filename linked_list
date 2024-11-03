//연결 리스트를 사용하여 학생의 이름과 점수를 저장하는 코드

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 학생 정보를 저장하는 노드 구조체 정의
struct Node {
    char name[50];
    int score;
    struct Node* next;
};

// 노드 추가 함수
void addNode(struct Node** head, char* name, int score) {
    struct Node* newNode = malloc(sizeof(struct Node));
    strcpy(newNode->name, name);   // 학생 이름 복사
    newNode->score = score;        // 점수 설정
    newNode->next = *head;
    *head = newNode;
}

// 리스트 출력 함수
void printList(struct Node* head) {
    while (head) {
        printf("Name: %s, Score: %d\n", head->name, head->score);
        head = head->next;
    }
}

int main() {
    struct Node* head = NULL;

    // 여러 학생 추가
    addNode(&head, "Alice", 85);
    addNode(&head, "Bob", 90);
    addNode(&head, "Charlie", 78);

    // 리스트 출력
    printList(head);

    return 0;
}
