#include <iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

int partition(int* numbers, int start, int n)
{
    int pivot = numbers[n];

    while ( start < n )
    {
        while ( numbers[start] < pivot )
            start++;

        while ( numbers[n] > pivot )
            n--;

        if ( numbers[start] == numbers[n] )
            start++;
        else if ( start < n )
        {
            int tmp = numbers[start];
            numbers[start] = numbers[n];
            numbers[n] = tmp;
        }
    }

    return n;
}

void quicksort(int* numbers, int start, int n)
{
    if ( start < n )
    {
        int x = partition(numbers, start, n);
        quicksort(numbers, start, x-1);
        quicksort(numbers, x+1, n);
    }
}

int main()
{
    int c = 0, n=10000;
    int numbers[10000];
    string line;
    fstream myfile;
    myfile.open("data10k.txt");
    while(myfile.good())
    {
        getline(myfile,line);
        stringstream(line)>>numbers[c];
        c++;
    }

    //Laman ng Array
    /*for(c = 0; c<n; c++)
    {
        cout<<numbers[c]<<endl;
    }*/

    cout<<"\n\n\nSorting\n";
    quicksort(numbers, 0, n);

    //Laman ng Sorted Array
    for(c = 0; c<n; c++)
    {
        cout<<numbers[c]<<endl;
    }
    myfile.close();

    return 0;
}
