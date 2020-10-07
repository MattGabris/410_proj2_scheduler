/*
 * scheduler.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

//TODO fill in content
#include "../includes/scheduler.h"

void Scheduler::add(PCB p){
	ready_q->push(p);
	sort();
}

PCB Scheduler::getNext() {
	PCB temporary = ready_q->front();
	ready_q->pop();
	sort();
	return temporary;
}

bool Scheduler::isEmpty() {
	return ready_q->empty();
}

bool Scheduler::time_to_switch_processes(int tick_count, PCB &p){
	return p.remaining_cpu_time <= 0;
}
