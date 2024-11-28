//Program for Round Robin Scheduling with arrival time as zero , different and same arrival times


#include <climits>
#include <iostream>
using namespace std;

struct Process
{
    int AT, BT, ST[20], WT, FT, TAT, pos;
};

int quant;

int main()
{
    int n, i, j;

    // Taking Input
    cout << "Enter the no. of processes: ";
    cin >> n;
    Process p[n];

    cout << "Enter the quantum: " << endl;
    cin >> quant;

    cout << "Enter the process numbers: " << endl;
    for (i = 0; i < n; i++)
        cin >> p[i].pos;

    cout << "Enter the Arrival time of processes: " << endl;
    for (i = 0; i < n; i++)
        cin >> p[i].AT;

    cout << "Enter the Burst time of processes: " << endl;
    for (i = 0; i < n; i++)
        cin >> p[i].BT;

    // Declaring variables
    int c = n, s[n][20];
    float time = 0, mini = INT_MAX, b[n], a[n];

    // Initializing burst and arrival time arrays
    int index = -1;
    for (i = 0; i < n; i++)
    {
        b[i] = p[i].BT;
        a[i] = p[i].AT;
        for (j = 0; j < 20; j++)
        {
            s[i][j] = -1;
        }
    }

    int tot_wt, tot_tat;
    tot_wt = 0;
    tot_tat = 0;
    bool flag = false;

    while (c != 0)
    {
        mini = INT_MAX;
        flag = false;

        for (i = 0; i < n; i++)
        {
            float p = time + 0.1;
            if (a[i] <= p && mini > a[i] && b[i] > 0)
            {
                index = i;
                mini = a[i];
                flag = true;
            }
        }

        // if at =1 then loop gets out hence set flag to false
        if (!flag)
        {
            time++;
            continue;
        }

        // calculating start time
        j = 0;

        while (s[index][j] != -1)
        {
            j++;
        }

        if (s[index][j] == -1)
        {
            s[index][j] = time;
            p[index].ST[j] = time;
        }

        if (b[index] <= quant)
        {
            time += b[index];
            b[index] = 0;
        }
        else
        {
            time += quant;
            b[index] -= quant;
        }

        if (b[index] > 0)
        {
            a[index] = time + 0.1;
        }

        // calculating arrival, burst, final times
        if (b[index] == 0)
        {
            c--;
            p[index].FT = time;
            p[index].WT = p[index].FT - p[index].AT - p[index].BT;
            tot_wt += p[index].WT;
            p[index].TAT = p[index].BT + p[index].WT;
            tot_tat += p[index].TAT;
        }
    } // end of while loop

    // Printing output
    cout << "Process number ";
    cout << "Arrival time ";
    cout << "Burst time ";
    cout << "\tStart time";
    j = 0;
    while (j != 10)
    {
        j += 1;
        cout << " ";
    }
    cout << "\t\tFinal time";
    cout << "\tWait Time ";
    cout << "\tTurnAround Time" << endl;

    for (i = 0; i < n; i++)
    {
        cout << p[i].pos << "\t\t";
        cout << p[i].AT << "\t\t";
        cout << p[i].BT << "\t";
        j = 0;
        int v = 0;
        while (s[i][j] != -1)
        {
            cout << p[i].ST[j] << " ";
            j++;
            v += 3;
        }
        while (v != 40)
        {
            cout << " ";
            v += 1;
        }
        cout << p[i].FT << "\t\t";
        cout << p[i].WT << "\t\t";
        cout << p[i].TAT << endl;
    }

    // Calculating average wait time and turnaround time
    double avg_wt, avg_tat;
    avg_wt = tot_wt / static_cast<double>(n);
    avg_tat = tot_tat / static_cast<double>(n);

    // Printing average wait time and turnaround time
    cout << "The average wait time is: " << avg_wt << endl;
    cout << "The average TurnAround time is: " << avg_tat << endl;

    return 0;
}
