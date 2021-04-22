#include<stdio.h>
#include<string.h>
int x = 0;
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
struct process{
	int arrival_time;
	int completion_time;
	int turnaround_time;
	int waiting_time;
	int burst_time;
	char pid[10];
	void getdata(){
		printf("Enter the process id: ");
		scanf("%s", &pid);
		printf("Enter the arrival time for process %s: ", pid);
		scanf("%d", &arrival_time);
		printf("Enter the burst time: ");
		scanf("%d", &burst_time);
	
	}
	void putdata(){
		printf("Process id: %s Arrival Time: %dms Burst time: %d ms Completion time: %d ms Turnaround time: %d ms Waiting time: %d ms\n", pid, arrival_time, burst_time, completion_time, turnaround_time, waiting_time);
	}
    void processval(){
	x+=burst_time;
	completion_time = x;
	turnaround_time = completion_time-arrival_time;
	waiting_time = turnaround_time-burst_time;
}
};


int main(){
	printf("Enter the no. of processes: ");
	int n;
	scanf("%d", &n);
	process p[n];
	for(int i=0; i<n; i++){
		p[i].getdata();
	}
	for(int i=0; i<n; i++){
		for(int j = 0; j<n-1; j++){
			if(p[j].arrival_time>p[j+1].arrival_time){
				swap(&p[j].burst_time, &p[j+1].burst_time);
				swap(&p[j].arrival_time, &p[j+1].arrival_time);
				char a[10];
				strcpy(a, p[j].pid);
				strcpy(p[j].pid, p[j+1].pid);
				strcpy(p[j+1].pid, a);
			}
		}
	}
    for(int i=0; i<n-1; i++){
		if(p[i].arrival_time==p[i+1].arrival_time&&p[i].burst_time>p[i+1].burst_time){
			swap(&p[i].burst_time, &p[i+1].burst_time);
				swap(&p[i].arrival_time, &p[i+1].arrival_time);
				char a[10];
				strcpy(a, p[i].pid);
				strcpy(p[i].pid, p[i+1].pid);
				strcpy(p[i+1].pid, a);
		}
	}
	for(int i=0; i<n; i++){
		p[i].processval();
	}
	for(int i=0; i<n; i++){
		p[i].putdata();
	}
	return 0;
}
