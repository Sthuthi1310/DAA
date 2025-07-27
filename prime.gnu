set title 'Prime'
set xrange[1:5]
set yrange[1:100]
set xlabel 'Input size'
set ylabel 'Operation Count'
set style data line
plot 'C:\Users\Sthuthi Sheela\Desktop\DAA\prime.txt' using 1:2 title '2-n','C:\Users\Sthuthi Sheela\Desktop\DAA\prime.txt' using 1:2 title '2-n-1','C:\Users\Sthuthi Sheela\Desktop\DAA\prime.txt' using 1:2 title '2-(n/2)','C:\Users\Sthuthi Sheela\Desktop\DAA\prime.txt' using 1:2 title '2-sqrt(n);