#!/bin/bash
./mathlib-test -s | tail -n +3 | awk '{print $1" " $2}' > arcSin.dat
./mathlib-test -c | tail -n +3 | awk '{print $1" " $2}' > arcCos.dat
./mathlib-test -t | tail -n +3 | awk '{print $1" " $2}' > Tan.dat
./mathlib-test -l | tail -n +3 | awk '{print $1" " $2}' > Log.dat

./mathlib-test -s | tail -n +3 | awk '{print $1" " $3}' > asin.dat
./mathlib-test -c | tail -n +3 | awk '{print $1" " $3}' > acos.dat
./mathlib-test -t | tail -n +3 | awk '{print $1" " $3}' > tan.dat
./mathlib-test -l | tail -n +3 | awk '{print $1" " $3}' > log.dat



gnuplot <<xx

set terminal jpeg

set output "arcSin.jpg"
plot "asin.dat" with linespoints,"arcSin.dat" with linespoints

set output "arcCos.jpg"
plot "acos.dat" with linespoints,"arcCos.dat" with linespoints

set output "Tan.jpg"
plot "tan.dat" with linespoints,"Tan.dat" with linespoints

set output "Log.jpg"
plot "log.dat" with linespoints,"Log.dat" with linespoints

xx
