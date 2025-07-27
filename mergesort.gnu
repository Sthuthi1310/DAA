set title 'Merge sort'
set xrange[10:100]
set yrange[15:570]
set xlabel 'Input size'
set ylabel 'Operation Count'
set style data line
plot 'C:\Users\Sthuthi Sheela\Desktop\DAA\file2.txt' using 1:2 title 'best','C:\Users\Sthuthi Sheela\Desktop\DAA\file2.txt' using 1:2 title 'average','C:\Users\Sthuthi Sheela\Desktop\DAA\file2.txt' using 1:2 title 'worst'