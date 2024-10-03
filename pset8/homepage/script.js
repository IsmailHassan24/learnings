document.addEventListener("DOMContentLoaded", function(){
    console.log("DOM fully loaded and parsed");

const x = document.getElementById("demo");

x.addEventListener("click", function geoLocation() {
    if (navigator.geolocation) {
        navigator.geolocation.getCurrentPosition(showGeoLocation, showError);
    } else {
        x.innerHTML = "Geolocation not supported";
    }
});

function showGeoLocation(position) {
    x.innerHTML = "Latitude: " + position.coords.latitude +
    "<br>Longitude: " + position.coords.longitude;
}

function showError(error) {
    switch(error.code) {
      case error.PERMISSION_DENIED:
        x.innerHTML = "User denied the request for Geolocation."
        break;
      case error.POSITION_UNAVAILABLE:
        x.innerHTML = "Location information is unavailable."
        break;
      case error.TIMEOUT:
        x.innerHTML = "The request to get user location timed out."
        break;
      case error.UNKNOWN_ERROR:
        x.innerHTML = "An unknown error occurred."
        break;
    }
  }
});
