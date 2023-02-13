// https://www.geeksforgeeks.org/interleave-first-half-queue-second-half/
// https://leetcode.com/problems/interleaving-string/


// APPROACH 1 (USING QUEUE)
// 1. Fetch the first half element from the queue & push into a new queue
// 2. while new queue is not empty push value from both queue  alternately


// T.C. -> O(N)
// S.C. -> O(N)


// APPROACH 2 USING STACK 
// eg. 2 3 4 5 6 7 8 9

// 1. put first halff element in stack
//    6 7 8 9 5 4 3 2

// 2. now pop first half queue & push it back
//    5 4 3 26 7 8 9 

// 3. put First half into stack & take element alternately from both stack & queue
