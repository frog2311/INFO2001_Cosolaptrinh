#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    char name[50];
    int id;
    int age;
    float gpa;
};

void sortStudentsByName(struct Student students[], int numStudents) {
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = i + 1; j < numStudents; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                struct Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void sortStudentsByGPA(struct Student students[], int numStudents) {
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = i + 1; j < numStudents; j++) {
            if (students[i].gpa < students[j].gpa) {
                struct Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void searchStudentsByName(struct Student students[], int numStudents, const char* name) {
    int found = 0;
    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Sinh vien %d:\n", i + 1);
            printf("Ten: %s\n", students[i].name);
            printf("Ma so: %d\n", students[i].id);
            printf("Tuoi: %d\n", students[i].age);
            printf("GPA: %.2f\n", students[i].gpa);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien co ten \"%s\".\n", name);
    }
}

void searchStudentsById(struct Student students[], int numStudents, int id) {
    int found = 0;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].id == id) {
            printf("Sinh vien %d:\n", i + 1);
            printf("Ten: %s\n", students[i].name);
            printf("Ma so: %d\n", students[i].id);
            printf("Tuoi: %d\n", students[i].age);
            printf("GPA: %.2f\n", students[i].gpa);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien co ID "%d\".\n", id);
    }
}

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents = 0;
    int choice;

    do {
        printf("1. Nhap thong tin sinh vien\n");
        printf("2. Hien thi danh sach sinh vien\n");
        printf("3. Cap nhat thong tin sinh vien\n");
        printf("4. Sap xep danh sach sinh vien theo ten\n");
        printf("5. Sap xep danh sach sinh vien theo GPA\n");
        printf("6. Tim kiem sinh vien theo ten\n");
        printf("7. Tim kiem sinh vien theo ID\n");
        printf("0. Thoat\n");
        printf("Chon mot so: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
    int numToAdd;
    printf("Nhap so luong sinh vien can nhap: ");
    scanf("%d", &numToAdd);

    if (numStudents + numToAdd <= MAX_STUDENTS) {
        for (int i = 0; i < numToAdd; i++) {
            printf("Nhap thong tin sinh vien %d:\n", numStudents + i + 1);
            printf("Ten: ");
            scanf("%s", students[numStudents + i].name);
            printf("Ma so: ");
            scanf("%d", &students[numStudents + i].id);
            printf("Tuoi: ");
            scanf("%d", &students[numStudents + i].age);
            printf("GPA: ");
            scanf("%f", &students[numStudents + i].gpa);
        }
        numStudents += numToAdd;
    } else {
        printf("Không đủ chỗ trống trong danh sách sinh viên.\n");
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
    printf("Nhap ma so sinh vien can cap nhat: ");
    scanf("%d", &studentId);
    int index = -1; 
    for (int i = 0; i < numStudents; i++) {
        if (students[i].id == studentId) {
            index = i;
            break;
        }
    }
    
    if (index != -1) {
        printf("Nhap thong tin cap nhat cho sin vien boi ma so %d:\n", studentId);
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
            case 4:
    sortStudentsByName(students, numStudents);
    printf("Danh sach sinh vien sau khi sap xep theo ten:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Sinh vien %d:\n", i + 1);
        printf("Ten: %s\n", students[i].name);
        printf("Ma so: %d\n", students[i].id);
        printf("Tuoi: %d\n", students[i].age);
        printf("GPA: %.2f\n", students[i].gpa);
    }
            break;
            case 5:
    sortStudentsByGPA(students, numStudents);
    printf("Danh sach sinh vien sau khi sap xep theo GPA:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Sinh vien %d:\n", i + 1);
        printf("Ten: %s\n", students[i].name);
        printf("Ma so: %d\n", students[i].id);
        printf("Tuoi: %d\n", students[i].age);
        printf("GPA: %.2f\n", students[i].gpa);
    }
            break;
            case 6: 
    { char searchName[50];
        printf("Nhap ten sinh vien can tim kiem: ");
        scanf("%s", searchName);
        searchStudentsByName(students, numStudents, searchName);
            break;
    }
            case 7: 
    { int searchId;
        printf("Nhap ID sinh vien can tim kiem: ");
        scanf("%d", &searchId);
        searchStudentsById(students, numStudents, searchId);
            break;
    }
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
