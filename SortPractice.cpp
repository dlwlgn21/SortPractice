#include <iostream>

void PrintArray(int input[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << input[i] << " ";
    }
    std::cout << std::endl;
}

void Swap(int& value1, int& value2)
{
    int temp = value1;
    value1 = value2;
    value2 = temp;
}

// Sequential Sort
// 시간복잡도 O(n^2), 공간복잡도 O(n) [매개변수도 카운팅해서!]
void SequentialSort(int input[], int size)
{
    // 이 코드는 조금 더 최적화 할 여지가 있다.
    // 마지막 원소는 정렬할 필요가 없으니까.
    // 이렇게 하면 횟수는 1회 줄일 수 있지만 크게 차이는 없음.
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            if (input[i] > input[j])
            {
                Swap(input[i], input[j]);
            }
        }
    }
}

// Selection Sort 젤 작은거 골라내서 꺼내오는 것
// 시간복잡도 O(n^2), 공간복잡도 O(n)
// 사람이 실제로 정렬 하는 형태
void SelectionSort(int input[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        int minIndex = i;
        for (int j = i; j < size; ++j)
        {
            if (input[minIndex] > input[j])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            Swap(input[i], input[minIndex]);
        }

    }
}


// Bubble Sort
// 시간복잡도 O(n^2), 공간복잡도 O(n)
// 빅오 표기는 결국엔 똑같음. 애가 조금 더 빠르긴 함.
void BubbleSort(int input[], int size)
{
    for (int phase = 0; phase < size - 1; ++phase)
    {
        for (int left = 0; left < size - 1 - phase; ++left)
        {
            if (input[left] > input[left + 1])
            {
                Swap(input[left], input[left + 1]);
            }
        }
    }
#if 0
    // 원성연님 버전
    while (size != 0)
    {
        for (int i = 0; i < size - 1; ++i)
        {
            if (input[i] > input[i + 1])
            {
                Swap(input[i], input[i + 1]);
            }

            --size;
        }
    }
    // 호익님 버전
    void BubbleSort(int input[], int size)
    {
        for (int i = size - 1; i > 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (input[j] > input[j + 1])
                {
                    int temp = input[j];
                    input[j] = input[j + 1];
                    input[j + 1] = temp;
                }
            }
        }
    }
#endif
}
// Insertion Sort
// 내가 들어갈 위치에 원소를 집어넣는다.
// 시도는 좋았으나 아쉽!
// 시간복잡도 O(n^2), 공간복잡도 O(n)
// 빅오 표기는 결국엔 똑같음. 애도 순차적, 선택적보다는 빠르긴 함.
void InsertionSort(int input[], int size)
{
    for (int i = 1; i < size; ++i)
    {
        int j = i;
        int target = input[i];
        while (--j >= 0 && target < input[j])
        {
            input[j + 1] = input[j];
            input[j] = target;
        }
    }
}

//천재가 만들어놓은 MergeSort
void Merge(int input[], int start, int half, int end, int temp[])
{
    int left{ start };
    int right{ half + 1 };
    int tempIndex{};

    // 작은거 넣는거
    while (start <= half && right <= end)
    {
        if (input[left] < input[right])
        {
            temp[tempIndex++] = input[left++];
        }
        else 
        {
            temp[tempIndex++] = input[right++];
        }
    }


    while (left <= half)
    {
        temp[tempIndex++] = input[left++];
    }
    while (right <= end)
    {
        temp[tempIndex++] = input[right++];
    }

    tempIndex = 0;
    for (int i = start; i <= end; ++i)
    {
        input[i] = temp[tempIndex++];
    }

}
// Merge Sort
// 시간복잡도:
// 공간복잡도:
void MergeSortRecursive(int input[], int start, int end, int temp[])
{
    // base case
    if (start >= end) 
    {
        return;
    }

    int half = (start + end) / 2;
    MergeSortRecursive(input, start, half, temp);
    MergeSortRecursive(input, half + 1, end, temp);
    Merge(input, start, half, end, temp);
}


int main()
{
    const int SIZE{ 5 };
    int array[SIZE]{ 8, 7, 2, 3, 1 };
    int tempArray[SIZE]{};
    //SORT
    
    //InsertionSort(array, SIZE);
    MergeSortRecursive(array, 0, SIZE - 1, tempArray);

    PrintArray(array, SIZE);
}
