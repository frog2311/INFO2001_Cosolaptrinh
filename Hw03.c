#include <stdio.h>

int main() {
    int num_students;
    float total = 0.0;

    printf("Nhap so luong sinh vien trong lop: ");
    scanf("%d", &num_students);

    float scores[num_students];

    for (int i = 0; i < num_students; i++) {
        printf("Nhap diem cua sinh vien %d: ", i + 1);
        scanf("%f", &scores[i]);
        total += scores[i];
    }

    float average_score = total / num_students;

    printf("Diem trung binh cua lop la: %.2f\n", average_score);

    return 0;
}
