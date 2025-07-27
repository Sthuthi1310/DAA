set title 'String Match'
set xrange[1:4]
set yrange[3:12]
set xlabel "Iteration"
set ylabel "Operation Count"
set style data line
plot 'C:\Users\Sthuthi Sheela\Desktop\DAA\CountStr.txt' using 1:2 title "Best case",'C:\Users\Sthuthi Sheela\Desktop\DAA\CountStr.txt' using 1:3 title "Average case",'C:\Users\Sthuthi Sheela\Desktop\DAA\CountStr.txt' using 1:4 title "Worst case"