 #include<stdio.h>
#include<stdlib.h>
#include<string.h>

int fth_pwd = 0, wid_amt = 0, dep_amt = 0, n, p;
char fth_name[20];

struct create_account {
    char name[20];
    int pwd;
    int saving;
    int expense;
    struct create_account* add;
};

struct create_account* start = NULL;

void create_acc() {
    struct create_account* node = (struct create_account*)malloc(sizeof(struct create_account));
    node->add = NULL;

    printf("\nEnter Name of New User:");
    scanf("%s", node->name);

    printf("\nEnter the User Password:");
    scanf("%d", &node->pwd);

    if (start == NULL)
        start = node;
    else {
        struct create_account* ptr = start;
        while (ptr->add != NULL) {
            ptr = ptr->add;
        }
        ptr->add = node;
    }
}

void login() {
    int saving, expense, balance, up_blc;
    printf("\nWelcome to login page.!");
    printf("\nEnter the Name of the user:");
    scanf("%s", fth_name);

    printf("\nEnter the user password:");
    scanf("%d", &fth_pwd);

    struct create_account* ptr = start;

    while (ptr != NULL) {
        if (strcmp(fth_name, ptr->name) == 0 && ptr->pwd == fth_pwd) {
            printf("\nWelcome %s to tracking app", ptr->name);
            printf("\nDo You want to add friends for splitting(3 Friends)\nPress 1 for Yes OR 2 for NO");
            scanf("%d", &n);

            switch (n) {
            case 1:
                printf("\nRegister Your  3 Friends:");
                create_acc();
                create_acc();
                create_acc();

                printf("\nDo You want to add Money in your saving Press 1 \n Press 2 for expense in item\n press 3 for splitting between friends ");
                scanf("%d", &p);

                switch (p) {
                case 1:
                    printf("\nEnter the amount to be added in saving:");
                    scanf("%d", &saving);
                    ptr->saving = ptr->saving + saving;
                    break;

                case 2:
                    printf("\nEnter the amount you want to expense on the items:");
                    scanf("%d", &expense);
                    ptr->expense = ptr->expense + expense;
                    break;

                case 3:
                    printf("\nYou want to split the expense between the friends:");
                    printf("\nAdd balance to split the amount:");
                    scanf("%d", &balance);
                    up_blc = balance / 4;

                    struct create_account* str = start;

                    while (str != NULL) {
                        str->saving = str->saving + up_blc;
                        str = str->add;
                    }
                    break;
                }
                break;

            case 2:
                return;

            default:
                break;
            }

            ptr = ptr->add;
        }
    }
}

int main() {
    printf("\nWelcome to Tracking app");
    int r;

    printf("\nENTER 1 for CREATE NEW ACCOUNT\n");
    printf("Enter 2 for WITHDRAWL\n");
    printf("Enter 3 for EXIT\n");

    do {
        printf("\nEnter Your Choice :");
        scanf("%d", &r);

        switch (r) {
        case 1:
            create_acc();
            break;

        case 2:
            login();
            break;

        default:
            printf("\nYOU ENTERED INVALID CHOICE\n");
        }

    } while (r != 3);

    return 0;
}
