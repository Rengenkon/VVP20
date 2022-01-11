#include <iostream>
#include <random>
/*
Задание 20

1. Дан целочисленный массив A размера N. Назовем серией группу подряд идущих одинаковых элементов, а длиной серии — количество этих элементов (длина серии может быть равна 1). Сформировать два новых целочисленных массива B и C одинакового размера, записав в массив B длины всех серий исходного массива, а в массив C — значения элементов, образующих эти серии
2. Дано целое число L (> 0) и целочисленный массив размера N. Заменить каждую серию массива, длина которой больше L, на один элемент с нулевым значением
3. Дано целое число K (> 0) и целочисленный массив размера N. Поменять местами последнюю серию массива и его серию с номером K
4. Дано множество A из N точек (точки заданы своими координатами x, y). Среди всех точек этого множества, лежащих во второй четверти, найти точку, наиболее удаленную от начала координат. Если таких точек нет, то вывести точку с нулевыми координатами
5. Дано множество A из N точек (N > 2, точки заданы своими координатами x, y). Найти наибольший периметр треугольника, вершины которого принадлежат различным точкам множества A, и сами эти точки (точки выводятся в том же порядке, в котором они перечислены при задании множества A).

Каждая задача решена в отдельном классе
*/

class z1
{
private:
    int n, y = -1;
    int *a, *b, *c;

public:

    z1(int size = 10) {
        n = size;
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = i + 1;
        }
        b = new int[n];
        c = new int[n];
    }



    void print_arr() {
        std::cout << "Массив 1:\n";
        for (int i = 0; i < n; i++) {
            std::cout << a[i] << ' ';
        }
        std::cout << "\n";
        for (int i = 0; i < y + 1; i++) {
            std::cout << b[i] << ' ';
        }
        std::cout << "\n";
        for (int i = 0; i < y + 1; i++) {
            std::cout << c[i] << ' ';
        }
        std::cout << "\n";
    }

    void foo() {
        for (int i = 0; i < n; i++) {
            int s = 0;
            for (int j = i; j < n; j++) {
                if (a[i] == a[j]) {
                    s++;
                }
                else {
                    y++;
                    b[y] = s;
                    c[y] = a[i];
                    i = i + s - 1;
                    break;
                }

                if (j == n - 1) {
                    y++;
                    b[y] = s;
                    c[y] = a[n - 1];
                }
            }
        }
        

    }
};

class z2
{
private:
    int n, l;
    int* a;

public:

    z2(int size = 10, int leght = 2) {
        n = size;
        l = leght;
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = i + 1;
        }
    }



    void print_arr() {
        std::cout << "Массив 1:\n";
        for (int i = 0; i < n; i++) {
            std::cout << a[i] << ' ';
        }
        std::cout << "\n";
    }

    void foo() {
        for (int i = 0; i < n; i++) {
            int s = 0;
            for (int j = i; j < n; j++) {
                if (a[i] == a[j]) {
                    s++;
                }
                else {
                    if (s > l) {
                        a[i] = 0;
                        for (int h = i + 1; h < n - s + 1; h++) {
                            a[h] = a[h + s - 1];
                        }
                        n = n - s + 1;
                    }
                    else {
                        i = i + s - 1;
                    }
                    break;
                }

                if (j == n - 1) {
                    if (s > l) {
                        a[i] = 0;
                        for (int h = i + 1; h < n - s; h++) {
                            a[h] = a[h + s - 1];
                        }
                        n = n - s + 1;
                    }
                }
            }
        }


    }
};

class z3
{
private:
    int n, l;
    int* a;

public:

    z3(int size = 15, int leght = 2) {
        n = size;
        l = leght;
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = i / 3;
        }
    }



    void print_arr() {
        std::cout << "Массив 1:\n";
        for (int i = 0; i < n; i++) {
            std::cout << a[i] << ' ';
        }
        std::cout << "\n";
    }

    void foo() {
        int k = 0;
        int s = 0;
        for (int i = 0; i < n; i++) {
            s = 0;
            for (int j = i; j < n; j++) {
                if (a[i] == a[j]) {
                    s++;
                }
                else {
                    k++;
                    i = i + s - 1;
                    break;
                }
            }

            if (k == l) {
                k = i + 1 - s;
                break;
            }
        }

        int q = 1;
        for (int i = n - 1; i > -1; i--) {
            if (a[i] == a[i - 1]) {
                q++;
            }
            else {
                break;
            }
        }

        if (q > s) {

            for (int i = n - q - 1; i > k + s; i--) {
                a[i + (q - s)] = a[i];
            }
        }
        else {
            
            for (int i = k + s; i < n - q; i++) {
                a[i + (q - s)] = a[i];
            }
        }

        l = a[k];//сохраняем элемнт
        for (int i = k; i < k + q; i++) {
            a[i] = a[n - 1];
        }
        for (int i = n - 1; i > n - s - 1; i--) {
            a[i] = l;
        }
    }
};

class z4
{
private:
    int n;
    int* a, * b;

public:

    z4(int size = 10) {
        n = size;
        a = new int[n];
        b = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = rand()%21 - 10;
            b[i] = rand() % 20 - 10;
        }
    }



    void print_arr() {
        std::cout << "\n x  ";
        for (int i = 0; i < n; i++) {
            std::cout << a[i] << ' ';
        }
        std::cout << "\n y  ";
        for (int i = 0; i < n; i++) {
            std::cout << b[i] << ' ';
        }
        std::cout << "\n";
    }

    void foo() {
        int j = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] < 0 && b[i] > 0) {
                if (j == -1 || (a[i] * a[i] + b[i] * b[i]) > (a[j] * a[j] + b[j] * b[j])) {
                    j = i;
                }
            }
        }
        std::cout << "Наиболее удаленная точка\n";
        if (j == -1) {
            std::cout << "0 0";
        }
        else {
            std::cout << a[j] << " " << b[j];
        }
        std::cout << "\n";
    }
};

class z5
{
private:
    int n;
    int* a, * b;

public:

    z5(int size = 10) {
        n = size;
        a = new int[n];
        b = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = rand() % 21 - 10;
            b[i] = rand() % 21 - 10;
        }
    }

    void print_arr() {
        std::cout << "\n x  ";
        for (int i = 0; i < n; i++) {
            std::cout << a[i] << ' ';
        }
        std::cout << "\n y  ";
        for (int i = 0; i < n; i++) {
            std::cout << b[i] << ' ';
        }
        std::cout << "\n";
    }

    void foo() {
        int y[3] = {-1, -1, -1};
        double r = 0, q = -1;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int h = j + 1; h < n; h++) {
                    r = sqrt((a[i] - a[j]) * (a[i] - a[j]) + (b[i] - b[j]) * (b[i] - b[j])) + sqrt((a[i] - a[h]) * (a[i] - a[h]) + (b[i] - b[h]) * (b[i] - b[h])) + sqrt((a[h] - a[j]) * (a[h] - a[j]) + (b[h] - b[j]) * (b[h] - b[j]));
                    if (q < r) {
                        q = r;
                        y[0] = i;
                        y[1] = j;
                        y[2] = h;
                    }
                }
            }
        }
        std::cout << "Периметр " << q << "\n x  ";
        for (int i = 0; i < 3; i++) {
            std::cout << a[y[i]] << ' ';
        }
        std::cout << "\n y  ";
        for (int i = 0; i < 3; i++) {
            std::cout << b[y[i]] << ' ';
        }
        std::cout << "\n";
    }
};


int main()
{
    setlocale(LC_ALL, "rus");

    z5 first;
    first.print_arr();
    first.foo();


    std::cout << "Hello World!\n";
}
