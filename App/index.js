var http = require("http").Server(http);
var io = require("socket.io").listen(http);
var path = require("path"); // dodanie ścieżek do plików
var fs = require("fs");
var os = require("os");
var sp = require("serialport");
const Readline = require("@serialport/parser-readline");
var express = require("express");
var bodyParser = require("body-parser");
var sessions = require("express-session");

var app = express();
var port = 8080;
var router = express.Router(); // configuration
var session;

// Static files : HTML, CSS, JS
app.use(express.static("public"));

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));
app.use(
  sessions({
    secret: "gref345f54",
    resave: false,
    saveUninitialized: true,
  })
);

app.get("/", function (req, res) {
  res.sendFile(path.join(__dirname, "/public/login.html"));
});

app.get("/", function (req, res) {
  session = req.session;
  if (session.uniqueID) {
    res.redirect("/redirects");
  }
  res.sendFile("./public/login.html", { root: __dirname });
});

app.post("/login", function (req, res) {
  session = req.session;
  if (session.uniqueID) {
    res.redirect("/redirects");
  }
  if (
    req.body.username == "administrator" &&
    req.body.password == "administrator"
  ) {
    session.uniqueID = req.body.username;
  }
  res.redirect("/redirects");
});

app.get("/redirects", function handler(req, res) {
  session = req.session;
  if (session.uniqueID) {
    var host = req.headers["host"].split(":")[0];
    url = req.url;
    res.writeHead(301, {
      Location: "http://192.168.1.21" + ":" + "8000" + "/?code=1234",
    });
    res.end();
    req.session.destroy();
  } else {
    res.sendFile("./public/login.html", { root: __dirname });
  }
});

app.listen(port, "192.168.1.21", function () {
  console.log("listening on *:8080");
});
