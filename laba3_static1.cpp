#include <iostream>
#include <ctime>
#include <random>
#include <cmath>

bool is_correct(double&);
bool int_correct(short&);
bool check_size(short);
void input_mass(int&, double&, int, double*);
double min_element(int, double*);
void min_numb_elem(double, int, double*);
int min_neg(int, double*);
int max_neg(int, double*);
bool negative_number(int, double*);
double sum(int, int, int, double*);
void sort_arr(int, double, double*);
void print_arr(int, double*);
void rand_numb(int, int, int, double*);
bool randNumb_function(short,double*);
bool inputNumb_function(short, double*);
int input_sizeOfArr(short&);
int input_typeOfArr(short&);

int main()
{
        const short Max_size{ 100 };
        short type{0};
        double arr[Max_size]{};
        short size{0};
        try
        {
            if (!input_sizeOfArr(size))
            {
                throw false;
            }
            if (!input_typeOfArr(type))
            {
                throw false;
            }
            if (type == 2)
            {
                if (!inputNumb_function(size, arr))
                {
                    throw false;
                }
            }
            if (type == 1)
            {
                if (!randNumb_function(size, arr))
                {
                    throw false;
                }
            }
            if (type != 1 && type != 2)
            {
                throw false;
            }
        }
       catch(bool)
       {
           std::cout << "mistake";
       }
    return 0;
}

bool is_correct(double& number)
{
    return (std::cin >> number) ? true : false;
}
bool int_correct(short& number)
{
    return (std::cin >> number) ? true : false;
}
bool check_size(short number)
{
    return (number > 0 && number < 100) ? true : false;

}
bool checkint_size(int number)
{
    return (number > 0 && number < 100) ? true : false;

}

void input_mass(int& prov, double& temp, int size, double* arr)
{
    for (int i = 0; i < size; i++)
    {
        if (is_correct(temp))
        {
            arr[i] = temp;
        }
        else
        {
            prov = 0;
            break;
        }
    }
}
double min_element(int size, double* arr)
{
    double min_number = { arr[0] };
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min_number)
        {
            min_number = arr[i];
        }
    }
    return min_number;
}
void min_numb_elem(double min, int size, double* arr)
{
    for (int i = size - 1; i >= 0; i--)
    {
        if (arr[i] == min)
        {
            std::cout << i + 1 << '\n';
        }
    }
}
int min_neg(int size, double* arr)
{
    int min_neg;
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] < 0)
        {
            min_neg = i;
            break;
        }
    }
    return min_neg;
}
int max_neg(int size, double* arr)
{
    int max_neg;
    for (int i = size - 1; i >= 0; i--)
    {
        if (arr[i] < 0)
        {
            max_neg = i;
            break;
        }
    }
    return max_neg;
}
bool negative_number(int size, double* arr)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            return true;
        }
    }
    return false;
}
double sum(int min, int max, int size, double* arr)
{
    double sum_numb{ 0 };
    for (int i = min + 1; i < max; i++)
    {
        sum_numb += arr[i];
    }
    return sum_numb;
}
void sort_arr(int size, double X, double* arr)
{
    for (int i = 1; i < size; ++i)
    {
        double save = arr[i];
        int j = i - 1;
        while (j >= 0 && std::abs(arr[j]) > X)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = save;
    }
}
void print_arr(int size, double* arr)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << '\n';
    }
}
void rand_numb(int a, int b, int size, double* arr)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % (b - a + 1) + a;
    }
}
bool randNumb_function(short size, double* arr)
{
    short a;
    short b;
    try
    {
        std::cout << "input range number of mass from 1 to 100" << '\n';
        if (!int_correct(a))
        {
            throw false;
        }
        if (!check_size(a))
        {
            throw false;
        }
        if (!int_correct(b))
        {
            throw false;
        }
        if (!check_size(b))
        {
            throw false;
        }
        if (a > b)
        {
            std::swap(a, b);
        }
        srand(time(NULL));
        rand_numb(a, b, size, arr);
        std::cout << "array is :" << '\n';
        print_arr(size, arr);
        std::cout << "the numbers of the minimum array elements is :" << '\n';
        min_numb_elem(min_element(size, arr), size, arr);
        if (negative_number(size, arr))
        {
            int min = min_neg(size, arr);
            int max = max_neg(size, arr);
            std::cout << "sum between " << min + 1 << " and " << max + 1 << " elements is " << '\n';
            std::cout << sum(min, max, size, arr) << '\n';
        }
        std::cout << " input number X. This number need for array sorting " << '\n';
        double X;
        if (!is_correct(X))
        {
            throw false;
        }
        std::cout << " sorted array " << '\n';
        sort_arr(size, X, arr);
        print_arr(size, arr);
    }
    catch (bool)
    {
        return 0;
    }
    return 1;
}
bool inputNumb_function(short size, double* arr)
{
    try
    {
        double temp{ 0 };
        int prov = 1;
        std::cout << "input " << size << " numbers" << '\n';
        input_mass(prov, temp, size, arr);
        if (prov == 0)
        {
            throw false;
        }
        std::cout << "the numbers of the minimum array elements is :" << '\n';
        min_numb_elem(min_element(size, arr), size, arr);
        if (negative_number(size, arr))
        {
            int min = min_neg(size, arr);
            int max = max_neg(size, arr);
            std::cout << "sum between " << min + 1 << " and " << max + 1 << " elements is " << '\n';
            std::cout << sum(min, max, size, arr) << '\n';
        }
        double X;
        std::cout << " input number X. This number need for array sorting " << '\n';
        if (!is_correct(X))
        {
            throw false;
        }
        std::cout << " sorted array " << '\n';
        sort_arr(size, X, arr);
        print_arr(size, arr);
    }
    catch (bool)
    {
        return 0;
    }
    return 1;
}
int input_sizeOfArr(short& size)
{
    try
    {
        std::cout << "input size of mass > 0 but < 100" << '\n';
        if (int_correct(size) == 0)
        {
            throw false;
        }
        if (check_size(size) == 0)
        {
            throw false;
        }
    }
    catch (bool)
    {
        return 0;
    }
    return size;
}
int input_typeOfArr(short& type)
{
    try
    {
        std::cout << "if you want random number press 1 , if you want to enter numbers, enter 2" << '\n';
        if (int_correct(type) == 0)
        {
            throw false;
        }
        if (check_size(type) == 0)
        {
            throw false;
        }
    }
    catch (bool)
    {
        return 0;
    }
    return type;
}