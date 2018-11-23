#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int countDigit(int n) 
{ 
    int count = 0; 
    while (n != 0) { 
        n = n / 10; 
        ++count; 
    } 
    return count; 
}

int generate_random_number(int range)
{
    int t;
    t = rand() % (range*10);
    t /= 10;
    
    return t;
}

int exp_complete(int bucket_state[], int n)
{
    int i;

    for (i = 0; i < n; i++) {
        // cout << i << " : " << bucket_state[i] << " ";
        if (bucket_state[i] == 0) {
            // cout << endl;
            return 0;
        }
    }
    cout << endl;

    return 1;
}

int find_avg(int a[], int n)
{
    int i;
    int sum = 0;

    for (i = 0; i < n; i++) {
        sum += a[i];
    }
    cout << "sum : " << sum << endl;
    return (sum / n);
}

int main(int argc, char const *argv[])
{
    int n;
    int i;
    int j;
    int range;
    int random_num;
    int total_capacity;
    int num_experements;

    total_capacity = 0;
    cout << "Enter total number of products:" << endl;
    cin >> n;
    
    int capacity[n];
    int cap_range[n];
    int bucket_state[n];
    
    cout << "Enter the capacity of each product:" << endl;
    for (i = 0; i < n; i++) {
        cout << "product " << i + 1 << ": ";
        cin >> capacity[i];
        total_capacity += capacity[i];
        cap_range[i] = total_capacity;

        cout << i << " capacity["<<i<<"]" << capacity[i] << endl;
        cout << "total_capacity" << total_capacity << endl;
        cout << "cap_range["<<i<<"] " << cap_range[i] << endl << endl;
    }


    cout << "total_capacity : " << total_capacity << endl;
    cout << "countDigit(total_capacity) : " << countDigit(total_capacity) << endl; 
    range = pow(10, countDigit(total_capacity));
    cout << "range : " << range << endl;

    cout << "How many times a simulation has to performed? " << endl;
    cin >> num_experements;
    int exp_statistics[num_experements];

    for (i = 0; i < num_experements; i++) {
        exp_statistics[i] = 0;
    }

    for (i = 0; i < num_experements; i++) {
        for (j = 0; j < n; j++) {
            bucket_state[j] = 0;
        }

        int tmp = 0;
        while (!exp_complete(bucket_state, n)) {
            // random_num = generate_random_number(range);
            int random_num1[] = {3, 45, 78};

            // cout << "rand num : " << random_num << endl;

            for (j < 0; j < n; j++) {
                if (random_num1[tmp++] < cap_range[j]) {
                    cout << "rand num : " << random_num1[tmp-1] << endl;
                    
                    bucket_state[j] = 1;
                    break;
                }
                tmp--;
            }
            
            exp_statistics[i] += 1;

            if (tmp == 6) {
                break;
            } else {
                tmp++;
            }
        }
    }

    cout << "Avg is : " << find_avg(exp_statistics, num_experements) << endl;

    return 0;
}