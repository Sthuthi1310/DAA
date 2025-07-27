set title 'String match'
set xrange[10:100]
set yrange[9:200]
set xlabel 'Input size'
set ylabel 'Operation Count'
set style data line
plot 'C:\Users\Sthuthi Sheela\Desktop\DAA\CountStr.txt' using 1:2 title 'Best case','C:\Users\Sthuthi Sheela\Desktop\DAA\CountStr.txt' using 1:3 title'Average case','C:\Users\Sthuthi Sheela\Desktop\DAA\CountStr.txt' using 1:4 title'Worst case'

