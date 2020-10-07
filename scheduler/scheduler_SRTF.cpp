/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */

//TODO fill in content
using namespace std;
#include "../includes/scheduler_SRTF.h"
#include <algorithm>
bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p) {
	// if job is faster
	if (p.remaining_cpu_time <= 0)
		return true;

	if (!ready_q->empty() && p.remaining_cpu_time > ready_q->front().remaining_cpu_time){
		return true;
	} else {
		return false;
	}
}
bool cpu_time_sort(const PCB& x, const PCB& y) {
	return x.remaining_cpu_time > y.remaining_cpu_time;
}
void Scheduler_SRTF::sort() {
	preemptive = true;
	vector<PCB> temp;

	while(!ready_q->empty()){
		temp.push_back(ready_q->front());
		ready_q->pop();
	}
	std::sort(temp.begin(), temp.end(), cpu_time_sort);
	while(!temp.empty()){
		ready_q->push(temp.back());
		temp.pop_back();
	}
}
