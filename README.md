# acsl
American Computer Science League (ACSL)

For solution program sources, use the following commands to build & run:

# C++
g++ <prog>.cpp -std=c++11
cat <prog>_sample.in | ./a.out
# diff the output against <prog>_sample.out
cat <prog>_test.in | ./a.out
# diff the output against <prog>_test.out

# Java
cat <prog>_sample.in | java <prog>.java
# diff the output against <prog>_sample.out
cat <prog>_test.in | java <prog>.java
# diff the output against <prog>_test.out

# Python
cat <prog>_sample.in | python3 <prog>.py
# diff the output against <prog>_sample.out
cat <prog>_test.in | python3 <prog>.py
# diff the output against <prog>_test.out

Input/Output Data

There are two sets of input/output data: <prog>_sample.in/.out & <prog>_test.in/.out. The former is from sample input/output; the latter is from test input/output. The commas are removed from input data files, while the results are remained the same for the output files.

Hacker Rank Online System

All the solution programs are tailored to the <prog>_sample.in and <prog>_test.in file format which have 5 test cases typically. Some problems have different number of test cases or their input format are different. Such programs are not very common and the files intuitively self-descriptive.

However, when solving programming problems via the Hacker Rank Online code judge system, the solutions are expected to process ONLY one test case in each execution. There will be multiple test cases provided.
