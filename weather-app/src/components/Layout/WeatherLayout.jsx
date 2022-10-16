import React from "react";
import "./WeatherLayout.css";

function WeatherLayout(props) {
  return (
    <React.Fragment>
      <div className="container">
        <h2 className="heading">Weather Today</h2>
        <h3 className="place">{props.place}</h3>

        <div className="date">
          <h3 className="weekday">{`${props.day}`}</h3>{" "}
          <span className="dateMonth">{props.date}</span>
        </div>

        <div className="temp-box">
          <img src={props.imgURL} className="weather-img" alt="weather" />
          <div className="temp">
            <h1 title="Temperature">
              <span className="temp-value">{props.temp}</span> °C
            </h1>
            <h2 className="min-max" title="Minimum/Maximum Temprature">
              {props.tempMinMax}
            </h2>
          </div>
        </div>

        <div>
          <div className="row">
            <div className="col-4 weather" title="Humidity">
              <img
                src="https://img.icons8.com/fluency-systems-filled/48/FFFFFF/dew-point.png"
                alt="humidity"
              />
              <p>{props.humidity}</p>
            </div>
            <div className="col-4 weather" title="Pressure">
              <img
                src="https://img.icons8.com/ios-glyphs/30/FFFFFF/atmospheric-pressure--v1.png"
                alt="pressure"
              />
              <p>{props.pressure}</p>
            </div>
            <div className="col-4 weather" title="Wind">
              <img
                src="https://img.icons8.com/ios-filled/50/FFFFFF/wind--v1.png"
                alt="wind"
              />
              <p>{props.wind}</p>
            </div>
          </div>
        </div>
      </div>
    </React.Fragment>
  );
}

export default WeatherLayout;
