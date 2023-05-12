#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fungsi untuk menampilkan question
void displayquestion(char *question, char *option[])
{
    printf("%s\n", question);
    for (int i = 0; i < 4; i++)
    {
        printf("    %d. %s\n", i + 1, option[i]);
    }
}

// Fungsi untuk memeriksa answer yang diberikan oleh pengguna
int answerchecker(int answer, int correctanswer)
{
    if (answer == correctanswer)
    {
        printf("\n-------------------------\n");
        printf("|Your answer is correct!|\n");
        printf("-------------------------\n\n");
        return 1;
    }
    else
    {
        printf("-----------------------------------------------\n");
        printf("|Your answer is wrong. The correct answer is %d|\n", correctanswer);
        printf("-----------------------------------------------\n\n");
        return 0;
    }
}

void welcome()
{
    printf("==================================================\n");
    printf("||                   Welcome to                 ||\n");
    printf("||          Who Wants To Be A Millionaire       ||\n");
    printf("==================================================\n");
    printf("||        Get ready to play and win big!        ||\n");
    printf("==================================================\n");
    printf("Lets create an account first\n");
    printf("1. Yes\n");
    printf("2. No\n");
}

int main(int argc, char *argv[])
{
    system("cls");
    char username[20], password[20], passcheck[20];
    char account[20];
    int cntrl = 0, found = 0, choose;
    char *question[5] = {
        "1. What is the capital city of Indonesia?",
        "2. Who is the first president of Indonesia?",
        "3. Who is the founder of Thelephone?",
        "4. Who is the founder of computer algorithm?",
        "5. Who is the founder of Microsoft?"};

    char *option[5][4] = {
        {"Jakarta", "Surabaya", "Bandung", "Bali"},
        {"Joko Widodo", "Susilo Bambang Yudhoyono", "Soekarno", "Megawati Soekarnoputri"},
        {"Thomas Alva Edison", "Alexander Graham Bell", "Nikola Tesla", "Michael Faraday"},
        {"Ada Lovelace", "Charles Babbage", "Alan Turing", "Tim Berners-Lee"},
        {"Bill Gates", "Steve Jobs", "Mark Zuckerberg", "Jeff Bezos"}};

    int correctanswer[5] = {1, 3, 2, 2, 1};
    int score = 0, input;

    FILE *fp;

    if (argc == 3)
    {
        goto login;
    }

    while (1)
    {
        welcome();
        printf("Please insert an input : ");
        if (scanf("%d", &input) == 1) // memvalidasi bahwa user memasukkan bilangan bulat dan bukan karakter
        {
            if (input < 1 || input > 2)
            {
                system("cls");
                printf("==========================================\n");
                printf("|Please enter according to the procedure!|\n");
                printf("==========================================\n");
                continue;
            }
            break;
        }
        else
        {
            system("cls");
            printf("=========================================\n");
            printf("|Invalid input. Please enter an integer!|\n");
            printf("=========================================\n");
            scanf("%*[^\n]"); // membersihkan buffer input
        }
    }

    if (input == 1)
    {
        if ((fp = fopen("database/login.bin", "wb")) == NULL)
        {
            printf("Error!\n");
            return EXIT_FAILURE;
        }

        printf("======== Welcome to Register Session =========\n");
        fflush(stdin);
        printf("==>Enter your username: ");
        fgets(username, 20, stdin);
        username[strcspn(username, "\n")] = 0;
        printf("\n==>Enter your password: ");
        fgets(password, 20, stdin);
        password[strcspn(password, "\n")] = 0;
    pass:
        printf("\n==>Re-confirm password: ");
        fgets(passcheck, 20, stdin);
        passcheck[strcspn(passcheck, "\n")] = 0;
        printf("\n==============================================\n");

        while (password != passcheck)
        {
            if (strcmp(password, passcheck) == 0)
            {
                printf("\nYour account has been created\n");
                break;
            }
            else
            {
                printf("\nInvalid password!!\n");
                goto pass;
            }
        }

        sprintf(account, "%s@%s", username, password);
        fwrite(account, sizeof(char), sizeof(account) / sizeof(char), fp);
        fputc('\n', fp);

        fclose(fp);
        printf("Please proceed to login by : ./FileMainProgram.exe username password\n");

        return EXIT_SUCCESS;
    }
    else
    {
        return EXIT_FAILURE;
    }

login:
    if ((fp = fopen("database/login.bin", "rb")) == NULL)
    {
        printf("Error!, Opening file failed!");
        return EXIT_FAILURE;
    }

    char usernameinput[10], passwordinput[10];
    strcpy(usernameinput, argv[1]);
    strcpy(passwordinput, argv[2]);

    fread(account, sizeof(char), sizeof(account) / sizeof(char), fp);

    fclose(fp);

    char *record[3];

    record[0] = strtok(account, "@");
    while (record[cntrl++] != NULL)
    {
        record[cntrl] = strtok(NULL, "@");
    }

    strcpy(username, record[0]);
    strcpy(password, record[1]);

    if ((strcmp(usernameinput, username) == 0) && (strcmp(passwordinput, password) == 0))
    {
        printf("===============================\n");
        printf("|Login Succes!, Welcome %s|\n", username);
    menu:
        printf("===============================\n");
        printf("|Who Wants To Be a Millionaire|\n");
        printf("===============================\n");
        printf("|          Main Menu          |\n");
        printf("|          1. Play            |\n");
        printf("|          2. Rules           |\n");
        printf("|          3. FAQ             |\n");
        printf("|          4. Exit            |\n");
        printf("===============================\n");
        fflush(stdin);
        while (1)
        {
            printf("Please insert an input : ");
            if (scanf("%d", &input) == 1) // memvalidasi bahwa user memasukkan bilangan bulat dan bukan karakter
            {
                if (input < 1 || input > 4)
                {
                    printf("==========================================\n");
                    printf("|Please enter according to the procedure!|\n");
                    printf("==========================================\n");
                    continue;
                }
                choose = input;
                break;
            }
            else
            {
                printf("=========================================\n");
                printf("|Invalid input. Please enter an integer!|\n");
                printf("=========================================\n");
                scanf("%*[^\n]"); // membersihkan buffer input
            }
        }

        if (choose == 1)
        {
            system("cls");
            for (int i = 0; i < 5; i++)
            {
                displayquestion(question[i], option[i]);
                int answer;
                printf("Pull up your answer (1-4): ");
                scanf("%d", &answer);
                if (answerchecker(answer, correctanswer[i]))
                {
                    score += 200000;
                }
                else
                {
                    printf("You failed in this game\n");
                    printf("Your total score is: %d\n", score);
                    exit(0);
                }
                while (1)
                {
                    if (i == 4)
                    {
                        break;
                    }
                    printf("Do you want to continue the game?\n");
                    printf("1. Yes\n");
                    printf("2. No\n");
                    printf("Please insert an input : ");
                    if (scanf("%d", &input) == 1) // memvalidasi bahwa user memasukkan bilangan bulat dan bukan karakter
                    {
                        if (input < 1 || input > 2)
                        {
                            // system("cls");
                            printf("==========================================\n");
                            printf("|Please enter according to the procedure!|\n");
                            printf("==========================================\n");
                            continue;
                        }
                        choose = input;
                        break;
                    }
                    else
                    {
                        // system("cls");
                        printf("=========================================\n");
                        printf("|Invalid input. Please enter an integer!|\n");
                        printf("=========================================\n");
                        scanf("%*[^\n]"); // membersihkan buffer input
                    }
                }
                if (choose == 1)
                {
                    printf("\n");
                    continue;
                }
                else if (choose == 2)
                {
                    printf("Your total score is: %d\n", score);
                    printf("Your total prize is : $%d\n", score);
                    exit(0);
                }
            }
        }

        else if (choose == 2)
        {
            printf("=========================================\n");
            printf("||             GAME RULES              ||\n");
            printf("=========================================\n");
            printf("1. There are 5 questions that must be answered to win the grand prize of 1 million Dollar\n");
            printf("2. Each question has 4 answer choices, only one answer is correct\n");
            printf("3. If you answer correctly, the prize value will continue to increase, but if you answer incorrectly, the game will stop and you will be considered a failure.\n");
            printf("4. At the end of each question you will be given the opportunity to decide whether to continue the game or stop\n");
            printf("5. If the player chooses to stop, the prize will be adjusted to the total prize that has been accumulated\n\n");
            fflush(stdin);
            printf("Press enter to continue : ");
            getchar();
            system("cls");
            goto menu;
        }

        else if (choose == 3)
        {
            printf("=========================================\n");
            printf("||    Frequently Asked Questions       ||\n");
            printf("=========================================\n");
            printf("Q:For what purpose is this program created?.\n");
            printf("A:This program was created to fulfill the assignment of the final semester exam in the programming lab.\n\n");
            printf("Q:Who are the people behind the making of this program?.\n");
            printf("A:The people behind the making of this program are Ganang Setyo Hadi, Milaulfatul Rizka, Nuri Masyitah, and Nazwa Salsabila.\n\n");
            printf("Q:Where can the programming documentation be seen?.\n");
            printf("A:You can see it at https://github.com/notsuperganang/Proyek-Kelompok4\n\n");
            fflush(stdin);
            printf("Press enter to continue : ");
            getchar();
            system("cls");
            goto menu;
        }
        else
        {
            system("cls");
            return EXIT_SUCCESS;
        }
    }

    // Jika pengguna berhasil menjawab semua question
    printf("===================================================\n");
    printf("||               CONGRATULATION!!!               ||\n");
    printf("===================================================\n");
    printf("||           You Won The Grand Prize!!           ||\n");
    printf("||                  $1.000.000                   ||\n");
    printf("===================================================\n");
    printf("||         Your total score is: %d          ||\n", score);
    printf("===================================================\n");
    return 0;
}
