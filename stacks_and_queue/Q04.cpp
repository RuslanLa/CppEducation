/*
 * Queue via Stacks: Implement a MyQueue class which implements a queue using two stacks.
 */
#include <iostream>
#include "StackBasedQueue.h"
#include "utils.h"

int main(){
    StackBasedQueue<int> queue {};
    queue.push(0);
    queue.push(1);
    queue.push(2);
    print(queue);
    queue.push(3);
    print(queue);
    queue.push(4);
    queue.push(5);
    queue.push(6);
    print(queue);
}