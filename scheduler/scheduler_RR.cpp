/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 7, 2019
 *      Author: keith
 *
 *      implements round robin scheduling algorithm
 *      pre-emptive
 */

//TODO fill in content
#include "../includes/scheduler_RR.h"

bool Scheduler_RR::time_to_switch_processes(int tick_count, PCB &p) {
	sort();
	if (p.remaining_cpu_time <= 0){
		return true;
	}
	else {
		return (p.required_cpu_time - p.required_cpu_time) % time_slice == 0;
	}
}

void Scheduler_RR::sort() {
	preemptive = true;
}
