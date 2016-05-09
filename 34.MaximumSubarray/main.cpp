#include <QCoreApplication>
#include <iostream>

int maxSubArraySum(int a[], int size)
{
   int max_so_far = 0, max_ending_here = 0;
   for (int i = 0; i < size; i++)
   {
       max_ending_here = max_ending_here + a[i];
       if (max_ending_here < 0)
           max_ending_here = 0;

       /* Do not compare for all elements. Compare only
          when  max_ending_here > 0 */
       else if (max_so_far < max_ending_here)
           max_so_far = max_ending_here;
   }
   return max_so_far;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int max_sum = maxSubArraySum(arr, n);
    std::cout << "Maximum contiguous sum is \n" << max_sum << std::endl;

    return a.exec();
}

