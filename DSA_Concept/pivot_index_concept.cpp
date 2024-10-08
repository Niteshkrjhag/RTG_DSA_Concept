//The pivot index is the index where the sum of all the numbers strictly to 
// the left of the index is equal to the sum of all the numbers strictly to the index's right.

you can calulate by storing prefixsum from and right after that 
compare lprefixsum[i]==rprefixsum[i] if they match return that index other wise -1;
