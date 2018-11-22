#include <iostream>
#include <math.h>
#include "Task.h"
using namespace std; 

bool TaskQueue::enqueue(const Task& t){ // Add a new task
	if(isFull()){
		return 0;
	}
	if(_numItems + _front < _queueSize ){ //before the arrary is filled
		
		
		_tasks[_back].type = t.type;
		_tasks[_back].taskID = t.taskID; 

		size_t strSize;
		int size;
		for (strSize = 0; t.description[strSize]; strSize++);

		size = static_cast<int>(strSize);
		_tasks[_back].description = new (std::nothrow) char[size];

		for(int i = 0; i < size; i++){
			_tasks[_back].description[i] = t.description[i];
		} 
		delete [] t.description;
		_back++;
		_numItems++;
	}
	else{
		_tasks[(_front + _numItems) % _queueSize - 1] = t;
		_back = 0; 
		_numItems++;
	}

	return 1; 
	
}               
Task* TaskQueue::dequeue(){ // Remove current task
	if(isEmpty()){
		return 0;
	}
	if (_front + 1 < _queueSize ){
		_front++;
		_numItems--;
		return &_tasks[_front - 1];
	}
	else{
		_front = 0;
		_numItems--;
		return &_tasks[_queueSize - 1];
	}
}                          
const Task* TaskQueue::peek() const{ // What is current task?
	if(isEmpty()){
		return 0;
	}
	return &_tasks[_front];

}                         
const Task* TaskQueue::next(const Task::TaskType& t) const{ // Return next task of type t
	if(_front < _back){
		for(int i = _front; i <= _back; i++){
			if(_tasks[i].type == t){
				return &_tasks[i]; 
			}
		}
	}
	else if (_front > _back){
		for(int i = _front; i < _queueSize; i++){
			if(_tasks[i].type == t){
				return &_tasks[i];
			}
		}
		for(int i = 0; i <= _back; i++){
			if(_tasks[i].type == t){
				return &_tasks[i];
			}
		}
	
	}
	return NULL;

} 
bool TaskQueue::isFull() const{  // Queue is full
	if(_numItems == _queueSize){
		return 1;
	}
	else{
		return 0;
	}

}                    
bool TaskQueue::isEmpty() const{ // Queue is empty
	if(_numItems == 0){
		return 1;
	}
	else{
		return 0;
	}

}                      
bool TaskQueue::quarterFull() const{ // Queue is < quarter full 
	if(_numItems <= _queueSize/4){
		return 1;
	}
	else{
		return 0;
	}

}                    
bool TaskQueue::doubleQueueSize(){ // Double queue size
	_queueSize *= 2;
	if(Task* task = new (std::nothrow) Task[_queueSize]){
		for(int i = 0; i < _queueSize/2; i++){
			task[i] = _tasks[i];
		}
		delete [] _tasks;
		_tasks = task; 
		return true;
	} 
	return false;
	


}                  
bool TaskQueue::halveQueueSize(){ // Halve queue size
	if(_numItems <= _queueSize/2){
		_queueSize /= 2;
		if(Task* task = new (std::nothrow) Task[_queueSize]){
			for(int i = 0; i < _queueSize; i++){
				task[i] = _tasks[i];
			}

			delete [] _tasks;
			_tasks = task;
			return 1;
		}
		return 0;
		
	}
	else{
		return 0;
	}


}     

TaskQueue::TaskQueue(){ //constructor 
	_front = 0; //start of tasks 
	_back = 0; //current added task
	_numItems = 0; //number of tasks
	_queueSize = 10; //the total size of the queue

	_tasks = new (std::nothrow) Task[_queueSize]; //the tasks array 

}      

TaskQueue::~TaskQueue(){ //destructor 
	/*_front = 0; //start of tasks 
	_back = 0; //current added task
	_numItems = 0; //number of tasks
	_queueSize = 10; //the total size of the queue*/
	delete [] _tasks; 


}      

#ifndef MARMOSET_TESTING

int main() {
	TaskQueue goon; 
	Task t;
	t.taskID = 1;
	t.type = Task::VACUUM;
	t.description = "he";

	cout << goon.isEmpty() << endl;
	cout << goon.isFull() << endl;
	goon.enqueue(t); 
	goon.doubleQueueSize();
	cout << goon.isEmpty() << endl; 
	cout << goon.isFull() << endl; 

	return 0;
}

#endif
