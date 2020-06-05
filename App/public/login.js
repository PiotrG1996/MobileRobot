// ustawienie nazwy użytkownika oraz hasła
//var objUser = [
//  {
//    username: "administrator",
//  password: "administrator"

//}
//]

// funkcja sprawdzająca poprawność wpisywanych danych do logowania
//function sprawdz() {
//var username = document.getElementById("username").value;
//var password = document.getElementById("password").value;

//for(i = 0; i < objUser.length; i++) {
//  if ( username == objUser[i].username && password == objUser[i].password)
//{
//      window.open("./app/index.html");
//}
//else {
// window.open("./login.html", "_self");
//}
// }

//}

// globalne wywołanie w pliku HTML funkcji animacji tytułu

$(".txt").html(function (i, html) {
  var chars = $.trim(html).split("");

  return "<span>" + chars.join("</span><span>") + "</span>";
});

/* Przykładowy kod do rozszerzenia funkcjonalności formularza logowania  */
var s,
  myLogin = {
    /* informacje o nowo tworzonym użytkowniku */
    settings: {
      servletInscription: "Inscription",
      servletConnexion: "Connexion",
      signed: false,
      sign_request: false,
      pseudo: "",
      pswd: "",
      grade: "1",
      dataAuth: "",
      dataConn: "",
    },

    init: function () {
      s = this.settings;
      myLogin.init_sign();
      myLogin.init_log();
    },

    init_sign: function () {
      /* Pobieranie elementów strony*/
      var choose = document.getElementsByClassName("onoffswitch")[0];
      var btn1 = document.getElementById("sign");
      var btn2 = document.getElementById("submit");
      var login = document.getElementById("login");

      /* Dodanie lisenera do przycisku SignIn*/
      btn1.addEventListener("click", function (e) {
        // animacja suwaka

        {
          login.style.transition = "min-height 0.7s ease ";
          login.style.minHeight = "480px";

          btn1.style.transition = "transform 0.7s ease ";
          btn1.style.webkitTransition = "-webkit-transform 0.7s ease ";
          btn1.style.transform = "translateY(50px)";
          btn1.style["-webkit-transform"] = "translateY(50px)";

          btn2.style.transition = "transform 0.7s ease ";
          btn2.style.webkitTransition = "-webkit-transform 0.7s ease ";
          btn2.style.transform = "translateY(50px)";
          btn2.style["-webkit-transform"] = "translateY(50px)";

          choose.style.transition = "opacity 2s ease,transform 1s ease";
          choose.style.WebkitTransition = "opacity 1s";
          choose.style.webkitTransition = "-webkit-transform 0.7s ease";
          choose.style.transform = "translateY(20px)";
          choose.style["-webkit-transform"] = "translateY(20px)";
          choose.style.opacity = "1";
        }
      });
    },

    request_sign: function () {},

    request_log: function () {},
  };

// Inicjowanie, gdy dokument jest gotowy.
$(document).ready(myLogin.init());
