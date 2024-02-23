for (var ii = 4, jj = 3; jj >= 0; ii++, jj--) {
  var multiply = ii * jj;
  var divide = ii / jj;
  var log = Math.log(jj);
  var sqrt = Math.sqrt(jj - 1);

  document.writeln(ii + " * " + jj + " = " + multiply.toFixed(3) + "<br>");
  document.writeln(ii + " / " + jj + " = " + divide.toFixed(3) + "<br>");
  document.writeln("log(" + jj + ") = " + log.toFixed(3) + "<br>");
  document.writeln("sqrt(" + (jj - 1) + ") = " + sqrt.toFixed(3) + "<br><br>");
}
