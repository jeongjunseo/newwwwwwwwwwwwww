#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Element;

int compare(const void* a, const void* b) {
    return ((Element*)a)->value - ((Element*)b)->value;
}

int main() {
    int N;
    scanf("%d", &N);

    int* num = (int*)malloc(sizeof(int) * N);
    Element* elements = (Element*)malloc(sizeof(Element) * N);
    int* rank = (int*)malloc(sizeof(int) * N);

    // num �迭 �Է� �� elements �迭 �ʱ�ȭ
    for (int i = 0; i < N; i++) {
        scanf("%d", &num[i]);
        elements[i].value = num[i];
        elements[i].index = i;
    }

    // elements �迭 ����
    qsort(elements, N, sizeof(Element), compare);

    // rank �迭 ���
    int current_rank = 0;
    for (int i = 0; i < N; i++) {
        if (i > 0 && elements[i].value != elements[i - 1].value) {
            current_rank++;
        }
        rank[elements[i].index] = current_rank;
    }

    // ��� ���
    for (int i = 0; i < N; i++) {
        printf("%d ", rank[i]);
    }

    free(num);
    free(elements);
    free(rank);

    return 0;
}