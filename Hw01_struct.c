#include <stdio.h>

#define MAX_STUDENTS 100

struct Student {
    char name[50];
    int id;
    int age;
    float gpa;
};

int main() {
    struct Student students[MAX_STUDENTS]; 
    int numStudents = 0; 
    int choice;
    do {
        printf("1. Nhap thong tin sinh vien\n");
        printf("2. Hien thi danh sach sinh vien\n");
        printf("3. Cap nhat thong tin sinh vien\n");
        printf("0. Thoat\n");
        printf("Chon mot so: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
    int numToAdd;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &numToAdd);

    if (numStudents + numToAdd <= MAX_STUDENTS) {
        for (int i = 0; i < numToAdd; i++) {
            printf("Nhap thong tin sinh vien %d:\n", numStudents + i + 1);
            printf("Ten: ");
            scanf("%s", students[numStudents + i].name);
            printf("Nhap ma so: ");
            scanf("%d", &students[numStudents + i].id);
            printf("Tuoi: ");
            scanf("%d", &students[numStudents + i].age);
            printf("GPA: ");
            scanf("%f", &students[numStudents + i].gpa);
        }
        numStudents += numToAdd;
    } else {
        printf("Khong du cho trong trong danh sach sinh vien.\n");
    }
    break;
            case 2:
    printf("Danh sach sinh vien:\n");
        for (int i = 0; i < numStudents; i++) {
            printf("Sinh vien %d:\n", i + 1);
            printf("Ten: %s\n", students[i].name);
            printf("Ma so: %d\n", students[i].id);
            printf("Tuoi: %d\n", students[i].age);
            printf("GPA: %.2f\n", students[i].gpa);
        }
                break;
            case 3:
    int studentId;
    printf("Nhap ma so sinh vien: ");
    scanf("%d", &studentId);
    
    int index = -1; 
    for (int i = 0; i < numStudents; i++) {
        if (students[i].id == studentId) {
            index = i;
            break;
        }
    }
    
    if (index != -1) {
        printf("Nhap thong tin cap nhat cho sinh vien voi ma so %d:\n", studentId);
        printf("Ten: ");
        scanf("%s", students[index].name);
        printf("Tuoi: ");
        scanf("%d", &students[index].age);
        printf("GPA: ");
        scanf("%f", &students[index].gpa);
    } else {
        printf("Ma so sinh vien khong hop le.\n");
    }
    break;
            case 0:
                printf("Da thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }

        printf("\n");
    } while (choice != 0);

    return 0;
}
