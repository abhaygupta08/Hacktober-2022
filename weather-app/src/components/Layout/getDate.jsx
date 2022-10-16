import React from 'react';
 
function GetDate (){

    const weekday = [
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday",
      ];
      const month = [
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December",
      ];
      
      const currentDate = new Date();
      
      const day = weekday[currentDate.getDay()];
      
      const date = month[currentDate.getMonth()] + " " + currentDate.getDate();
   return {day: day, date: date};
}
 
export default GetDate