#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

struct application_type
{
    char name[125];
    char family_name[125];
    char father_name[125];
    char passport[125];
    char place[125];
    int school_number;
    int specialty;
    int ball1, ball2, ball3, ball_school;
    int total_ball;
    struct application_type *next;
};
struct specialty
{
    int places;
    char title[255];
    int id;
    struct specialty *next;
};

struct rating_by_spec{
    int pass_ball;
    int id;
};
void show(struct specialty *head)
{
    struct specialty *Q;
    Q = head;
    while (Q != NULL)
    {
        printf("id:   %d\n", Q->id);
        printf("Title:   %s\n", Q->title);
        printf("Places:   %d\n", Q->places);
        printf("---------------------------\n");
        Q = Q->next;
    }
}

void show_app(struct application_type *head)
{
    struct application_type *Q;
    Q = head;
    while (Q != NULL)
    {
        printf("name surname fathername:   %s  %s  %s\n", Q->name, Q->family_name, Q->father_name);
        printf("passport number place of birth school number:   %s  %s  %d\n", Q->passport, Q->place, Q->school_number);
        printf("specialty:   %d \n", Q->specialty);
        printf("Ball1 ball2 ball3 ball_school | total_ball:   %d %d %d  %d | %d\n", Q->ball1, Q->ball2, Q->ball3, Q->ball_school, Q->total_ball);
        printf("---------------------------\n");
        Q = Q->next;
    }
}


void bubbleSort(struct rating_by_spec *num)
{
    int size = 36;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = (size - 1); j > i; j--)
        {
            if (num[j - 1].pass_ball > num[j].pass_ball)
            {
                struct rating_by_spec temp = num[j - 1];
                num[j - 1] = num[j];
                num[j] = temp;
            }
        }
    }
}

