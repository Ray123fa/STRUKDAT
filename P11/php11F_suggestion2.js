function showHint(str) {
  if (str.length == 0) {
    document.getElementById("txtHint").innerHTML = "";
  }

  xhttp = new XMLHttpRequest();

  xhttp.onreadystatechange = function () {
    if (this.readyState == 4 && this.status == 200) {
      var response = JSON.parse(this.responseText);
      var txtHint = "";

      if (response.length > 0) {
        for (var i = 0; i < response.length; i++) {
          txtHint += response[i].name;
          if (i < response.length - 1) {
            txtHint += ", ";
          }
        }
      } else {
        txtHint = "No suggestion";
      }

      document.getElementById("txtHint").innerHTML = txtHint;
    }
  };

  xhttp.open("GET", "php11F_getHint2.php?keyword=" + str, true);
  xhttp.send();
}
