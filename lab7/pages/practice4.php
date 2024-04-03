<?php
// Create a variable that stores the value of the number entered by the user
$size = $_POST["size"];

echo "<h1>EECS 348 Lab 7: Practice 4</h1>";

// Start the table and use a border of 1
echo "<table border=\"1\">";

// This prints the header row
echo "<th></th>"; // Empty because the top left cell of the table should be empty
for ($x=1; $x <= $size; $x++) {
  echo "<th>" . $x . "</th>"; // print the column number as the table header
}

// Loop through the rows
for ($i=1; $i <= $size; $i++) {
  // Each row should create a new row in the html table
  echo "<tr>";
  echo "<th>" . $i . "</th>"; // print the row number as the table header
  // Loop through the columns
  for ($j=1; $j <= $size; $j++) {
    // Each column in each row is really a cell.
    // And we want each cell to contain the product of the current row and column
    echo "<td>" . $i * $j . "</td>";
  }
  // We have looped through every cell in this row so now we end the row.
  echo "</tr>";
}
// We have looped through every cell in every row so we are done with the table.
echo "</table>";
?>
