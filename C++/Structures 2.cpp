/*Information about the rooms in the hostel is given. The record looks like: room number, room area, faculty, number of residents.
• form an array of records.
• calculate the number of different faculties and put them in a separate array.
• display data on the number of rooms, the number of students and the average area per student for each faculty.*/

/*Дана информация о комнатах в общежитии. Запись имеет вид: номер комнаты, площадь комнаты, факультет, количество проживающих. 
•	сформировать массив из записей. 
•	вычислить количество различных факультетов и занести их в отдельный массив.
•	вывести данные о  количестве комнат, количестве студентов и средней площади на одного студента по каждому факультету.*/

#include <iostream>
using namespace std;
typedef struct
{
    char name[10];
    int vipus;
    int post;
    float pr;
} school;

void IndexSort(school arr[], int n, int* B)
{
    int i, j, t = 0;
    for (i = 0; i < n; i++)
    {
        B[i] = i;
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (arr[B[i]].pr < arr[B[j]].pr)
            {
                t = B[i];
                B[i] = B[j];
                B[j] = t;
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int i, j, t, n;
    school S;

    cout << "Количество школ: ";
    cin >> n;
    cout << endl;

    school* arr = new school[n];
    int* B = new int[n];

    for (i = 0; i < n; i++)
    {
        cout << "Номер школы: ";
        cin >> arr[i].name;
        cout << "Всего выпускников:";
        cin >> arr[i].vipus;
        cout << "Поступили в вуз:";
        cin >> arr[i].post;
        if (arr[i].vipus < arr[i].post)
        {
            cout << "Ошибка" << endl;
            break;
        }
        cout << "\n\n";
    }

    for (i = 0; i < n; i++)
    {
        arr[i].pr = ((float)arr[i].post / (float)arr[i].vipus) * 100;
    }

    IndexSort(arr, n, B);

    for (i = 0; i < n; i++)
    {
        cout << "Школа: " << arr[B[i]].name << "\nВыпускников: " << arr[B[i]].vipus << "\n% : " << arr[B[i]].pr;
        cout << "\n--------------------------------------------------";
        cout << "\n";
    }

    return 0;
}
