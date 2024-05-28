function showHint(str) {
  if (str.length == 0) {
    document.getElementById("txtHint").innerHTML = "";
  }

  xhttp = new XMLHttpRequest();

  xhttp.onreadystatechange = function () {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("txtHint").innerHTML = this.responseText;
    }
  };

  xhttp.open("GET", "php11F_getHint.php?keyword=" + str, true);
  xhttp.send();
}
