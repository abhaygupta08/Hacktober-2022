import { BrowserRouter, Route, useHistory } from "react-router-dom";
import "bootstrap/dist/css/bootstrap.min.css";

import FormLayout from "./components/Layout/FormLayout";
import Weather from "./components/Weather/Weather";
import Header from "./components/Header/Header";

function App() {
  const history = useHistory();

  function clickHandeler(city) {
    history.push("/weather?city=" + city);
  }

  return (
    <BrowserRouter>
      <Header />
      <FormLayout onClick={clickHandeler} />

      <Route path="/weather">
        <Weather />
      </Route>
    </BrowserRouter>
  );
}

export default App;
