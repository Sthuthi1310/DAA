set title 'Bubble_sort'
set xrange[5:50]
set yrange[-10:1200]
set xlabel 'Input size'
set ylabel 'Operation Count'
set style data line
plot 'C:\Users\Sthuthi Sheela\Desktop\DAA\CountB.txt' using 1:2 title 'Best case','C:\Users\Sthuthi Sheela\Desktop\DAA\CountB.txt' using 1:3 title'Average case','C:\Users\Sthuthi Sheela\Desktop\DAA\CountB.txt' using 1:4 title'Worst case'

