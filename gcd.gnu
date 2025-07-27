set title 'GCD Worst'
set xrange[1:10]
set yrange[1:50]
set xlabel 'Input size'
set ylabel 'Operation Count'
set style data line
plot 'C:\Users\Sthuthi Sheela\Desktop\DAA\gcd5.txt' using 1:2 title 'Euclid','C:\Users\Sthuthi Sheela\Desktop\DAA\gcd5.txt' using 1:3 title'Subtraction','C:\Users\Sthuthi Sheela\Desktop\DAA\gcd5.txt' using 1:4 title'Modified euclid'

