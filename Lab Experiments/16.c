#include <stdio.h>

struct Employee {
    int id;
    char name[30];
    float salary;
};

int main() {
    FILE *fp;
    struct Employee e;
    int n, pos;

    fp = fopen("employee.dat", "wb");

    printf("Enter number of employees: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter ID, Name and Salary: ");
        scanf("%d %s %f", &e.id, e.name, &e.salary);
        fwrite(&e, sizeof(e), 1, fp);
    }

    fclose(fp);

    fp = fopen("employee.dat", "rb");

    printf("\nEnter employee position to access: ");
    scanf("%d", &pos);

    fseek(fp, (pos - 1) * sizeof(e), SEEK_SET);

    if (fread(&e, sizeof(e), 1, fp) == 1) {
        printf("\nEmployee ID: %d", e.id);
        printf("\nEmployee Name: %s", e.name);
        printf("\nEmployee Salary: %.2f\n", e.salary);
    } else {
        printf("Employee not found.\n");
    }

    fclose(fp);

    return 0;
}
