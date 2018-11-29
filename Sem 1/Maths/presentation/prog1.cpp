#include <bits/stdc++.h>

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
    t = rand() % range;
   
    return t;
}

int exp_complete(int *bucket_state, int n)
{
    int i;

    for (i = 0; i < n; ++i) {
        if (bucket_state[i] == 0) {
            return 0;
        }
    }

    return 1;
}

int find_avg(int *a, int n)
{
    int i;
    int sum = 0;
    cout << endl << "Trials needed in each Experement : " ;

    for (i = 0; i < n; i++) {
        cout << a[i] << " "; 
        sum += a[i];

    }
    cout << endl;
    cout << "sum : " << sum << endl;
    return (sum / n);
}

int main(int argc, char const *argv[])
{
    int n;
    int i;
    int j;
    int in;
    int avg;
    int trial;
    int tot_cap;
    int range;
    int exp_num;
    
    cout << "Enter total number of products to be inserted." << endl;
    cin >> n;
    tot_cap = 0;

    int products[n];
    int bucket_state[n];

    for (i = 0; i < n; ++i) {
        cout << "Enter capacity of " << i + 1 << " product: ";
        cin >> in;
        tot_cap += in;
        products[i] = tot_cap;
    }

    srand(time(0));
    range = pow(10, countDigit(tot_cap - 1));
    cout << "Enter the number of trials you want to perform " << endl;
    cin >> exp_num;
    int exp_stats[exp_num];
    

    for (i = 0; i < exp_num; ++i) {
        exp_stats[i] = 0;
    }

    for (i = 0; i < exp_num; ++i) {
        cout << "Experement num : " << i+1 << endl;

        for (j = 0; j < n; ++j) {
            bucket_state[j] = 0;
        }

        trial = 0;
        while (!exp_complete(bucket_state, n)) {
            in = generate_random_number(range);
            cout << "Random Num Generated is : " << in << endl;

            for (j = 0; j < n; ++j) {
                if (in < products[j]) {
                    bucket_state[j] += 1;
                    trial++;
                    break;
                }
            }

            cout << "trial : " << trial << endl;
        }

        cout << endl << endl;
        exp_stats[i] = trial;

    }

    avg = find_avg(exp_stats, exp_num);
    cout << "Avg is " << avg << endl;

    return 0;
}
