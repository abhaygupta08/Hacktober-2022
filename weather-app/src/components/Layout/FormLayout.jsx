import React, { useState } from "react";
import { useHistory } from "react-router-dom";
import _ from "lodash";

import "./FormLayout.css";

function FormLayout(props) {
  const history = useHistory();

  const [city, setCity] = useState("");

  const handeler = (e) => {
    if (city.trim() === "") {
      alert("Invalid input. Can't enter empty input");
      return;
    }
    e.preventDefault();
    history.push("/weather?city=" + _.lowerCase(city));
    setCity("");
  };

  function changeHandeler(e) {
    setCity(e.target.value);
  }

  return (
    <form onSubmit={handeler} className="form-control">
      <input placeholder="Enter City" value={city} onChange={changeHandeler} />
      <button className="btn-light btn-lg" type="submit">
        Search
      </button>
    </form>
  );
}

export default FormLayout;
