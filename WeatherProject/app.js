//WeatherData javascript functions

const express = require("express");
const https = require("https");
const bodyParser = require("body-parser");

const app = express();

app.use(bodyParser.urlencoded({ extended: true }));

app.get("/", function (req, res) {
  res.sendfile(__dirname + "/index.html");
});

app.post("/", function (req, res) {
  var query;
  req.body.cityName == "" ? (query = "London") : (query = req.body.cityName);
  const apiKey = "";
  const unit = "imperial";
  var url =
    "https://api.openweathermap.org/data/2.5/weather?q=" +
    query +
    "&units=" +
    unit +
    "&appid=" +
    apiKey;

  https.get(url, function (response) {
    console.log("status code: " + response.statusCode);

    response.on("data", function (data) {
      const weatherData = JSON.parse(data);
      const temp = weatherData.main.temp;
      const weatherDescription = weatherData.weather[0].description;
      const icon = weatherData.weather[0].icon;

      var imageURL = "http://openweathermap.org/img/wn/" + icon + "@2x.png";

      //console.log(weatherData);
      //console.log(temp);
      //  console.log(weatherDescription);
      //console.log(imageURL);
      res.write(
        "<h1> temp in " + query + "burry " + temp + " farenheit </h1> "
      );
      res.write(
        "<h2>the Weather is currently : " +
          weatherDescription +
          "</h2>"
      );
      res.write("<img src=" + imageURL + "> <p></p>");
      res.send();
    });
  });
});

/*

c
 */

app.listen(3000, function () {
  console.log("server in action");
});
