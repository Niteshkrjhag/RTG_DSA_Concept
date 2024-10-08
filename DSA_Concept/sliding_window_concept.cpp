Case I:

1. Fixed Size Sliding Window:

The general steps to solve these questions by following below steps:

Find the size of the window required, say K.
Compute the result for 1st window, i.e. include the first K elements of the data structure.
Then use a loop to slide the window by 1 and keep computing the result window by window.


you just have an window of constant size due to which you only look at outgoing
pointer and incoming pointer but before it you do a operation on a constant size window

for(int i= 0;i<n;i++){
    for(int j=i;j<n;j++){
        if(i==0){
            // perform an operation 
        }
        if(arr[i]==// conditon){
        // statement;
        }
        if(arr[j]==// condtion){
        // statement:
        }
    }
}

case II:

2. Variable Size Sliding Window:

The general steps to solve these questions by following below steps:

In this type of sliding window problem, we increase our right pointer one by one till our condition is true.
At any step if our condition does not match, we shrink the size of our window by increasing left pointer.
Again, when our condition satisfies, we start increasing the right pointer and follow step 1.
We follow these steps until we reach to the end of the array.

here we more right pointer till it satisfies the condition other wise we move left pointer until our 
required condition holds true;

int i = 0;  // left pointer
for(int j=0;j<n;j++){  // right pointer

// condtion statement or perform operation and move left pointer accordingly;

}





How to Identify Sliding Window Problems:

These problems generally require Finding Maximum/Minimum Subarray, Substrings which satisfy some 
specific condition.
The size of the subarray or substring ‘K’ will be given in some of the problems.
These problems can easily be solved in O(N2) time complexity using nested loops, using sliding window 
we can solve these in O(n) Time Complexity.
Required Time Complexity: O(N) or O(Nlog(N))
Constraints: N <= 106 , If N is the size of the Array/String.


// for more concept look at gfg documentation on sliding window