int len(struct application_type *ABITURIENTS)
{
    int len = 0;
    struct application_type *temp;
    temp = ABITURIENTS;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

struct application_type *pop(struct application_type *head)
{
    struct application_type *prev = NULL;
    struct application_type *res = NULL;
    int val;
    if (head == NULL)
    {
        exit(-1);
    }
    prev = (head);
    (head) = (head)->next;
    free(prev);
    return head;
}

struct application_type *pop123(struct application_type *head)
{
    struct application_type *prev = NULL;
    //struct application_type  * res = NULL;
    if (head == NULL)
    {
        exit(-1);
    }
    prev = (head);
    //res = prev;
    (head) = (head)->next;
    return (prev);
    // return res;
}
struct application_type *sort1(struct application_type *root)
{
    struct application_type *new_root = NULL;

    while (root != NULL)
    {
        struct application_type *node = root;
        root = root->next;

        if (new_root == NULL || node->total_ball < new_root->total_ball)
        {
            node->next = new_root;
            new_root = node;
        }
        else
        {
            struct application_type *current = new_root;
            while (current->next != NULL && (node->total_ball >= current->next->total_ball))
            {
                current = current->next;
            }

            node->next = current->next;
            current->next = node;
        }
    }

    return new_root;
}

struct application_type *del(struct application_type *head, struct application_type *prev)
{
    if (head == NULL)
    {
        exit(-1);
    }

    if (head == prev)
    {
        head = pop(head);
    }
    else
    {
        struct application_type *elem = prev->next;
        if (elem->next != NULL)
        {
            prev->next = elem->next;
        }
        else
        {
            prev->next = NULL;
        }
        free(elem);
    }

    return head;
}

struct application_type *take_a_node(struct application_type **head, struct application_type **prev,struct application_type **temp123)
{
    if ((*temp123) == NULL)
    {
        exit(-1);
    }
    else
    if ((*head) == (*prev))
    {struct application_type *temp = (*prev);
        (*head) = (*head)->next;
        (*temp123) = (*head);
        (*prev)->next = NULL;
        (*prev) = (*head);
        return temp;
    }
    else
    {
        struct application_type *temp = (*prev)->next;
        (*temp123)=(*temp123)->next;
        temp->next=NULL;
        return temp;
    }
}
/*//////////???????????????
void push(Node **head, int data) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->value = data;
    tmp->next = (*head);
    (*head) = tmp;
}*/

struct application_type *push(struct application_type *ABITURIENTS, struct application_type *application)
{

    if (ABITURIENTS == NULL)
    {
        ABITURIENTS = application;
        ABITURIENTS->next = NULL;
    }
    else
    {
        application->next = ABITURIENTS;
        ABITURIENTS = application;
    }
    return ABITURIENTS;
}

void backup(FILE *fp_from, FILE *fp_in)
{
    if (fp_in == NULL || fp_from == NULL)
    {
        printf("It looks like there are some problems \n");
        return;
    }

    //
    //переписываем в другой файл
    char str1[255];
    while (fgets(str1, 255, fp_from))
    {

        //printf("%s\n",str1);
        fprintf(fp_in, " %s  ", str1);
    }
    fclose(fp_in);
    fclose(fp_from);
}

void save(FILE *fp1, struct application_type *ABITURIENTS)
{
    if (fp1 == NULL)
    {
        printf("It looks like there are some problems \n");
        return;
    }
    struct application_type *temp = ABITURIENTS;

    //            temp = ABITURIENTS;
    /* fprintf(fp1, "Name: ");
    fprintf(fp1, "Surname:  ");
    fprintf(fp1, "Fathername:  ");
    fprintf(fp1, "ball1:  ");
    fprintf(fp1, "ball2:  ");
    fprintf(fp1, "ball3:  ");
    fprintf(fp1, "school grade:  ");
    fprintf(fp1, "passport:   ");
    fprintf(fp1, "place:   ");
    fprintf(fp1, "school number:   ");
    fprintf(fp1,"\n");*/
    while (temp != NULL)
    {

        //                ABITURIENTS = ABITURIENTS->next;
        fprintf(fp1, "Name:%s ", temp->name);
        fprintf(fp1, "Surname:%s ", temp->family_name);
        fprintf(fp1, "Fathername:%s ", temp->father_name);
        fprintf(fp1, "ball1:%d ", temp->ball1);
        fprintf(fp1, "ball2:%d ", temp->ball2);
        fprintf(fp1, "ball3:%d ", temp->ball3);
        fprintf(fp1, "school_grade:%d  ", temp->ball_school);
        fprintf(fp1, "passport:%s ", temp->father_name);
        fprintf(fp1, "place:%s ", temp->place);
        fprintf(fp1, "school_number:%d ", temp->school_number);
        fprintf(fp1, "totall_amount:%d ", temp->total_ball);
        fprintf(fp1, "id_specialty:%d ", temp->specialty);
        fprintf(fp1, "\n");
        temp = temp->next;
    }
    fclose(fp1);
}

void save_and_backup(struct application_type *ABITURIENTS)
{
    FILE *fp1;
    FILE *fp3;
    fp3 = fopen("/Users/victoriasviridchik/CLionProjects/2sem_lab6/backup", "w");
    fp1 = fopen("/Users/victoriasviridchik/CLionProjects/2sem_lab6/application_data", "r");    backup(fp1, fp3);

    if (!ABITURIENTS)
    {
        printf("There is no data to save!");
        //очистить апп дата  и перенести в бэкап
        backup(fp1, fp3);
        fp1 = fopen("/Users/victoriasviridchik/CLionProjects/2sem_lab6/application_data", "w");        fclose(fp1);
        return;
    }
    //записываем данные
    fp1 = fopen("/Users/victoriasviridchik/CLionProjects/2sem_lab6/application_data", "w");
    save(fp1, ABITURIENTS);
}

int from_str_to_double(char s[125])
{
    int flag = 0;
    char temp[125] = {'\0'};
    //printf("++%c\n",s[1]);
    if (s[1] == '\n')
    {
        //        char temp[125]={'\0'};
        strncpy(temp, s, 1);
        //char s = {'\0'};
        //strcpy(s,temp);
        flag = 1;
    }
    if (s[2] == '\n')
    {

        strncpy(temp, s, 2);
        flag = 1;
    }
    if (flag == 1)
    {
        if (temp[0] == '-')
        {
            printf("%s", "Should be positive! EVERETHING\n");
            return -1;
        }
        int i = 0, sum = 0;
        while (temp[i] != '\0')
        {
            if (temp[i] <= '9' && temp[i] >= '0' && sum < INT_MAX / 100)
            {
                sum = sum * 10 + (temp[i] - '0');
                i++;
            }
            else
            {
                printf("%s", "Should be NUMBER!\n");
                return -1;
            }
        }
        return sum;
    }
    else
    {
        if (s[0] == '-')
        {
            printf("%s", "Should be positive! EVERETHING\n");
            return -1;
        }
        int i = 0, sum = 0;
        while (s[i] != '\0')
        {
            if (s[i] <= '9' && s[i] >= '0' && sum < INT_MAX / 100)
            {
                sum = sum * 10 + (s[i] - '0');
                i++;
            }
            else
            {
                printf("%s", "Should be NUMBER!\n");
                return -1;
            }
        }
        return sum;
    }
}

char *name_by_id(struct specialty *Specialty, int id)
{
    struct specialty *Q = Specialty;
    while (Q!=NULL){
        if(Q->id == id){
            return Q->title;
        }
        Q = Q->next;
    }
}


struct specialty *load_specialties(FILE *fp, struct specialty *Specialty)
{
    int id = 1;
    //char mas[255];
    char str[255];

    while (!feof(fp))
    {
        fgets(str, sizeof(str), fp);
        char sep[5] = ":";
        char strange[12] = {'\0'};
        char *istr;
        if (strcmp(str, "[\n") == 0)
        {
            //printf ("===============================qwerty\n");
            while (strcmp(str, "]\n") != 0)
            {
                fgets(str, sizeof(str), fp);
                if (strcmp(str, "]\n") == 0)
                {
                    break;
                }
                istr = strtok(str, sep);
                istr = strtok(NULL, sep);
                //printf ("%s",istr);
                strncpy(strange, istr, 2);
                struct specialty *temp = malloc(sizeof(struct specialty));
                temp->places = from_str_to_double(strange);
                temp->id = id;
                id++;
                //printf("$$$$%d",temp->id);
                //puts(temp->id);

                //        istr = strtok (NULL,sep);
                //        istr = strtok (str,sep);
                //        printf("+++%s\n",str);

                //printf ("****%s\n",str);
                strcpy(temp->title, str);
                temp->next = NULL;
                if (Specialty == NULL)
                {
                    Specialty = temp;
                }
                else
                {
                    temp->next = Specialty;
                    Specialty = temp;
                }
                //puts(Specialty->title);
            }
            //return 0;
        }
    }
    return Specialty;
}

int search(struct specialty *Specialty, int id)
{
    struct specialty *temp = malloc(sizeof(struct specialty));
    temp = Specialty;
    int flag = 0;
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            flag = 1;
            return temp->places;
        }
        temp = temp->next;
    }
    if (flag == 0)
    {
        return -1;
    }
}
int main()
{
    //   char ss[255] = {"4\n"};
    //printf("%c\n",ss[1]);
    int amount_applications_by_specialty[35] = {0};
    int amount_of_admmited_by_specialty[35] = {0};
    struct application_type *ABITURIENTS = malloc(sizeof(struct application_type));
    ABITURIENTS = NULL;
    struct application_type *STUDENTS = malloc(sizeof(struct application_type));
    STUDENTS = NULL;
    struct specialty *Specialty = malloc(sizeof(struct specialty));
    Specialty = NULL;

    FILE *fp;
    FILE *fp1;
    fp = fopen("/Users/victoriasviridchik/CLionProjects/2sem_lab6/faculties", "r");
    fp1 = fopen("/Users/victoriasviridchik/CLionProjects/2sem_lab6/application_data", "w");
    if (!(fp != NULL && fp1 != NULL))
    {
        printf("It looks like there are some problems \n");
        return 0;
    }
    Specialty = load_specialties(fp, Specialty);

    fclose(fp);

    char command[125];
    while (1)
    {
        printf("%s", "\nEnter command(enrollment, quit, create_application, destroy_application, show_faculties, show_the_busket) \n ");
        scanf("%s", command);
        if (strcmp(command, "quit") == 0)
        {
            puts("Thank you! Goodbye");
            break;
        }
        else if (strcmp(command, "create_application") == 0)
        {
            struct application_type *application = malloc(sizeof(struct application_type));

            char s[125];
            puts("Desirible Specialty , Choose id number from the list:\n");
            //show(Specialty);

            if (!Specialty)
            {
                printf("There is no specialties!");
                continue;
            }
            else
            {
                show(Specialty);
            }
            scanf("%s", s);
            int id_app = from_str_to_double(s);

            if (id_app < 1 || id_app > 35)
            {
                printf("Be carefull! There is no such specialty or invalid data.Start please again");
                continue;
            }

            application->specialty = id_app;
            amount_applications_by_specialty[id_app] += 1;
            puts("Enter name");
            scanf(" %s", application->name);
            puts("Enter familyname");
            scanf(" %s", application->family_name);
            puts("Enter fathername");
            scanf(" %s", application->father_name);

            puts("Enter grade for the first subject");
            scanf("%s", s);
            int tmp = 0;
            tmp = from_str_to_double(s);
            if (tmp <= 0)
            {
                fclose(fp1);
                printf("Wrong data\n");
                continue;
            }
            else
            {
                application->ball1 = tmp;
            }

            puts("Enter grade for the second subject");
            scanf("%s", s);

            tmp = from_str_to_double(s);
            if (tmp <= 0)
            {
                fclose(fp1);
                printf("Wrong data\n");
                continue;
            }
            else
            {
                application->ball2 = tmp;
            }

            puts("Enter grade for the third subject");
            scanf("%s", s);
            tmp = from_str_to_double(s);
            if (tmp <= 0)
            {
                fclose(fp1);
                printf("Wrong data\n");
                continue;
            }
            else
            {
                application->ball3 = tmp;
            }

            puts("Enter grade for the school grade");
            scanf("%s", s);
            tmp = from_str_to_double(s);
            if (tmp <= 0)
            {
                fclose(fp1);
                printf("Wrong data\n");
                continue;
            }
            else
            {
                application->ball_school = tmp;
            }

            puts("Enter passport data");
            scanf("%s", s);
            strcpy(application->passport, s);
            //            application.passport = s;

            puts("Enter place data");
            scanf("%s", s);
            strcpy(application->passport, s);

            //            application.passport = s;

            puts("Enter school number");
            scanf("%s", s);
            tmp = from_str_to_double(s);
            if (tmp <= 0)
            {
                fclose(fp1);
                printf("Wrong data\n");
                continue;
            }
            else
            {
                application->school_number = tmp;
            }

            application->total_ball = 0;
            application->total_ball = application->ball1 + application->ball2 + application->ball3 + application->ball_school;
            printf("%s  %s  %s  %d  %d  %d  %d  %s  %s  %d  %d", application->name, application->family_name, application->father_name, application->ball1, application->ball2, application->ball3, application->ball_school, application->passport, application->place, application->school_number, application->total_ball);
            //            application = NULL;

            ABITURIENTS = push(ABITURIENTS, application);
            save_and_backup(ABITURIENTS);
        }
        else if (strcmp(command, "back_to_old_data") == 0)
        {
            ABITURIENTS = NULL;
            int ii = 0;

            FILE *fp3;
            fp3 = fopen("/Users/victoriasviridchik/CLionProjects/2sem_lab6/backup", "r");            char str_backup[255];

            while (!feof(fp3))
            {
                struct application_type *application = malloc(sizeof(struct application_type));
                char data_for_one[255] = {'\0'};
                fgets(str_backup, sizeof(str_backup), fp3);
                char s = str_backup[0];
                int i = 0;
                int j = 0;
                while (s != '\0')
                {
                    if (s == ':')
                    {
                        i++;
                        s = str_backup[i];
                        data_for_one[j] = '|';
                        j++;
                        while (s != ' ' && s != '\0')
                        {
                            // char temp[255] = {'\0'};
                            data_for_one[j] = s;
                            j++;
                            //strcat(data_for_one,&s);
                            //strcat(data_for_one,"\0");
                            i++;
                            s = str_backup[i];
                        }
                        i++;
                    }
                    else
                    {
                        i++;
                        s = str_backup[i];
                        continue;
                    }
                }
                //printf("%s",data_for_one);

                char sep[10] = "|";
                char *istr;
                istr = strtok(data_for_one, sep);
                int jj = 0;
                while (istr != NULL)
                {
                    // printf ("++++%s\n",istr);

                    // Вывод очередной выделенной части
                    if (jj == 0)
                    {
                        //printf("+++++++=%s\n",istr);
                        strcpy(application->name, istr);
                    }
                    else if (jj == 1)
                    {
                        strcpy(application->family_name, istr);
                        //printf ("%s\n",istr);
                    }
                    else if (jj == 2)
                    {
                        strcpy(application->father_name, istr);
                        //printf ("%s\n",istr);
                    }
                    else if (jj == 3)
                    {
                        application->ball1 = from_str_to_double(istr);

                        //printf ("%s\n",istr);
                        //printf ("%d\n",application->ball1);
                    }
                    else if (jj == 4)
                    {
                        application->ball2 = from_str_to_double(istr);

                        //printf ("%s\n",istr);
                        // printf ("%d\n",application->ball2);
                    }
                    else if (jj == 5)
                    {
                        application->ball3 = from_str_to_double(istr);

                        //                    printf ("%s\n",istr);
                        //                    printf ("%d\n",application->ball3);
                    }
                    else if (jj == 6)
                    {
                        application->ball_school = from_str_to_double(istr);

                        //                    printf ("%s\n",istr);
                        //                    printf ("%d\n",application->ball_school);
                    }
                    else if (jj == 7)
                    {
                        strcpy(application->passport, istr);
                        //printf ("%s\n",istr);
                    }
                    else if (jj == 8)
                    {
                        strcpy(application->place, istr);
                        //printf("%s\n", istr);
                    }
                    else if (jj == 9)
                    {
                        application->school_number = from_str_to_double(istr);

                        //                    printf ("%s\n",istr);
                        //                    printf ("%d\n",application->school_number);
                    }
                    else if (jj == 10)
                    {
                        application->total_ball = from_str_to_double(istr);

                        //                    printf ("%s\n",istr);
                        //                    printf ("%d\n",application->total_ball);
                    }
                    else if (jj == 11)
                    {
                        application->specialty = from_str_to_double(istr);

                        //                    printf ("%s\n",istr);
                        //                    printf ("%d\n",application->specialty);
                    }
                    // Выделение очередной части строки
                    istr = strtok(NULL, sep);
                    jj++;
                }
                ABITURIENTS = push(ABITURIENTS, application);
            }

            save_and_backup(ABITURIENTS);
            show_app(ABITURIENTS);
        }
        else if (strcmp(command, "destroy_application") == 0)
        {

            if (ABITURIENTS == NULL)
            {
                puts("There is no applications");
                continue;
            }

            struct application_type *data_temp = malloc(sizeof(struct application_type));
            struct application_type *prev = malloc(sizeof(struct application_type));
            data_temp = ABITURIENTS;
            prev = ABITURIENTS;
            char name_temp[255];
            char family_name_temp[255];

            puts("Enter name");
            scanf(" %s", name_temp);
            puts("Enter familyname");
            scanf(" %s", family_name_temp);
            int is_found = 0;
            while (data_temp != NULL)
            {
                if (strcmp(data_temp->name, name_temp) == 0 && strcmp(data_temp->family_name, family_name_temp) == 0)
                {
                    is_found = 1;
                    if (ABITURIENTS->next == NULL)
                    {
                        ABITURIENTS = NULL;
                    }
                    else
                    {
                        ABITURIENTS = del(ABITURIENTS, prev);
                    }
                }
                prev = data_temp;
                data_temp = data_temp->next;
            }

            if (is_found == 0)
            {
                printf("There is no application with the given name and the given  surname");
            }

            save_and_backup(ABITURIENTS);

        }
        else if (strcmp(command, "save") == 0)
        {
            save_and_backup(ABITURIENTS);
        }
        else if (strcmp(command, "help") == 0)
        {
            printf("List of available commands: Create application, view result\n");
            printf("Create application\n");
            printf("destroy_application\n");
            printf("back_to_old_dara\n");
            printf("save\n");
            printf("enrollment\n");
            printf("help\n");

        }else if (strcmp(command, "enrollment") == 0){
            ABITURIENTS = sort1(ABITURIENTS);
            printf("Abiturients rating in descending: \n");
            show_app(ABITURIENTS);
            printf(" \n");

            int *data_grade_pass = malloc(sizeof(int)*36);
            int *data_semi_grade_pass = malloc(sizeof(int)*36);

            int i;
            for( i=1; i<36; i++){
                data_grade_pass[i] = 0;
            }

            for( i=1; i<36; i++){
                data_semi_grade_pass[i] = 0;
            }
            struct application_type *temp123 = malloc(sizeof(struct application_type));
            temp123 = ABITURIENTS;
            struct application_type *prev = malloc(sizeof(struct application_type));
            prev = ABITURIENTS;
            struct application_type *temp_temp = malloc(sizeof(struct application_type));
            temp_temp = NULL;
            while (temp123 != NULL)
            {
                if (search(Specialty, temp123->specialty) > amount_of_admmited_by_specialty[temp123->specialty])
                {
                    amount_of_admmited_by_specialty[temp123->specialty] += 1;
                    temp_temp = take_a_node(&ABITURIENTS, &prev, &temp123);
                    STUDENTS = push(STUDENTS, temp_temp);
                }
            }
            printf("\nEnrollment process is done! See the Students\n");
            show_app(STUDENTS);
            struct application_type *Qq = malloc(sizeof(struct application_type));
            Qq = STUDENTS;
            Qq = sort1(Qq);
            struct application_type *Q = malloc(sizeof(struct application_type));
Q = ABITURIENTS;
            while (Qq!=NULL){
                int tttemp = Qq->specialty;
                if (data_grade_pass[tttemp]==0){
                    data_grade_pass[tttemp] = Qq->total_ball;
                }
                Qq=Qq->next;
            }
            while (Q!=NULL){
                int ttemp = Q->specialty;
                if(data_semi_grade_pass[ttemp] == data_grade_pass[ttemp]){
                    data_semi_grade_pass[ttemp] = Q->total_ball;
                }
                Q=Q->next;
            }
            printf("\nData about passing grade by specialty :\n");

int ii;
            struct rating_by_spec rating[36];
for( ii = 1; ii<36; ii++){
    printf("At this specialty : %s    ",name_by_id(Specialty,ii));
    if (data_grade_pass[ii]==0){
        printf("Passing ball is : no information \n");
    }else{
        printf("Passing ball is : %d\n", data_grade_pass[ii]);
        struct rating_by_spec r;
        r.id = ii;
        r.pass_ball=data_grade_pass[ii];
        rating[ii]=r;
    }
    if (data_grade_pass[ii]==0){
        printf("Semi - Passing ball is : no information \n");
    }else{
        printf("Semi-Passing ball is : %d\n", data_semi_grade_pass[ii]);
    }
}

int jj ;
bubbleSort(rating);
printf("Specialty rating in descending: \n");
for(jj = 1 ;jj<36;jj++){
    printf("Specialty : %s    ",name_by_id(Specialty,ii));
}
            }

    }
    return 0;
}