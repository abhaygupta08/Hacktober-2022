import React, { useEffect, useState } from "react";
import { useLocation } from "react-router-dom";
import _ from "lodash";

import WeatherLayout from "../Layout/WeatherLayout";
import Loading from "../Loading/Loading";
import GetDate from "../Layout/getDate";

function Weather() {
  const [weatherDetails, setWeatherDetails] = useState({});
  const [loading, setLoading] = useState(false);
  const [error, setError] = useState(null);

  const location = useLocation();
  const searchParams = new URLSearchParams(location.search);
  const query = searchParams.get("city");

  const {date, day} = GetDate();
  

  useEffect(() => {
    async function sendRequest(query) {
      setLoading(true);
      try {
        const response = await fetch(
          "https://api.openweathermap.org/data/2.5/weather?appid=a7ee98cc1a53b614d89d211466f1b973&q=" +
            query +
            "&units=metric"
        );

        const data = await response.json();

        if (!response.ok) {
          let message = data.message;
          if (message === "city not found") {
            message = "Invalid city. Try again!";
          }
          throw new Error(message);
        }

        const transformedData = {
          place: _.capitalize(query),
          date: date,
          day: day,
          temp: data.main.temp,
          tempMinMax: data.main.temp_min + "/" + data.main.temp_max,
          humidity: data.main.humidity,
          pressure: data.main.pressure,
          wind: data.wind.speed,
          icon: data.weather[0].icon,
          imgURL:
            "http://openweathermap.org/img/wn/" +
            data.weather[0].icon +
            "@2x.png",
        };

        setWeatherDetails(transformedData);
        console.log("Success");
      } catch (err) {
        setError(err.message);
      }
      setLoading(false);
    }

    sendRequest(query);
  }, [query]);

  return (
    <div>
      {loading ? (
        <div className="centered">
          <Loading />
        </div>
      ) : null}

      {!loading && !error ? (
        <WeatherLayout
          place={weatherDetails.place}
          date={weatherDetails.date}
          day={weatherDetails.day}
          imgURL={weatherDetails.imgURL}
          temp={weatherDetails.temp}
          tempMinMax={weatherDetails.tempMinMax}
          humidity={weatherDetails.humidity}
          pressure={weatherDetails.pressure}
          wind={weatherDetails.wind}
        />
      ) : null}

      {error && !loading ? <p className="centered">{error}</p> : null}
    </div>
  );
}

export default Weather;
