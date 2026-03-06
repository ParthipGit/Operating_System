#include <stdio.h>

struct process {
    char pid[10];
    int at, bt;
    int ct, tat, wt, rt;
};

void sorting(struct process p[], int n) {
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
            if(p[i].at > p[j].at) {
                struct process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
}

int main() {

    int n, quantum;
    struct process p[20];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter PID, Arrival Time and Burst Time for each process:\n");
    for(int i = 0; i < n; i++)
        scanf("%s %d %d", p[i].pid, &p[i].at, &p[i].bt);

    printf("Enter quantum time: ");
    scanf("%d", &quantum);

    sorting(p, n);

    int q[100], front = 0, rear = 0;
    int visited[20] = {0};
    int time = 0, completed = 0;
    float total_wt = 0, total_tat = 0;

    for(int i = 0; i < n; i++)
        p[i].rt = p[i].bt;

    time = p[0].at;
    q[rear++] = 0;
    visited[0] = 1;

    while(completed < n) {

        int i = q[front++];

        if(p[i].rt > quantum) {
            time += quantum;
            p[i].rt -= quantum;
        } else {
            time += p[i].rt;
            p[i].rt = 0;
            p[i].ct = time;
            p[i].tat = p[i].ct - p[i].at;
            p[i].wt = p[i].tat - p[i].bt;
            completed++;
        }

        for(int j = 0; j < n; j++) {
            if(p[j].at <= time && visited[j] == 0) {
                q[rear++] = j;
                visited[j] = 1;
            }
        }

        if(p[i].rt > 0)
            q[rear++] = i;
    }

    printf("\nWaiting Time:\n");
    for(int i = 0; i < n; i++) {
        printf("%s %d\n", p[i].pid, p[i].wt);
        total_wt += p[i].wt;
    }

    printf("Turnaround Time:\n");
    for(int i = 0; i < n; i++) {
        printf("%s %d\n", p[i].pid, p[i].tat);
        total_tat += p[i].tat;
    }

    printf("Average Waiting Time: %.2f\n", total_wt/n);
    printf("Average Turnaround Time: %.2f\n", total_tat/n);

    return 0;
}
