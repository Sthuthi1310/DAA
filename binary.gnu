set title 'Binary Search'
set xrange[0:100]
set yrange[1:16]
set xlabel 'Input size'
set ylabel 'Operation Count'
set style data line
plot 'C:\Users\Sthuthi Sheela\Desktop\DAA\binarycount.txt' using 1:2 title 'Best case','C:\Users\Sthuthi Sheela\Desktop\DAA\binarycount.txt' using 1:4 title'Worst case'

