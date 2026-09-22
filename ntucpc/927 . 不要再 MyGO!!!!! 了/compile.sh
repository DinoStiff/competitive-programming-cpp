#!/bin/bash

problem="nogo"
grader_name="grader"

g++ -std=gnu++17 -O2 -Wall -pipe -o "${problem}.exe" "${grader_name}.cpp" "${problem}.cpp"
