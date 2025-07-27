set title "BINARY SEARCH"
set xrange[11:101]
set yrange[1:10]
set xlabel "Input size"
set ylabel "Operation count"
set style data line
plot 'binarycount.txt' using 1:2 title 'Best case', 'binarycount.txt' using 1:4 title'Worst case', 'binarycount.txt' using 1:4 title'Worst case'
# Set the terminal (use 'qt' or 'pngcairo' if qt is not available)
set terminal qt enhanced font 'Arial,10' size 800,600

# Optional: if you want to save the plot as image, uncomment below 2 lines
# set terminal pngcairo size 800,600
# set output 'binarysearch_output.png'

# Set titles and labels
set title "BINARY SEARCH - Operation Count vs Input Size"
set xlabel "Input size (n)"
set ylabel "Operation count"
set xrange [10:100]
set yrange [0:*]
set grid
set key outside

# Use lines and points
set style data linespoints
set pointsize 1.5

# Plot data: Best case (1), Worst case (log₂n), Average case (log₂n - 1)
plot 'binarycount.txt' using 1:2 title 'Best Case' lt rgb "green", \
     'binarycount.txt' using 1:3 title 'Average Case' lt rgb "blue", \
     'binarycount.txt' using 1:4 title 'Worst Case' lt rgb "red"

# If you used pngcairo, uncomment this to close the output
# set output
